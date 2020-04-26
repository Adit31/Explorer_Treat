#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
#include<map>
//#include <windows.h>
#include<queue>
using namespace std;
/*
Bank User ID: bank1234
Password: 1234bank
*/
void gotoxy(short x, short y)
{
printf("%c[%d;%df",0x1B,y,x);
}
struct node
{
    char des[30];
    int visited;
};

map<char*,vector< node > > x;
void bfs(char s[30],char d[30])
{
    //map<char*,bool> visited;

    queue<char*> queue;

    //visited[s] = true;
    queue.push(s);
    vector<node> ::iterator i;
    int f=0;
    while(!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop();
        f=0;
        for (i = x[s].begin(); i != x[s].end(); ++i)
        {
            if ((*i).visited==0)
            {
                (*i).visited = 1;
                if(strcpy((*i).des,d))
                f=1;
                queue.push((*i).des);
            }
        }
    }
    if(f==1)
    {
    	fflush(stdin);
    	getchar();
    	system("cls");
    	gotoxy(20,20);
    	cout<<"MODES OF TRAVEL ARE AVAILABLE!!!";
    	gotoxy(20,22);
    	cout<<"CHECK SITE FOR FLIGHT/TRAIN NUMBERS";
    	fflush(stdin);
    	getchar();
	}
	else
	{

    	fflush(stdin);
    	getchar();
		system("cls");
    	gotoxy(20,20);
    	cout<<"YOUR DESTINATION CANNOT BE REACHED!!!";
    	gotoxy(20,22);
    	cout<<"SORRY FOR THE INCONVENIENCE";
    	fflush(stdin);
    	getchar();
	}
}
void searchs()
{
	system("cls");
    char s[30],d[30];
    gotoxy(10,10);
    cout<<"ENTER STARTING POINT :";
    gotoxy(47,10);
    cin>>s;
    gotoxy(10,12);
    cout<<"ENTER DESTINATION :";
    gotoxy(47,12);
    cin>>d;
    bfs(s,d);
}

class Bank
{
private :
char user[30];
char pass[30];
long unsigned int bal;
public :
Bank()
{
    strcpy(user,"\0");
    strcpy(pass,"\0");
    bal=0;
}
void setuser(char x[30])
{
    strcpy(user,x);
}
void setpass(char x[30])
{
    strcpy(pass,x);
}
void setbal(long unsigned int x)
{
    bal=x;
}
char * retuser()
{
    return user;
}
char * retpass()
{
    return pass;
}
long unsigned int retbal()
{
    return bal;
}
};

class pb
{
private :
long unsigned int amount;
char func[30];
char name[30];
int number;
public :
pb()
{
    strcpy(func,"\0");
    number=0;
    strcpy(name,"\0");
    amount=0;
}
char* retfunc()
{
    return func;
}
int retnumber()
{
    return number;
}
char * retname()
{
    return name;
}
long unsigned int retamount()
{
    return amount;
}
void setfunc(char x[30])
{
    strcpy(func,x);
}
void setnumber(int x)
{
   number=x;
}
void setname(char x[30])
{
    strcpy(name,x);
}
void setamount(long unsigned int x)
{
    amount=x;
}
};


