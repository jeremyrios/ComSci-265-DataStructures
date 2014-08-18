#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void main()
{
	int i = 1000;  
	double d = 0.0947628;

	cout << "Original Format\n" << endl;
	cout << i << "\t" << d << endl;

	cout << "Other Format\n" << endl;
	cout.flags(ios::oct | ios::scientific);
	cout << i << "\t" << d << endl;

	cout << "Original Format\n" << endl;
	cout.unsetf(ios::oct | ios::scientific);
	cout << i << "\t" << d << endl;
}