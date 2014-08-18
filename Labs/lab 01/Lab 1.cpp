//This program does stuff…and is written by me
#include "stdafx.h"
#include <iostream> 
using std::cin;
using std::cout; 
using std::endl;

int  main()
{
   // rem 4 is the remainder at 4 years, the other are something like that.
   // y = the year value that is used in this program rather well don’t you
   // think ? 
	int y, rem4, rem100, rem400;
	char DoItAgainSam;

	do
	{
     cout <<"Enter a yr";
	  cin>> y;
	  rem4 = y%4;
        rem100 = y %100;
        rem400 = y % 400;
        if ( rem4 == 0 && rem100 != 0  || rem400 == 0)
            cout << endl << y << " is a leap y " << endl;
        else
            cout << endl << y << " is not a leap y " << endl;

	  cout << "\nPlay again ?? ";
	  cin >> DoItAgainSam;
	}
	while (DoItAgainSam == 'y');
	return 0;	
}
