
#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// Constants
const int SIZE = 100; // Global constants should be all caps
const string INPUT_FILE("M:\\Computer Programing\\COMSC 265\\Labs\\Lab 1213\\CutomerPurchases.txt");
const string UPDATE_FILE("");

//global sturcture
struct purchase
{
	string accountNumber; // this dosn't need to be an int
	string firstName;
	string lastName;
	string itemName;
	double cost;
	string itemDescription;
	int qty;
	purchase *ptrNext; // got to have these ptr's inorder to create a linked list
	purchase *ptrPrev; 
};


// global function delerations
int readInFile(purchase *customer[]); 
void printRecords(purchase *customer[], int Customers);
// void open(ifstream& fin);                          seams a little redundent to have a function to
// void read(ifstream& fin,purchase* customer[]);      open and one to read ???

int main()
{
	// variables
	int customers;
	//ofstream fout;
	purchase *customer[SIZE];

	// function call / main code
	customers = readInFile(customer);
	printRecords(customer, customers);
	
	system("pause"); // so the system doesnt quit after execution of program
}

// function definitions

/*
void open(ifstream& fin)
{
	fin.open(inputFile);
	
	if (fin.is_open()) // checks to see if file is open or not.
		cout << "File successfully open"<<endl<<endl;

	else
		cout << "Error opening file"<<endl;
}
*/

// Function that is passed an array of pointers that will point to a 
// structure type an returns the number of customers read in



int readInFile(purchase *customer[]) 
{                                                        // 
	int i=0; 
	string temp; 
	customer[i] = new purchase;        // dynamiclly allocates memory 
	purchase *ptrTemp = customer[i];   // for first spot in array stucture 
	ifstream fin(INPUT_FILE);              // INPUT_FILE is a constant global string 
	if(fin.is_open()) 
	{ 
		getline(fin, ptrTemp->accountNumber, ',');      // Reads in comma (,) 
		getline(fin, ptrTemp->firstName, ',');          // seperated data from a file 
		getline(fin, ptrTemp->lastName, ',');           // and tokenises the data into 
		getline(fin, ptrTemp->itemName, ',');           // respective stucture varaibles 
		fin >> ptrTemp->cost; 
		getline(fin, temp, ','); 
		getline(fin, ptrTemp->itemDescription, ','); 
		fin >> ptrTemp->qty; 
		getline(fin, temp); 
		while(!fin.eof())                           // Until end of file is reached 
		{ 
			getline(fin, temp, ','); 
			if (temp == ptrTemp->accountNumber)       // if the next card number is the 
			{                                         // same as the prev 
				ptrTemp->ptrNext = new purchase;      // memory is dynamically created 
				ptrTemp->ptrNext->ptrPrev = ptrTemp;  // in a linked list fashon sprouting 
				ptrTemp = ptrTemp->ptrNext;           // from the original card number (customer) 
				ptrTemp->accountNumber = temp; 
				getline(fin, ptrTemp->firstName, ','); 
				getline(fin, ptrTemp->lastName, ','); 
				getline(fin, ptrTemp->itemName, ','); 
				fin >> ptrTemp->cost; 
				getline(fin, temp, ','); 
				getline(fin, ptrTemp->itemDescription, ','); 
				fin >> ptrTemp->qty; 
				getline(fin, temp); 
				ptrTemp->ptrNext = 0;  // the pointer to the next node is set to NULL 
			} 
			else 
			{ 
				i++; 
				customer[i] = new purchase;     // memory is dynamicly alocated 
				ptrTemp = customer[i];          // for new customer 
				ptrTemp->accountNumber = temp; 
				getline(fin, ptrTemp->firstName, ','); 
				getline(fin, ptrTemp->lastName, ','); 
				getline(fin, ptrTemp->itemName, ','); 
				fin >> ptrTemp->cost; 
				getline(fin, temp, ','); 
				getline(fin, ptrTemp->itemDescription, ','); 
				fin >> ptrTemp->qty; 
				getline(fin, temp); 
			} 
		} 
		fin.close(); 
	} 
	else 
	{ 
		cout << "ERROR: unable to open input file" << endl; 
	} 
	return (i+1);
}

void printRecords(purchase *customer[], int Customers) 
{
	int total = 0;
	purchase *p;
	for(int i=0; i<Customers; i++) 
	{
		cout << endl << (i+1) << ".) " << customer[i]->firstName << " " 
			<< customer[i]->lastName << endl;
		for(p=customer[i]; p; p=p->ptrNext)
		{
			total++; // totals up the number of prchases for selected customer
		}
		p=customer[i];
		cout << endl << p->firstName << " " << p->lastName << " has made " << total 
			<< " purchases on charge card number " << p->accountNumber << endl 
			<< "___________________________________________________\n"
			<< "Quantity   Item Name        Cost      Item Description \n";
		while(p) // lists all puchases linked to that customer
		{
			cout.precision(2);
			cout << fixed << "    " << setiosflags(ios::left) << setw(8) << p->qty 
				<< setw(16) << p->itemName << setw(10) << p->cost 
				<< p->itemDescription << endl;
			p=p->ptrNext;
		}
	}
}

/*void read(ifstream& fin, purchase* customer[]) // reads user input via .txt file
{
	// NOTE: use the "->" instead of dot notation for arrays thats what it wants.
	int count=0;
	int num[10];
	while (fin.good())
	{
//		fin>>customer[count]->accountNumber;
fin>>num[count];//customer[0]->accountNumber;
		//cout << num[count];
		//cout << count<<endl;
		count++;// keeps track of array element and how many times its looped
	}
}

 2)	Read in the file into the following:
Create an ‘array’ of pointers, of the purchase structure type, called ‘customer’.
Note:  ‘customer’ is an array of pointers, not a pointer variable to an array.
3)	Read in the purchase file into the customer array, each member in the array is a different customer, each customer member has a sprouting linked List of purchase. 
NOTE: Each element of the array can have its own linked list hanging from it.

Dynamically create a purchase structure for each purchase record read from the file.
Sequentially read each element of the ‘array’.
	Check to see if that charge card is already in the ‘array’
		If yes, then add the purchase to the ‘linked list’ hanging off that array element
		If not, then add the purchase record to the next unused ‘array’ element

Close file after read last record.

4)	Create individual functionality to: 
a.	Add a purchase to the ‘linked list’ for an existing person, found at an array index
b.	Add a purchase to the array for an new person
c.	Find if customer name is in list
d.	Find if charge number is in list
e.	List Names of Purchasers
f.	List of Charge Card Numbers 
g.	List all purchase for a selected Name
h.	Total amount purchased from one customer
i.	Total amount purchased from all customer
j.	Other function as required.
Note:  functionalize your program.

5)	Save updates to new file called ‘purchaseUpdates’

*/