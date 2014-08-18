
	// Jeremy Rios-Martinez
	// COMSC 265
	// LAb 12-13-14


#include "stdafx.h"
#include <iostream> 
#include <fstream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
	using namespace std;

// Constants
const int MAX_CUSTOMERS = 15;
const string inputFile("E:\\Computer Programing\\COMSC 265\\Labs\\Lab 1213\\CutomerPurchases.txt");
const string saveFile("E:\\Computer Programing\\COMSC 265\\Labs\\Lab 1213\\purchaseUpdates.txt");

// Type Descriptions
struct purchase
{
	string accountNumber;
	string firstName;
	string lastName;
	string itemName;
	double cost;
	string itemDescription;
	int quantity;
	purchase *ptrNext;
	purchase *ptrPrev;
};


// Prototypes
int readInFile(purchase *ptrCustomer[]);
void mainLoop(purchase *ptrCustomer[], int numOfCustomers);
void addPurchase4existingCustomer(purchase *ptrCustomer[], int numOfCustomers);
int addNewCustomerAndPurchase(purchase *ptrCustomer[], int numOfCustomers);
void findCustomerName(purchase *ptrCustomer[], int numOfCustomers);
void findChargeCardNumber(purchase *ptrCustomer[], int numOfCustomers);
void listCusomers(purchase *ptrCustomer[], int numOfCustomers);
void listChargeCardNumbers(purchase *ptrCustomer[], int numOfCustomers);
void listPurchases4selectedName(purchase *ptrCustomer[], int numOfCustomers, int customer);
void totalPurchaseAmount4selectedName(purchase *ptrCustomer[], int numOfCustomers);
void totalPurchaseAmount4allNames(purchase *ptrCustomer[], int numOfCustomers);
void updateFile(purchase *ptrCustomer[], int numOfCustomers);
int whichCustomer(purchase *ptrCustomer[], int numOfCustomers);
string upperCase(string str);
void sortCustomersByName(purchase *ptrCustomer[],  int numOfCustomers);
void sortCustomersPurchases(purchase *ptrCustomer[],  int numOfCustomers);
template <class T> 
void swapFields(T &a, T &b);

// Main Function
int main()
{
	int numOfCustomers = 0;
	purchase *ptrCustomer[MAX_CUSTOMERS];

	numOfCustomers = readInFile(ptrCustomer);

	mainLoop(ptrCustomer, numOfCustomers);

	system("pause");
	return 0;
}

