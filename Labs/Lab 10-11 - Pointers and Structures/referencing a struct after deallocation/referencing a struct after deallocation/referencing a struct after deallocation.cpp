                                                                                                                                                                                                                                                                                                                                                       //McDonalds Coffees Program Printout
// Jeremy Rios-Martinez
// Exersise 3
 

#include "stdafx.h"
#include <iostream> 
#include <math.h>
#include <ctype.h>
#include <string>
using namespace std;

void make_a_person();

// Type Descriptions
struct person
{
	string firstName;
	string lastName;
};

int main()
{
	make_a_person();

	person *ptrP1;
	ptrP1 = &P1;
	cout << ptrP1->firstName << " " << ptrP1->lastName << endl;

	system("pause");
	return 0;
}

void make_a_person()
{
	person P1;
	P1.firstName = "Jeremy";
	P1.lastName = "Rios-Martinez";

    person *ptrP1;
	ptrP1 = &P1;
	cout << ptrP1->firstName << " " << ptrP1->lastName << endl;
}