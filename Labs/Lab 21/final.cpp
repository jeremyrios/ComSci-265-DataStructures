// final.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include <iostream>
using namespace std;

const int SIZE = 10;

int *pIntArray  = new int[SIZE];


int sumValuesInArray(int x);
void assignNumbersToArray(int x);
int determineMaxValue(int x);

int main()
{
  int index=0, sum=0, maxValue=0;

  assignNumbersToArray(index);
  sum = sumValuesInArray(index);
  maxValue = determineMaxValue(index);

  cout << endl << sum << endl << maxValue;
	return 0;
}

void assignNumbersToArray(int x)
{

  if(x>0)
  {
    x--;
    *(pIntArray+x) = (x+1);
    cout << *(pIntArray+x) << endl;
    assignNumbersToArray(x);
  }

}

int sumValuesInArray(int x)
{
  int sum=0;
  if (x < SIZE-1)
  {
    cout << *(pIntArray+x) << endl;
    sum = *(pIntArray+x) + sumValuesInArray(x++);
  }
  else
  {
    return *(pIntArray+x);
  }
  return sum;
}

int determineMaxValue(int x)
{
  if(x>1)
  {
    if(*(pIntArray+(x-1)) < sumValuesInArray(--x))
    {
      return *(pIntArray+(x-1));
    }
  }
  else
  {
    return 0;
  }
}