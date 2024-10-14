#include <Wt/WApplication.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WContainerWidget.h>
#include <iostream>
using namespace Wt;

class FinanceApp : public WApplication
{
public:
	WLineEdit *incomeInput[7];
	WLineEdit *transactionInput[7];
	WText *resultText;

	FinanceApp(const WEnvironment &env) : WApplication(env)
	{
		setTitle("Finance Management");

		WContainerWidget *container = root();
		container->addWidget(new WText("Enter income and transaction values for each day:<br>"));

		// Create input fields for 7 days
		for (int i = 0; i < 7; i++)
		{
			container->addWidget(new WText("<br>Day " + std::to_string(i + 1) + ": "));
			incomeInput[i] = new WLineEdit(container);
			incomeInput[i]->setPlaceholderText("Income");
			transactionInput[i] = new WLineEdit(container);
			transactionInput[i]->setPlaceholderText("Transaction");
		}

		// Create button to calculate the results
		WPushButton *calcButton = new WPushButton("Calculate Weekly Summary", container);
		calcButton->clicked().connect(this, &FinanceApp::calculateWeek);

		resultText = new WText(container); // Display results
	}

	void calculateWeek()
	{
		int income[7], transaction[7];
		for (int i = 0; i < 7; i++)
		{
			income[i] = std::stoi(incomeInput[i]->text().toUTF8());
			transaction[i] = std::stoi(transactionInput[i]->text().toUTF8());
		}

		// Implement the day and week logic from your original code
		int totalSaving = 0, totalDue = 0;
		for (int i = 0; i < 7; i++)
		{
			int saving = income[i] > transaction[i] ? income[i] - transaction[i] : 0;
			int due = transaction[i] > income[i] ? transaction[i] - income[i] : 0;
			totalSaving += saving;
			totalDue += due;
		}

		// Calculate averages
		float avgSaving = totalSaving / 7.0;
		float avgDue = totalDue / 7.0;

		// Display results in the web app
		std::string summary = "Average Saving: " + std::to_string(avgSaving) +
							  "<br>Average Due: " + std::to_string(avgDue);
		resultText->setText(summary);
	}
};

WApplication *createApplication(const WEnvironment &env)
{
	return new FinanceApp(env);
}

int main(int argc, char **argv)
{
	return WRun(argc, argv, &createApplication);
}