class user
{
private :
Bank bank;
long unsigned int balance;
char name[30];
pb passbook[100];
char mobile[11];
char email[30];
char pass[30];
char DOB[11];
int no;
public :
user()
{
    balance=0;
    strcpy(name,"\0");
    strcpy(mobile,"\0");
    strcpy(email,"\0");
    strcpy(pass,"\0");
    strcpy(DOB,"\0");
    no=0;
}
void setbuser(char x[30])
{
    bank.setuser(x);
}
void setbpass(char x[30])
{
    bank.setpass(x);
}
void setbbal(long unsigned int x)
{
    bank.setbal(x);
}
char* retbuser()
{
    return bank.retuser();
}
char* retbpass()
{
    return bank.retpass();
}
long unsigned int retbbal()
{
    return bank.retbal();
}
long unsigned int retbalance()
{
    return balance;
}
char* retname()
{
    return name;
}
char * retmobile()
{
    return mobile;
}
char* retemail()
{
    return email;
}
char* retpass()
{
    return pass;
}
char* retDOB()
{
    return DOB;
}
int retno()
{
    return no;
}
void setbalance(long unsigned int x)
{
    balance=x;
}
void setname(char x[30])
{
    strcpy(name,x);
}
char* retpfunc(int i)
{
    return passbook[i].retfunc();
}
int retpnumber(int i)
{
    return passbook[i].retnumber();
}
char* retpname(int i)
{
    return passbook[i].retname();
}
long unsigned int retpamount(int i)
{
    return passbook[i].retamount();
}
void setpfunc(int i, char x[30])
{
    passbook[i].setfunc(x);
}
void setpnumber(int i, int x)
{
    passbook[i].setnumber(x);
}
void setpname(int i, char x[30])
{
    passbook[i].setname(x);
}
void setpamount(int i, long unsigned int x)
{
    passbook[i].setamount(x);
}
void setmobile(char x[11])
{
    strcpy(mobile,x);
}
void setemail(char x[30])
{
    strcpy(email,x);
}
void setpass(char x[30])
{
    strcpy(pass,x);
}
void setDOB(char x[11])
{
    strcpy(DOB,x);
}
void setno(int x)
{
    no=x;
}
void input();
int checkemail();
int checkmobile();
void display();
void modify();
void deposit();
void sortpb();
void viewpb();
void deactivate();
}v;
void user::deactivate()
{
int p,i;
user e;
ifstream fin;
fin.open("user.dat",ios::in|ios::binary);
ofstream fout;
fout.open("temp.dat",ios::out|ios::binary);
setbbal(retbbal()+balance);
balance=0;
while(fin.read((char*)&e,sizeof(user)))
{
if(strcmp(mobile,e.mobile))
{
fout.write((char*)&e,sizeof(user));
}
}
fout.close();
fin.close();
remove("user.dat");
rename("temp.dat","user.dat");
system("cls");
cout<<"ACCOUNT DEACTIVATED\n";
}
void user::deposit()
{
int b,s,i,t;
long unsigned int a;
char sa[30];
t=0;
system("cls");
gotoxy(10,10);
cout<<"ENTER AMOUNT TO BE ADDED\n";
gotoxy(47,10);
cin>>a;
if(a>retbbal())
{
    system("cls");
    gotoxy(30,30);
cout<<"TRANSACTION NOT POSSIBLE ( BANK BALANCE IS LOW )\n";
fflush(stdin);
getchar();
return;
}
passbook[no].setamount(a);
gotoxy(10,12);
cout<<"ENTER YOUR CHOICE";
gotoxy(10,13);
cout<<"1. PAY VIA NET BANKING";
gotoxy(10,14);
cout<<"2. EXIT";
gotoxy(10,15);
cin>>b;
system("cls");
switch(b)
{
case 1:
    gotoxy(10,10);
    cout<<"ENTER BANK NAME\n";
       gotoxy(47,10);
       cin>>sa;
       passbook[no].setname(sa);
       gotoxy(10,12);
       cout<<"ENTER USERNAME\n";
       gotoxy(47,12);
       cin>>sa;
       passbook[no].setnumber(-1);
       if(strcmp(sa,retbuser()))
       {
       system("cls");
       gotoxy(30,30);
       cout<<"INCORRECT USERNAME\n";
       fflush(stdin);
       getchar();
       break;
       }
       gotoxy(10,14);
       cout<<"ENTER PASSWORD\n";
       gotoxy(47,14);
       cin>>sa;
       if(strcmp(sa,retbpass()))
       {
           system("cls");
           gotoxy(30,30);
       cout<<"INCORRECT PASSWORD\n";
       fflush(stdin);
       getchar();
       break;
       }
       balance+=a;
       setbbal(retbbal()-a);
       t=1;
       break;
case 2:return;
default:cout<<"INVALID CHOICE\n";
}
char x[30];
strcpy(x,"ADDED FROM");
passbook[no].setfunc(x);
system("cls");
if(t==1)
{
gotoxy(15,18);
cout<<"RUPEES "<<a<<" HAVE BEEN ADDED TO YOUR WALLET\n";
++no;
}
else
cout<<"TRANSACTION UNSUCCESSFUL\n";
}
void user::sortpb()
{
pb j;
int i,k;
for(k=0;k<no-1;k++)
{
for(i=0;i<no-k-1;i++)
{
if(passbook[i].retamount()<passbook[i+1].retamount())
{
j=passbook[i];
passbook[i]=passbook[i+1];
passbook[i+1]=j;
}
}
}
}
void user::viewpb()
{
system("cls");
sortpb();
int pos,j,i;
for(i=0;i<no;i++)
{
if(passbook[i].retamount()==0||strcmp(passbook[i].retfunc(),"\0")==0||strcmp(passbook[i].retname(),"\0")==0||passbook[i].retnumber()==0)
{
pos=i;
--no;
for(j=pos;j<no;j++)
passbook[i]=passbook[i+1];
}
cout<<i+1<<". RUPEES "<<passbook[i].retamount()<<"\n   "<<passbook[i].retfunc()<<" "<<passbook[i].retname()<<"\n   ID: "<<passbook[i].retnumber()<<"\n\n";
}
}
void user::display()
{
    gotoxy(10,13);
    cout<<"NAME : ";
    gotoxy(47,13);
    cout<<name;
    gotoxy(10,14);
    cout<<"MOBILE NUMBER : ";
    gotoxy(47,14);
    cout<<mobile;
    gotoxy(10,15);
    cout<<"E-MAIL ID : ";
    gotoxy(47,15);
    cout<<email;
    gotoxy(10,16);
    cout<<"WALLET BALANCE : ";
    gotoxy(47,16);
    cout<<balance;
}
void user::input()
{
ofstream fout ;
fout.open("user.dat",ios::app | ios::binary);
int i;
long unsigned int p;
char temp[30];
for(i=0;i<100;i++)
{
system("cls");
gotoxy(10,10);
cout<<"ENTER YOUR MOBILE NUMBER\n";
gotoxy(47,10);
cin>>mobile;
if(checkmobile())
break;
else
fflush(stdin); getchar();
}
if(!checkmobile())
return;
for(i=0;i<100;i++)
{
system("cls");
gotoxy(10,10);
cout<<"ENTER YOUR MOBILE NUMBER";
gotoxy(47,10);
cout<<mobile;
gotoxy(10,12);
cout<<"ENTER YOUR EMAIL-ID\n";
gotoxy(47,12);
cin>>email;
if(checkemail())
break;
else
fflush(stdin);
getchar();
}
if(!checkemail())
return;
for(i=0;i<100;i++)
{
system("cls");
gotoxy(10,10);
cout<<"ENTER YOUR MOBILE NUMBER";
gotoxy(47,10);
cout<<mobile;
gotoxy(10,12);
cout<<"ENTER YOUR EMAIL-ID";
gotoxy(47,12);
cout<<email;
gotoxy(10,14);
cout<<"CREATE YOUR PASSWORD\n";
gotoxy(47,14);
cin>>pass;
if(strlen(pass)==0)
{
gotoxy(20,16);
cout<<"INVALID PASSWORD\n";
fflush(stdin);
getchar();
}
else
break;
}
if(strlen(pass)==0)
return;
for(i=0;i<100;i++)
{
system("cls");
gotoxy(10,10);
cout<<"ENTER YOUR NAME\n";
gotoxy(52,10);
cin>>name;
if(strlen(name)==0)
{
gotoxy(20,12);
cout<<"INVALID NAME\n";
fflush(stdin);
getchar();
}
else
break;
}
if(strlen(name)==0)
return;
gotoxy(10,12);
cout<<"ENTER YOUR DATE OF BIRTH ( DD/MM/YYYY )\n";
gotoxy(52,12);
cin>>DOB;
for(i=0;i<100;i++)
{
system("cls");
gotoxy(10,10);
cout<<"ENTER NET BANKING USERNAME\n";
gotoxy(47,10);
cin>>temp;
if(strlen(temp)==0)
{
gotoxy(20,12);
cout<<"INVALID BANK USERNAME\n";
fflush(stdin);
getchar();
}
else
break;
}
if(strlen(temp)==0)
return;
else
setbuser(temp);
for(i=0;i<100;i++)
{
system("cls");
gotoxy(10,10);
cout<<"ENTER NET BANKING USERNAME";
gotoxy(47,10);
cout<<temp;
gotoxy(10,12);
cout<<"ENTER YOUR NET BANKING PASSWORD\n";
gotoxy(47,12);
cin>>temp;
if(strlen(temp)==0)
{
gotoxy(20,14);
cout<<"INVALID BANK PASSWORD\n";
fflush(stdin);
getchar();
}
else
break;
}
if(strlen(temp)==0)
return;
else
setbpass(temp);
gotoxy(10,14);
cout<<"ENTER YOUR BANK BALANCE\n";
gotoxy(47,14);
cin>>p;
setbbal(p);
fout.write((char*)this,sizeof(user));
fout.close();
system("cls");
gotoxy(20,10);
cout<<"\t\tYOUR USER ACCOUNT HAS BEEN CREATED SUCCESSFULLY\n";
display();
gotoxy(20,20);
cout<<"LOGIN TO USE YOUR ACCOUNT\n";
fflush(stdin);
getchar();
}
int user::checkemail()
{
int a=0;
ifstream fin;
fin.open("user.dat",ios::in|ios::binary);
if(strlen(email)!=0)
{
user e;
while(fin.read((char *)&e,sizeof(user)))
{
if(!(strcmp(email,e.email)))
a++;
}
fin.close();
if(a==1)
{
cout<<"ACCOUNT ASSOCIATED WITH THIS EMAIL-ID ALREADY EXISTS\n";
fflush(stdin);
getchar();
return 0;
}
else
return 1;
}
else
return 1;
}
int user::checkmobile()
{
int a=0;
ifstream fin;
fin.open("user.dat",ios::in|ios::binary);
user e;
while(fin.read((char*)&e,sizeof(user)))
{
if(!(strcmp(mobile,e.mobile)))
a++;
}
fin.close();
if(a==1)
{
cout<<"ACCOUNT LINKED TO THIS MOBILE NUMBER ALREADY EXISTS\n";
fflush(stdin);
getchar();
return 0;
}
else if(strlen(mobile)!=10)
{
cout<<"INVALID MOBILE NUMBER\n";
fflush(stdin);
getchar();
return 0;
}
else
return 1;
}
void user::modify()
{
int a,j;
char b,c,p[30],s[30];
do
{
system("cls");
gotoxy(10,12);
cout<<"1. CHANGE NAME";
gotoxy(10,13);
cout<<"2. CHANGE E-MAIL ID";
gotoxy(10,14);
cout<<"3. CHANGE PASSWORD";
gotoxy(10,15);
cout<<"4. CHANGE DATE OF BIRTH";
gotoxy(10,16);
cout<<"5. EXIT\n";
gotoxy(10,17);
cout<<"ENTER YOUR CHOICE :";
gotoxy(30,17);
cin>>a;
system("cls");
switch(a)
{
case 1:cout<<"CURRENT NAME\n"<<name<<"\nARE YOU SURE YOU WANT TO CHANGE YOUR REGISTERED NAME?(Y/N)\n";
       cin>>c;
       if(c=='n'||c=='N')
       break;
       fflush(stdin);
       getchar();
       system("cls");
       cout<<"ENTER NEW NAME\n";
       cin>>name;
       break;
case 2:cout<<"CURRENT E-MAIL ID\n"<<email<<"\nARE YOU SURE YOU WANT TO CHANGE YOUR REGISTERED E-MAIL ID?(Y/N)\n";
       cin>>c;
       if(c=='n'||c=='N')
       break;
       fflush(stdin);
       getchar();
       system("cls");
       cout<<"ENTER NEW E-MAIL ID\n";
       cin>>email;
       break;
case 3:cout<<"\nARE YOU SURE YOU WANT TO CHANGE YOUR PASSWORD?(Y/N)\n";
       cin>>c;
       if(c=='n'||c=='N')
       break;
       fflush(stdin);
       getchar();
       for(j=0;j<100;j++)
       {
       system("cls");
       cout<<"ENTER NEW PASSWORD\n";
       cin>>s;
       cout<<"RE-ENTER PASSWORD\n";
       cin>>p;
       if(strcmp(s,p))
       cout<<"UNSUCCESSFUL, PASSWORDS DO NOT MATCH\n";
       else
       {
       strcpy(pass,s);
       break;
       }
       }
       break;
case 4:cout<<"CURRENT DATE OF BIRTH\n"<<DOB<<"\nARE YOU SURE YOU WANT TO CHANGE YOUR REGISTERED DATE OF BIRTH?(Y/N)\n";
       cin>>c;
       if(c=='n'||c=='N')
       break;
       fflush(stdin);
       getchar();
       system("cls");
       cout<<"ENTER NEW DATE OF BIRTH ( DD/MM/YYYY ) \n";
       cin>>DOB;
       break;
case 5:return;
default:cout<<"INVALID CHOICE\n";
}
system("cls");
cout<<"DO YOU WANT TO MODIFY OTHER REGISTERED INFORMATION?(Y/N)\n";
cin>>b;
}while(b=='y'||b=='Y');
}
class admin
{
private :
char user[30];
char password[30];
public :
admin()
{
    strcpy(user,"admin");
    strcpy(password,"password@admin");
}
char* retuser()
{
    return user;
}
char* retpass()
{
    return password;
}
void setuser(char x[30])
{
    strcpy(user,x);
}
void setpass(char x[30])
{
    strcpy(password,x);
}
};
class travel
{
    protected:
        int no;
        char name[30], start[30], dest[30];
    public:
    travel()
    {
    	no=0;
    	strcpy(name,"\0");
    	strcpy(start,"\0");
    	strcpy(dest,"\0");
	}
	int get_no()
	{
		return no;
	}
	char * retstart()
	{
	    return start;
	}
	char * retdest()
	{
	    return dest;
	}
};
class flight : public travel
{
	int eseat, bseat, eprice, bprice;
	public:
	flight()
	{
    	eseat=0;
    	bseat=0;
    	eprice=0;
    	bprice=0;
	}
	char * getname()
	{
	    return name;
	}
	int get_eseat()
	{
		return eseat;
	}
    void seteseat(int x)
    {
        eseat=x;
    }
    void setbseat(int x)
    {
        bseat=x;
    }
	int get_bseat()
	{
		return bseat;
	}

