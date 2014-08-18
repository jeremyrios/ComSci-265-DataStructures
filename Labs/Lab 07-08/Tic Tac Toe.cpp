// Lab 78
// Exersise 2 Tic Tac Toe
// Author: Jeremy Rios-Martinez  
// Course: COMSC 265

#include "stdafx.h"
#include <iostream> 
using namespace std;

// Prtotypes
bool decisionEngine(char board[][3], int moves);
void displayBoard(char board[][3]);
void makeMove(char board[][3], int whoseTurnItIs);
int checkForWinner(char board[][3]);
bool playAgain();

void main()
{ // Declarations
  bool loop = true, gameOn;
  int decision, whoseTurnItIs, i,j;
  char board[3][3];
  while(loop)
  {
    decision=0;
    whoseTurnItIs=0;
    gameOn = true;
    board[0][0] = '1';
    board[0][1] = '2';
    board[0][2] = '3';
    board[1][0] = '4';
    board[1][1] = '5';
    board[1][2] = '6';
    board[2][0] = '7';
    board[2][1] = '8';
    board[2][2] = '9';
    displayBoard(board);
    while(gameOn)
    {
      makeMove(board, whoseTurnItIs);
      whoseTurnItIs++;
      gameOn = decisionEngine(board, whoseTurnItIs);
    }
    loop = playAgain();
  }
  system("pause");
}

void makeMove(char board[][3], int whoseTurnItIs)
{
  bool vaildPosition = false;
  int positionNum, row, column;
  while(!vaildPosition)
  {
    cout << endl << endl << "Enter the number of the position" 
      << endl << "where you wish to make your play: "; 
    cin >> positionNum;
    row = (positionNum-1) / 3; // (positionNumber) (1,2,3) == 0, (4,5,6) == 1, (7,8,9) == 2
    column = (positionNum-1) % 3; // (positionNumber) (1,4,7) == 0, (2,5,8) == 1, (3,6,9) == 2
    if(positionNum < 1 || positionNum > 9)
    {
      cout << "\nIm sorry but that is not a valid option!" << endl;
      displayBoard(board);
    }
    else
    {
      if((board[row][column] == 'X') || (board[row][column] == 'O'))
      {
        cout << "\nIm sorry but position has already been taken" << endl;
        displayBoard(board);
      }
      else
      {
        vaildPosition = true;
      }
    }
  }
  if(whoseTurnItIs % 2 == 0) // Even == X's turn, Odd == O's turn
  {    
    board[row][column] = 'X'; // Replaces chosen position number with an X
  }
  else
  {    
    board[row][column] = 'O'; // Replaces chosen position number with an O
  }
}

bool decisionEngine(char board[][3], int moves)
{
  int winner;
  bool gameOn = true;
  displayBoard(board);

  winner = checkForWinner(board);

  if(winner == 1 || winner == 2)
  {
    gameOn = false;
  }
  if(winner != 1 && winner!=2 && moves==9)
  {
    cout << "\n\nCats game, no winner" << endl;
    gameOn = false;
  }
  return (gameOn);
}

void displayBoard(char board[][3])
{
  int i, j;
  cout << endl;
  for(i=0; i<3; i++)
  {
    for(j=0; j<3; j++)
    {
      if(j<2)
      {
        cout << " " << board[i][j] << " |";
      }
      else
      {
        cout << " " << board[i][j];
      }
    }
    if(i<2)
    {
      cout << endl;
      cout << "---|---|---" << endl;
    }
  }
}

int checkForWinner(char board[][3])
{
  int winner = 0;

  if(((board[0][0]=='X') && (board[1][1]=='X') && (board[2][2]=='X')) ||
    ((board[0][0]=='X') && (board[0][1]=='X') && (board[0][2]=='X')) ||
    ((board[0][0]=='X') && (board[1][0]=='X') && (board[2][0]=='X')) ||
    ((board[2][0]=='X') && (board[2][1]=='X') && (board[2][2]=='X')) ||
    ((board[1][0]=='X') && (board[1][1]=='X') && (board[1][2]=='X')) ||
    ((board[0][1]=='X') && (board[1][1]=='X') && (board[2][1]=='X')) ||
    ((board[0][2]=='X') && (board[1][2]=='X') && (board[2][2]=='X')) ||
    ((board[0][2]=='X') && (board[1][1]=='X') && (board[2][0]=='X')))
  {
    cout << endl << endl << "Player X wins" << endl;
    winner = 1;
  }

  if(((board[0][0]=='O') && (board[1][1]=='O') && (board[2][2]=='O')) ||
    ((board[0][0]=='O') && (board[0][1]=='O') && (board[0][2]=='O')) ||
    ((board[0][0]=='O') && (board[1][0]=='O') && (board[2][0]=='O')) ||
    ((board[2][0]=='O') && (board[2][1]=='O') && (board[2][2]=='O')) ||
    ((board[1][0]=='O') && (board[1][1]=='O') && (board[1][2]=='O')) ||
    ((board[0][1]=='O') && (board[1][1]=='O') && (board[2][1]=='O')) ||
    ((board[0][2]=='O') && (board[1][2]=='O') && (board[2][2]=='O')) ||
    ((board[0][2]=='O') && (board[1][1]=='O') && (board[2][0]=='O')))
  {
    winner = 2;
    cout <<endl << endl << "Player O wins" << endl;
  }
  return winner;
}

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