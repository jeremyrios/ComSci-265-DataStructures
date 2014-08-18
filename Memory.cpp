// MEMORY GAME.	
// COMSC 265 Advanced C++
// Final Projet
// Jeremy Rios
// December 8, 2010

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>			
#include <ctype.h>				
#include <time.h>				
#include <windows.h>
#include <iomanip>
using namespace std;
/*********************************************************************************************/

// Constants
const int CARD_HEIGHT = 3;
const int CARD_WIDTH = 8;
const int MAX_ROWS = 8;
const int MAX_COLUMNS = 8;
const int MAX_CARDS = 64;
const int MAX_WORDS = 40;
const int NUM_OF_SUBJECTS = 5;
const int NUM_OF_BOARD_SIZES = 5;
const int TOP_TEN = 10;
const string SUBJECT[NUM_OF_SUBJECTS] = {"Animals", "Cities", "Colleges", "Countries", "States"};
const string BOARD_SIZE[NUM_OF_BOARD_SIZES] = {"4 x 4", "5 x 5", "6 x 6", "7 x 7", "8 x 8"};
const string DIRECTORY("E:\\Computer Programing\\COMSC 265\\Final Project\\");
const string FILE_TYPE(".txt");
/*********************************************************************************************/

// Global Varibles
int boardSize=4, subject=0, offset, initalRow, initalCol, row_1, col_1, row_2, col_2,
    bottomRow, bottomCol, points, numOfRecords[NUM_OF_BOARD_SIZES]={0};

string subjectWords[MAX_WORDS][NUM_OF_SUBJECTS];
string *pSubjectWords[MAX_WORDS][NUM_OF_SUBJECTS];
time_t startTime, currentTime, endTime;
/*********************************************************************************************/

// User Defined Types
struct records
{
  string firstName;
  string lastName;
  string timeToComplete;
  int score;
}highScores[NUM_OF_BOARD_SIZES][TOP_TEN];

struct cardFace
{
  char pixel[CARD_HEIGHT][CARD_WIDTH];
  bool blank;
}blankCard, *pBlankCard;

struct gameCard
{
  cardFace front;
  cardFace back;
};
struct gameBoard 
{
  gameCard card[MAX_ROWS][MAX_COLUMNS];
}board, *pBoard;
/**********************************************************************************************/

// Function Declarations
void readInFiles();
void intro_1();
void intro_2();
void makeBlankCard();
bool mainMenu();
void options();
int forWhichBoard();
void board_size();
void chooseSubject();
void viewHighScores(int board);
void startGame();
void formBackFaceOfCards();
void formFrontFaceOfCards();
void displayParameters();
int getNumOfCards();
void getShuffeledWords(string* pWord[], int &numOfCards);
void displayBoard();
void chooseFisrtCard();
void chooseSecondCard();
void flipCard(int inputRow, int inputColumn);
void checkIfCardsMatch();
void printScore();
bool checkIfDone();
void checkIfHighScore();
void newHighScore(string time);
void saveNewScore();
void delay(long seconds);
void goTo(int x, int y);
void shootTextOnScreen(int x, int y, char ch[]);
void newLine(int numberOfNewLines);
void timer();
string convertInt(int number);
void invalidChoice();
void errorOpeningFile(string);
/*******************************************************************************************/

// MAIN
int main()
{
  bool repeat = true;
  pBlankCard = &blankCard;
  pBoard = &board;
  makeBlankCard();
  readInFiles();
  intro_1();
  intro_2();
  while(repeat)
  {
    repeat = mainMenu();
  }
  system("pause");
  return 0;
}

/********************************************************************************************/

// Function Defintions

