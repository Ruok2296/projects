#include <iostream>
using namespace std;

class day
{
	public:
	int income;
	int tr;
	int save, min;
	day() { cout << "" << endl; }
	day(int x, int y)
	{
		income = x;
		tr = y;
		if (income > tr)
		{
			save = income - tr;
			min = 0;
		}
		else if (tr > income)
		{
			save = 0;
			min = tr - income;
		}
		else
		{
			save = 0;
			min = 0;
		}
	
	
	}
	void showinfo()
	{
		cout << "This weeks income is " << income << endl;
		cout << "This weeks transiction is " << tr << endl;
		if (save > min)
		{
			cout << "This week saving is " << save << endl;
		}
		else if (min > save)
		{
			cout << "This week has " << min << " due" << endl;
		}
		else
		{
			cout << "No save or due " << endl;
		}
	}
};
class week : public day
{
public:
	float avg_saving;
	float avg_min;
	week(day a, day b, day c, day d, day e, day f, day g)
	{
		avg_saving = (a.save + b.save + c.save + d.save + e.save + f.save + g.save) / 7.0;
		avg_min = (a.min + b.min + c.min + d.min + e.min + f.min + g.min) / 7.0;
	}
	void showdata()
	{

		cout << "This weeks avarage saving is " << avg_saving << endl;
		cout << "This wees avarage due is " << avg_min << endl;
		if (avg_saving > avg_min)
		{
			cout << "You have done a great job!" << endl;
		}
		else if (avg_min > avg_saving)
		{
			cout << "Very bad , You have many dues " << endl;
		}
		else
		{
			cout << "Try to save!" << endl;
		}
	}
};

int main()
{
	char op;
	do{
	int x[6],y[6];
	for(int i  =0 ;i<7;i++){
		cout << "give me the 3ed day income and transiction : " << endl;
		cin>>x[i]>>y[i];
	}
	day day1(x[1], y[1]);
	day day2(x[2], y[2]);
	day day3(x[3], y[3]);
	day day4(x[4], y[4]);
	day day5(x[5], y[5]);
	day day6(x[6], y[6]);
	day day7(x[7], y[7]);

	week week1(day1, day2, day3, day4, day5, day6, day7);
	week1.showdata();
	cout<<"Do you want to do it again?"<<endl;
	
	cin>>op;
		////cout<<"Do you wanna do it again ?"<<endl	
	}while(op=='Y'||op=='y');
}
/*void callmain(){
	main();
}*/