// Routines
int readInFile(purchase *ptrCustomer[])
{
	int i=0;
	string temp;
	ptrCustomer[i] = new purchase;        // dynamiclly allocates memory 
	purchase *ptrTemp = ptrCustomer[i];   // for first spot in array stucture
	ifstream fin(inputFile);
	if(fin.is_open())
	{
		getline(fin, ptrTemp->accountNumber, ',');          // Reads in comma (,) 
		getline(fin, ptrTemp->firstName, ',');              // seperated data from a file
		ptrTemp->firstName = upperCase(ptrTemp->firstName); // and tokenises the data into
		getline(fin, ptrTemp->lastName, ',');               // respective stucture varaibles
		ptrTemp->lastName = upperCase(ptrTemp->lastName); 
		getline(fin, ptrTemp->itemName, ',');             
		ptrTemp->itemName = upperCase(ptrTemp->itemName); 
		fin >> ptrTemp->cost;
		getline(fin, temp, ',');
		getline(fin, ptrTemp->itemDescription, ',');
		ptrTemp->itemDescription = upperCase(ptrTemp->itemDescription); 
		fin >> ptrTemp->quantity;
		getline(fin, temp);
		while(!fin.eof())                           // Until end of file is reached
		{                                           
			getline(fin, temp, ',');                  
			if (temp == ptrTemp->accountNumber)       // if the next card number is the 
			{                                         // same as the prev
				ptrTemp->ptrNext = new purchase;        // memory is dynamically created 
				ptrTemp->ptrNext->ptrPrev = ptrTemp;    // in a linked list fashon sprouting 
				ptrTemp = ptrTemp->ptrNext;             // from the original card number (customer)
				ptrTemp->accountNumber = temp;
				getline(fin, ptrTemp->firstName, ',');             
				ptrTemp->firstName = upperCase(ptrTemp->firstName); 
				getline(fin, ptrTemp->lastName, ',');               
				ptrTemp->lastName = upperCase(ptrTemp->lastName); 
				getline(fin, ptrTemp->itemName, ',');             
				ptrTemp->itemName = upperCase(ptrTemp->itemName); 
				fin >> ptrTemp->cost;
				getline(fin, temp, ',');
				getline(fin, ptrTemp->itemDescription, ',');
				ptrTemp->itemDescription = upperCase(ptrTemp->itemDescription); 
				fin >> ptrTemp->quantity;
				getline(fin, temp);
				ptrTemp->ptrNext = 0;  // the pointer to the next node is set to NULL
			}
			else
			{
				i++;
				ptrCustomer[i] = new purchase;     // memory is dynamicly alocated 
				ptrTemp = ptrCustomer[i];          // for new customer
				ptrTemp->accountNumber = temp;
				getline(fin, ptrTemp->firstName, ',');              // seperated data from a file
				ptrTemp->firstName = upperCase(ptrTemp->firstName); // and tokenises the data into
				getline(fin, ptrTemp->lastName, ',');               // respective stucture varaibles
				ptrTemp->lastName = upperCase(ptrTemp->lastName); 
				getline(fin, ptrTemp->itemName, ',');             
				ptrTemp->itemName = upperCase(ptrTemp->itemName); 
				fin >> ptrTemp->cost;
				getline(fin, temp, ',');
				getline(fin, ptrTemp->itemDescription, ',');
				ptrTemp->itemDescription = upperCase(ptrTemp->itemDescription); 
				fin >> ptrTemp->quantity;
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

void mainLoop(purchase *ptrCustomer[], int numOfCustomers)
{
	int option;
	bool loop = true;
	while(loop)
	{
		option = 0;
		cout << "\n                   Main Menu\n"
			<< "____________________________________________________\n"
			<< " 1.) Add a purchase for an existing customer\n"
			<< " 2.) Add a new customer and purchase\n"
			<< " 3.) Find if customer name is in list\n"
			<< " 4.) Find if charge number is in list\n"
			<< " 5.) List Cusomers\n"
			<< " 6.) List Charge Card Numbers\n" 
			<< " 7.) List all purchases for a selected Name\n"
			<< " 8.) Print Total amount purchased from a select customer\n"
			<< " 9.) Print Total amount purchased from all customers\n"
			<< "10.) Sort Customer Names Alphabeticaly\n"
			<< "11.) Sort Customer Purchases Alphabeticaly\n"
			<< "12.) Exit\n\n"
			<< "Entry: ";
		fflush(stdin);
		cin >> option;
		switch(option)
		{
		case 1: // Add a purchase for an existing customer
			addPurchase4existingCustomer(ptrCustomer, numOfCustomers);
			break;
		case 2: // Add a new customer and purchase
			numOfCustomers = addNewCustomerAndPurchase(ptrCustomer, numOfCustomers);
			break;
		case 3: // Find if customer name is in list
			findCustomerName(ptrCustomer, numOfCustomers);
			break;
		case 4: // Find if charge number is in list
			findChargeCardNumber(ptrCustomer, numOfCustomers);
			break;
		case 5: // List Cusomers
			cout << endl << "                Customers"
				<< endl << "_________________________________________\n";
			listCusomers(ptrCustomer, numOfCustomers);
			break;
		case 6: // List Charge Card Numbers
			cout << endl << "           Charge Card Numbers"
				<< endl << "_________________________________________\n";
			listChargeCardNumbers(ptrCustomer, numOfCustomers);
			break;
		case 7: // List all purchases for a selected Name
			listPurchases4selectedName(ptrCustomer, numOfCustomers, MAX_CUSTOMERS);
			break;
		case 8: // Print Total amount purchased from a select customer
			totalPurchaseAmount4selectedName(ptrCustomer, numOfCustomers);
			break;
		case 9: // Print Total amount purchased from all customers
			totalPurchaseAmount4allNames(ptrCustomer, numOfCustomers);
			break;
		case 10:
			sortCustomersByName(ptrCustomer, numOfCustomers);
			listCusomers(ptrCustomer, numOfCustomers);
			break;
		case 11:
			sortCustomersPurchases(ptrCustomer,  numOfCustomers);
			break;
		case 12: // EXIT Program
			loop = false;
			break;
		}
	}
}

// Options

// Add a purchase to the ‘linked list’ for an existing person, found at an array index
void addPurchase4existingCustomer(purchase *ptrCustomer[], int numOfCustomers) 
{
	int i, customer=0;
	purchase *ptrTemp;
	customer = whichCustomer(ptrCustomer, numOfCustomers); // operator choses customer
	ptrTemp = ptrCustomer[customer]; // operator defines 
	while(ptrTemp->ptrNext)   
	{                         
		ptrTemp = ptrTemp->ptrNext; // advances to the end of linked list
	}
	ptrTemp->ptrNext = new purchase;     // dynamiclally aloocates memory for new purchase
	ptrTemp->ptrNext->ptrPrev = ptrTemp; // linked to the end of customer selected 
	ptrTemp = ptrTemp->ptrNext;
	ptrTemp->ptrNext = 0;

	ptrTemp->accountNumber = ptrTemp->ptrPrev->accountNumber; // sets card #, first name,  
	ptrTemp->firstName = ptrTemp->ptrPrev->firstName;         // and last name to that of 
	ptrTemp->lastName = ptrTemp->ptrPrev->lastName;           // prev node
	cout << "Please enter the Name of Item purchased: ";
	fflush(stdin);
	cin >> ptrTemp->itemName;                           // Then gets user defined inputs for
	ptrTemp->itemName = upperCase(ptrTemp->itemName);  
	cout << "Please enter the cost of the item: ";      // item name, cost, item description 
	fflush(stdin);                                      // and quanitty
	cin >> ptrTemp->cost;
	cout << "Please enter the item description: ";
	fflush(stdin);
	getline(cin, ptrTemp->itemDescription);
	ptrTemp->itemDescription = upperCase(ptrTemp->itemDescription); 
	cout << "How many were purchased: ";
	fflush(stdin);
	cin >> ptrTemp->quantity; // lists all purchases for that customer to confirm user inputs
	listPurchases4selectedName(ptrCustomer, numOfCustomers, customer); 	
	updateFile(ptrCustomer, numOfCustomers);   // prints all stored data to a file		
}

// Add a purchase to the array for an new person
int addNewCustomerAndPurchase(purchase *ptrCustomer[], int numOfCustomers) 
{
	purchase *p;
	ptrCustomer[numOfCustomers] = new purchase; // dynamically aloocates memory 
	p = ptrCustomer[numOfCustomers];            // for a new customer
	cout << "Please enter the customer's first name: ";
	fflush(stdin);
	cin >> p->firstName;
	cout << "Please enter the customer's last name: ";
	fflush(stdin);
	cin >> p->lastName;
	cout << "Please enter " << p->firstName << " " << p->lastName << "'s account number: ";
	fflush(stdin);
	cin >> p->accountNumber;
	cout << "Please enter the name of item purchased: ";
	fflush(stdin);
	cin >> p->itemName;                              // gets user inputs for  
	cout << "Please enter the item cost: ";          // first name, last name, card number,
	fflush(stdin);                                   // item name, cost, item description, 
	cin >> p->cost;                                  // and quanitty
	cout << "Please enter the quantity purchased: ";
	fflush(stdin);
	cin >> p->quantity;
	cout << "Please enter the item description: ";
	fflush(stdin);
	getline(cin, p->itemDescription);
	p->ptrNext = 0;
	p->ptrPrev = 0;
	numOfCustomers++;  // lists all purchases for that customer to confirm user inputs
	listPurchases4selectedName(ptrCustomer, numOfCustomers, (numOfCustomers-1));
	updateFile(ptrCustomer, numOfCustomers); // prints all stored data to a file
	return numOfCustomers;
}

//	Find if customer name is in list
void findCustomerName(purchase *ptrCustomer[], int numOfCustomers) 
{
	int i, option;
	bool foundIt = false;
	string enteredName, customerName;
	cout << endl << "Enter the full name of the customer you are looking for: ";
	fflush(stdin);
	getline(cin, enteredName);             // get name operator is looking for and
	enteredName = upperCase(enteredName); // lowercase it for comparing purposes
	for(i=0; i<numOfCustomers && !foundIt; i++) 
	{ 
		customerName = ptrCustomer[i]->firstName + ' ' + ptrCustomer[i]->lastName;
		customerName = upperCase(customerName); // compares operator inputed name to names 
		if(customerName == enteredName)          // pointed to by *struct array
		{
			cout << endl << ptrCustomer[i]->firstName << " " 
				<< ptrCustomer[i]->lastName << "'s card number is: " 
				<< ptrCustomer[i]->accountNumber << endl;
			foundIt = true;
		}
	}
	if(!foundIt)
	{
		cout << endl << "Im sorry but currently there is not a customer on file with that name. "
			<< endl;
	}
}

//	Find if charge number is in list
void findChargeCardNumber(purchase *ptrCustomer[], int numOfCustomers) 
{
	bool foundIt = false;
	int i, cardNumber, customerCardNumber;
	cout << endl << "Enter the card number you are looking for: ";
	fflush(stdin);
	cin >> cardNumber;                        // get name operator is looking for 
	for(i=0; i<numOfCustomers && !foundIt; i++)
	{ 
		customerCardNumber = atoi(ptrCustomer[i]->accountNumber.c_str());
		if(customerCardNumber == cardNumber)  // compares custumer card numbers on file 
		{                                     // to name operator is looking for
			cout << endl << "That card Number belongs to " << ptrCustomer[i]->firstName 
				<< " " << ptrCustomer[i]->lastName << endl;
			foundIt = true;
		}
	}
	if(!foundIt)
	{
		cout << endl << "Im sorry but currently there is not a customer with that card number on file. "
			<< endl;
	}
}

//	List Names of Purchasers
void listCusomers(purchase *ptrCustomer[], int numOfCustomers) 
{
	for(int i=0; i<numOfCustomers; i++) 
	{
		cout << (i+1) << ".) " << ptrCustomer[i]->firstName << " " 
			<< ptrCustomer[i]->lastName << endl;
	}
}

//	List of Charge Card Numbers 
void listChargeCardNumbers(purchase *ptrCustomer[], int numOfCustomers) 
{
	for(int i=0; i<numOfCustomers; i++)
	{
		cout << (i+1) << ".) " << ptrCustomer[i]->accountNumber << endl;
	}
}

// List all purchases for a selected Name
void listPurchases4selectedName(purchase *ptrCustomer[], int numOfCustomers, int customer) 
{
	int totalPurchases = 0;
	purchase *p;
	if(customer == MAX_CUSTOMERS)
	{
		customer = whichCustomer(ptrCustomer, numOfCustomers);
	}
	for(p=ptrCustomer[customer]; p; p=p->ptrNext)
	{
		totalPurchases++; // totals up the number of prchases for selected customer
	}
	p=ptrCustomer[customer];
	cout << endl << p->firstName << " " << p->lastName << " has made " << totalPurchases 
		<< " purchases on charge card number " << p->accountNumber << endl 
		<< "___________________________________________________\n"
		<< "Quantity   Item Name        Cost      Item Description \n";
	while(p) // lists all puchases linked to that customer
	{
		cout.precision(2);
		cout << fixed << "    " << setiosflags(ios::left) << setw(8) << p->quantity 
			<< setw(16) << p->itemName << setw(10) << p->cost 
			<< p->itemDescription << endl;
		p=p->ptrNext;
	}
}

// Total amount purchased from one customer
void totalPurchaseAmount4selectedName(purchase *ptrCustomer[], int numOfCustomers) 
{
	int i, customer;
	purchase *p;
	double totalPurhaseAmmount = 0;
	customer = whichCustomer(ptrCustomer, numOfCustomers);
	for(p=ptrCustomer[customer]; p; p=p->ptrNext)
	{
		totalPurhaseAmmount += (double)(p->cost * p->quantity);
	}
	p=ptrCustomer[customer];
	cout << endl << "The total Purchase ammount for " << p->firstName 
		<< " " << p->lastName << " is: $" << fixed << setprecision(2)
		<< totalPurhaseAmmount << endl;
}

//	Total amount purchased from all customers
void totalPurchaseAmount4allNames(purchase *ptrCustomer[], int numOfCustomers) 
{
	int i, j;
	double totalPurhaseAmmount=0;
	purchase *p;
	for(i=0; i<numOfCustomers; i++)
	{
		for(p=ptrCustomer[i]; p; p=p->ptrNext)
		{
			totalPurhaseAmmount += (double)(p->cost * p->quantity);
		}
	}
	cout << endl << "The total Purchase ammount for all customers is: $" << fixed << setprecision(2)
		<< totalPurhaseAmmount << endl;
}

// write data in memory to an output file
void updateFile(purchase *ptrCustomer[], int numOfCustomers)
{
	int i;
	purchase *ptrTemp;
	ofstream fout(saveFile);
	if(fout.is_open())
	{
		for(i=0; i<numOfCustomers; i++) // write all customersand purchases 
		{                               // to a comma (,) seperated output file
			ptrTemp = ptrCustomer[i];
			while(ptrTemp)
			{
				fout.precision(2);
				fout << fixed <<  ptrTemp->accountNumber << "," << ptrTemp->firstName << ","
					<< ptrTemp->lastName << "," << ptrTemp->itemName << ","
					<< ptrTemp->cost << "," << ptrTemp->itemDescription 
					<< "," << ptrTemp->quantity << endl;
				ptrTemp = ptrTemp->ptrNext;
			}
		}
	}
	else
	{
		cout << "ERROR unable to open output file\n";
	}
}

// Determine the customer that operator choses
int whichCustomer(purchase *ptrCustomer[], int numOfCustomers)
{
	int option;
	cout << "             For which customer?\n"
		<< "__________________________________________________\n";
	listCusomers(ptrCustomer, numOfCustomers);
	cout << endl << "Entry: ";
	fflush(stdin);
	cin >> option; // operator selects customer it wants list purchases for
	while(option<1 || option>numOfCustomers) // incase operator makes invalid chose
	{
		cout << endl << "Im sorry but that is not a valid option please try again\n"
			<< "________________________________________________________\n";
		listCusomers(ptrCustomer, numOfCustomers);
		cout << endl << "Entry: ";
		fflush(stdin);
		cin >> option; // operator selects customer it wants list purchases for
	}
	return --option;
}

// string to UpperCase function
string upperCase(string str)
{
	for(int i=0; i<str.length(); i++)
	{
		if(islower(str[i]))
		{
			str[i] = toupper(str[i]);
		}
	}
	return str;
}

// Function to sort Names alphbeticaly (selection sort)
void sortCustomersByName(purchase *ptrCustomer[],  int numOfCustomers)
{
	{
		int i, j, biggest;
		purchase *ptrTemp;
		string customerName1, customerName2;
		for (i=(numOfCustomers-1); i>0; i--)
		{
			biggest = 0;                 // initialize to subscript of first element
			for (j=1; j<=i; j++)         // locate biggest between positions 1 and i.
			{
				customerName1 = ptrCustomer[j]->firstName + " " + ptrCustomer[j]->lastName;
				customerName2 = ptrCustomer[biggest]->firstName + " " + ptrCustomer[biggest]->lastName;
				if (customerName1.compare(customerName2) > 0) // compare stings 
				{
					biggest=j;
				}
			}
			ptrTemp = ptrCustomer[biggest];   // Swap biggest found with element in position i.
			ptrCustomer[biggest] = ptrCustomer[i];
			ptrCustomer[i] = ptrTemp;
		}
	}
}

// Function to sort customer Purchases Alphabetically (bubble sort)
void sortCustomersPurchases(purchase *ptrCustomer[],  int numOfCustomers)
{
	bool swap;
	purchase *p;
	for (int i=0; i<numOfCustomers; i++) // runs sort for each customer
	{
		do
		{
			swap = false;
			for (p=ptrCustomer[i]; p->ptrNext; p=p->ptrNext)        // sets p to first node of linked
			{                                                       // list and compares item names 
				if (p->itemName.compare(p->ptrNext->itemName) > 0)  // with the item name of next node  
				{                                                   // if p is bigger, the itemName,
					swapFields(p->itemName, p->ptrNext->itemName);  // cost, itemDescription, and quantity
					swapFields(p->cost, p->ptrNext->cost);          // fields are swaped.
					swapFields(p->itemDescription, p->ptrNext->itemDescription);
					swapFields(p->quantity, p->ptrNext->quantity);
					swap = true;
				}
			}
		} while (swap);
	}
	cout << endl << "Customer purchases have been sorted" << endl;
}

// Template swap function 
template <class T> 
void swapFields(T &a, T &b)
{
  T temp;

  temp = a;
  a = b;
  b = temp;
}
