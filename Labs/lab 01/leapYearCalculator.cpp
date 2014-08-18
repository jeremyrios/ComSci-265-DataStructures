// leapYearCalculator.cpp
// Author: Bill Schwarz     
// Last Modified by: Jeremy Rios-Martinez       
// Date Last Modified: August 22, 2010 
// Program Description: 
//  Program accepts a user defined year then determines if entry is a leap year.
// Note:
//  A leap year is a year that is evenly divisible by 4 and not by 100 or, a
//  year that is evenly divisible by 400.

#include "stdafx.h"
#include <iostream> 
using std::cin;
using std::cout; 
using std::endl;

int  main()
{
  // year = the user defined year input
  // remainder4 = the remainder after the user defined year is divided by 4.
  // remainder100 = the remainder after the user defined year is divided by 100.
  // remainder400 = the remainder after the user defined year is divided by 400.

  int year, remainder4, remainder100, remainder400;
  char repeatOption;

  do
  {
    cout << "\nEnter a year: ";
	cin >> year;

	remainder4 = year % 4;
    remainder100 = year % 100;
    remainder400 = year % 400;

    if (remainder4 == 0 && remainder100 != 0 || remainder400 == 0)
      cout << endl << year << " is a leap year\n";

    else
      cout << endl << year << " is not a leap year\n";  

	cout << "\nPlay again? (y or n): ";
	cin >> repeatOption;
  }
  while (repeatOption == 'y');
  system ("pause");
  return 0;	
}


