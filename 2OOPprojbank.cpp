#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<iomanip.h>
#include<ctype.h>

double accon=567788,card[3]={6589,8342,9600},cv=987,date=102023;

struct trand
{
	double amount;
	char type;
};
class bank
{
 protected:
  trand trans[20];
  double phno,cardno[3],acno,cvv,re,expdate;
  unsigned long int acbal,deposit,withdrawl,chd;
  char pass[15],passcheck[15], acname[20], actype[20],add[20];
  float a;
 public:
  void transaction(double am,char ch)
  {
	trans[re].amount=am;
	trans[re].type=ch;
  }
  void debit()
  {
	chd=1;
	cardno[0]=card[0];
	cardno[1]=card[1];
	cardno[2]=card[2]++;
	cvv=cv++;
	expdate=date++;
  }

	  void getdata()
  {
   cout<<"\nEnter account name: ";
   gets(acname);
   cout<<endl<<"Enter account type Savings/Current: ";
   gets(actype);
   cout<<"ENTER PHONE NUMBER: ";
   cin>>phno;
   cout<<"ENTER ADDRESS: ";
   gets(add);
   cout<<"Please wait while we generate a account no for you....\n";
 for( a=0 ; a<1000 ;)
 { a=a+0.0002;
 }
   acno=accon++;
   cout<<"Your account number is: "<<acno;
   cout<<endl<<"Enter the 10 character account password: ";
   cin.ignore();
   for( int j=0 ; j<10 ; j++ )
   {
    pass[j]=getch();
    cout<<"*";
   }
   pass[j]='\0';
   cout<<endl<<endl<<"Enter account balance: ";
   cin>>acbal;
   cout<<endl;
   char l;
   cout<<"Do you want the facility of debit card(Y/N): ";
   cin>>l;
   if(l=='Y'||l=='y')
   {
	debit();
	cout<<"Wait while we generate a debit card no for you.....";

 for( a=0 ; a<1000 ;)
 { a=a+0.0002;
 }
	cout<<"\nYour debit card no.: "<<cardno[0]<<cardno[1]<<cardno[2]<<"\nCvv: "<<cvv<<"\nExp date: "<<expdate;
	getch();
	getch();
   }
   else
	chd=0;
 }//end of getdata

 void showdata()
 {
	cout<<"|"<<setw(8)<<(acno/1000)<<'|'<<setw(14)<<acname<<'|'<<setw(13)<<actype<<'|'<<"**********"<<'|'<<setw(14)<<acbal<<'|'<<'\n';
	cout<<"----------------------------------------------------------------\n";
 }  // end of showdata

 int dep()
 { cout<<"Account name: ";
   puts(acname);

   cout<<endl<<"Enter the account password: ";

   cin.ignore();
   for(int j=0 ; j<10 ;j++)
    {
     passcheck[j]=getch();
     cout<<"*";
    }
    passcheck[j]='\0';
    cout<<endl;
   if (!strcmp(pass,passcheck))
    {
      cout<<"Enter the deposit amount: ";
      cin>>deposit;

      acbal=acbal+deposit;
      transaction(deposit,'D');
      cout<<"The new account balance is :"<<acbal<<endl;
      return(0);
    }
   else
   {
    cout<<"Incorrect password"<<endl;
    getch();
    return(0);
   }

 } //end of dep

  int wit()
 {
  cout<<"Account name: ";
  puts(acname);

  cout<<endl<<"Enter the account password: ";
  for(int j=0 ; j<10 ;j++)
   {
    passcheck[j]=getch();
    cout<<"*";
   }
   passcheck[j]='\0';
   cout<<endl;
  if (!strcmp(pass,passcheck))
  {
    cout<<"Enter the withdrawl amount: ";
    cin>>withdrawl;

    if(acbal>=withdrawl)
    {
     acbal=acbal-withdrawl;
     transaction(withdrawl,'W');
     }
    else
    {
     cout<<"Insufficient balance"<<endl;
    }

    cout<<endl<<"The new account balance is :"<<acbal<<endl;
    return(0);
  }
  else
  {
   cout<<"Incorrect password"<<endl;
   getch();
   return(0);
  }

 }//end of wit

 unsigned long int acn()
 {
  return(acno);
 }
 int passch(char a[11])
 {
	if(!strcmp(a,passcheck))
	{
		return 1;
	}
	else
		return 0;
 }

