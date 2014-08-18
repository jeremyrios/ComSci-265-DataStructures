#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void main()
{
	double x = .001234567;
	double y = 1.946e9;

	cout << "\nDisplayed in default format\n" << endl;
	cout << "X = " << x << endl << "Y = " << y << endl;

	cout << "\nDisplayed in scientific format\n" << endl;
	cout.setf(ios::scientific, ios::floatfield);
	cout << "X = " << x << endl << "Y = " << y << endl;

	cout << "\nDisplayed in default format\n" << endl;
	cout.unsetf(ios::scientific);
	cout << "X = " << x << endl << "Y = " << y << endl;

	cout << "\nDisplayed in fixed format\n" << endl;
	cout.setf(ios::fixed, ios::floatfield);
	cout << "X = " << x << endl << "Y = " << y << endl;
}