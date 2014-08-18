#include "stdafx.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include<ctime>
#include<conio.h>
#include <Windows.h>
using namespace std;

/********************** Structure **********************/
// 1. Word: Store elements of the game-table           //
// 2. Index: Store Row / Column of two chosen tables   //
// 3. Record: Store the records of the players         //
// 4. tm *Time: Store the elapsed game-play time       //
/////////////////////////////////////////////////////////
struct Word
{
	char card[10];				// Store word from text-file
	unsigned short temp :8;		// Store Integer for randomize
	unsigned short RM_NUM :7;	// Store Table Number
	unsigned short showUp :1;	// Store On/Off for showing the chosen word
};
struct Index
{
	unsigned short row :8;		// Store Row value of the Game Table 
	unsigned short col :8;		// Store Colum value of the Game Table
}Room[2];
struct Record
{
	char userName[15];			// Store the User Name
	time_t elapsed;				// Store the Total Elapsed Time
};
struct tm *Time;

/******************* Global Variables ******************/
ifstream fin;
int GAME_SIZE = 0;				// Decide the size of game-table
const int REC_MAX = 11;			// The maximum range of Record array
int recSize = 1;				// Actual counter for Record array
int gameSet = 0;				// The total number of table cells
int pickRoom = 0;				// Store the room number chosen by user
time_t beg_time, end_time, gap_time;	// Store the time information
Record R[REC_MAX];				// Store the elapsed time records
Word** gameTable;
Word *itemList;					// Store the wordsets

/***************** Function Prototypes ****************/
void repeatSymbol(int, int);
void getTableSize();
void drawScreen_Topic();
void createTable();
void printTable();
void getItems();
void assignTable();
void getRoomNum();
void timeCounter();
void failCount();
void deleteTable();
void finishGame();
void openOldRecord();
void sortRecord();
void updateRecord();
void printRecord();
void randomizeList();
bool findRoomNum(Index [], bool);
bool checkMatching(Index []);
string getFileName();
string getRecordFile();
void makeWordList(Word [], const int);

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned int)time(0));

	getTableSize();
	createTable();
	drawScreen_Topic();
	getItems();
	assignTable();

	beg_time = clock() / CLOCKS_PER_SEC;	// Set the beginning time

	while(gameSet)
	{
		int i = 0;
		bool SWITCH = 0;			// Decide whether 1st or 2nd choice
		bool chkRM_NUM = true;		// Check duplication of Room Number
		bool chkFail = true;		// Check if the chosens words same

		while(i < 2)
		{
			printTable();
			timeCounter();
			getRoomNum();
			chkRM_NUM = findRoomNum(Room, SWITCH);

			if(chkRM_NUM)
			{
				SWITCH = !SWITCH;	// Switch the choice
				i++;
			}
		}

		printTable();
		chkFail = checkMatching(Room);

		if(!chkFail)
			failCount();
	}
	deleteTable();

	end_time = clock() / CLOCKS_PER_SEC;	// Final Lapsed
	gap_time = end_time - beg_time;			// Gap time between beginning and ending
	Time = localtime(&gap_time);			// Convert gap_time into Time

	finishGame();
	openOldRecord();
	sortRecord();
	updateRecord();
	printRecord();

	return 0;
}

/*************** Function Bodies ***************/

void getTableSize()
{
	char temp = 0;
	cout << "\n\n   Choose a board size [1. Small (4 X 4), 2. Medium (6 X 6), 3. Large (8 X 8)]: ";
	cin.get(temp);
	cin.ignore(1, 10);

	if(temp == '1')
		GAME_SIZE = 4;
	else if(temp == '2')
		GAME_SIZE = 6;
	else if(temp == '3')
		GAME_SIZE = 8;

	gameSet = GAME_SIZE * GAME_SIZE;
}

void repeatSymbol(int size, int symbol)
{
	for(int i = 0; i < size; i++)
		cout << (char)symbol;
}

