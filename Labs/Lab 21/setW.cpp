#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void main()
{
  string in;
  int counter = 0;
  cout << "Enter a sentence: ";
  getline(cin, in);
  for (int i=0; i<in.length(); i++)
  {
    if(i && (i % 5) == 0)
	{
	  cout << endl << setw(++counter) << " ";
	}
	cout << in[i];
  }
}