	int get_eprice()
	{
		return eprice;
	}

	int get_bprice()
	{
		return bprice;
	}
	int input();
	void display();
	void delete1();
}f;


class train : public travel
{
	int ac1seat, ac2seat, ac3seat, noacseat, ac1price, ac2price, ac3price, noacprice, stops;
	char stop[15][30];
	public:
	train()
	{
		stops=0;
		ac1seat=0;
		ac2seat=0;
		ac3seat=0;
		noacseat=0;
		ac1price=0;
		ac2price=0;
		ac3price=0;
		noacprice=0;
		for(int i=0;i<15;++i)
		strcpy(stop[i],"\0");
	}
	void getstop(char x[15][30])
	{
	    for(int i=0;i<stops;++i)
            strcpy(x[i],stop[i]);
	}
	char * getname()
	{
	    return name;
	}
	void delete1();
	int getstops()
	{
		return stops;
	}
	void setac1seat(int x)
	{
	    ac1seat=x;
	}
	void setac2seat(int x)
	{
	    ac2seat=x;
	}
	void setac3seat(int x)
	{
	    ac3seat=x;
	}
	void setnoacseat(int x)
	{
	    noacseat=x;
	}
	int get_ac1price()
	{
	    return ac1price;
	}
	int get_ac2price()
	{
	    return ac2price;
	}
	int get_ac3price()
	{
	    return ac3price;
	}
	int get_noacprice()
	{
	    return noacprice;
	}
	int get_ac1seat()
	{
	    return ac1seat;
	}
	int get_ac2seat()
	{
	    return ac2seat;
	}
	int get_ac3seat()
	{
	    return ac3seat;
	}
	int get_noacseat()
	{
	    return noacseat;
	}
	int input();
	void display();
}t;

int flight::input() {
    system("cls");
    gotoxy(10, 10);
    cout << "ENTER THE FLIGHT NUMBER ";
    gotoxy(57, 10);
    cin >> no;
        int a=0;
ifstream fin;
fin.open("flight.dat",ios::in|ios::binary);
flight e;
while(fin.read((char*)&e,sizeof(flight)))
{
if(no==e.get_no())
a++;
}
fin.close();
if(a==1)
{
cout<<"FLIGHT ALREADY REGISTERED\n";
fflush(stdin);
getchar();
return 0;
}
    gotoxy(10, 11);
    cout << "ENTER THE NUMBER OF ECONOMY CLASS SEATS";
    gotoxy(57, 11);
    cin >> eseat;
    gotoxy(10, 12);
    cout << "ENTER THE NUMBER OF BUSINESS CLASS SEATS";
    gotoxy(57, 12);
    cin >> bseat;
    gotoxy(10, 13);
    cout << "ENTER THE FLIGHT NAME";
    gotoxy(57, 13);
    cin>>name;
    gotoxy(10, 14);
    cout << "ENTER THE STARTING POINT ";
    gotoxy(57, 14);
    cin>>start;
    gotoxy(10, 15);
    cout << "ENTER THE DESTINATION ";
    gotoxy(57, 15);
    cin>>dest;
    gotoxy(10, 16);
    cout << "ECONOMY CLASS TICKET PRICE ";
    gotoxy(57, 16);
    cin>>eprice;
    gotoxy(10, 17);
    cout << "BUSINESS CLASS TICKET PRICE ";
    gotoxy(57, 17);
    cin>>bprice;
    return 1;
}
void mapping()
{

    ifstream fin;
    node g;
    fin.open("flight.dat",ios::in|ios::binary);
    while(fin.read((char*)&f,sizeof(flight)))
    {
        strcpy(g.des,f.retdest());
        g.visited=0;
        x[f.retstart()].push_back(g);
    }
    fin.close();
    char z[15][30];

    fin.open("train.dat",ios::in|ios::binary);
    while(fin.read((char*)&t,sizeof(train)))
    {
        t.getstop(z);
        strcpy(g.des,z[0]);
        g.visited=0;
        x[t.retstart()].push_back(g);
for(int i=0;i<t.getstops()-1;++i)
{
    strcpy(g.des,z[i+1]);
        g.visited=0;
x[z[i]].push_back(g);
}
strcpy(g.des,t.retdest());
        g.visited=0;
x[z[t.getstops()-1] ].push_back(g );
    }
    fin.close();
}
void flight::display() {
    system("cls");
    gotoxy(10, 10);
    cout << "FLIGHT  NUMBER ";
    gotoxy(47, 10);
    cout << no;
    gotoxy(10, 11);
    cout << "FLIGHT NAME ";
    gotoxy(47, 11);
    cout<<name;
    gotoxy(10, 12);
    cout << "NO OF ECONOMY CLASS SEATS ";
    gotoxy(47, 12);
    cout << eseat;
    gotoxy(10, 13);
    cout << "NO OF BUSINESS CLASS SEATS ";
    gotoxy(47, 13);
    cout << bseat;
    gotoxy(10, 14);
    cout << "STARTING POINT ";
    gotoxy(47, 14);
    cout<<start;
    gotoxy(10, 15);
    cout << "DESTINATION ";
    gotoxy(47, 15);
    cout<<dest;
    gotoxy(10, 16);
    cout << "ECONOMY CLASS TICKET PRICE ";
    gotoxy(47, 16);
    cout<<eprice;
    gotoxy(10, 17);
    cout << "BUSINESS CLASS TICKET PRICE";
    gotoxy(47, 17);
    cout<<bprice;
    gotoxy(10, 18);
    cout << "PRESS ANY KEY TO CONTINUE ";
    fflush(stdin);
	getchar();
}
int train::input() {
    system("cls");
    gotoxy(10, 10);
    cout << "ENTER THE TRAIN NUMBER ";
    gotoxy(57, 10);
    cin >> no;
        int a=0;
ifstream fin;
fin.open("train.dat",ios::in|ios::binary);
train e;
while(fin.read((char*)&e,sizeof(train)))
{
if(no==e.get_no())
a++;
}
fin.close();
if(a==1)
{
cout<<"TRAIN ALREADY REGISTERED\n";
fflush(stdin);
getchar();
return 0;
}
    gotoxy(10, 11);
    cout << "ENTER THE NUMBER OF FIRST AC CLASS SEATS";
    gotoxy(57, 11);
    cin >> ac1seat;
    gotoxy(10, 12);
    cout << "ENTER THE NUMBER OF SECOND AC CLASS SEATS";
    gotoxy(57, 12);
    cin >> ac2seat;
    gotoxy(10, 13);
    cout << "ENTER THE NUMBER OF THIRD AC CLASS SEATS";
    gotoxy(57, 13);
    cin >> ac3seat;
    gotoxy(10, 14);
    cout << "ENTER THE NUMBER OF NON AC CLASS SEATS";
    gotoxy(57, 14);
    cin >> noacseat;
    gotoxy(10, 15);
    cout << "ENTER THE TRAIN NAME";
    gotoxy(57, 15);
    cin>>name;
    gotoxy(10, 16);
    cout << "ENTER THE STARTING POINT ";
    gotoxy(57, 16);
    cin>>start;
    gotoxy(10, 17);
    cout << "ENTER THE DESTINATION ";
    gotoxy(57, 17);
    cin>>dest;
    gotoxy(10, 18);
    cout << "ENTER THE NUMBER OF STOPS BEFORE DESTINATION ";
    gotoxy(57, 18);
    cin>>stops;
    for(int i=0;i<stops;++i)
    {
    gotoxy(10, 19+i);
    cout << "ENTER STOP NUMBER "<<i+1<<" ";
    gotoxy(57, 19+i);
    cin>>stop[i];
	}
    gotoxy(10, 19+stops);
    cout << "FIRST AC CLASS TICKET PRICE ";
    gotoxy(57, 19+stops);
    cin>>ac1price;
    gotoxy(10, 20+stops);
    cout << "SECOND AC CLASS TICKET PRICE ";
    gotoxy(57, 20+stops);
    cin>>ac2price;
    gotoxy(10, 21+stops);
    cout << "THIRD AC CLASS TICKET PRICE ";
    gotoxy(57, 21+stops);
    cin>>ac3price;
    gotoxy(10, 22+stops);
    cout << "NON AC CLASS TICKET PRICE ";
    gotoxy(57, 22+stops);
    cin>>noacprice;
    return 1;
}
void train::display() {
    system("cls");
    gotoxy(10, 10);
    cout << "TRAIN  NUMBER ";
    gotoxy(47, 10);
    cout << no;
    gotoxy(10, 11);
    cout << "TRAIN NAME ";
    gotoxy(47, 11);
    cout<<name;
    gotoxy(10, 12);
    cout << "NO OF FIRST AC CLASS SEATS ";
    gotoxy(47, 12);
    cout << ac1seat;
    gotoxy(10, 13);
    cout << "NO OF SECOND AC CLASS SEATS ";
    gotoxy(47, 13);
    cout << ac2seat;
    gotoxy(10, 14);
    cout << "NO OF THIRD AC CLASS SEATS ";
    gotoxy(47, 14);
    cout << ac3seat;
    gotoxy(10, 15);
    cout << "NO OF NON AC CLASS SEATS ";
    gotoxy(47, 15);
    cout << noacseat;
    gotoxy(10, 16);
    cout << "STARTING POINT ";
    gotoxy(47, 16);
    cout<<start;
    for(int i=0;i<stops;++i)
    {
    gotoxy(10, 17+i);
    cout << "STOP NUMBER "<<i+1<<" ";
    gotoxy(47, 17+i);
    cout<<stop[i];
	}
    gotoxy(10, 17+stops);
    cout << "DESTINATION ";
    gotoxy(47, 17+stops);
    cout<<dest;
    gotoxy(10, 18+stops);
    cout << "FIRST AC CLASS TICKET PRICE ";
    gotoxy(47, 18+stops);
    cout<<ac1price;
    gotoxy(10, 19+stops);
    cout << "SECOND AC CLASS TICKET PRICE";
    gotoxy(47, 19+stops);
    cout<<ac2price;
    gotoxy(10, 20+stops);
    cout << "THIRD AC CLASS TICKET PRICE ";
    gotoxy(47, 20+stops);
    cout<<ac3price;
    gotoxy(10, 21+stops);
    cout << "NON AC CLASS TICKET PRICE";
    gotoxy(47, 21+stops);
    cout<<noacprice;
    gotoxy(10, 22+stops);
    cout << "PRESS ANY KEY TO CONTINUE ";
    fflush(stdin);
	getchar();
}
class hotel
{
	int no,suites,rooms,rprice,sprice;
	char name[30],location[30];
	public:
		hotel()
		{
			no=0;
			suites=0;
			rooms=0;
			rprice=0;
			sprice=0;
			strcpy(name,"\0");
			strcpy(location,"\0");
		}
		int getno()
		{
			return no;
		}
		int getrprice()
		{
			return rprice;
		}
		void delete1();
		int getsprice()
		{
			return sprice;
		}
		void setrooms(int x)
		{
		    rooms=x;
		}
		void setsuites(int x)
		{
		    suites=x;
		}
		int getsuites()
		{
		    return suites;
		}
		int getrooms()
		{
		    return rooms;
		}
		char * getname()
		{
		    return name;
		}
		int input();
		void display();
}h;