void drawScreen_Topic()
{
	system("CLS");
	cout << endl << endl;
	cout << "    " << (char)1; repeatSymbol(10, 6);
	cout << " Press the Number of Topic ";
	repeatSymbol(10, 6); cout << (char)2 << endl;
	cout << "    " << (char)5; repeatSymbol(47, ' '); cout << (char)5 << endl;
	cout << "    " << (char)5 << "	1. Popular Baby Names";
	repeatSymbol(23, ' '); cout << (char)5 << endl;
	cout << "    " << (char)5; repeatSymbol(47, ' '); cout << (char)5 << endl;
	cout << "    " << (char)5 << "	2. Contents of the Bible";
	repeatSymbol(20, ' '); cout << (char)5 << endl;
	cout << "    " << (char)5; repeatSymbol(47, ' '); cout << (char)5 << endl;
	cout << "    " << (char)5 << "	3. Names of Colors";
	repeatSymbol(26, ' '); cout << (char)5 << endl;
	cout << "    " << (char)5; repeatSymbol(47, ' '); cout << (char)5 << endl;
	cout << "    " << (char)5 << "	4. Country Names";
	repeatSymbol(28, ' '); cout << (char)5 << endl;
	cout << "    " << (char)5; repeatSymbol(47, ' '); cout << (char)5 << endl;
	cout << "    " << (char)5 << "	5. Names of Fruit";
	repeatSymbol(27, ' '); cout << (char)5 << endl;
	cout << "    " << (char)5; repeatSymbol(47, ' '); cout << (char)5 << endl;
	cout << "    " << (char)3; repeatSymbol(47, 6); cout << (char)4 << endl;
}

string getFileName()
{
	switch(_getch())
	{
	case 49:
		return "babyName.txt";
	case 50:
		return "bibleList.txt";
	case 51:
		return "colorList.txt";
	case 52:
		return "countryList.txt";
	case 53:
		return "fruitList.txt";
	}
}

void createTable()
{
	gameTable = new Word* [GAME_SIZE];
	for(int i = 0; i < GAME_SIZE; i++)
		gameTable[i] = new Word [GAME_SIZE];

	// Initialize the table
	for(int i = 0, roomNum = 1; i < GAME_SIZE; i++)
	{
		for(int j = 0; j < GAME_SIZE; j++)
		{
			gameTable[i][j].showUp = 0;
			gameTable[i][j].RM_NUM = roomNum++;
		}
	}
}

void printTable()
{
	system("CLS");
	cout << endl << endl;
	for(int i = 0; i < GAME_SIZE; i++)
	{
		for(int j = 0; j < GAME_SIZE; j++)
		{
			if(gameTable[i][j].showUp)
				cout << setfill (' ') << "  [" << setw(8) << left << gameTable[i][j].card << "]";
			else
			{
				cout << setfill ('0') << "  [" << "   " << setw(2) 
					<< right << gameTable[i][j].RM_NUM << "   " << "]";
			}
		}
		cout << endl << endl;
	}
}

bool checkRandoms(int begNum, int rNum, bool& chkDup)
{
	for(begNum; (begNum >= 0) && chkDup; begNum--)
	{
		if(itemList[begNum].temp == rNum)
			chkDup = false;
	}

	return chkDup;
}

void getItems()
{
	const int IDX_TOTAL = 40;
	Word tempItem[IDX_TOTAL];

	string fileName = getFileName();
	fin.open(fileName.c_str());
	for(int i = 0; fin.good(); i++)
	{
		fin >> tempItem[i].card;
		fin.ignore(8, 10);
	}
	fin.close();

	makeWordList(tempItem, IDX_TOTAL);
}

void makeWordList(Word tempItem [], const int IDX_TOTAL)
{
	itemList = new Word [gameSet];
	int rNum = rand() % IDX_TOTAL;

	for(int i = 0, j = i + 1; i < gameSet; rNum = rand() % IDX_TOTAL)
	{
		bool chkDup = true;
		checkRandoms(i, rNum, chkDup);

		if(chkDup)
		{
			itemList[i].temp = rNum;
			strcpy_s(itemList[i++].card, tempItem[rNum].card);
			itemList[j].temp = rNum;
			strcpy_s(itemList[j++].card, tempItem[rNum].card);
			i++; j++;
		}
	}

	randomizeList();
}

void randomizeList()
{
	int rNum = rand() % gameSet;
	for(int base = 0; base < gameSet; base++)
	{
		if(base != rNum)
		{
			Word temp;
			temp = itemList[base];
			itemList[base] = itemList[rNum];
			itemList[rNum] = temp;
		}
		else
			base--;
		rNum = rand() % gameSet;
	}
}

void assignTable()
{
	for(int i = 0, idx = 0; i < GAME_SIZE; i++)
	{
		for(int j = 0; j < GAME_SIZE; j++)
			strcpy_s(gameTable[i][j].card, itemList[idx++].card);
	}

	delete [] itemList;
}

void getRoomNum()
{
	int a, b;
	a = _getch() - 48;
	b = _getch() - 48;

	pickRoom = (a * 10) + b;
}

