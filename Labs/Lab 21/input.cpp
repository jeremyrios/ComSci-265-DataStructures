#include <iostream>
using namespace std;

void main()
{
	int x;

	cout << endl << "cin.rdstate():" << cin.rdstate();
	cout << endl << "cin.rdstate():" << cin.eof();
    cout << endl << "cin.rdstate():" << cin.fail();
	cout << endl << "cin.rdstate():" << cin.bad();
	cout << endl << "cin.rdstate():" << cin.good();

	cout << endl << "Enter a char:";
	cin >> x;

	cout << "Output values After a bad input operation: " << endl;
	cout << endl << "cin.rdstate():" << cin.rdstate();
	cout << endl << "cin.rdstate():" << cin.eof();
    cout << endl << "cin.rdstate():" << cin.fail();
	cout << endl << "cin.rdstate():" << cin.bad();
	cout << endl << "cin.rdstate():" << cin.good();

	cin.clear();
	
	cout << "Output values After a clear: " << endl;
	cout << endl << "cin.rdstate():" << cin.rdstate();
	cout << endl << "cin.rdstate():" << cin.eof();
    cout << endl << "cin.rdstate():" << cin.fail();
	cout << endl << "cin.rdstate():" << cin.bad();
	cout << endl << "cin.rdstate():" << cin.good();

	
}
