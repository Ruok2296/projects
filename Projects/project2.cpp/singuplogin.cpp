#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void writecanditals(const string &name, const string &password){
	ofstream outfile("credentials.txt");
	outfile<<name<<endl;
	outfile <<password<<endl;
	outfile.close();
}
bool readCredentials(string &name, string &password){
	ifstream infile("credentials.txt");
	if(infile){
		getline(infile,name);
		getline(infile,password);
		infile.close();
		return true;
	}else{
		return false;
	}
}
bool login(string &inputname,string &inputpass){
	string storedname;string storedpass;
	if(readCredentials(storedname, storedpass)){
		return (storedname == inputname && storedpass == inputpass);
	}else {
		return false;
	}
}
int main()
{

	string name;
	string password;

	cout<<"Hello , welocme to my game "<<endl;
	cout<<"DO you want to login  or sign up ?(l for login and s for sign up)"<<endl;
	char OP1;
	cin>>OP1;
		if(OP1 =='l'){

			cout<<"name : "<<endl;
			cin>>name;
			cout<<"password : "<<endl;
			cin>>password;
			//bool OP2 = readCredentials(name,password);
			if(login(name,password)){
				cout<<"Ok , You are good to go !"<<endl;
			}else {
				cout << "wrong credentials "<<endl;
			return 0 ;
			}
		}else{
			cout<<"give me your name : "<<endl;
			cin>>name ;
			cout<<"Give me your password : "<<endl;
			cin>>password;
			writecanditals(name,password);
		}


	return 0;
}