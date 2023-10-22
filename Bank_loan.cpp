#include <iostream>
#include <cmath>
#include <tuple>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

//this function allows to add the table to the text file
int createTable(float loanRemaining, int month, float annualRate, float totalMonthlyPayment, ofstream &MyFile)
{
    //setting precision to 1
	cout << fixed << setprecision(2);
	if (loanRemaining <= 0)
	{
		return 1;
	}

	float y = annualRate / 100.0;
	float monthInterest = loanRemaining *(y / 12);
	float loanRepaidInMonth = totalMonthlyPayment - monthInterest;
	//writing to file
	MyFile << month << "        " << fixed << setprecision(2) << loanRemaining << "               " << monthInterest << "           " << fixed << setprecision(2) << loanRepaidInMonth << endl;
	loanRemaining = loanRemaining - loanRepaidInMonth;
	month = month + 1;
	//it is a recursive function
	return createTable(loanRemaining, month, annualRate, totalMonthlyPayment, MyFile);
}

//this function validates whether the loan asked by customer is between the given ranges
float evaluateLoanMaximum(int maxLoanAmount, float loanTaken)
{
	while (loanTaken > maxLoanAmount)
	{
		cout << "Error: Maximum loan amount that is available is " << maxLoanAmount << " Rs." << endl;
		cout << "Enter a correct loan value : ";
		cin >> loanTaken;
		cout << endl;
	}

	return loanTaken;
}

//this function validates whether the loan repay period asked is between the given ranges
int evaluateRepayPeriod(int maxPossibleRepayPeriod, int desiredRepayPeriod)
{
	while (desiredRepayPeriod > maxPossibleRepayPeriod)
	{
		cout << "Error: Maximum repay period that is available is " << maxPossibleRepayPeriod << " months." << endl;
		cout << "Enter a correct repay period in months : ";
		cin >> desiredRepayPeriod;
		cout << endl;
	}

	return desiredRepayPeriod;
}