int hotel::input() {
    system("cls");
    gotoxy(10, 10);
    cout << "ENTER THE HOTEL NUMBER ";
    gotoxy(57, 10);
    cin >> no;
        int a=0;
ifstream fin;
fin.open("hotel.dat",ios::in|ios::binary);
hotel e;
while(fin.read((char*)&e,sizeof(hotel)))
{
if(no==e.getno())
a++;
}
fin.close();
if(a==1)
{
cout<<"HOTEL ALREADY REGISTERED\n";
fflush(stdin);
getchar();
return 0;
}
    gotoxy(10, 11);
    cout << "ENTER THE NUMBER OF SUITES";
    gotoxy(57, 11);
    cin >> suites;
    gotoxy(10, 12);
    cout << "ENTER THE NUMBER OF ROOMS";
    gotoxy(57, 12);
    cin >> rooms;
    gotoxy(10, 13);
    cout << "ENTER THE HOTEL NAME";
    gotoxy(57, 13);
    cin>>name;
    gotoxy(10, 14);
    cout << "ENTER THE SUITE PRICE ";
    gotoxy(57, 14);
    cin>>sprice;
    gotoxy(10, 15);
    cout << "ENTER THE ROOM PRICE ";
    gotoxy(57, 15);
    cin>>rprice;
    gotoxy(10,16);
    cout << "ENTER LOCATION ";
    gotoxy(57, 16);
    cin>>location;
    return 1;
}
void hotel::display() {
    system("cls");
    gotoxy(10, 10);
    cout << "HOTEL  NUMBER ";
    gotoxy(47, 10);
    cout << no;
    gotoxy(10, 11);
    cout << "HOTEL NAME ";
    gotoxy(47, 11);
    cout<<name;
    gotoxy(10, 12);
    cout << "NO OF SUITES ";
    gotoxy(47, 12);
    cout << suites;
    gotoxy(10, 13);
    cout << "NO OF ROOMS ";
    gotoxy(47, 13);
    cout << rooms;
    gotoxy(10, 14);
    cout << "PRICE OF SUITE ";
    gotoxy(47, 14);
    cout<<sprice;
    gotoxy(10, 15);
    cout << "PRICE OF ROOM ";
    gotoxy(47, 15);
    cout<<rprice;
    gotoxy(10, 16);
    cout << "LOCATION ";
    gotoxy(47, 16);
    cout<<location;
    gotoxy(10, 17);
    cout << "PRESS ANY KEY TO CONTINUE ";
    fflush(stdin);
	getchar();
}
void view_flight_details()
{
    ifstream fin;
    fin.open("flight.dat", ios::in|ios::binary );
    system("cls");
    int a=0;
	while(fin.read((char*) &f, sizeof(flight)))
    {
	    f.display();
	    ++a;
    }
    if(a==0)
    {
	gotoxy(10, 10);
	cout << "NO RECORDS PRESENT !!!";
	fflush(stdin);
	getchar();
    }
    fin.close();
}
void enter_flight_details()
{
    char ch='y';
    do
    {
	system("cls");
	ofstream fout;
	fout.open("flight.dat", ios::app|ios::binary);
	if(f.input())
	fout.write((char*)&f, sizeof(flight));
	fout.close();
	gotoxy(20, 23);
	cout << "DO YOU WISH TO ENTER MORE?(Y/N)";
	cin >> ch;
    }
    while(ch == 'y' || ch == 'Y');
}

void view_train_details()
{
    ifstream fin;
    fin.open("train.dat", ios:: in|ios::binary );
    system("cls");
    int a=0;
	while(fin.read((char*) &t, sizeof(train)))
    {
	    t.display();
	    ++a;
    }
    if(a==0)
    {
	gotoxy(10, 10);
	cout << "NO RECORDS PRESENT !!!";
	fflush(stdin);
	getchar();
    }
    fin.close();
}