//Pre Game Routine
void intro_1()
{
  system("cls");
  shootTextOnScreen(34,30,"COMSC  265");
  shootTextOnScreen(33,30," ");
  shootTextOnScreen(32,32,"Final  Project");
  shootTextOnScreen(31,32," ");
  delay(2000);
  system("cls");
}
/**********************/
void intro_2()
{
  system("cls");
  shootTextOnScreen(24,30,"-<>-<>-<>- MEOMORY -<>-<>-<>-");
  shootTextOnScreen(23,30," ");
  shootTextOnScreen(34,32,"Designed");
  shootTextOnScreen(33,32," ");
  shootTextOnScreen(37,34,"By");
  shootTextOnScreen(36,34," ");
  shootTextOnScreen(29,36,"Jeremy Rios-Martinez");
  shootTextOnScreen(28,36," ");
  delay(4000);
  system("cls");
}
/********************/
void readInFiles()
{
  int i, j, pos, min, sec;
  string fileName, word;
  ifstream fin;
  for (i=0; i<NUM_OF_SUBJECTS; i++)
  {
    fileName = DIRECTORY + SUBJECT[i] + FILE_TYPE;
    fin.open(fileName);
    if (fin.is_open())
    {
      for(j=0; !fin.eof() && j<MAX_WORDS; j++) 
      {
        pSubjectWords[j][i] = &subjectWords[j][i];
        fin >> word;
        *pSubjectWords[j][i] = word;
      }
      fin.close();
    }
    else
    {
      errorOpeningFile(fileName);
    }
  }
  for (i=0; i<NUM_OF_BOARD_SIZES; i++)
  {
    fileName = DIRECTORY + BOARD_SIZE[i] + FILE_TYPE;
    fin.open(fileName);
    if (fin.is_open())
    {
      for(j=0; !fin.eof() && j<TOP_TEN; j++) 
      {
        fin >> highScores[i][j].firstName;
        fin >> highScores[i][j].lastName;
        fin >> highScores[i][j].timeToComplete;
        fin >> highScores[i][j].score;
        numOfRecords[i]++;
      }
      fin.close();
    }
    else
    {
      errorOpeningFile(fileName);
    }
  }
}
/**************************/
void makeBlankCard()
{
  int i, j;
  for(i=0; i<CARD_HEIGHT; i++)
  {
    for(j=0; j<CARD_WIDTH; j++)
    {
      pBlankCard->pixel[i][j] = ' ';
    }
  }
}
/****************************/

//Main Menu
bool mainMenu()
{
  int board =0, option=0, dummy;
  while (option<1 || option>4)
  {
    system("cls");
    newLine(5);
    cout << "\t\t" << "       Main Menu"; 
    newLine(2);
    cout << "\t\t" << "(1) Start Game        " << endl
         << "\t\t" << "(2) Options           " << endl
         << "\t\t" << "(3) View High Scores  " << endl
         << "\t\t" << "(4) Exit              " << endl
         << endl
         << "\t\t" << "Entry: ";
    cin >> option; 
    if (option<1 || option>4)
    {
      invalidChoice();
    }
  }
  switch(option)
  {
  case 1: 
    startGame();
    break;
  case 2: 
    options();
    break;
  case 3:
    board = forWhichBoard();
    viewHighScores(board);
	newLine(5);
    cout << "\t\t" << "Press (1 ENTER) for Main Menu      " << endl
         << endl
         << "\t\t" << "Entry: ";
	cin >> dummy;
    break;
  case 4:
    return false;
  }
}
/***********************/