 bank()
 {
  pass[10]='/0';
  passcheck[10]='/0';
  re=0;
 }
};//end of class

class holder: public bank
{
	int amoun;
	public:
	void deposit();
	void transfer();
	void debits();
	void passbook();
	void send(int a,double d);
};

void holder::deposit()
{
	cout<<"ENTER AMOUNT TO BE ADDED TO THE ACCOUNT USING DEBIT\CREDIT CARD\n";
	cin>>amoun;
	cout<<" ENTER CARD NO: ";
	cin.ignore();
	cout<<"ENTER CVV: ";
	cin.ignore();
	cout<<"ENTER DATE: ";
	cin.ignore();
	send(amoun,(acno-567788));
	cout<<"ADDED SUCCESSFULLY.....";
}

void holder::transfer()
{
	cout<<"ENTER AMOUNT TO BE TRANSFERED: ";
	cin>>amoun;
	cout<<"ENTER BANK ACCOUNT NUMBER: ";
	double acc;
	cin>>acc;
	if(acc<567788||acc>=accon)
	{
		cout<<"NO SUCH ACCOUNT EXISTS!!!!!!!!!!!!!!!\n";
		return ;
	}
	else
	{
		send(amoun,(acc-56788));
		transaction(amoun,'W');
	 for( a=0 ; a<1000 ;)
	 { a=a+0.0002;
	 }
		cout<<"TRANSFERED SUCCESSFUL!!! ";
	}
}

void holder::debits()
{
	int choice;
	cout<<"1.Block and replace debit card\n2.Stop debit card services\n3.Enter choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:debit();
			cout<<"BLOCKED AND REPLACED SUCCESSFULLY\n";
			cout<<"New debit card info-\n";
			cout<<"Card no-: "<<cardno[0]<<cardno[1]<<cardno[2];
			cout<<"\ncvv-"<<cvv;
			cout<<"\Exp date"<<expdate;
						break;
		case 2:chd=0;
			cout<<"STOPPED SUCCESSFULLY....";
						break;
		case 3: cout<<"Card no-: "<<cardno[0]<<cardno[1]<<cardno[2];
			cout<<"\ncvv-"<<cvv;
			cout<<"\Exp date"<<expdate;
						break;
		default: cout<<"WRONG CHOICE.....";
	}
}

