// Printing Memory Address.cpp 
// Jeremy Rios-Martinez
// Lab 10-11
// Exercise 1 run 1

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main()
{
  double aDouble = 55555;
  int anInt = 44;
  string aString ("Memory Addresses");	
	
	cout << "Double " << dec << aDouble << " " << hex << showbase << (int)&aDouble << endl
	     << "Int " << dec << anInt << " " << hex << showbase <<  (int)&anInt << endl
	     << "String " << aString << " " << hex <<  showbase <<  (int)&aString << endl;

	system("pause");
	return 0;
}