//Start Game and Sequential Functions
void startGame()
{
  bool finished = false;
  double dif;
  time (&startTime);
  points = 0;
  formBackFaceOfCards();
  formFrontFaceOfCards();
  displayParameters();
  while(!finished)
  {
    displayBoard();
    timer();
    printScore();
    chooseFisrtCard();
    chooseSecondCard();
    checkIfCardsMatch();
    finished = checkIfDone();
  }
}
/************************/
int getNumOfCards()
{
  int numOfCards;
  if(boardSize % 2)
  {
    numOfCards = (boardSize*boardSize)-1;
  }
  else
  {
    numOfCards = (boardSize*boardSize);
  }
  return numOfCards;
}
/***************************/
void formBackFaceOfCards()
{
  int i, j, k, l;
  for(i=0; i<boardSize; i++)
  {
    for (j=0; j<boardSize; j++)
    {
      if((boardSize==5 && (i==2 && j==2)) || (boardSize==7 && (i==3 && j==3)))
      {
        pBoard->card[i][j].back.blank = true;
        for(k=0; k<CARD_HEIGHT; k++)
        {
          for(l=0; l<CARD_WIDTH; l++)
          {
            pBoard->card[i][j].back.pixel[k][l] = pBlankCard->pixel[k][l];
          }
        }
      }
      else
      {
        pBoard->card[i][j].back.blank = false;
        for(k=0; k<CARD_HEIGHT; k++)
        {
          for(l=0; l<CARD_WIDTH; l++)
          {
            if(k==0)
            {
              if(l==0)
              {
                pBoard->card[i][j].back.pixel[k][l] = 201;
              }
              else if(l==(CARD_WIDTH-1))
              {
                pBoard->card[i][j].back.pixel[k][l] = 187;
              }
              else
              {
                pBoard->card[i][j].back.pixel[k][l] = 205;
              }
            }
            else if(k==(CARD_HEIGHT-1))
            {
              if(l==0)
              {
                pBoard->card[i][j].back.pixel[k][l] = 200;					
              }
              else if(l==(CARD_WIDTH-1))
              {
                pBoard->card[i][j].back.pixel[k][l] = 188;
              }
              else
              {
                pBoard->card[i][j].back.pixel[k][l] = 205;
              }
            }
            else 
            {
              if(l==0 || l==(CARD_WIDTH-1))
              {
                pBoard->card[i][j].back.pixel[k][l] = 186;
              }
              else
              {
                pBoard->card[i][j].back.pixel[k][l] = ' ';
              }
            }
          }
        }
      }
    }
  }
}
/**********************************/
void formFrontFaceOfCards()
{
  int i, j, k, l, m, n, length, numOfCards; 
  string* pWord[MAX_CARDS];
  string tempStr;
  numOfCards = getNumOfCards();
  getShuffeledWords(pWord, numOfCards);
  for(i=0; i<boardSize; i++)
  {
    for (j=0; j<boardSize; j++)
    { 
      if((boardSize==5 && (i==2 && j==2)) || (boardSize==7 && (i==3 && j==3)))
      {
        pBoard->card[i][j].front.blank = true;
        for(k=0; k<CARD_HEIGHT; k++)
        {
          for(l=0; l<CARD_WIDTH; l++)
          {
            pBoard->card[i][j].front.pixel[k][l] = pBlankCard->pixel[k][l];
          }
        }
      }
      else
      {
        n=0;
        numOfCards--;
        tempStr = *pWord[numOfCards];
        length = tempStr.length();
        m = (CARD_WIDTH-length)/2;
        pBoard->card[i][j].front.blank = false;
        for(k=0; k<CARD_HEIGHT; k++)
        {
          for(l=0; l<CARD_WIDTH; l++)
          {
            if(k==1)
            {
              if(m)
              {
                pBoard->card[i][j].front.pixel[k][l] = ' ';
                m--;
              }
              else if(length)
              {
                pBoard->card[i][j].front.pixel[k][l] = tempStr[n];
                n++;
                length--;
              }
              else
              {
                pBoard->card[i][j].front.pixel[k][l] = ' ';
              }
            }
            else 
            {
              pBoard->card[i][j].front.pixel[k][l] = ' ';
            }
          }
        }
      }
    }
  }
}
/***********************************/
void getShuffeledWords(string* pWord[], int &numOfCards)
{
  int i, r, randNum;

  string* pTemp;

  srand (time(NULL));

  for(i=0; i<numOfCards; i+=2)
  {
    randNum = rand() % MAX_WORDS;
    pWord[i] = pSubjectWords[randNum][subject];
    pWord[i+1] = pWord[i];

  }
  for (i=0; i<(numOfCards-1); i++)
  {
    r = i + (rand() % (numOfCards-i)); // Random remaining position.
    pTemp = pWord[i]; 
    pWord[i] = pWord[r]; 
    pWord[r] = pTemp;
  }
}
/****************************************************************/
void displayParameters()
{
  offset = (MAX_COLUMNS-boardSize)/2;
  initalRow = (MAX_ROWS/2);

  if(boardSize%2)
  {
    initalCol = (MAX_COLUMNS/2)+((CARD_WIDTH+1)*offset)+3;
  }
  else
  {
    initalCol = (MAX_COLUMNS/2) + ((CARD_WIDTH+1)*offset);
  }

  bottomRow = (initalRow+2) + (CARD_HEIGHT*boardSize);
  bottomCol = (MAX_COLUMNS);
}
/********************************/
void displayBoard()		// Display the main screen of the game
{	
  system("cls");
  int i, j, k, l, row, column;
  goTo(26, 2);
  cout << "-<>-<>-<>- MEOMORY -<>-<>-<>-";

  row = initalRow;
  column = initalCol+(MAX_COLUMNS/2)+1;
  for(i=0; i<boardSize; i++)
  {
    goTo(column, row);
    cout << i+1;
    column += (CARD_WIDTH+1);
  }

  row = initalRow+2;
  column = initalCol;
  for(i=0; i<boardSize; i++)
  {
    goTo(column, row);
    cout << i+1;
    row += CARD_HEIGHT;
  }

  row = initalRow+1;
  column = initalCol+2;
  for(i=0; i<boardSize; i++)
  {
    for (j=0; j<boardSize; j++)
    {
      goTo(column, row);
      for(k=0; k<CARD_HEIGHT; k++)
      {
        for(l=0; l<CARD_WIDTH; l++)
        {
          cout << pBoard->card[i][j].back.pixel[k][l];
        }
        row++;
        goTo(column, row);
      }
      row -= CARD_HEIGHT;
      column += (CARD_WIDTH+1);
      goTo(column, row);
    }
    row += (CARD_HEIGHT);
    column = initalCol+2;
  }
}
/***************************/
void printScore()
{
  goTo(bottomCol,1);
  cout << "SCORE: " << points;
}
/*************************/
void chooseFisrtCard()										//to input the first point
{
  goTo(bottomCol,bottomRow);
  cout << "Enter the Row and Column of your first card";
  goTo(bottomCol,bottomRow+1);
  cout << "Entry:                                     ";
  goTo(bottomCol+7,bottomRow+1);
  cin >> row_1 >> col_1;
  if((row_1<1||row_1>boardSize) ||
    (col_1<1||col_1>boardSize) ||
    (pBoard->card[row_1-1][col_1-1].back.blank == true))
  {
    invalidChoice();
    system("cls");
    displayBoard();
    timer();
    printScore();
    chooseFisrtCard();
  }
  system("cls");
  displayBoard();
  timer();
  printScore();
  flipCard(row_1-1, col_1-1);
}
/******************************/
void flipCard(int inputRow, int inputColumn)
{
  int row = ((initalRow+1) + (inputRow*CARD_HEIGHT));
  int column = ((initalCol+2) + (inputColumn*(CARD_WIDTH+1)));
  goTo(column, row);
  for(int i=0; i<CARD_HEIGHT; i++)
  {
    for(int j=0; j<CARD_WIDTH; j++)
    {
      cout << pBoard->card[inputRow][inputColumn].front.pixel[i][j];
    }
    row++;
    goTo(column, row);
  }
}
/****************************************************/
void chooseSecondCard()										//to input the second point 
{
  goTo(bottomCol,bottomRow);
  cout << "Enter the Row and Column of your second card";
  goTo(bottomCol,bottomRow+1);
  cout << "Entry:                                      ";
  goTo(bottomCol+7,bottomRow+1);
  cin >> row_2 >> col_2;
  if((row_2<1||row_2>boardSize) ||
    (col_2<1||col_2>boardSize) ||
    (pBoard->card[row_2-1][col_2-1].back.blank == true) ||
    ((row_2==row_1)&&(col_2==col_1)))
  {
    invalidChoice();
    system("cls");
    displayBoard();
    timer();
    printScore();
    flipCard(row_1-1, col_1-1);
    chooseSecondCard();
  }
  system("cls");
  displayBoard();
  timer();
  printScore();
  flipCard(row_1-1, col_1-1);
  flipCard(row_2-1, col_2-1);
}
/*******************************/
void checkIfCardsMatch()
{
  int i, j;
  string word1 = pBoard->card[row_1-1][col_1-1].front.pixel[1],
  word2 = pBoard->card[row_2-1][col_2-1].front.pixel[1];
  goTo(bottomCol,bottomRow);
  cout << "                                                    ";
  goTo(bottomCol,bottomRow+1);
  cout << "                                                    ";    
  if(word1 == word2)
  {
    goTo(bottomCol,bottomRow);
    cout << "Congratulations, You found a match!";
    points += 10;
    pBoard->card[row_1-1][col_1-1].back.blank = true;
    pBoard->card[row_2-1][col_2-1].back.blank = true;
    for(i=0; i<CARD_HEIGHT; i++)
    {
      for(j=0; j<CARD_WIDTH; j++)
      {
        pBoard->card[row_1-1][col_1-1].back.pixel[i][j] = ' ';
        pBoard->card[row_2-1][col_2-1].back.pixel[i][j] = ' ';
      }
    }
  }
  else
  {
    goTo(bottomCol,bottomRow);
    cout << "Sorry those don't match";
    points -= 5;
  }
  delay(5000);
}
/********************************/
bool checkIfDone()
{
  int i, j;
  for(i=0; i<boardSize; i++)
  {
    for(j=0; j<boardSize; j++)
    {
      if(pBoard->card[i][j].back.blank == false)
      {
        return false;
      }
    }
  }
  time (&endTime);
  checkIfHighScore();
  return true;
}
/**************************/
void checkIfHighScore()
{
  int min, i, secTens;
  string time, mins, secsTens, secsOnes;
  long int secOnes;
  unsigned double dif;
  dif = difftime (endTime, startTime);
  secOnes = (int)dif;
  min = secOnes/60;
  secOnes %= 60;
  secTens = secOnes/10;
  secOnes %= 10;
  secsTens = convertInt(secTens);
  secsOnes = convertInt(secOnes);
  mins = convertInt(min); 
  time = mins + ':' + secsTens + secsOnes;
  if(numOfRecords[boardSize-4]<TOP_TEN)
  {
    newHighScore(time);
  }
  else
  {
    for(i=0; i<TOP_TEN; i++)
    {
      if(time.compare(highScores[boardSize-4][i].timeToComplete) > 0)
      {
        newHighScore(time);
      }
    }
  }
}
/*******************************/
void newHighScore(string time)
{
  int i=boardSize-4 ,j=numOfRecords[boardSize-4];
  system("cls");
  viewHighScores(i);
  cout << "Congrats, You got a new high score!" << endl << endl
       << "\t\t" << "Please enter your first and last name" << endl
       << "\t\t" << "Entry: ";
  cin >> highScores[i][j].firstName >> highScores[i][j].lastName;

  highScores[i][j].timeToComplete = time;
  highScores[i][j].score = points;
  numOfRecords[boardSize-4]++;
  saveNewScore();

  system("cls");
  viewHighScores(i);
  system("pause");
}
/**************************************/
void saveNewScore()
{
  int i=boardSize-4, j=numOfRecords[boardSize-4], k;
  string fileName;
  ofstream fout;
  fileName = DIRECTORY + BOARD_SIZE[i] + FILE_TYPE;
  fout.open(fileName);
  if (fout.is_open())
  {
    for(k=0; k<j; k++) 
    {
      fout << highScores[i][k].firstName; 
	  fout << " ";
      fout << highScores[i][k].lastName;
	  fout << " ";
      fout << highScores[i][k].timeToComplete;
	  fout << " ";
      fout << highScores[i][k].score;
      if(k<j-1)
      {
	      fout << endl;
      }
    }
    fout.close();
  }
  else
  {
    errorOpeningFile(fileName);
  }
}
/***************************/

