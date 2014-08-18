// Assignment 17 
// 15 Sum Game
// Author: Jeremy Rios-Martinez  
// Course: COMSC 265

#include "stdafx.h"
#include <iostream> 
using namespace std;

// Constants
const int ROW = 3;
const int COLUMN = 3;

// Prtotypes
void displayBoard(int *pBoard[][COLUMN], int options[], int whoseTurnItIs);
void makeMove(int *pBoard[][COLUMN], int options[]);
bool decisionEngine(int *pBoard[][3], int options[], int whoseTurnItIs);
bool checkForWinner(int *pBoard[][COLUMN]);
bool playAgain();

// Main Function
void main()
{ 
	bool loop = true, gameOn;
	int decision, whoseTurnItIs, i, j;
	int options[(ROW*COLUMN)] = {1,2,3,4,5,6,7,8,9};
	int board[ROW][COLUMN] = {0};
	int *pBoard[ROW][COLUMN];
	for(i=0; i<ROW; i++)
	{
		for(j=0; j<COLUMN; j++)
		{
			pBoard[i][j] = &board[i][j];
		}
	}
	while(loop)
	{
		decision=0;
		whoseTurnItIs=0;
		gameOn = true;
		displayBoard(pBoard, options, whoseTurnItIs);
		while(gameOn)
		{
			makeMove(pBoard, options);
			whoseTurnItIs++;
			gameOn = decisionEngine(pBoard, options, whoseTurnItIs);
		}
		loop = playAgain();
	}
	system("pause");
}

// funtion to display board 
void displayBoard(int *pBoard[][COLUMN], int options[], int whoseTurnItIs)
{
	int i, j, k;
	cout << endl << "Player " << (whoseTurnItIs%2)+1 << "'\s turn" << endl
		 << "Options: [";
	for(k=0; k<(ROW*COLUMN); k++)
	{ 
		if(k<(ROW*COLUMN)-1)
		{
			if(options[k])
			{
				cout << options[k] << "][";
			}
			else
			{
				cout << " ][";
			}
		}
		else
		{
			if(options[k])
			{
				cout << options[k] << "]" << endl << endl;
			}
			else
			{
				cout << "]" << endl << endl;
			}
		}
	}
	for(i=0; i<ROW; i++)
	{
		for(j=0; j<COLUMN; j++)
		{
			if(j<COLUMN-1)
			{
				if(*pBoard[i][j])
				{
					cout << " " << (*pBoard[i][j]) << " |";
				}
				else
				{
					cout << "   |";
				}
			}
			else
			{
				if(*pBoard[i][j])
				{
					cout << " " << (*pBoard[i][j]) << endl;
				}
				else
				{
					cout << "  " << endl;
				}
			}
		}
		if(i<ROW-1)
		{
			cout << "---|---|---" << endl;
		}
	}
}

// function to get operator input
void makeMove(int *pBoard[][COLUMN], int options[])
{
	bool validOption = false, vaildPosition = false;
	int number, row, column;
	while(!validOption)
	{
		cout << endl << "Please select the number you wish to play" << endl 
			 << "from the list of available options: ";
		cin >> number;
		   // checks if entered number is a vaild and availible option
		if(number<1 || number>(ROW*COLUMN) || !(options[number-1]))
		{
			cout << "\nIm sorry but that is not a valid option!" << endl
				 << "Please try again" << endl;
		}
		else
		{   // when a number is selected it is replaced with a 0 so it is no longer displyed 
			options[number-1]=0; 
			validOption = true;
		}
	}
	while(!vaildPosition)
	{
		cout << endl << endl << "Enter the row and column where" << endl
			 << "you wish to make your play: "; 
		cin >> row >> column;
		// checks if entered values are within bounds of the 2D array
		if(row<1 || row>ROW || column<1 || column>COLUMN)
		{ 
			cout << "\nIm sorry but that is not a valid option!" << endl
				 << "Please try again" << endl;
		}
		else
		{   // checks if a number has already been played in selected row & column
			if(*pBoard[row-1][column-1]) 
			{
				cout << "\nIm sorry but position has already been taken" << endl;
			}
			else
			{
				*pBoard[row-1][column-1] = number; // assigns # to 2D int array
				vaildPosition = true;
			}
		}
	}
}

// decide if play continues or if a player has entered a winning combination
bool decisionEngine(int *pBoard[][3], int options[], int whoseTurnItIs)
{
	bool winner;
	bool gameOn = true;
	displayBoard(pBoard, options, whoseTurnItIs);
	winner = checkForWinner(pBoard);
	if(winner) // if winner found 
	{
		gameOn = false;
		if(whoseTurnItIs%2) // determines winner by who played last
		{
			cout << endl << "***  GAME OVER  ***  Player 1 Wins  ***";
		}
		else
		{
			cout << endl << "***  GAME OVER  ***  Player 2 Wins  ***";
		}
	} // if no winner and all posible moves have been played
	if(!winner && whoseTurnItIs == (ROW*COLUMN))  
	{
		cout << "\n\nCats game, no winner" << endl;
		gameOn = false;
	}
	return (gameOn);
}

// All posible winning combinations
bool checkForWinner(int *pBoard[][COLUMN])
{
	if( (((*pBoard[0][0])+(*pBoard[1][1])+(*pBoard[2][2])) == 15) ||
		(((*pBoard[0][0])+(*pBoard[0][1])+(*pBoard[0][2])) == 15) ||
		(((*pBoard[0][0])+(*pBoard[1][0])+(*pBoard[2][0])) == 15) ||
		(((*pBoard[2][0])+(*pBoard[2][1])+(*pBoard[2][2])) == 15) ||
		(((*pBoard[1][0])+(*pBoard[1][1])+(*pBoard[1][2])) == 15) ||
		(((*pBoard[0][1])+(*pBoard[1][1])+(*pBoard[2][1])) == 15) ||
		(((*pBoard[0][2])+(*pBoard[1][2])+(*pBoard[2][2])) == 15) ||
		(((*pBoard[0][2])+(*pBoard[1][1])+(*pBoard[2][0])) == 15)    )
	{
		return true;
	}
	return false;
}
 
// function determines if operator wishes to play again
bool playAgain()
{
	char answer;
	bool validAnswer;
	cout << endl << endl << "Would you like to play again? (Y or N): ";    
	cin >> answer;
	if (islower(answer)) // checks if user char input is lower case
	{
		answer = toupper(answer); // if so is changes it to uppercase
	}
	validAnswer = (answer == 'Y' || answer == 'N'); // checks if that char input is a valid choice
	while(!validAnswer)
	{
		cout << endl << endl << "Your answer was not Y or N. Please try again." 
			<< endl << "Would you like to play again? (Y or N): ";
		cin >> answer;
		if (islower(answer)) // checks if user char input is lower case
		{
			answer = toupper(answer); // if so is changes it to uppercase
			validAnswer = (answer == 'Y' || answer == 'N'); // checks if that char input is a valid choice
		}
	}
	if(answer == 'Y') // User has chosen to run program again 
	{                 // so loop varible in main() will remain true
		return validAnswer;
	}
	else
	{                       // User has chosen not to run program again
		return !validAnswer;  // so loop varible in main() will now be false
	}                    
}