//this function returns 5 values.
//this function shows the loans that are available according to the given inputs by user
tuple<float, int, float, string, int,bool> showLoanDetails(int ageCustomer, int monIncomeCustomer)
{
	cout << fixed << setprecision(2);
	bool correct=true;
	char loanType;
	float loanTaken;
	int desiredRepayPeriod;
	if (ageCustomer >= 60 && monIncomeCustomer >= 35000)
	{
		cout << "  Loan name         Max.loan amount(Rs)    Max.repay period    annual interest rate(%) " << endl << endl;
		cout << " S.Senior citizen        500,000.00             60                  4.5" << endl;
		cout << endl;
	}
	else if (ageCustomer >= 18 && ageCustomer <= 25 && monIncomeCustomer >= 45000)
	{
		cout << "  Loan name         Max.loan amount(Rs)    Max.repay period    annual interest rate(%) " << endl << endl;
		cout << " V.Vehicle             1,000,000.00             60                   14" << endl;
		cout << endl;
	}
	else if (ageCustomer >= 25 && ageCustomer <= 30)
	{
		if (monIncomeCustomer >= 100000)
		{
			cout << "  Loan name         Max.loan amount(Rs)    Max.repay period    annual interest rate(%) " << endl << endl;
			cout << " V.Vehicle             1,000,000.00             60                   14" << endl;
			cout << " H.Housing             2,500,000.00             60                    8" << endl;
			cout << " E.Education           1,500,000.00            284                    6" << endl;
			cout << endl;
		}
		else if (monIncomeCustomer >= 45000)
		{
			cout << "  Loan name         Max.loan amount(Rs)    Max.repay period    annual interest rate(%) " << endl << endl;
			cout << " V.Vehicle             1,000,000.00             60                   14" << endl;
			cout << " E.Education           1,500,000.00            284                    6" << endl;
			cout << endl;
		}
		else
		{
			cout << "You are not eligible for any loans.";
			correct=false;
			return make_tuple(0, 0, 0, "", 0,correct);
		}
	}
	else if (ageCustomer >= 30 && ageCustomer <= 35)
	{
		if (monIncomeCustomer >= 100000)
		{
			cout << "  Loan name         Max.loan amount(Rs)    Max.repay period    annual interest rate(%) " << endl << endl;
			cout << " V.Vehicle             1,000,000.00             60                   14" << endl;
			cout << " H.Housing             2,500,000.00             60                    8" << endl;
			cout << " E.Education           1,500,000.00            284                    6" << endl;
			cout << " P.Personal           20,000,000.00             60                 14.5" << endl;
			cout << " Q.Personal           30,000,000.00             84                 16.2" << endl;
			cout << endl;
		}
		else if (monIncomeCustomer >= 45000)
		{
			cout << "  Loan name         Max.loan amount(Rs)    Max.repay period    annual interest rate(%) " << endl << endl;
			cout << " V.Vehicle             1,000,000.00             60                   14" << endl;
			cout << " E.Education           1,500,000.00            284                    6" << endl;
			cout << endl;
		}
		else
		{
			cout << "You are not eligible for any loans.";
			correct=false;
			return make_tuple(0, 0, 0, "", 0,correct);
		}
	}
	else if (ageCustomer >= 35 && ageCustomer <= 55)
	{
		if (monIncomeCustomer >= 100000)
		{
			cout << "  Loan name         Max.loan amount(Rs)    Max.repay period    annual interest rate(%) " << endl << endl;
			cout << " V.Vehicle             1,000,000.00             60                   14" << endl;
			cout << " H.Housing             2,500,000.00             60                    8" << endl;
			cout << " P.Personal           20,000,000.00             60                 14.5" << endl;
			cout << " Q.Personal           30,000,000.00             84                 16.2" << endl;
			cout << endl;
		}
		else if (monIncomeCustomer >= 45000)
		{
			cout << "  Loan name         Max.loan amount(Rs)    Max.repay period    annual interest rate(%) " << endl << endl;
			cout << " V.Vehicle             1,000,000.00             60                   14" << endl;
			cout << endl;
		}
		else
		{
			cout << "You are not eligible for any loans.";
			correct=false;
			return make_tuple(0, 0, 0, "", 0,correct);
		}
	}
	else
	{
		cout << "You are not eligible for any loans.";
		correct=false;
		return make_tuple(0, 0, 0, "", 0,correct);
	}

	cout << endl;
	cout << "Please input the letter in front of the loan name you chosen :";
	cin >> loanType;
	cout << "Please input the loan amount you wish to take : ";
	cin >> loanTaken;

	if (loanType == 'v' || loanType == 'V')
	{

		loanTaken = evaluateLoanMaximum(1000000, loanTaken);
	}
	else if (loanType == 'h' || loanType == 'H')
	{
		loanTaken = evaluateLoanMaximum(2500000, loanTaken);
	}
	else if (loanType == 'e' || loanType == 'E')
	{
		loanTaken = evaluateLoanMaximum(1500000, loanTaken);
	}
	else if (loanType == 's' || loanType == 'S')
	{
		loanTaken = evaluateLoanMaximum(500000, loanTaken);
	}
	else if (loanType == 'p' || loanType == 'P')
	{
		loanTaken = evaluateLoanMaximum(20000000, loanTaken);
	}
	else if (loanType == 'q' || loanType == 'Q')
	{
		loanTaken = evaluateLoanMaximum(30000000, loanTaken);
	}

	cout << "Please input the repay period in months that you wish to repay in : ";
	cin >> desiredRepayPeriod;

	if (loanType == 'v' || loanType == 'V')
	{
		desiredRepayPeriod = evaluateRepayPeriod(60, desiredRepayPeriod);
	}
	else if (loanType == 'h' || loanType == 'H')
	{
		desiredRepayPeriod = evaluateRepayPeriod(60, desiredRepayPeriod);
	}
	else if (loanType == 'e' || loanType == 'E')
	{
		desiredRepayPeriod = evaluateRepayPeriod(284, desiredRepayPeriod);
	}
	else if (loanType == 's' || loanType == 'S')
	{
		desiredRepayPeriod = evaluateRepayPeriod(60, desiredRepayPeriod);
	}
	else if (loanType == 'p' || loanType == 'P')
	{
		desiredRepayPeriod = evaluateRepayPeriod(60, desiredRepayPeriod);
	}
	else if (loanType == 'q' || loanType == 'Q')
	{
		desiredRepayPeriod = evaluateRepayPeriod(84, desiredRepayPeriod);
	}

	if (loanType == 'v' || loanType == 'V')
	{
		return make_tuple(loanTaken, desiredRepayPeriod, 14.0, "Vehicle", 60,correct);
	}
	else if (loanType == 'h' || loanType == 'H')
	{
		return make_tuple(loanTaken, desiredRepayPeriod, 8.0, "Housing", 60,correct);
	}
	else if (loanType == 'e' || loanType == 'E')
	{
		return make_tuple(loanTaken, desiredRepayPeriod, 6.0, "Education", 284,correct);
	}
	else if (loanType == 's' || loanType == 'S')
	{
		return make_tuple(loanTaken, desiredRepayPeriod, 4.5, "Senior citizen", 60,correct);
	}
	else if (loanType == 'p' || loanType == 'P')
	{
		return make_tuple(loanTaken, desiredRepayPeriod, 14.5, "Personal", 60,correct);
	}
	else if (loanType == 'q' || loanType == 'Q')
	{
		return make_tuple(loanTaken, desiredRepayPeriod, 16.2, "Personal", 60,correct);
	}
	else
	{
		return make_tuple(0, 0, 0, "", 0,correct);
	}
}

