#include <iostream>
using namespace std;


void print_stuff(float data_stuff)
{
   cout << "Print stuff answer is " << data_stuff << endl;
}

void print_message(float data_message)
{
	cout << "Print Message answer is " << data_message << endl;
}

void print_float (float data_float)
{
   cout << "Print float answer is " << data_float<< endl;
}

void (*fnPointer[3])(float) = {print_stuff, print_message, print_float};

int main()
{
  (*fnPointer[0])(3.14195);
  (*fnPointer[1])(3.14195);
  (*fnPointer[2])(3.14195);

  return 0;
}