void holder::passbook()
{
	int u=0;
	cout<<"-----------------------------------------\n";
	cout<<"|SNO. |TRANSACTION     |    TYPE         |\n";
	cout<<" ----------------------------------------\n";
	while(u<=re)
	{
		cout<<"|"<<setw(5)<<u+1<<"|"<<setw(16)<<trans[u].amount<<"|"<<setw(17)<<trans[u].type<<"|\n";
			cout<<" ----------------------------------------\n";
		++u;
	}
	if(u==0)
	cout<<"NO RECORDS FOUND!!!!!!!!!!!!!!!!!!";
	getch();
}
holder b[25];
void holder::send(int a,double d)
{
	b[d].acbal+=a;
	b[d].transaction(a,'D');

}
	void customer();
	void employee();
	void main()
	{
		clrscr();
		char choice[15],cont;
		do
		{
		clrscr();
		cout<<"                 NATIONAL BANK\n";
		cout<<"CONTIUE AS CUSTOMER OR EMPLOYEE?: ";
		gets(choice);
		if(!strcmp(choice,"CUSTOMER\0")||!strcmp(choice,"customer\0"))
		{
			customer();
		}
		else if(!strcmp(choice,"EMPLOYEE\0")||!strcmp(choice,"employee\0"))
		{
			employee();
		}
		else
			cout<<"WRONG CHOICE!!!!!!!!!!!";
		cout<<"WANT TO CONTINUE (Y/N)? :";
		cin>>cont;

		}while(cont=='Y'|| cont=='y');
	getch();
}
void customer()
{
	clrscr();
	int choice;
	char cont;
	do
	{
		clrscr();
		cout<<"1.TRANSFER FUNDS\n2.DEPOSIT FUNDS\n3.DEBIT CARD SETTINGS\n4.PASSBOOK\nENTER YOUR CHOICE: ";
		cin>>choice;
		cout<<"ENTER YOUR ACCOUNT NUMBER: ";
		double k;
		cin>>k;
		if(k-567788<0&&k>accon)
		{
			cout<<"NO SUCH ACCOUNT EXISTS!!!!!";
		}
		else
		{
			cout<<"ENTER 10 DIGIT PASSWORD: ";
			char pas[11];
			gets(pas);
			pas[10]='\0';
			int p=b[k-567788].passch(pas);
			if(p==1)
			switch(choice)
			{
				case 1:b[k-567788].transfer();
							break;
				case 2:b[k-567788].deposit();
							break;
				case 3:b[k-567788].debits();
							break;
				case 4:b[k-567788].passbook();
							break;
				default:cout<<"WRONG CHOICE!!!!!!!";
			}
			else
				cout<<"WRONG PASSWORD!!!!!!!!!!!";
		}
			cout<<"WANT TO CONTINUE AS CUSTOMER (Y/N): ";
			cin>>cont;

		}while(cont=='Y'||cont=='y');
      return;
}
	void employee()
{
	void wir(bank *c,int y);
 clrscr();
 ofstream fout;
 ifstream fin;
 fout.open("BANK.dat",ios::out);
 fin.open("pass.dat",ios::in,ios::nocreate);
unsigned int n;
unsigned long int acncheck ;
char ch='a',ans='a';
char p[10],r[10];
 fin.read((char*)&r,sizeof(r));
 r[6]='\0';
cout<<"                              NATIONAL BANK "<<endl<<endl;

cout<<"ENTER THE USER PASSWORD: ";
	for(int z=0;z<6;++z)
	{
		p[z]=getch();
		cout<<"*";
	}
	p[z]='\0';

if(!strcmp(p,r))
{
	cout<<endl<<endl;
}
else
{
cout<<"\nWRONG PASSWORD EXITING!!!!!";
	return;
	getch();
}

// delay

 cout<<"Welcome USER!"<<endl<<"Loading Software .  .  .";
 float a=0.001;
 for( a=0 ; a<1000 ;)
 { a=a+0.0002;
 }

cout<<endl<<endl<<"Enter the number of records you want to enter: ";
cin>>n;

for (int i=0; i<n; i++)
{
 b[i].getdata();
 fout.write((char*)&b[i],sizeof(bank));
}
fout.close();
do
{
 clrscr();
cout<<endl<<"Choose the operation you would like to perform: "<<endl;
cout<<"a)Make a deposit"<<endl;
cout<<"b)Make a withdrawl"<<endl;
cout<<"c)Add a bank record"<<endl;
cout<<"d)See the existing records"<<endl;
cout<<"e)Exit"<<endl  ;
cout<<"Enter your choice: ";
cin>>ch;

switch(ch)
{
 case 'a' :
	 cout<<"Enter the account number: ";
	 cin>>acncheck;
	 for(int k=0 ; k<n; k++)
	 {
	  if(acncheck==b[k].acn())
	   {b[k].dep();}
	  else
	  {cout<<"No such account! "<<endl;}
	 }
	 wir(b,n);
					break;
 case 'b' :
	 cout<<"Enter the account number: ";
	 cin>>acncheck;
	 for(k=0 ; k<n; k++)
	 {
	  if(acncheck==b[k].acn())
	  { b[k].wit();}
	   else
	  { cout<<"No such account !"<<endl;}
	 }
	 wir(b,n);
					break;

 case 'c' :
	 b[n].getdata();
	 n++;
	  wir(b,n);
	 break;

 case 'd' :
	  cout<<"----------------------------------------------------------------\n";
	  cout<<"|Acc. No.|   Acc. Name  | Acc. Type   | Password | Acc. Balance |\n";
	  cout<<"----------------------------------------------------------------\n";
	  for(k=0 ; k<n; k++)
	  {
	   b[k].showdata();
	  }
	  getch();
	  break;

 case 'e' :cout<<"EXITING........";
				break;
 default: cout<<"WRONG CHOICE TRY AGAIN!!!\n";
}

cout<<endl<<"Press Y to continue as employee: "    ;
cin>>ans ;



}while(ans=='y' || ans=='Y');

getch();
fin.close();
fout.close();

}
void wir(bank *c,int y)
{
	ofstream fout;
	fout.open("BANK.dat",ios::out,ios::nocreate);
	for(int i=0;i<y;++i)
	{
		 fout.write((char*)&c[i],sizeof(bank));
	}
	fout.close();
}
