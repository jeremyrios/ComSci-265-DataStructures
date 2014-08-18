/* rand example: guess the number */
#include "stdafx.h"
#include <time.h>
#include <iostream>
using namespace std;

int i,c;

void remainder();

int main ()
{

 remainder();
 

  system("pause");
  return 0;
}

void remainder()
{
 for(i=1; i<=8; i++)
  {
	  c = (8-i)/2;
		  cout << c << endl;
  }
}