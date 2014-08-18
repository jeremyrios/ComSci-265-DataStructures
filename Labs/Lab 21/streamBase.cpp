#include <iostream>
#include <iomanip>
using namespace std;

void main()
{
  int n = 962849;
  char buffer [10];
  cout << "The number entered is: " << n <<endl;
  cout << dec << n << " in hexadecimal is: " << hex << n << endl;
  cout << dec << n << " in octal is: " << oct << n << endl;
  cout << dec << n << " in decimal is: " << dec << n << endl;
  itoa(n, buffer, 4);
  cout << dec << n << " in base 4 is: " << buffer << endl;
}