//this function calculates the discount factor and total amount paid by customer
int calulationLoan(float loanTaken, int desiredRepayPeriod, float interestRate, ofstream& MyFile)
{
	cout << fixed << setprecision(2);
	float y = interestRate / 100.0;
	float periodicInterestRate = y / 12;
	float c = 1 + periodicInterestRate;
	float b = (pow(c, desiredRepayPeriod));
	float n = (b - 1);
	float x = (b *periodicInterestRate);
	float discountFactor = n / x;
	float totalMonthlyPayment = loanTaken / discountFactor;
	float totalAmountPaid = totalMonthlyPayment * desiredRepayPeriod;
	cout << fixed << setprecision(2);
	MyFile << "Total amount paid by customer at the end of repay period : " << totalAmountPaid << endl<<endl;
	cout << "Total amount paid by customer at the end of repay period : " << totalAmountPaid << endl<<endl;
	cout << "Monthly amount paid by customer : " << totalMonthlyPayment << endl<<endl;
	cout<<"Total interest earned by bank : "<<totalAmountPaid-loanTaken<<endl<<endl;
	MyFile << "month   Remaining loan amount    Interest      repaid loan amount" << endl;
	createTable(loanTaken, 1, interestRate, totalMonthlyPayment, MyFile);
}

//this function writes the data into the text file
void writeIntoFile(string name, string loanType, int maxPeriodsAllowed, float interestRate, float loanTaken, int desiredRepayPeriod, ofstream &MyFile)
{
	cout << fixed << setprecision(2);
	MyFile << "Name of the customer : " << name << endl;
	MyFile << "selected loan : " << loanType << endl;
	MyFile << "Maximum repay period allowed : " << maxPeriodsAllowed << endl;
	MyFile << "Annual interest rate : " << interestRate << endl;
	MyFile << "Requested loan amount : " << fixed << setprecision(2) << loanTaken << endl;
	MyFile << "Repay period : " << desiredRepayPeriod << endl;

}