//Options Menu and Sub Menus
void options()
{
  int option;
  bool done;
  done = false;
  while(!done)
  {
    option=0;
    while (option<1 || option>3)
    {
      system("cls");
      newLine(5);
      cout << "\t\t" << "       Options"; 
      newLine(1);
      cout << "\t\t" << "                            defalt    current" << endl
        << "\t\t" << "(1) Edit Board Size         4 x 4      " << BOARD_SIZE[boardSize-4] << endl
        << "\t\t" << "(2) Edit Card Catagory     Animals    " << SUBJECT[subject] << endl
        << "\t\t" << "(3) Main Menu           " << endl
        << endl
        << "\t\t" << "Entry: ";
      cin >> option; 
      if (option<1 || option>3)
      {
        invalidChoice();
      }
    }
    switch(option)
    {
    case 1: 
      board_size();
      break;
    case 2: 
      chooseSubject();
      break;
    case 3: 
      done = true;
      break;
    }
  }
}
/**********************/
void board_size()
{
  int boardOption;
  boardOption=0;
  while (boardOption<1 || boardOption>5)
  {
    system("cls");
    newLine(5);
    cout << "\t\t" << "Choose the level of deficulty and board size"; 
    newLine(2);
    cout << "\t\t" << "(1) Kindergarten        4 x 4" << endl
         << "\t\t" << "(2) Elementary School   5 x 5" << endl
         << "\t\t" << "(3) Middle school       6 x 6" << endl
         << "\t\t" << "(4) High school         7 x 7" << endl
         << "\t\t" << "(5) College             8 x 8" << endl 
         << endl
         << "\t\t" << "Entry: ";
    cin >> boardOption; 
    if (boardOption<1 || boardOption>5)
    {
      invalidChoice();
    }
  }
  system("cls");
  boardSize = boardOption+3;
}
/*************************/
void chooseSubject()
{
  int i;

  while(subject<1 || subject>NUM_OF_SUBJECTS)
  {
    system("cls");
    newLine(5);
    cout << "\t\t" << "Choose a subject";
    newLine(2);
    for (i=0; i<NUM_OF_SUBJECTS; i++)
    {
      cout << "\t\t" << "(" << i+1 << ") " << SUBJECT[i] << endl;
    }
    cout << endl << "\t\t" << "Entry: ";
    cin >> subject;
    system("cls");
    if(subject<1 || subject>NUM_OF_SUBJECTS)
    {
      invalidChoice();
    }
  }
  system("cls");
  subject--;
}
/***************************/

