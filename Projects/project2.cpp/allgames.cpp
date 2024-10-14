#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void writecanditals(const string &name, const string &password)
{
	ofstream outfile("credentials.txt");
	outfile << name << endl;
	outfile << password << endl;
	outfile.close();
}
bool readCredentials(string &name, string &password)
{
	ifstream infile("credentials.txt");
	if (infile)
	{
		getline(infile, name);
		getline(infile, password);
		infile.close();
		return true;
	}
	else
	{
		return false;
	}
}
bool login(string &inputname, string &inputpass)
{
	string storedname;
	string storedpass;
	if (readCredentials(storedname, storedpass))
	{
		return (storedname == inputname && storedpass == inputpass);
	}
	else
	{
		return false;
	}
}

void rps()
{
	char p;
	char b;
	char op;
	cout << "This game is 3 time , who wins 2 times or more shell win " << endl;
	cout << "p for paper r for rock and s for siger " << endl;
	do
	{
		int points = 0;
		for (int i = 0; i < 3; i++)
		{
			cout << "you use : ";
			cin >> p;
			string rps = "rps";
			srand(time(nullptr));

			int n = rand() % 3;
			b = rps[n];
			cout << "bot used : " << b << endl;

			if (p != b)
			{
				if (b == 'r')
				{
					if (p == 'p')
					{
						points++;
					}
				}
				else if (b == 'p')
				{
					if (p == 's')
					{
						points++;
					}
				}
				else if (b == 's')
				{
					if (p == 'r')
					{
						points++;
					}
				}
			}
		}
		cout << "Your points: " << points << endl;
		if (points >= 2)
		{
			cout << "You win!" << endl;
		}
		else
		{
			cout << "You lose !" << endl;
		}
		cout << "Do you want to play again?" << endl;
		cin >> op;
	} while (op == 'y' || op == 'Y');

}

int main()
{

	string name;
	string password;

	cout << "Hello , welocme to my game " << endl;
	cout << "DO you want to login  or sign up ?(l for login and s for sign up)" << endl;
	char OP1;
	cin >> OP1;
	if (OP1 == 'l')
	{

		cout << "name : " << endl;
		cin >> name;
		cout << "password : " << endl;
		cin >> password;
		
		if (login(name, password))
		{
			cout << "Ok , You are good to go !" << endl;
		}
		else
		{
			cout << "wrong credentials " << endl;
			return 0;
		}
	}
	else
	{
		cout << "give me your name : " << endl;
		cin >> name;
		cout << "Give me your password : " << endl;
		cin >> password;
		writecanditals(name, password);
	}

	cout << "Which game would you like to play?" << endl;
	char game;
	cout << " a -> rockpapersizer" << endl;
	cin >> game;
	if (game == 'a')
	{
		rps();
		cout << "Thanks for playing it !" << endl;
	}

	return 0;
}