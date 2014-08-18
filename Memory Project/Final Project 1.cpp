// Final Project.cpp : Defines the entry point for the console application.
//MEMORY GAME.	

#include "stdafx.h"
#include <iostream>
using namespace std;

#include <algorithm>			
#include<ctype.h>				
#include<time.h>				
#include<windows.h>

struct mem_char
{
	char ch[5][5];
};

int e, i, j, q, m, n, x=0, row_1, column_1, row_2, column_2, score=0;
char words[16] = {'a','g','h','j','k','a','s','d','f','g','s','d','f','h','j','k'};
char re_play;
mem_char char_1[2];

// Function Declarations
void end_game();
void input_first_point();
void input_second_point();
void delay(long seconds) ;
void goTo(int x, int y);
void score_1();
void new_line(int y);
void output_1();
void num_1();
void num_2();
void main_1();
void intro();
void shootTextOnScreen( int x ,int y , char ch[]);
void sleep(unsigned int mseconds);
/***********************/



int main()
{
  srand((unsigned)time(0));
  using std::random_shuffle;
  random_shuffle(words, words+16);
  for(m=1; m<5; m++)
  {
    for (n=1; n<5; n++)
	{
	  do
	  {
	    char_1[1].ch[m][n] = *(words+x);
		x++;
		break;
	  }while(x<16);
	}
  }
  char_1[0].ch[0][0]=' ';
  for ( int u=1; u<5; u++)
  {
	char_1[0].ch[0][u] = 48+u;
	char_1[0].ch[u][0] = 48+u;
	for(int y=1; y<5; y++)
	{
	  char_1[0].ch[u][y] = '*';
	}
  }
  intro(); // Display Intro
  new_line(3);
  for(i=0; i<5; i++)
  {
    cout << "       \t\t\t";
	for (j=0; j<5; j++)
	{
	  cout << char_1[0].ch[i][j] << "    ";
	}
	new_line(3);
  }
  new_line(3);
  main_1();
  new_line(4);
  system("pause");
  return 0;
}
/******************/


void intro()
{
	system("cls");
	shootTextOnScreen(39,30,"COMSC  265");
	shootTextOnScreen(38,30," ");
	shootTextOnScreen(38,32,"Final Project");
	shootTextOnScreen(37,32," ");
	delay(2000);
	system("cls");
	shootTextOnScreen(29,30,"-<>-<>-<>- MEOMORY -<>-<>-<>-");
	shootTextOnScreen(28,30," ");
	shootTextOnScreen(40,32,"Designed");
	shootTextOnScreen(39,32," ");
	shootTextOnScreen(43,34,"By");
	shootTextOnScreen(42,34," ");
	shootTextOnScreen(34,36,"Jeremy Rios-Martinez");
	shootTextOnScreen(33,36," ");
	delay(4000);
	system("cls");
}
/********************/
void main_1()
{
  goTo(1,20);
  num_1();
  output_1();
  score_1();
  if(char_1[1].ch[row_1][column_1] == char_1[1].ch[row_2][column_2])
  {
    goTo(1,20);
	cout<<"Good Man"<<endl;
	char_1[0].ch[row_1][column_1]=' ';
	char_1[0].ch[row_2][column_2]=' ';
	score+=10;
  }
  else
  {
    goTo(1,20);
	cout<<"Try Again";
	new_line(5);
	score-=4;
  }
  if(char_1[1].ch[row_1][column_1] != char_1[1].ch[row_2][column_2])
  {
    char_1[0].ch[row_1][column_1]='*','*';
	char_1[0].ch[row_2][column_2]='*','*';
  }
  sleep(1600);
  system("cls");
  output_1();
  score_1();
  for (i=1 ; i<2 ; i++)
  {
    for ( j=1 ; j<2 ; j++)
	{
	  if ( char_1[0].ch[i][j]==' '     &&  char_1[0].ch[i][j+1]==' '   && 
		   char_1[0].ch[i][j+2]==' '   &&  char_1[0].ch[i][j+3]==' '   && 
		   char_1[0].ch[i+1][j]==' '   &&  char_1[0].ch[i+1][j+1]==' ' && 
		   char_1[0].ch[i+1][j+2]==' ' &&  char_1[0].ch[i+1][j+3]==' ' &&
		   char_1[0].ch[i+2][j]==' '   &&  char_1[0].ch[i+2][j+1]==' ' &&
		   char_1[0].ch[i+2][j+2]==' ' &&  char_1[0].ch[i+2][j+3]==' ' &&
		   char_1[0].ch[i+3][j]==' '   &&  char_1[0].ch[i+3][j+1]==' ' &&
		   char_1[0].ch[i+3][j+2]==' ' &&  char_1[0].ch[i+3][j+3]==' '  )
	  {
	    cout<<"\n\nYou have finished with score "<<score<<endl<<endl;
		cout<<"Do you want to play again?(y/n)";
		cin>>re_play;
		re_play=tolower(re_play);
		while(isdigit(re_play))
		{
		  cout<<"Please enter a character";
		  cin>>re_play;
		}
		if (re_play=='y')
		{
	      score=0;
		  x=0;
		  system("cls");
		  main();
		}
		if (re_play=='n')
		{
		  cout<<"Thank you for playing memory";
		  exit(0);
		}
		else
		{
		  exit(0);
		}
	  }
	}
  }
  main_1();
}