//View High Scores Menu and Sub Menus
void viewHighScores(int board)
{
  int i, j=board;
  string name;
  system("cls");
  newLine(3);
  cout << "\t\t\t" << "       High Scores"; 
  newLine(2);
  cout << "\t\tName                     Time       Score" << endl
       << "\t\t_________________________________________" << endl;
  for(i=0; i<numOfRecords[j]; i++)
  {
    name = highScores[j][i].firstName + " " + highScores[j][i].lastName;
    cout << "\t\t" << setw (25) << left << name; 
    cout << left << highScores[j][i].timeToComplete << "       " 
         << left << highScores[j][i].score << endl;
  }
  newLine(2);
  cout << "\t\t";
}
/**************************************/
int forWhichBoard()
{
  int option=0;
  system("cls");
  while (option<1 || option>5)
  {
    newLine(5);
    cout << "\t\t" << "For which level of deficulty and board size"; 
    newLine(2);
    cout << "\t\t" << "(1) Kindergarten        4 x 4" << endl
         << "\t\t" << "(2) Elementary School   5 x 5" << endl
         << "\t\t" << "(3) Middle school       6 x 6" << endl
         << "\t\t" << "(4) High school         7 x 7" << endl
         << "\t\t" << "(5) College             8 x 8" << endl 
         << endl
         << "\t\t" << "Entry: ";
    cin >> option; 
    if (option<1 || option>5)
    {
      invalidChoice();
    }
  }
  system("cls");
  return --option;
}
/***************************/

