                                                                                                                                                                                                                                                                                                                                                       //McDonalds Coffees Program Printout
// Jeremy Rios-Martinez
// Exersise 5
 
#include "stdafx.h"
#include <iostream> 
#include <math.h>
#include <ctype.h>
#include <string>
using namespace std;

// Type Descriptions
struct person
{
	string firstName;
	string lastName;
};

person* make_a_person();

int main()
{
	person *ptrP1;
	ptrP1 = P1;
	cout << ptrP1->firstName << " " << ptrP1->lastName << endl;

	person P1;
	P1.firstName = "Jeremy";
	P1.lastName = "Rios-Martinez";

	system("pause");
	return 0;
}

