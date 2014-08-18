// Lab 78
// Exersise 1
// Author: Jeremy Rios-Martinez  
// Course: COMSC 265

#include "stdafx.h"
#include <iostream> 
#include <math.h>
#include <ctype.h>
using namespace std;

const int TABLE_ROWS = 11;
const int TABLE_COLUMNS = 11;

void createTable(int intArray[][TABLE_COLUMNS]);
void printTable(int intArray[][TABLE_COLUMNS]);
void mainLoop(int intArray[][TABLE_COLUMNS]);

int main ()
{
  int intArray[TABLE_ROWS][TABLE_COLUMNS];

  createTable(intArray);
  printTable(intArray);
  mainLoop(intArray);

  cout << endl;
  system("pause");
  return 0;
}

//Function that creates table using a 2D array
void createTable(int intArray[][TABLE_COLUMNS])
{
  int i, j;
  const int zero = 0;
  for (j=0; j<TABLE_COLUMNS; j++) 
  {
    intArray[zero][j] = j; // Sets top row of table (left to right) to 0 -9
    intArray[j][zero] = j; // Sets first column (top to bottom) to 0 - 9
  }
  for(i=1; i<TABLE_ROWS; i++, j++)
  {
    for(j=1; j<TABLE_COLUMNS; j++) // Fills in body of table by multiplying the 
    {                              // row cell with the corresponding column cell
      intArray[i][j] = intArray[zero][j] * intArray[i][zero]; 
    }
  }
}

// Function that simply prints the table
void printTable(int intArray[TABLE_COLUMNS][TABLE_COLUMNS])
{
  int i, j;
  for(i=0; i<TABLE_ROWS; i++)
  {
    for(j=0; j<TABLE_COLUMNS; j++)
    {
      cout.width(2);  
      cout << intArray[i][j] << "  ";
    }
    cout << endl;
  }
}

// Main Loop function
void mainLoop(int intArray[][TABLE_COLUMNS])
{ // Declarations
  int firstNumber, secondNumber;
  char answer = ' ';
  bool loop = true, validAnswer;
  cout << endl << "Pick two integers between 0 - 9 "  
    << endl << "and I will tell you their product. "
    << endl << "1st Number: ";
  while(loop)
  {
    cin >> firstNumber;
    while(firstNumber > 9 || firstNumber < 0) // Tests if user input is between 0 - 9
    {
      cout << endl << "Your 1st number was not between 0 - 9. Please try again: ";
      cin >> firstNumber;
    }
    cout << "2nd Number: ";
    cin >> secondNumber;
    while(secondNumber > 9 || secondNumber < 0) // Tests if user input is between 0 - 9
    {
      cout << endl << "Your 2nd number was not between 0 - 9. Please try again: ";
      cin >> secondNumber;
    }
    cout << endl << "The product of " << firstNumber << " and " << secondNumber
      << " is: " << intArray[firstNumber][secondNumber] << endl // Returns the product of two
      << endl << "Would you like to play again? (Y or N): ";    // user defined inputs and asks
    cin >> answer;                                                 // what to do next
    if (islower(answer)) // checks if user char input is lower case
    {
      answer = toupper(answer); // if so is changes it to uppercase
    }
    validAnswer = (answer == 'Y' || answer == 'N'); // checks if that char input is a valid choice
    while(!validAnswer)
    {
      cout << endl << "Your answer was not Y or N. Please try again." << endl
        << "Would you like to play again? (Y or N): ";
      cin >> answer;
      if (islower(answer)) // checks if user char input is lower case
      {
        answer = toupper(answer); // if so is changes it to uppercase
        validAnswer = (answer == 'Y' || answer == 'N'); // checks if that char input is a valid choice
      }
    }
    if(answer == 'Y') // if user chooses to run again program asks to input 2 new integer varibles
    {
      cout << endl << "Pick your next two integers remember they must be between 0 - 9: "
        << endl << "1st Number: ";
    }
    else
    {
      loop = false;
    }
  }

}