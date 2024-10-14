#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	char p;
	char b;
	char op;
	cout<<"This game is 3 time , who wins 2 times or more shell win "<<endl;
	do{
	int points =0;
	for(int i = 0 ;i<3;i++){
		cout << "you use : ";
		cin >> p;
		string rps = "rps";
		srand(time(nullptr));

		int n = rand() % 3;
		b = rps[n];
		cout << "bot used : " << b << endl;

		if(p!=b){
			if(b=='r'){
				if(p=='p'){
					points++;
				}
			}else if(b =='p'){
				if(p=='s'){
					points++;
				}
			}else if(b =='s'){
				if(p=='r'){
					points++;
				}
			}
		}
	}
	cout<<"Your points: "<<points<<endl;
	if(p>=2){
		cout<<"You win!"<<endl;
	}else{
		cout<<"You lose !"<<endl;
	}
		cout<<"Do you want to play again?"<<endl;
		cin>>op;
	}while(op=='y'||op=='Y');
	return 0;
}