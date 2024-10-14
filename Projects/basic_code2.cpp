#include <iostream>
using namespace std;

class Week
{
protected:
	int income;
	int transaction; // Changed 'tr' to 'transaction' for clarity

public:
	int savings, minimumDue; // Renamed for clarity

	void getInf(int x, int y)
	{
		income = x;
		transaction = y;
	}

	void calculate()
	{
		if (income > transaction)
		{
			savings = income - transaction;
			minimumDue = 0;
		}
		else if (transaction > income)
		{
			savings = 0;
			minimumDue = transaction - income;
		}
		else
		{
			savings = 0;
			minimumDue = 0;
		}
	}

	void showInfo() const
	{
		cout << "This week's income is: " << income << endl;
		cout << "This week's transaction is: " << transaction << endl;

		if (savings > minimumDue)
		{
			cout << "This week saving is: " << savings << endl;
		}
		else if (minimumDue > savings)
		{
			cout << "This week has: " << minimumDue << " due" << endl;
		}
		else
		{
			cout << "No savings or dues this week." << endl;
		}
	}
};

int main()
{
	Week w1;
	int x, y;

	cout << "Enter income and transaction: ";
	cin >> x >> y;

	w1.getInf(x, y);
	w1.calculate();
	w1.showInfo();

	return 0;
}
/*Key Changes
Variable Names: More descriptive names for better understanding.
Const in Member Function: Added const to showInfo() to indicate that it doesn’t modify any member variables.
Input Prompt: Added a prompt for user input to improve usability.
Conclusion
Your program is well-structured and follows object-oriented principles. With a few tweaks, you can enhance readability and maintainability. If you have any specific areas you want to improve or questions about the code, feel free to ask!
*/