int main()
{
	int choose = 0;
	bool chooseCorrect = true;
	bool ageAndIncomeCorrect=true;
	string nameCustomer;
	int desiredRepayPeriod;
	int ageCustomer, monIncomeCustomer;
	float loanTaken;
	int loanTakenInt;
	float interestRate;
	string loanType;
	int maxPeriodsAllowed;

	cout << "\t\t WELCOME TO BANK" << endl << endl;
	cout << "Please select one of the options below :" << endl;
	cout << "\t 1. Add a customer ." << endl;
	cout << "\t 2. Exit ." << endl << endl;
	cout << "Your selection : ";
	cin >> choose;
	cout << endl;

	//validating the user input
	while (!cin)
	{
		cin.clear();
		cin.ignore();
		cout << "Entered wrong value " << endl;
		cout << "Please give a proper integer value (1 or 2) : ";
		cin >> choose;
		cout << endl;
		chooseCorrect = true;
	}

	if (choose == 2 || choose == 1)
	{
		chooseCorrect = true;
	}
	else
	{
		chooseCorrect = false;
	}

	while (!chooseCorrect)
	{
		cout << "Entered wrong value " << endl;
		cout << "Please give a proper integer value (1 or 2) : ";
		cin >> choose;
		cout << endl;
		while (!cin)
		{
			cin.clear();
			cin.ignore();
			cout << "Entered wrong value " << endl;
			cout << "Please give a proper integer value (1 or 2) : ";
			cin >> choose;
			chooseCorrect = true;
		}

		if (choose == 2 || choose == 1)
		{
			chooseCorrect = true;
		}
	}

	while (choose == 1)
	{
		ofstream myFile;
		fstream myFile_Handler;
		cout << endl;
		cout << "Enter your name: ";
		cin >> nameCustomer;
		cout << "Enter your age: ";
		cin >> ageCustomer;
		cout << "Enter your monthly income: ";
		cin >> monIncomeCustomer;
		cout << "The loans that can be taken by you are shown below ." << endl << endl;

		//saving the tuple returned values into variables
		tie(loanTaken, desiredRepayPeriod, interestRate, loanType, maxPeriodsAllowed,ageAndIncomeCorrect) = showLoanDetails(ageCustomer, monIncomeCustomer);
		cout << endl;
		cout << endl;
		if (ageAndIncomeCorrect)
		{
			string fileName = nameCustomer + ".txt";
		ofstream MyFile(fileName);

		myFile_Handler.open(fileName, ios:: in | ios::out);

		if (!myFile_Handler)
		{
			cout << "File did not open!";
			exit(1);
		}

		writeIntoFile(nameCustomer, loanType, maxPeriodsAllowed, interestRate, loanTaken, desiredRepayPeriod, MyFile);
		if (loanTakenInt)
			cout << endl << "This transaction is successful" << endl << endl;
		calulationLoan(loanTaken, desiredRepayPeriod, interestRate, MyFile);
		}

		chooseCorrect=true;
		cout << "Please select one of the options below :" << endl;
		cout << "\t 1. Add a customer ." << endl;
		cout << "\t 2. Exit ." << endl;
		cin >> choose;
		cout << endl;
		while (!cin)
		{
			cin.clear();
			cin.ignore();
			cout << "Entered 1 wrong value " << endl;
			cout << "Please give a proper integer value (1 or 2) : ";
			cin >> choose;
			cout << endl;
			chooseCorrect = true;
		}

		if (choose == 2 || choose == 1)
		{
			chooseCorrect = true;
		}

		while (!chooseCorrect)
		{
			cout << endl;
			cout << "Entered 2 wrong value " << endl;
			cout << "Please give a proper integer value (1 or 2) : ";
			cin >> choose;
			cout << endl;
			while (!cin)
			{
				cin.clear();
				cin.ignore();
				cout << endl;
				cout << "Entered 3 wrong value " << endl;
				cout << "Please give a proper integer value (1 or 2) : ";
				cin >> choose;
				chooseCorrect = true;
			}

			if (choose == 2 || choose == 1)
			{
				chooseCorrect = true;
			}
		}
	};

	return 0;
}
