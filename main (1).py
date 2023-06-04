#
# Client-side python app for photoapp, this time working with
# web service, which in turn uses AWS S3 and RDS to implement
# a simple photo application for photo storage and viewing.
#
# Project 02 for CS 310, Spring 2023.
#
# Authors:
#   Adit Goyal
#   Prof. Joe Hummel (initial template)
#   Northwestern University
#   Spring 2023
#

import requests  # calling web service
import jsons  # relational-object mapping
from PIL import Image
import piexif

import uuid
import pathlib
import logging
import sys
import os
import base64

from configparser import ConfigParser

import matplotlib.pyplot as plt
import matplotlib.image as img

class User:
  userid: int  # these must match columns from DB table
  email: str
  lastname: str
  firstname: str
  bucketfolder: str


class Asset:
  assetid: int  # these must match columns from DB table
  userid: int
  assetname: str
  bucketkey: str


class BucketItem:
  Key: str      # these must match columns from DB table
  LastModified: str
  ETag: str
  Size: int
  StorageClass: str

def prompt():
  print()
  print(">> Enter a command:")
  print("   0 => end")
  print("   1 => stats")
  print("   2 => users")
  print("   3 => assets")
  print("   4 => download")
  print("   5 => download and display")
  print("   6 => bucket contents")
  print("   7 => upload")

  cmd = int(input())
  return cmd

def stats(baseurl):
  try:
    api = '/stats'
    url = baseurl + api
    res = requests.get(url)
    
    if res.status_code != 200:
      print("Failed with status code:", res.status_code)
      print("url: " + url)
      if res.status_code == 400:
        body = res.json()
        print("Error message:", body["message"])
      return

    body = res.json()
    print("bucket status:", body["message"])
    print("# of users:", body["db_numUsers"])
    print("# of assets:", body["db_numAssets"])

  except Exception as e:
    logging.error("stats() failed:")
    logging.error("url: " + url)
    logging.error(e)
    return
    
def users(baseurl):
  try:
    api = '/users'
    url = baseurl + api
    res = requests.get(url)

    if res.status_code != 200:
      print("Failed with status code:", res.status_code)
      print("url: " + url)
      if res.status_code == 400:
        body = res.json()
        print("Error message:", body["message"])
      return

    body = res.json()
    users = []
    for row in body["data"]:
      user = jsons.load(row, User)
      users.append(user)
    for user in users:
      print(user.userid)
      print(" ", user.email)
      print(" ", user.lastname, ",", user.firstname)
      print(" ", user.bucketfolder)

  except Exception as e:
    logging.error("users() failed:")
    logging.error("url: " + url)
    logging.error(e)
    return

def assets(baseurl):
  try:
    api = '/assets'
    url = baseurl + api
    res = requests.get(url)

    if res.status_code != 200:
      print("Failed with status code:", res.status_code)
      print("url: " + url)
      if res.status_code == 400:
        body = res.json()
        print("Error message:", body["message"])
      return

    body = res.json()
    assets = []
    for row in body["data"]:
      asset = jsons.load(row, Asset)
      assets.append(asset)
    for asset in assets:
      print(asset.assetid)
      print(" ", asset.userid)
      print(" ", asset.assetname)
      print(" ", asset.bucketkey)

  except Exception as e:
    logging.error("assets() failed:")
    logging.error("url: " + url)
    logging.error(e)
    return

def download(baseurl, assetid, flag):
  try:
    api = '/download/'
    url = baseurl + api + str(assetid)
    res = requests.get(url)

    if res.status_code != 200:
      print("Failed with status code:", res.status_code)
      print("url: " + url)
      if res.status_code == 400:
        body = res.json()
        print("Error message:", body["message"])
      return

    body = res.json()
    if "no such asset" in body["message"]:
      print("No such asset...")
    else:
      print("userid:", body["user_id"])
      print("asset name:", body["asset_name"])
      print("bucket key:", body["bucket_key"])
      if isinstance(body["data"], str):
        base64Data = base64.b64decode(body["data"])
      elif isinstance(body["data"], list):
        base64Data = base64.b64decode(body["data"][0])
      imageFile = open(body["asset_name"], "wb")
      imageFile.write(base64Data)
      print("Downloaded from S3 and saved as '", body["asset_name"], "'")

      if flag:
        image = img.imread(body["asset_name"])
        plt.imshow(image)
        plt.show()
    
  except Exception as e:
    logging.error("download() failed:")
    logging.error("url: " + url)
    logging.error(e)
    return

