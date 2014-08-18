// Exercise_4b.cpp
// Author: Jeremy Rios-Martinez  
// Course: COMSC 265

#include "stdafx.h"
#include <iostream> 
using std::cin;
using std::cout; 
using std::endl;

#define TARGET 13

int main(void)
{
  int answer;
  bool loop = true;
  cout << "Im thinking of a number between 1 and 50 see if you can guess it: ";
  while (loop)
  {
	cin >> answer;
    if (answer > TARGET || answer < TARGET)     // conditions are in the order  
    {                                           // they are in becaue it is more 
	  if (answer > TARGET)                      // likley answer guessed will be
	  {                                         // will be greater than TARGET
	    cout << "To High... Guess again: ";
	  }
	  else
	  {
		cout << "To Low... Guess again: ";
	  }
	}
	else 
	{
	  cout << "Wow you guess it. You must be psychic\n";
	  loop = false;
	}
  }
  system ("pause");
  return 0;
}