/****************************************/

void num_1()
{
	input_first_point();
	system("cls");
	output_1();
	score_1();
	new_line(1);
	num_2();
}
/********************/
void num_2()
{
  input_second_point();
  system("cls");
  if(row_1==row_2&&column_1==column_2)
  {
    char_1[0].ch[row_1][column_1]='*';
	output_1();
	score_1();
	new_line(3);
	cout<<"Error\n\n#Don't Enter the co-ordinates of the same point\n\nYour score will be decreased by 5"<<endl<<endl<<endl;
	delay(3000);
	system("cls");
	output_1();
	score_1();
	new_line(3);
	num_1();
	system("cls");
	score-=5;
  }
}
/********************/
void input_first_point()										//to input the first point
{
  cout << "# Enter the Row and Column of your first card \n"
       << "Entry: ";
  cin >> row_1 >> column_1;
  if(column_1>4||row_1>4)
  {
	cout<<"\nThere's no point here with this co-ordinates\n\nEnter the co-ordinates between 1 and 4\n\n";
	input_first_point();
  }
  new_line(2);
  if(char_1[0].ch[row_1][column_1]==' ')
  {
	system("cls");
	output_1();
	cout<<"Error\n\nThis point have been hidden by you\n\n";
	input_first_point();
  }
  new_line(2);
  char_1[0].ch[row_1][column_1] = char_1[1].ch[row_1][column_1];
}
/********************************/
void input_second_point()										//to input the second point 
{
  new_line(2);
  cout << "# Enter the Row and Column of your second card \n"
       << "Entry: ";
  cin >> row_2 >> column_2;
  if(column_2>4||row_2>4)
  {
	cout << "\nThere's no point here with this co-ordinates\n\nEnter the co-ordinates between 1 and 4\n\n";
	input_second_point();
  }
  new_line(2);
  if(char_1[0].ch[row_2][column_2]==' ')
  {
    system("cls");
	output_1();
	cout<<"Error\n\nThis point have been hidden by you\n\n";
	input_second_point();
  }
  new_line(2);
  char_1[0].ch[row_2][column_2]=char_1[1].ch[row_2][column_2];
}
/*********************************/
void output_1()													//To display the main screen of 
{																//the game
  for( e=0 ; e<5 ; e++)
  {
    cout<<"       \t\t\t";
	for(q=0 ; q<5 ; q++)
	{
	  cout << char_1[0].ch[e][q] <<"    ";
	}
	new_line(3);
  }
}
/***********************/


void new_line(int numberOfNewLines)											//Make a number of new lines 
{
  for (int i=0 ; i<numberOfNewLines ; i++)
  {
	cout << endl;
  }
}
/*******************************************/
void delay(long seconds)										//This function is to make a
{																//delay on the screen	
  clock_t time1 = clock();  // use clock time
  clock_t time2 = time1 + seconds;
  while(time1 < time2)
  {
    time1 = clock();
  }
  return;
}
/********************************/
void score_1()
{													// This function moves the 
  goTo(64,17);									    // cursor to a specified place
  cout << "Score = " << score << endl;				// and writes the score
}
/**********************/
void sleep(unsigned int mseconds)								//This function is to make a
{																//delay on the screen
  clock_t goal = mseconds + clock();
  while (goal > clock());
}
/*****************************************/
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