bool findRoomNum(Index Room [], bool SWITCH)
{
	int i, j;
	for(i = 0; i < GAME_SIZE; i++)
	{
		for(j = 0; j < GAME_SIZE; j++)
		{
			if(gameTable[i][j].RM_NUM == pickRoom)
			{
				if(!gameTable[i][j].showUp)
				{
					gameTable[i][j].showUp = true;
					Room[SWITCH].row = i;
					Room[SWITCH].col = j;
					return true;
				}
				else
				{
					cout << "Room [" << pickRoom << "] is already opened!";
					Sleep(2000);
					return false;
				}
			}
		}
	}

	cout << "Room [" << pickRoom << "] is not existed" << endl;
	Sleep(2000);
	return false;
}

bool checkMatching(Index Room [])
{
	int chkMatch = strcmp(gameTable[Room[0].row][Room[0].col].card, 
		gameTable[Room[1].row][Room[1].col].card);

	if(chkMatch != 0)
	{
		gameTable[Room[0].row][Room[0].col].showUp = false;
		gameTable[Room[1].row][Room[1].col].showUp = false;
		return false;
	}
	else
	{
		gameSet -= 2;
		return true;
	}
}

void timeCounter()
{
	while(!_kbhit())
	{
		end_time = clock() / CLOCKS_PER_SEC;
		gap_time = end_time - beg_time;
		Time = localtime(&gap_time);

		cout << setfill('0') << right;
		cout << "   Elapsed Time: ";
		cout << setw(2) << Time->tm_min;
		cout << ":" << setw(2) << Time->tm_sec;
		cout << '\r';
		Sleep(1000);
	}
}

void failCount()
{
	for(int i = 5; i >= 0; i--)
	{
		cout << "  Those cards are not matched.. ";
		cout << "[ " << i << " ]" << " secs remain." << '\r';
		Sleep(1000);
	}
}

void deleteTable()
{
	for(int i = 0; i < GAME_SIZE; i++)
		delete [] gameTable[i];
	delete [] gameTable;
}

void finishGame()
{
	cout << "  Enter your last name: ";
	cin >> R[0].userName;
	cin.ignore(15, 10);
	R[0].elapsed = gap_time;

	cout << "  Congratulate, " << R[0].userName << " !! ";
	cout << "Total Elaspsed Time is " << Time->tm_min << "mins " 
		<< setw(2) << setfill('0') << right << Time->tm_sec << "secs. "<< endl << endl;
	cout << "  Press any key to see 'Ranking...'";
	cin.get();
}

string getRecordFile()
{
	switch(GAME_SIZE)
	{
	case 4:
		return "smallRec.txt";
	case 6:
		return "medRec.txt";
	case 8:
		return "largeRec.txt";
	}
}

void openOldRecord()
{
	string fileName = getRecordFile();

	fin.open(fileName.c_str());
	while(fin.good())
	{
		fin >> R[recSize].userName >> R[recSize].elapsed;
		if(strlen(R[recSize].userName) && recSize < REC_MAX)
			recSize++;
	}
	fin.close();
}

void sortRecord()
{
	for(int i = 0; i < recSize; i++)
	{
		for(int j = i + 1; j < recSize; j++)
		{
			if(R[i].elapsed > R[j].elapsed)
			{
				Record temp;
				temp = R[i];
				R[i] = R[j];
				R[j] = temp;
			}
		}
	}
}

void updateRecord()
{
	ofstream fout;
	string fileName = getRecordFile();

	fout.open(fileName.c_str());
	for(int i = 0; i < 10; i++)
		fout << R[i].userName << " " <<	R[i].elapsed << endl;
	fout.close();
}

void printRecord()
{
	system("CLS");
	cout << endl << endl;
	cout << "   "; repeatSymbol(10, 6);
	cout << " Time Ranking of " << GAME_SIZE << " X " << GAME_SIZE << " Table ";
	repeatSymbol(10, 6); cout << endl;
	cout << "       " << "Rank.       " << "Name.          " << "Elapsed Time."<< endl;

	for(int i = 0, j = 1; i < 10; i++)
	{
		Time = localtime(&R[i].elapsed);
		cout << setfill(' ');
		cout << "         " << setw(2) << right << j++ << ".       ";
		cout << setw(15) << left << R[i].userName << setw(2) << right << 
			setfill('0') << Time->tm_min << ":" << setw(2) << Time->tm_sec << endl;
	}

	cin.get();
}