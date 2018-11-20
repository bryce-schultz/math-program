/*
Bryce Schultz
11/18/2018
CS 133U

Description: program does math.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;

//function prototypes
int getData();
int findNumDigits(int n);
int findDigitAtPosition(int n, int p);
void displayMenu(int &c);
void processMenuChoice(int c, int &n);
void isPosNeg(int n);
void isOddEven(int n);
void displayAdditionTable();
void displayMultiplicationTable();
void printMsg(string msg, double n = 0, bool var = false);
void displayRestartMenu();


//main function
int main() {
	int menuChoice = 0;
	int number = 0;
	char choice = '\0';

	do {
		menuChoice = 0;
		number = 0;
		choice = '\0';
		number = getData();
		displayMenu(menuChoice);
		processMenuChoice(menuChoice, number);

		printMsg("\n\nWould you like to use the app again? (y/n): ");
		cin >> choice;
		choice = tolower(choice);
		cout << '\n';
	} while (choice != 'n');

	return 0;
}

//print message function for easy printing
void printMsg(string msg, double n, bool var) {
	if (var) {
		cout << msg << n;
	}
	else {
		cout << msg;
	}
}

//check if a number is positive or negitive
void isPosNeg(int n) {
	if (n > 0) {
		printMsg("\nNumber is positive");
	}
	else if (n < 0) {
		printMsg("\nNumber is negitive");
	}
	else if (n == 0) {
		printMsg("\nNumber is 0");
	}
}

//check if a number is odd or even
void isOddEven(int n) {
	if (n % 2 == 0)
	{
		printMsg("\nNumber is even");
	}
	else {
		printMsg("\nNumber is odd");
	}
}

//get user input for the number
int getData() {
	int number = 0;
	//get a number from the user
	printMsg("Enter a number: ");
	cin >> number;
	if (cin.fail())
	{
		printMsg("That's not a number!\n\n");
		cin.clear();
		cin.ignore();
		getData();
	}

	if (number < -1000000 || number > 1000000) {
		printMsg("That number is out of range!\n\n");
		getData();
	}
	return number;
}

//menu to restart the application
void displayRestartMenu() {
	char choice = '\0';
	printMsg("\n\nWould you like to use the app again? (y/n): ");
	cin >> choice;
	choice = tolower(choice);
	cout << '\n';
	if (choice == 'y') main();
}

//display the main menu
void displayMenu(int &c) {
	cout << "\n1) Is the number odd or even?\n"
		 << "2) Is the number positive or negitive?\n"
		 << "3) What is the square root of the number\n"
		 << "4) Display the number of digets in the number\n"
		 << "5) Get the diget at a specific position\n"
		 << "6) Display an addition table\n"
		 << "7) Display a multiplication table\n";

	cout << "Enter a menu choice: ";
	cin >> c;
}

//switch statement for processing menu input
void processMenuChoice(int c, int &n) {
	switch (c)
	{
		case 1:
		{
			//odd / even
			isOddEven(n);
			break;
		}
		case 2:
		{
			//pos / neg
			isPosNeg(n);
			break;
		}
		case 3:
		{
			//sqrt
			double root = sqrt(n);
			printMsg("\nThe square root is: ", root, true);
			break;
		}
		case 4:
		{
			//number of digets
			printMsg("\nThe number of didgets is: ", findNumDigits(n), true);
			break;
		}
		case 5:
		{
			int p = 0;
			do {
				printMsg("Enter the position: ");
				cin >> p;
				if (findNumDigits(n) < p) {
					printMsg("There are not that many digets in the number!\n\n");
				}
			} while (findNumDigits(n) < p);
			//didget at position
			printMsg("The number at the position is: ", findDigitAtPosition(n, p), true);
			break;
		}
		case 6:
		{
			//addition table
			displayAdditionTable();
			break;
		}
		case 7:
		{
			//multiplication table
			displayMultiplicationTable();
			break;
		}
		default:
		{
			//invalid input
			cout << "\nInvalid menu choice\n\n";
			main();
		}
	}
}

//get a digit at a position in an int
int findDigitAtPosition(int n, int p) {
	int a = n / pow(10, p-1);
	int b = n / pow(10, p);
	int c = a-b*10;
	return c;
}

//optimized findDigitAtPosition function, uses only one pow function
/*
int findDigitAtPosition(int n, int p) {
//	int a = pow(10, p-1);
//	int b = n / a;
//	int c = n / (a * 10);
//	return b - c * 10;
}
*/

//find the number of digits in an int
int findNumDigits(int n) {
	return n > 0 ? log10(n) + 1 : 1;
}

//creates an addition table using for loops
void displayAdditionTable() {
	int size = 12;
	cout << '\n';
	for (int i = 0; i <= size; i++) {
		for (int j = 0; j <= size; j++) {
			cout << setw(4) << j + i;
		}
		cout << "\n\n";
	}
}

//creates a multiplication table using for loops
void displayMultiplicationTable() {
	int size = 12;
	cout << '\n';
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			cout << setw(4) << j * i;
		}
		cout << "\n\n";
	}
}