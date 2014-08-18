#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void main()
{
	int x = 10000;
	cout.width(10); 
	cout << x << endl;

	cout.width(10); 
	cout.setf(ios::left);
	cout << x << endl;

	cout.width(10); 
	cout.setf(ios::internal);
	cout << hex << setiosflags (ios_base::showbase);
	cout << x << endl;

	cout.setf(ios::right);
	cout.width(10); 
	cout<< setfill('*');
	cout << dec << x << endl;

	cout.width(10);
	cout.unsetf(ios::internal);
	cout.unsetf(ios::right);
	cout<< setfill('%');
	cout << x << endl;

	cout.width(10); 
	cout.setf(ios::internal);
	cout << hex << setiosflags (ios_base::showbase);
	cout<< setfill('^');
	cout << x << endl;
}