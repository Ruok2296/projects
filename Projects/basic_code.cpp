#include <iostream>
using namespace std;

class day
{
public:
	int income;
	int tr;
	// public:
	int save, min;
	day() { cout<<""<<endl; }
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
	void cal()
	{
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
	//week() { //cout << "Error!" << endl; }
	week(day a, day b, day c, day d, day e, day f, day g)
	{
		avg_saving = (a.save + b.save + c.save + d.save + e.save + f.save + g.save) / 7.0;
		avg_min = (a.min + b.min + c.min + d.min + e.min + f.min + g.min)/ 7.0;
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


		//getdata();
		int x1, x2, x3, x4, x5, x6, x7;
		int y1, y2, y3, y4, y5, y6, y7;
		// cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6 >> x7 >> y7;
		cout << "give me the 1st day income and transiction : " << endl;
		cin >> x1 >> y1;
		cout << "give me the 2nd day income and transiction : " << endl;
		cin >> x2 >> y2;
		cout << "give me the 3ed day income and transiction : " << endl;
		cin >> x3 >> y3;
		cout << "give me the 4th day income and transiction : " << endl;
		cin >> x4 >> y4;
		cout << "give me the 5tht day income and transiction : " << endl;
		cin >> x5 >> y5;
		cout << "give me the 6th day income and transiction : " << endl;
		cin >> x6 >> y6;
		cout << "give me the 7th day income and transiction : " << endl;
		cin >> x7 >> y7;
		day day1(x1, y1);
		day day2(x2, y2);
		day day3(x3, y3);
		day day4(x4, y4);
		day day5(x5, y5);
		day day6(x6, y6);
		day day7(x7, y7);

		week week1(day1, day2, day3, day4, day5, day6, day7);
		week1.showdata();
		return 0;
}