//Sub Routine Functions
void goTo(int x, int y)
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);			//This function is to set
  COORD point;												//the cursor to a specified 
  point.X = x--;												//place on the screen
  point.Y = y--;
  SetConsoleCursorPosition(hConsole, point);
}
/*******************************/
void shootTextOnScreen(int x, int y, char ch[])                 //This function is to move text
{												                 //on the screen		
  for (int i=1; i<x; i++)
  {	
    goTo(i, y);
    {
      cout << ch << endl;
      cout << "         ";
      delay(5);
    }
    goTo(64,47);	
  }	
}
/*******************************************************/
void newLine(int numberOfNewLines)											//Make a number of new lines 
{
  for (int i=0 ; i<numberOfNewLines ; i++)
  {
    cout << endl;
  }
}
/*******************************************/
void delay(long seconds)	//This function is to make a delay on the screen	
{	
  clock_t time1 = clock();  // use clock time
  clock_t time2 = time1 + seconds;
  while(time1 < time2)
  {
    time1 = clock();
  }
  return;
}
/********************************/
void timer()
{
  int min, secTens;
  long int secOnes;
  double dif;
  time_t currentTime;
  time (&currentTime);
  dif = difftime (currentTime, startTime);
  secOnes = (int)dif;
  min = secOnes/60;
  secOnes %= 60;
  secTens = secOnes/10;
  secOnes %= 10;
  goTo(62,1);
  cout << "Timer " << min << ":" << secTens << secOnes;
}
/********************/
string convertInt(int number)
{
    if (number == 0)
        return "0";
    string temp="";
    string returnvalue="";
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0;i<temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}
/*************************************/

//Error Handling Functions
void errorOpeningFile(string fileName)
{
  system("cls");
  cout << "\a\a\a";
  newLine(5);
  cout << "\t\t " << "Error opening file";
  newLine(2);
  cout << "\t\t " << fileName;
  newLine(2);
  cout << "\t\t " << "I'll Wait while you fix me";
  newLine(2);
  system("pause");
}
/**********************************************/
void invalidChoice()
{
  system("cls");
  cout << "\a\a\a";
  shootTextOnScreen(20,30,"I'm Sorry but That was an invalid Choice");
  shootTextOnScreen(19,30," "); 
  shootTextOnScreen(32,32,"Please try again");
  shootTextOnScreen(31,32," ");
  delay(2000);
  system("cls");
}
/**********************************************************************************************/