void enter_train_details()
{
    char ch='y';
    do
    {
	system("cls");
	ofstream fout;
	fout.open("train.dat", ios::app|ios::binary);
	if(t.input())
	fout.write((char*)&t, sizeof(t));
	fout.close();
	gotoxy(20, 24+t.getstops());
	cout << "DO YOU WISH TO ENTER MORE?(Y/N)";
	cin >> ch;
    }
    while(ch == 'y' || ch == 'Y');
}
void view_hotel_details()
{
    ifstream fin;
    fin.open("hotel.dat", ios:: in | ios::binary);
    system("cls");
    int a=0;
	while(fin.read((char*) &h, sizeof(hotel)))
    {
	    h.display();
	    ++a;
    }
    if(a==0)
    {
	gotoxy(10, 10);
	cout << "NO RECORDS PRESENT !!!";
	fflush(stdin);
	getchar();
    }
    fin.close();
}

void enter_hotel_details()
{
    char ch='y';
    do
    {
	system("cls");
	ofstream fout;
	fout.open("hotel.dat", ios::app | ios::binary);
	if(h.input())
	fout.write((char*)&h, sizeof(h));
	fout.close();
	gotoxy(20, 23);
	cout << "DO YOU WISH TO ENTER MORE?(Y/N)";
	cin >> ch;
    }
    while(ch == 'y' || ch == 'Y');
}
void flight::delete1()
{
    system("cls");
    int found = 0, n;

    gotoxy(10, 10);
    cout << "ENTER FLIGHT NO ";
    cin >> n;

    ifstream fin;
    fin.open("flight.dat", ios:: in | ios::binary);
    ofstream fout;
    fout.open("temp.dat", ios:: out | ios::binary);

    if(!fin)
    {
	gotoxy(10, 10);
	cout << "NO RECORDS PRESENT !!!";
	fflush(stdin);
	getchar();
    }
    else
    {
	char ch='n';

	while (fin.read((char * )this, sizeof(flight)))
	{
		if(n!=no)
			fout.write((char*)this, sizeof(flight));
		else
		{
		    system("cls");

		    gotoxy(10, 10);
		    cout << "FLIGHT NAME ";
		    gotoxy(30, 10);
		    cout << name;

		    gotoxy(10, 12);
		    cout << "FLIGHT NO ";
		    gotoxy(30, 12);
		    cout << no;

		    gotoxy(10, 14);
		    cout << "STARTING POINT ";
		    gotoxy(30, 14);
		    cout << start;

		    gotoxy(10, 16);
		    cout << "DESTINATION ";
		    gotoxy(30, 16);
		    cout << dest;

		    gotoxy(10, 20);
		    cout << "DELETE FLIGHT DETAILS? (Y/N) ";
		    cin>>ch;

		    if(ch=='n' || ch=='N')
			fout.write((char*)this, sizeof(flight));

		    found = 1;
		}
	}

	if(found==0)
	{
		cout<<"\n\t NO SUCH FLIGHT NO EXISTS !!!";
		fflush(stdin);
		getchar();
	}
    }
    fin.close();
    fout.close();

    remove("flight.dat");
    rename("temp.dat", "flight.dat");
}
void train::delete1()
{
    system("cls");
    int found = 0, n;

    gotoxy(10, 10);
    cout << "ENTER TRAIN NO ";
    cin >> n;

    ifstream fin;
    fin.open("train.dat", ios:: in | ios::binary );
    ofstream fout;
    fout.open("temp.dat", ios:: out | ios::binary);

    if(!fin)
    {
	gotoxy(10, 10);
	cout << "NO RECORDS PRESENT !!!";
	fflush(stdin);
	getchar();
    }
    else
    {
	char ch='n';

	while (fin.read((char * )this, sizeof(train)))
	{
		if(n!=no)
			fout.write((char*)this, sizeof(train));
		else
		{
		    system("cls");

		    gotoxy(10, 10);
		    cout << "TRAIN NAME ";
		    gotoxy(30, 10);
		    cout << name;

		    gotoxy(10, 12);
		    cout << "TRAIN NO ";
		    gotoxy(30, 12);
		    cout << no;

		    gotoxy(10, 14);
		    cout << "STARTING POINT ";
		    gotoxy(30, 14);
		    cout << start;

		    gotoxy(10, 16);
		    cout << "DESTINATION ";
		    gotoxy(30, 16);
		    cout << dest;

		    gotoxy(10, 20);
		    cout << "DELETE TRAIN DETAILS? (Y/N) ";
		    cin>>ch;

		    if(ch=='n' || ch=='N')
			fout.write((char*)this, sizeof(train));

		    found = 1;
		}
	}

	if(found==0)
	{
		cout<<"\n\t NO SUCH TRAIN NO EXISTS !!!";
		int av; cin>>av;//fflush(stdin);
		getchar();
	}
    }
    fin.close();
    fout.close();

    remove("train.dat");
    rename("temp.dat", "train.dat");
}
void hotel::delete1()
{
    system("cls");
    int found = 0, n;

    gotoxy(10, 10);
    cout << "ENTER HOTEL NO ";
    cin >> n;

    ifstream fin;
    fin.open("hotel.dat", ios:: in | ios::binary);
    ofstream fout;
    fout.open("temp.dat", ios:: out | ios::binary);

    if(!fin)
    {
	gotoxy(10, 10);
	cout << "NO RECORDS PRESENT !!!";
	fflush(stdin);
	getchar();
    }
    else
    {
	char ch='n';

	while (fin.read((char * )this, sizeof(hotel)))
	{
		if(n!=no)
			fout.write((char*)this, sizeof(hotel));
		else
		{
		    system("cls");

		    gotoxy(10, 10);
		    cout << "HOTEL NAME ";
		    gotoxy(30, 10);
		    cout << name;

		    gotoxy(10, 12);
		    cout << "HOTEL NO ";
		    gotoxy(30, 12);
		    cout << no;

		    gotoxy(10, 14);
		    cout << "LOCATION ";
		    gotoxy(30, 14);
		    cout << location;

		    gotoxy(10, 20);
		    cout << "DELETE HOTEL DETAILS? (Y/N) ";
		    cin>>ch;

		    if(ch=='n' || ch=='N')
			fout.write((char*)this, sizeof(hotel));

		    found = 1;
		}
	}

	if(found==0)
	{
		cout<<"\n\t NO SUCH HOTEL NO EXISTS !!!";
		fflush(stdin);
		getchar();
	}
    }
    fin.close();
    fout.close();

    remove("hotel.dat");
    rename("temp.dat", "hotel.dat");
}
class tickets
{
    int rno, no, noofperson, price, type;
    char name[30],cmobile[11],entity[30];
    public:
	void flightreservation();
	void cancellation();
	void display();
    void trainreservation();
    void hotelreservation();
	int get_rno()
	{
		return rno;
	}
}t1;
void tickets::hotelreservation()
{
    system("cls");
    gotoxy(10, 10);
    cout << "RESERVATION ";
    gotoxy(10, 12);

    ifstream fin;
    fin.open("hotel.dat", ios::in | ios::binary);
    ofstream fout;
    fout.open("temp.dat", ios::out | ios::binary);

    if (!fin)
    {
	system("cls");
	gotoxy(10, 10);
	cout << "NO HOTELS AVAILABLE !!!";
	fflush(stdin);
	getchar();
    }
    else
    {
	int found = 0;
	cout << "ENTER THE HOTEL NO: ";
	cin >>no;

	while(fin.read((char*) &h, sizeof(hotel)))
	{
		if (no == h.getno())
		{
			strcpy(name,v.retname());

			strcpy(cmobile,v.retmobile());

			gotoxy(10, 16);
			cout << "CLASS ? (ROOM -> 1/ SUITE -> 2):";
			cin>>type;

			strcpy(entity,"HOTEL");
			gotoxy(10, 17);
			cout <<"NUMBER OF ROOMS:";
			cin>>noofperson;

			if(type==1)
            {
                if(h.getrooms()<noofperson)
            {
                system("cls");
                gotoxy(20,20);
                cout<<"RESERVATION FAILED DUE TO LACK OF SPACE IN THE "<<entity;
                fflush(stdin);
                getchar();
                break;
            }
				price = h.getrprice()*noofperson;
				h.setrooms((h.getrooms())-noofperson);
            }
			else
            {
                   if(h.getsuites()<noofperson)
            {
                system("cls");
                gotoxy(20,20);
                cout<<"RESERVATION FAILED DUE TO LACK OF SPACE IN THE "<<entity;
                fflush(stdin);
                getchar();
                break;
            }
				price = h.getsprice()*noofperson;
				h.setsuites((h.getsuites())-noofperson);
            }

			rno=no*100+type;
			if(v.retbalance()<price)
            {
                system("cls");
                gotoxy(20,20);
                cout<<"INSUFFICIENT WALLET BALANCE";
                fflush(stdin);
                getchar();
                break;
            }
        v.setbalance(v.retbalance()-price);
        v.setpamount(v.retno(),price);
        v.setpname(v.retno(),h.getname());
        v.setpnumber(v.retno(),h.getno());
        char x[30];
        strcpy(x,"PAID TO");
        v.setpfunc(v.retno(),x);
                v.setno(v.retno()+1);

			ofstream ofile;
			ofile.open("ticket.dat", ios::app | ios::binary);
			ofile.write((char *)this, sizeof(tickets));
			ofile.close();

			found = 1;
		}
		cout<<h.getrooms()<<"\n";
		fout.write((char*)&h,sizeof(hotel));
	}
	fin.close();
	fout.close();
	if(found==0)
	{
	    system("cls");
	    gotoxy(20,20);
		cout<<"HOTEL NOT FOUND !!!";
		remove("temp.dat");
		fflush(stdin);
		getchar();
	}
	else
    {
        gotoxy(20,20);
        cout<<"BOOKING SUCCESSFUL !!!";
        gotoxy(20,21);
        cout<<"YOUR RESERVATION NUMBER IS : "<<rno;
	remove("hotel.dat");
	rename("temp.dat","hotel.dat");
        fflush(stdin);
		getchar();
    }
    }
}
void tickets::trainreservation()
{
    system("cls");
    gotoxy(10, 10);
    cout << "RESERVATION ";
    gotoxy(10, 12);

    ifstream fin;
    fin.open("train.dat", ios::in | ios::binary);
    ofstream fout;
    fout.open("temp.dat", ios::out | ios::binary);

    if (!fin)
    {
	system("cls");
	gotoxy(10, 10);
	cout << "NO TRAINS AVAILABLE !!!";
	fflush(stdin);
	getchar();
    }
    else
    {
	int found = 0;
	cout << "ENTER THE TRAIN NO: ";
	cin >>no;

	while(fin.read((char*) &t, sizeof(train)))
	{
		if (no == t.get_no())
		{
			strcpy(name,v.retname());

			strcpy(cmobile,v.retmobile());

			gotoxy(10, 16);
			cout << "CLASS ? (FIRST AC -> 1/ SECOND AC -> 2/ THIRD AC -> 3/ NON-AC -> 4):";
			cin>>type;
			strcpy(entity,"TRAIN");
			gotoxy(10, 17);
			cout <<"NUMBER OF PERSON:";
			cin>>noofperson;

			if(type==1)
            {
                   if(t.get_ac1seat()<noofperson)
            {
                system("cls");
                gotoxy(20,20);
                cout<<"RESERVATION FAILED DUE TO LACK OF SPACE IN THE "<<entity;
                fflush(stdin);
                getchar();
                break;
            }
				price = t.get_ac1price()*noofperson;
				t.setac1seat((t.get_ac1seat())-noofperson);
            }
			else if(type==2)
            {
                                   if(t.get_ac2seat()<noofperson)
            {
                system("cls");
                gotoxy(20,20);
                cout<<"RESERVATION FAILED DUE TO LACK OF SPACE IN THE "<<entity;
                fflush(stdin);
                getchar();
                break;
            }
				price = t.get_ac2price()*noofperson;
				t.setac2seat((t.get_ac2seat())-noofperson);
            }
            else if(type==3)
            {
                                   if(t.get_ac3seat()<noofperson)
            {
                system("cls");
                gotoxy(20,20);
                cout<<"RESERVATION FAILED DUE TO LACK OF SPACE IN THE "<<entity;
                fflush(stdin);
                getchar();
                break;
            }
				price = t.get_ac3price()*noofperson;
				t.setac3seat((t.get_ac3seat())-noofperson);
            }
            else
            {
                                   if(t.get_noacseat()<noofperson)
            {
                system("cls");
                gotoxy(20,20);
                cout<<"RESERVATION FAILED DUE TO LACK OF SPACE IN THE "<<entity;
                fflush(stdin);
                getchar();
                break;
            }
				price = t.get_noacprice()*noofperson;
				t.setnoacseat((t.get_noacseat())-noofperson);
            }

			rno=no*100+type;
			if(v.retbalance()<price)
            {
                system("cls");
                gotoxy(20,20);
                cout<<"INSUFFICIENT WALLET BALANCE";
                fflush(stdin);
                getchar();
                break;
            }
        v.setbalance(v.retbalance()-price);
			        v.setpamount(v.retno(),price);
        v.setpname(v.retno(),t.getname());
        v.setpnumber(v.retno(),t.get_no());
                char x[30];
        strcpy(x,"PAID TO");
        v.setpfunc(v.retno(),x);
v.setno(v.retno()+1);
			ofstream ofile;
			ofile.open("ticket.dat", ios::app | ios::binary);
			ofile.write((char *)this, sizeof(tickets));
			ofile.close();

			found = 1;
		}
		fout.write((char*)&t,sizeof(train));
	}
	fin.close();
	fout.close();
	if(found==0)
	{
	    system("cls");
	    gotoxy(20,20);
		cout<<"TRAIN NOT FOUND !!!";
		remove("temp.dat");
		fflush(stdin);
		getchar();
	}
	else
    {
        gotoxy(20,20);
        cout<<"BOOKING SUCCESSFUL !!!";
        gotoxy(20,21);
        cout<<"YOUR RESERVATION NUMBER IS : "<<rno;

	remove("train.dat");
	rename("temp.dat","train.dat");
        fflush(stdin);
		getchar();
    }
    }
}
void tickets::flightreservation()
{
    system("cls");
    gotoxy(10, 10);
    cout << "RESERVATION ";
    gotoxy(10, 12);

    ifstream fin;
    fin.open("flight.dat", ios::in | ios::binary);
    ofstream fout;
    fout.open("temp.dat", ios::out | ios::binary);

    if (!fin)
    {
	system("cls");
	gotoxy(10, 10);
	cout << "NO FLIGHTS AVAILABLE !!!";
	fflush(stdin);
	getchar();
    }
    else
    {
	int found = 0;
	cout << "ENTER THE FLIGHT NO: ";
	cin >>no;

	while(fin.read((char*) &f, sizeof(flight)))
	{
		if (no == f.get_no())
		{
			strcpy(name,v.retname());

			strcpy(cmobile,v.retmobile());

			gotoxy(10, 16);
			cout << "CLASS ? (ECONOMY -> 1/ BUSINESS -> 2):";
			cin>>type;
			strcpy(entity,"FLIGHT");
			gotoxy(10, 17);
			cout <<"NUMBER OF PERSON:";
			cin>>noofperson;

			if(type==1)
            {
                                   if(f.get_eseat()<noofperson)
            {
                system("cls");
                gotoxy(20,20);
                cout<<"RESERVATION FAILED DUE TO LACK OF SPACE IN THE "<<entity;
                fflush(stdin);
                getchar();
                break;
            }
				price = f.get_eprice()*noofperson;
				f.seteseat((f.get_eseat())-noofperson);
            }
			else
            {
                                   if(f.get_bseat()<noofperson)
            {
                system("cls");
                gotoxy(20,20);
                cout<<"RESERVATION FAILED DUE TO LACK OF SPACE IN THE "<<entity;
                fflush(stdin);
                getchar();
                break;
            }
				price = f.get_bprice()*noofperson;
				f.setbseat((f.get_bseat())-noofperson);
            }

			rno=no*100+type;
			if(v.retbalance()<price)
            {
                system("cls");
                gotoxy(20,20);
                cout<<"INSUFFICIENT WALLET BALANCE";
                fflush(stdin);
                getchar();
                break;
            }
        v.setbalance(v.retbalance()-price);
			        v.setpamount(v.retno(),price);
        v.setpname(v.retno(),f.getname());
        v.setpnumber(v.retno(),f.get_no());
        char x[30];
        strcpy(x,"PAID TO");
        v.setpfunc(v.retno(),x);
        v.setno(v.retno()+1);
			ofstream ofile;
			ofile.open("ticket.dat", ios::app | ios::binary);
			ofile.write((char *)this, sizeof(tickets));
			ofile.close();

			found = 1;
		}
		fout.write((char*)&f,sizeof(flight));
	}
	fin.close();
	fout.close();
	if(found==0)
	{
	    system("cls");
	    gotoxy(20,20);
		cout<<"FLIGHT NOT FOUND !!!";
		remove("temp.dat");
		fflush(stdin);
		getchar();
	}
	else
    {
        gotoxy(20,20);
        cout<<"BOOKING SUCCESSFUL !!!";
        gotoxy(20,21);
        cout<<"YOUR RESERVATION NUMBER IS : "<<rno;

	remove("flight.dat");
	rename("temp.dat","flight.dat");
        fflush(stdin);
		getchar();
    }
    }
}
void tickets::cancellation()
{
    system("cls");
    int found = 0, n;

    gotoxy(10, 10);
    cout << "ENTER RESERVATION NO ";
    cin >> n;

    ifstream fin;
    fin.open("ticket.dat", ios:: in | ios::binary);
    ofstream fout;
    fout.open("temp.dat", ios:: out  | ios::binary);

    if(!fin)
    {
	gotoxy(10, 10);
	cout << "NO RECORDS PRESENT !!!";
	fflush(stdin);
	getchar();
    }
    else
    {
	char ch='n';

	while (fin.read((char * )this, sizeof(tickets)))
	{
		if(n!=rno)
			fout.write((char*)this, sizeof(tickets));
		else
		{
		    if(!strcmp(cmobile,v.retmobile()))
            {
		    system("cls");

		    gotoxy(10, 10);
		    cout << "NAME ";
		    gotoxy(30, 10);
		    cout << name;

		    gotoxy(10, 12);
		    cout << entity<<" NO ";
		    gotoxy(30, 12);
		    cout << no;

		    gotoxy(10, 14);
		    cout << "NO OF BOOKINGS ";
		    gotoxy(30, 14);
		    cout << noofperson;

		    gotoxy(10, 16);
		    cout << "PER TICKET AMOUNT ";
		    gotoxy(30, 16);
		    cout << (price/noofperson);

		    gotoxy(10, 18);
		    cout << "TOTAL AMOUNT ";
		    gotoxy(30, 18);
		    cout << price;

		    gotoxy(10, 20);
		    cout << "CANCEL TICKET? (Y/N) ";
		    cin>>ch;

		    if(ch=='n' || ch=='N')
			fout.write((char*)this, sizeof(tickets));

		    found = 1;
		    v.setbalance(v.retbalance()+price);
		}
		}
	}

	if(found==0)
	{
		cout<<"\n\t NO SUCH RESERVATION NO EXISTS !!!";
		fflush(stdin);
		getchar();
	}
    }
    fin.close();
    fout.close();

    remove("ticket.dat");
    rename("temp.dat", "ticket.dat");
}
void tickets::display()
{
    system("cls");
    int found = 0;

    ifstream fin;
    fin.open("ticket.dat", ios:: in | ios::binary);
    if(!fin)
    {
	gotoxy(10, 10);
	cout << "NO RECORDS PRESENT !!!";
	fflush(stdin);
	getchar();
    }
    else
    {
	while (fin.read((char * )this, sizeof(tickets)))
	{
		if(!strcmp(cmobile,v.retmobile()))
		{
		    system("cls");

		    gotoxy(10,8);
		    cout<<"RESERVATION NUMBER ";
		    gotoxy(30,8);
		    cout<<rno;
		    gotoxy(10, 10);
		    cout << "NAME ";
		    gotoxy(30, 10);
		    cout << name;

		    gotoxy(10, 12);
		    cout << entity<<" NO ";
		    gotoxy(30, 12);
		    cout << no;

		    gotoxy(10, 14);
		    cout << "NO OF BOOKINGS ";
		    gotoxy(30, 14);
		    cout << noofperson;

		    gotoxy(10, 16);
		    cout << "PER TICKET AMOUNT ";
		    gotoxy(30, 16);
		    cout << (price/noofperson);

		    gotoxy(10, 18);
		    cout << "TOTAL AMOUNT ";
		    gotoxy(30, 18);
		    cout << price;

		    gotoxy(10, 20);
		    cout << "PRESS ANY KEY TO CONTINUE ";
            		fflush(stdin);
            getchar();

		    found = 1;

		}
	}
	if(found==0)
	{
		cout<<"\n\t NO RESERVATIONS !!!";
		fflush(stdin);
		getchar();
	}
    }
    fin.close();
}
void menu()
{
    system("cls");
    gotoxy(30, 5);
    cout << "WELCOME";
    gotoxy(30, 8);
    cout << "EXPLORERS\' TREAT";
    gotoxy(25, 9);
    cout << "==========================";
    gotoxy(20, 15);
    cout << "1. VIEW FLIGHT DETAILS";
    gotoxy(20, 16);
    cout << "2. VIEW TRAIN DETAILS ";
    gotoxy(20, 17);
    cout << "3. VIEW HOTEL DETAILS ";
    gotoxy(20, 18);
    cout << "4. ADD MONEY TO WALLET ";
    gotoxy(20, 19);
    cout << "5. ACCESS PASSBOOK ";
    gotoxy(20, 20);
    cout << "6. MODIFY REGISTERED INFORMATION ";
    gotoxy(20, 21);
    cout << "7. CHECK WALLET BALANCE ";
    gotoxy(20, 22);
    cout << "8. CHECK BANK BALANCE ";
    gotoxy(20, 23);
    cout << "9. SEARCH FOR A PATH BETWEEN YOU AND YOUR DESTINATION ";
    gotoxy(20, 24);
    cout << "10.FLIGHT TICKET BOOKING ";
    gotoxy(20, 25);
    cout << "11.TRAIN TICKET BOOKING ";
    gotoxy(20, 26);
    cout << "12.HOTEL BOOKING ";
    gotoxy(20, 27);
    cout << "13.TICKET CANCELLATION ";
    gotoxy(20, 28);
    cout << "14.CHECK TICKET STATUS ";
    gotoxy(20, 29);
    cout << "15.DEACTIVATE YOUR ACCOUNT ";
    gotoxy(20, 30);
    cout << "0. EXIT";
    gotoxy(20, 31);
    cout << "ENTER YOUR CHOICE: ";
}
void adminmenu()
{
    system("cls");
    gotoxy(30, 5);
    cout << "WELCOME";
    gotoxy(30, 8);
    cout << "EXPLORERS\' TREAT";
    gotoxy(25, 9);
    cout << "==========================";
    gotoxy(20, 15);
    cout << "1.REGISTER FLIGHT DETAILS";
    gotoxy(20, 16);
    cout << "2.DELETE FLIGHT  DETAILS ";
    gotoxy(20, 17);
    cout << "3.REGISTER TRAIN DETAILS";
    gotoxy(20, 18);
    cout << "4.DELETE TRAIN DETAILS";
    gotoxy(20, 19);
    cout << "5.REGISTER HOTEL DETAILS ";
    gotoxy(20, 20);
    cout << "6.DELETE HOTEL DETAILS";
    gotoxy(20, 21);
    cout << "7.CHANGE USERNAME";
    gotoxy(20, 22);
    cout << "8.CHANGE PASSWORD";
    gotoxy(20, 23);
    cout << "0.EXIT";
    gotoxy(20, 24);
    cout << "ENTER YOUR CHOICE: ";
}
void updatebankbalance()
{
char c[9];
system("cls");
gotoxy(10,10);
cout<<"ENTER USER ID\n";
gotoxy(47,10);
cin>>c;
if(strcmp(c,"bank1234"))
{
    system("cls");
    gotoxy(30,30);
cout<<"INCORRECT USER ID\n";
fflush(stdin);
getchar();
return;
}
gotoxy(10,12);
cout<<"ENTER PASSWORD\n";
gotoxy(47,12);
cin>>c;
if(strcmp(c,"1234bank"))
{
    system("cls");
    gotoxy(30,30);
cout<<"INCORRECT PASSWORD\n";
fflush(stdin);
getchar();
return;
}
user e;
long unsigned int a;
ifstream fin;
fin.open("user.dat",ios::in|ios::binary);
ofstream fout;
fout.open("temp.dat",ios::out|ios::binary);
while(fin.read((char *)&e,sizeof(user)))
{
system("cls");
gotoxy(10,12);
cout<<"ENTER UPDATED BANK BALANCE OF "<<e.retname();
gotoxy(10,13);
cout<<"(Netbanking User ID: "<<e.retbuser()<<")\n";
gotoxy(47,12);
cin>>a;
e.setbbal(a);
fout.write((char *)&e,sizeof(user));
}
fout.close();
fin.close();
remove("user.dat");
rename("temp.dat","user.dat");
system("cls");
gotoxy(30,30);
cout<<"UPDATION COMPLETE\n";
fflush(stdin);
getchar();
}
int main()
{
	system("color F0");
    int n,m;
    char c;
    do
    {
    system("cls");
    gotoxy(23, 5);
    cout << "\t\tWELCOME";
    gotoxy(30, 8);
    cout << " EXPLORERS\' TREAT ";
    gotoxy(25, 9);
    cout << "==========================";
    gotoxy(20, 15);
    cout << "1.USER LOGIN ";
    gotoxy(20, 16);
    cout << "2.USER SIGN UP ";
    gotoxy(20, 17);
    cout << "3.ADMIN LOGIN ";
    gotoxy(20, 18);
    cout << "4.BANK LOGIN ";
    gotoxy(20, 19);
    cout << "0.EXIT ";
    gotoxy(20, 20);
    cout << "ENTER YOUR CHOICE: ";
    cin>>m;
    switch(m)
    {
    	case 1:{	system("cls");
    	mapping();
	char c[30];
	gotoxy(10,10);
	   cout<<"ENTER E-MAIL ID/MOBILE NUMBER\n";
	   gotoxy(47,10);
       cin>>c;
       ifstream fin;
       fin.open("user.dat",ios::in|ios::binary);
       int t=0;
       while(fin.read((char*)&v,sizeof(user)))
       {
       if(!(strcmp(c,v.retemail()))||!(strcmp(c,v.retmobile())))
       {
       t=1;
       break;
       }
       }
       fin.close();
       if(t==0)
       {
           system("cls");
       gotoxy(30,30);
       cout<<"E-MAIL ID/MOBILE NUMBER NOT FOUND\n";
       fflush(stdin);
       getchar();
       break;
       }
       gotoxy(10,12);
       cout<<"ENTER PASSWORD\n";
       gotoxy(47,12);
       cin>>c;
       if(strcmp(c,v.retpass()))
       {
           system("cls");
           gotoxy(30,30);
       cout<<"INCORRECT PASSWORD\n";
       fflush(stdin);
       getchar();
       break;
       }
       else
       {
           do
				{
	    		menu();
	    		cin>>n;
	    		switch(n)
	    		{
				case 1: view_flight_details(); break;
				case 2: view_train_details(); break;
				case 3: view_hotel_details(); break;
				case 4: v.deposit(); break;
				case 5: v.viewpb(); break;
				case 6: v.modify(); break;
				case 7: system("cls");  gotoxy(10,30); cout<<"YOUR CURRENT WALLET BALANCE IS : "<<v.retbalance()<<"\n"; break;
				case 8: system("cls"); gotoxy(10,30); cout<<"YOUR CURRENT BANK BALANCE IS : "<<v.retbbal()<<"\n"; break;
				case 9: searchs(); break;
				case 10:t1.flightreservation(); break;
				case 11:t1.trainreservation(); break;
				case 12:t1.hotelreservation(); break;
				case 13: t1.cancellation(); break;
				case 14: t1.display(); break;
				case 15: v.deactivate(); n=0; break;
				case 0: cout<<"\n\t\tBYE BYE !!!";
						fflush(stdin);
						getchar();
						break;
				default:cout<<"\n\t\tENTER A VALID CHOICE\n";
				fflush(stdin);
		getchar();
	    		}
	    		       fin.open("user.dat",ios::in|ios::binary);
       ofstream fout;
       fout.open("temp.dat",ios::out|ios::binary);
       user e;
       while(fin.read((char*)&e,sizeof(user)))
       {
       if(!(strcmp(e.retmobile(),v.retmobile())))
       fout.write((char*)&v,sizeof(user));
       else
       fout.write((char*)&e,sizeof(user));
       }
       fout.close();
       fin.close();
       remove("user.dat");
       rename("temp.dat","user.dat");
       fflush(stdin);
       getchar();
        		}while(n!=0);
       }
    			break;
    }
    	case 2:{
    	    v.input();
    		break;
    	}
    	case 3: {
    			system("cls");
    			char u[30],p[30],temp[30];
    			admin a;
				ifstream fin;
				fin.open("admin.dat", ios::in | ios::binary);
				if(fin)
    			{
                fin.read((char*)&a, sizeof(admin));
				fin.close();
   				}
				gotoxy(10,10);
				strcpy(temp,a.retuser());
				cout<<"ENTER USERNAME";
				gotoxy(47,10);
				cin>>u;
				if(strcmp(u,temp))
				{
					system("cls");
					gotoxy(30,10);
					cout<<"ERROR : INVALID USERNAME";
					fflush(stdin);
					getchar();
					break;
				}
				gotoxy(10,12);
				strcpy(temp,a.retpass());
				cout<<"ENTER PASSWORD";
				gotoxy(47,12);
				cin>>p;
				if(strcmp(p,temp))
				{
					system("cls");
					gotoxy(30,10);
					cout<<"ERROR : INVALID PASSWORD";
					fflush(stdin);
					getchar();
					break;
				}
				do
				{
	    		adminmenu();
	    		cin>>n;
	    		switch(n)
	    		{
				case 1: enter_flight_details(); break;
				case 2: f.delete1(); break;
				case 3: enter_train_details(); break;
				case 4: t.delete1(); break;
				case 5: enter_hotel_details(); break;
				case 6: h.delete1(); break;
				case 7: system("cls");
                        gotoxy(10,10);
                        cout<<"ENTER NEW USERNAME :";
                        gotoxy(47,10);
                        cin>>u;
                        gotoxy(10,12);
                        cout<<"RE-ENTER USERNAME :";
                        gotoxy(47,12);
                        cin>>p;
                        if(strcmp(u,p))
                        {
                            system("cls");
                            gotoxy(30,10);
                            cout<<"ERROR: USERNAMES DO NOT MATCH";
                            fflush(stdin);
                            getchar();
                            break;
                        }
                        gotoxy(10,14);
                        cout<<"ARE YOU SURE YOU WANT TO CHANGE YOUR USERNAME? (Y/N)   ";
                        cin>>c;
                        if(c=='y'||c=='Y')
                        {
                            a.setuser(u);
                            ofstream fout;
                            fout.open("admin.dat",ios::out | ios::binary);
                            fout.write((char*)&a,sizeof(a));
                            fout.close();
                        }
                        system("cls");
                        gotoxy(30,10);
                        cout<<"USERNAME CHANGED";
                        fflush(stdin);
                        getchar();
                        break;
                case 8: system("cls");
                        gotoxy(10,10);
                        cout<<"ENTER NEW PASSWORD :";
                        gotoxy(47,10);
                        cin>>u;
                        gotoxy(10,12);
                        cout<<"RE-ENTER PASSWORD :";
                        gotoxy(47,12);
                        cin>>p;
                        if(strcmp(u,p))
                        {
                            system("cls");
                            gotoxy(30,10);
                            cout<<"ERROR: PASSWORDS DO NOT MATCH";
                            fflush(stdin);
                            getchar();
                            break;
                        }
                        gotoxy(10,14);
                        cout<<"ARE YOU SURE YOU WANT TO CHANGE YOUR PASSWORD? (Y/N)   ";
                        cin>>c;
                        if(c=='y'||c=='Y')
                        {
                            a.setpass(u);
                            ofstream fout;
                            fout.open("admin.dat",ios::out | ios::binary);
                            fout.write((char*)&a,sizeof(a));
                            fout.close();
                        }
                        system("cls");
                        gotoxy(30,10);
                        cout<<"PASSWORD CHANGED";
                        fflush(stdin);
                        getchar();
                        break;
				case 0: cout<<"\n\t\tBYE BYE !!!";
						fflush(stdin);
						getchar();
						break;
				default:cout<<"\n\t\tENTER A VALID CHOICE\n";
				fflush(stdin);
                getchar();
	    		}
        		}while(n!=0);
    		break;
    		}
        case 4:updatebankbalance();
                break;
    	case 0: cout<<"\n\t\tBYE BYE !!!";
				fflush(stdin);
				getchar();
				return 0;
    	default:cout<<"\n\t\tINVALID CHOICE\n";
    	fflush(stdin);
		getchar();
	}
	system("cls");
	gotoxy(12,13);
	cout<<"DO YOU WANT TO CONTINUE USING EXPLORERS\' TREAT? (Y/N)";
	gotoxy(30,14);
	cin>>c;
    }while(c=='y'||c=='Y');
    return 0;
}
