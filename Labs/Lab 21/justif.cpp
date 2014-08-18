#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void main()
{
	int x = 12345;
	cout.width(10); 
	cout << x << endl;

	cout.width(10); 
	cout.setf(ios::left);
	cout << x << endl;

	cout.unsetf(ios::left);
	cout.width(10); 
	cout << x << endl;

	cout.width(10); 
	cout << setiosflags(ios::left) << x << endl;

	cout.width(10); 
	cout << resetiosflags(ios::left) << x << endl;;
}