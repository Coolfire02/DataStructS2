#include <iostream>
#include <map>
#include <string>

using namespace std;

const string EMPTY = "";

const string X[] = { EMPTY, "One ", "Two ", "Three ", "Four ", "Five ",
				"Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ",
				"Twelve ", "Thirteen ", "Fourteen ", "Fifteen ",
				"Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " };

const string Y[] = { EMPTY, EMPTY, "Twenty ", "Thirty ", "Forty ", "Fifty ",
				"Sixty ", "Seventy ", "Eighty ", "Ninety " };

enum Month {
	JANUARY = 0,
	FEBUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER,

};

double to1DP(double var) {
	var = round(var * 10) / 10;
	return var;
}

// Function to convert single digit or two digit number into words
string convert2digit(int n, string suffix)
{
	// if n is zero
	if (n == 0) {
		return EMPTY;
	}

	// split n if it is more than 19
	if (n > 19) {
		return Y[n / 10] + X[n % 10] + suffix;
	}
	else {
		return X[n] + suffix;
	}
}

// Function to convert a given number (max 9-digits) into words
string numberToWords(unsigned long long int n)
{
	// string to store word representation of given number
	string res;

	// this handles digits at ones & tens place
	res = convert2digit((n % 100), "");

	if (n > 100 && n % 100) {
		res = "and " + res;
	}

	// this handles digit at hundreds place
	res = convert2digit(((n / 100) % 10), "Hundred ") + res;

	// this handles digits at thousands & tens thousands place
	res = convert2digit(((n / 1000) % 100), "Thousand ") + res;

	// this handles digits at hundred thousands & one millions place
	res = convert2digit(((n / 100000) % 100), "Lakh, ") + res;

	// this handles digits at ten millions & hundred millions place
	res = convert2digit((n / 10000000) % 100, "Crore, ") + res;

	// this handles digits at ten millions & hundred millions place
	res = convert2digit((n / 1000000000) % 100, "Billion, ") + res;

	return res;
}

int main(void) {
	bool askingDate = true;
	int day, month, year;
	while (askingDate) {
		cout << "Enter a day: ";
		cin >> day;
		cout << "Enter month: ";
		cin >> month;
		cout << "Enter year: ";
		cin >> year;

		if (day < 0 || day > 31 || month < 0 || month > 12 || year < 0 || year > 2020) {
			cout << "Invalid date" << endl;
		}
		else {
			askingDate = true;
			break;
		}
	}
	string payee;
	cout << "Enter payee's name: ";
	cin >> payee;
	bool findingM = true;
	double amt;
	while (findingM) {
		cout << "Enter amt to pay: ";
		cin >> amt;
		if (amt < 0 || amt > 10000)
			cout << "cannot give less than 0 or 10000$" << endl;
		else {
			findingM = false;
		}
	}
	cout << "Date: " << day << "/" << month << "/" << year << endl;
	cout << "Pay To: " << payee << " $" << round(amt * 100) / 100 << endl;
	cout << numberToWords(amt) << " only" << endl;
}

int EX5(void) 
{

	double rainfall[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
	int leastRain = -1;
	int mostRain = -1;
	double total = 0;
	for (int i = 0; i < 12; i++) {
		cout << "Enter total rainfall for " << Month(i) << ": ";
		double input;
		cin >> input;

		if (input < 0) {
			cout << "Rainfall cannot be less than 0!" << endl;
			i--;
			continue;
		}
		else {
			rainfall[i] = input;
			total += input;
			if (leastRain >= 0 && rainfall[leastRain] > input) {
				leastRain = i;
			}
			else if (leastRain == -1) {
				leastRain = i;
			}

			if (mostRain >= 0 && rainfall[mostRain] < input) {
				mostRain = i;
			}
			else if (mostRain == -1) {
				mostRain = i;
			}
			cout << endl;
		}

	}

	cout << "Most Rain: " << Month(mostRain) << " at: " << to1DP(rainfall[mostRain]) << endl;
	cout << "Least Rain: " << Month(leastRain) << " at: " << to1DP(rainfall[leastRain]) << endl;
	cout << "Total Rainfall: " << to1DP(total) << endl;
	cout << "AVG. Rainfall: " << to1DP(total/12.0) << endl;
	return 0;
}