#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

int balance(int a);
int credit(int balance_old,string full_name,int a);
int debit(int balance_old,string full_name,int a);

class cls 
{
	int a;
	int b;
	string c;

	public:
	int fx();
	friend int keys();

}obj1,call;

int debit(int balance_old,string full_name,int a)
{	int debit;
	fstream file;
	cout<<endl<<"Amount?:";
	cin>>debit;
	int new_balance=balance_old-debit;
	if(new_balance<0)
	{
	    cout<<endl<<"you want loan?, yes or no"<<endl;
		string a;
		cin>>a;
		if(a=="yes")
		{            }
		else
		{
		    cout<<"exiting"<<endl<<"*********";
		    exit(0);
		}
		
	}
	file.open(full_name, ios::out);
	file<<new_balance;
	cout<<endl<<"Transaction Successfull"<<endl<<"      ******"<<endl<<"Balance:"<<new_balance;
	file.close();
	exit(0);
}

int credit(int balance_old,string full_name,int a)
{	int debit;
	fstream file;
	cout<<endl<<"Switching_To_Teller_"<<endl<<"      **********"<<endl<<"Input_Tellers_Credential_"<<endl;
	string key="BTYrW";
	string keyin;
	cin>>keyin;
	if (keyin==key)
	{
	cout<<"Success"<<endl<<"*******"<<endl<<"Amount?:";
	cin>>debit;
	int new_balance=balance_old+debit;
	file.open(full_name, ios::out);
	file<<new_balance;
	file.close();
	cout<<endl<<"Transaction Successfull"<<endl<<"      **********"<<endl<<"Balance:"<<new_balance;
	exit(0);
	}
	else
	{
	    cout<<endl<<"Wrong_Key_";
        int credit(int balance_old,string full_name,int a);
	}
	
}

int interlude_balance(string full_name, int a, int balance)
{   

    cout<<endl<<"Balance:"<<balance;
	cout<<endl<<"Choose Debit/Credit"<<endl;
	cout<<"1: Debit"<<endl<<"2: Credit"<<endl;
	int l;
	cin>>l;
	if(l==1)
	{
		debit(balance,full_name,a);
	}
	if(l==2)
	{
		credit(balance,full_name,a);
	}
	else
	{ 
		cout<<"exiting"<<endl<<"*********";
		exit(0);
	}
}

int admin(string full_name, int a)
{
cout<<endl<<"Switching_To_Teller_"<<endl<<"Input_Credential_"<<endl;
string keys;
cin>>keys;
string predefined_key="BTYrW";
if(keys==predefined_key)
{	cout<<"Success"<<endl<<"*******"<<endl<<"Amount?:";
	fstream file;
	file.open(full_name,ios::out);
	int k;
	cin>>k;
	file<<k;
	cout<<endl<<"Transaction Successfull"<<endl<<"      **********";
	interlude_balance(full_name,a,k);
}
else
{
	cout<<"Incorrect_Credential"<<endl<<"**********";
	admin(full_name,a);
}
}


int balance(int a)
{	
	fstream balance_file;
	string console_balance; 
	string k;
	string name="balance";
	int strtoint;	
	k=to_string(a);
	string full_name=name+k;
	fstream fs(full_name,ios_base::in);
	if(!fs)
	{
	balance_file.open(full_name,ios::out);
	admin(full_name,a);
	}
	balance_file.open(full_name,ios::in);
	getline(balance_file,console_balance);
	balance_file.close();
	int abc=stoi(console_balance); 
	interlude_balance( full_name,  a,  abc);
}

int keys() 
{	
    int a=0;
    int l=0;
	string read;
    string User_Defined_Key;
	fstream sign_up;
	cin>>obj1.c;
	sign_up.open("keys", ios::in);
	while(getline(sign_up, read))
	{	
		a++;
		if (read==obj1.c||obj1.c==User_Defined_Key)
	{	
		cout<<endl<<"Welcome New User "<<a<<endl;
		cout<<"     ********";
		sign_up.close();
		l=1;
		balance(a);
	}
	}
	   if(l!=1)
	{
		
		cout<<endl<<"Wrong_Key_"<<endl;
		cout<<"*********";
		sign_up.close();
    	cout<<endl<<" 'S' to 's'ign Up, anything else to retry "<<endl;
    	char s='s';
		char S='S';
    	if(getch()==s||S) 
	{
		cout<<"  Input a key to sign up as new user, without spaces "<<endl;
		cin>>User_Defined_Key;
		sign_up.open("keys", ios::out| ios::ate| ios::app);
		sign_up<<User_Defined_Key<<endl;
		sign_up.close();
		call.fx();
	}
	else
	{
		call.fx();
	}
	}
}


int main() 
{
	call.fx();
}

int cls::fx()
{	
	cout<<endl<<"Welcome_"<<endl;
	cout<<"********";
	cout<<endl<<"Input_Credential, Without_Spaces_"<<endl;
	keys();
}

