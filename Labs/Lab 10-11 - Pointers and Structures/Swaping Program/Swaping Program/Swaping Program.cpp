// Swaping Program.cpp 
// Jeremy Rios-Martinez
// Lab 10-11
// Exercise 2

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void swapAandB(int *iptr_A, int *iptr_B);

int main()
{
	int intA = 44, intB = 33;

	cout << "Before swap A = " << intA << " and B = " <<  intB << endl;

	swapAandB(&intA, &intB);

	cout << "After swap A = " << intA << " and B = " <<  intB << endl;

	system("pause");
	return 0;
}


void swapAandB(int *iptr_A, int *iptr_B)
{
	int temp;
	temp = *iptr_A;
	*iptr_A = *iptr_B;
	*iptr_B = temp;
}