def bucketContents(baseurl):
  try:
    api = '/bucket'
    url = baseurl + api
    res = requests.get(url)

    if res.status_code != 200:
      print("Failed with status code:", res.status_code)
      print("url: " + url)
      if res.status_code == 400:
        body = res.json()
        print("Error message:", body["message"])
      return

    anotherPageFlag = True
    while anotherPageFlag:
      body = res.json()
      contents = []
      lastKey = ""
      for row in body["data"]:
        content = jsons.load(row, BucketItem)
        contents.append(content)

      if len(contents) == 0:
        break
      
      for content in contents:
        print(content.Key)
        print(" ", content.LastModified)
        print(" ", content.Size)
        lastKey = content.Key
      
      print("another page? [y/n]")
      answer = input()
      if answer != 'y':
        anotherPageFlag = False
      else:
        url = baseurl + api + "?startafter=" + lastKey
        res = requests.get(url)

        if res.status_code != 200:
          print("Failed with status code:", res.status_code)
          print("url: " + url)
          if res.status_code == 400:
            body = res.json()
            print("Error message:", body["message"])
          return

  except Exception as e:
    logging.error("bucketContent() failed:")
    logging.error("url: " + url)
    logging.error(e)
    return

def _convert_to_decimal_degrees(coordinates):
  degrees = coordinates[0][0] / coordinates[0][1]
  minutes = coordinates[1][0] / coordinates[1][1]
  seconds = coordinates[2][0] / coordinates[2][1]

  return degrees + (minutes / 60) + (seconds / 3600)

def get_lat_lon(image_path):
  try:
    image = Image.open(image_path)
    exif_data = piexif.load(image.info["exif"])
    gps_data = exif_data.get('GPS')

    if gps_data:
      latitude = gps_data[piexif.GPSIFD.GPSLatitude]
      longitude = gps_data[piexif.GPSIFD.GPSLongitude]
      date_time = exif_data.get('0th', {}).get(piexif.ImageIFD.DateTime)

      latitude = _convert_to_decimal_degrees(latitude)
      longitude = _convert_to_decimal_degrees(longitude)

      if date_time:
        date_time_str = date_time.decode('utf-8')
        return latitude, longitude, date_time_str

      return latitude, longitude, ""

  except (AttributeError, KeyError, TypeError, IndexError):
    return

def upload(baseurl):
  try:
    api = '/image'
    userid = input("Enter user id: ")
    url = baseurl + api + "/" + userid
    filename = "basketball.jpg"
    with open(filename, mode='rb') as file:
      fileContent = file.read()
    base64Data = base64.b64encode(fileContent)
    imgData = base64Data.decode()

    image_path = "eng.jpg"
    latitude, longitude, date_time = get_lat_lon(image_path)
    if latitude and longitude and date_time:
        print("Latitude:", latitude)
        print("Longitude:", longitude)
        print("date time", date_time)
        postAPIBody = {
          "assetname": filename,
          "data": imgData,
          "latitude": latitude,
          "longitude": longitude,
          "date_time": date_time
        }
    else:
        print("No GPS data found in the image.")
    
    # postAPIBody = {
    #   "assetname": filename,
    #   "data": imgData
    # }
    res = requests.post(url, json = postAPIBody)
    print(res.json())
    
  except Exception as e:
    logging.error("upload() failed:")
    logging.error("url: " + url)
    logging.error(e)
    return

print('** Welcome to PhotoApp v2 **')
print()

sys.tracebacklimit = 0

config_file = 'photoapp-client-config'

print("What config file to use for this session?")
print("Press ENTER to use default (photoapp-config),")
print("otherwise enter name of config file>")
s = input()

if s == "":
  pass
else:
  config_file = s

if not pathlib.Path(config_file).is_file():
  print("**ERROR: config file '", config_file, "' does not exist, exiting")
  sys.exit(0)

configur = ConfigParser()
configur.read(config_file)
baseurl = configur.get('client', 'webservice')

cmd = prompt()

while cmd != 0:
  if cmd == 1:
    stats(baseurl)
  elif cmd == 2:
    users(baseurl)
  elif cmd == 3:
    assets(baseurl)
  elif cmd == 4:
    print("Enter asset id>")
    assetid = int(input())
    download(baseurl, assetid, 0)
  elif cmd == 5:
    print("Enter asset id>")
    assetid = int(input())
    download(baseurl, assetid, 1)
  elif cmd == 6:
    bucketContents(baseurl)
  elif cmd == 7:
    upload(baseurl)
  else:
    print("** Unknown command, try again...")
  cmd = prompt()

print()
print('** done **')