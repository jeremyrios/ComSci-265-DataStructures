// Merge File Program.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>	
#include <iostream>
#include <fstream>
using namespace std;

  const int CONTACTS = 10;
  const int LINES_IN_LETTER = 37;
  const int CHARACTERS_IN_LINE = 100;
  const string inputFile1("C:\\Users\\Rios\\Desktop\\ContactInfo.txt");
  const string inputFile2("C:\\Users\\Rios\\Desktop\\PoliticalCampaignLetter.txt");
  const string outputFile("C:\\Users\\Rios\\Desktop\\");
  const string fileExtension(".txt");

struct records
{
  string firstName;
  string lastName;
  string address;
  string city;
  string state;
  string zipcde;
  string phoneNumber;
  string annualIncome;
  string politicalParty;
};

struct recordFlags
{
  const string firstName;
  const string lastName;
  const string address;
  const string city;
  const string state;
  const string zipcde;
  const string phoneNumber;
  const string annualIncome;
  const string politicalParty;
};

void getRecords(string *inputFile, records *donationContact[]);
void getLetter(string *inputFile, string *letterLine[]);
void mergeFiles(string *outputFile, string *fileExtension, records *donationContact[], recordFlags *contactFlag, string *letterLine[]);

int main()
{

  records donationContact[CONTACTS];
  recordFlags contactFlag = {"[FIRST_NAME]","[LAST_NAME]","[ADDRESS]","[CITY]","[STATE]","[ZIPCODE]","[PHONE_NUMBER]","[ANUAL_INCOME]","[POLITICAL_PARTY]"};

  string letterLine[LINES_IN_LETTER];

  getRecords(&inputFile1, &donationContact);
  getLetter(&inputFile2, &letterLine);
  mergeFiles(&outputFile, &fileExtension, &donationContact, &contactFlag, &letterLine);

  system("pause");
  return 0;
}

void getRecords(string *sPtr_inputFile, records *rPtr_donationContact[]) 
{
  ifstream fin (*sPtr_inputFile);
  int i=0;

  size_t flag1, flag2, length;
  //char* cPtr-wholeLine;
  char wholeLine[CHARACTERS_IN_LINE];
  if (!fin.is_open())
  {
    while(!fin.eof())
    {
      fin.getline(wholeLine, CHARACTERS_IN_LINE);
	  //cPtr-wholeLine = strtok (wholeLine,"[");
	
	  flag1 = wholeLine.find('|');
	  rPtr_donationContact[i]->firstName.assign(wholeLine, 0, flag1); 

	  wholeLine[flag1] = ' ';
	  flag2 = wholeLine.find('|');
	  length = flag2 - flag1;
	  rPtr_donationContact[i]->lastName.assign(wholeLine, flag2+1, length); 

	  wholeLine[flag2] = (' ');
	  flag1 = wholeLine.find('|');
	  length = flag1 - flag2;
	  rPtr_donationContact[i]->address.assign(wholeLine, flag1+1, length);

	  wholeLine[flag1] = ' ';
	  flag2 = wholeLine.find('|');
	  length = flag2 - flag1;
	  rPtr_donationContact[i]->city.assign(wholeLine, flag2+1, length);

	  wholeLine[flag2] = (' ');
	  flag1 = wholeLine.find('|');
	  length = flag1 - flag2;
	  rPtr_donationContact[i]->state.assign(wholeLine, flag1+1, length);

	  wholeLine[flag1] = ' ';
	  flag2 = wholeLine.find('|');
	  length = flag2 - flag1;
	  rPtr_donationContact[i]->zipcde.assign(wholeLine, flag2+1, length);
	  wholeLine[flag2] = (' ');
	  flag1 = wholeLine.find('|');
	  length = flag1 - flag2;
	  rPtr_donationContact[i]->phoneNumber.assign(wholeLine, flag1+1, length);

	  wholeLine[flag1] = ' ';
	  flag2 = wholeLine.find('|');
	  length = flag2 - flag1;
	  rPtr_donationContact[i]->annualIncome.assign(wholeLine, flag2+1, length);

	  wholeLine[flag2] = (' ');
	  flag1 = wholeLine.find('|');
	  length = flag1 - flag2;
	  rPtr_donationContact[i]->politicalParty.assign(wholeLine, flag1+1, length);

	  i++;
    }
  }
  else 
  {
    cout << "Could not open file \"" << (*sPtr_inputFile) << "\"" << endl;
  }
}

void getLetter(string &inputFile, string letterLine[])
{
  {
  ifstream fin (inputFile);
  int i = 0;
  if (!fin.is_open())
  {
    while(!fin.eof())
    {
      fin.getline(letterLine[i], '\n');
	  i++;
    }
  }
  else 
  {
    cout << "Could not open file \"" << inputFile << "\"" << endl;
  }
}
}

void mergeFiles(string outputFile, string fileExtension, records donationContact[], recordFlags contactFlag, string letterLine[])
{
  {
	bool lineClear;
	int i, j;
    ofstream fout;
	string temp;
	size_t leftBracket, rightBracket, length;
    string newFileName;
    for (i=0; i<CONTACTS; i++)
    {
	  newFileName.clear();
	  newFileName += outputFile;
	  newFileName += (i + 48); // 48 == 0 ASCII CODE
	  newFileName += fileExtension;
	  fout.open(newFileName);
	  if (fout.is_open())
      {
        while(!fout.eof())
        {
		  for(j=0; j<LINES_IN_LETTER; j++)
		  {
			lineClear = false;
		    while(!lineClear)
			{
		      leftBracket = letterLine[j].find_first_of("[");
			  if (leftBracket == string::npos)
			  {
				lineClear = true;
				cout << letterLine[j] << endl;
				fout << letterLine[j] << endl;
			  }
			  else
			  {
			    rightBracket = letterLine[j].find_first_of("]");
			    length = leftBracket-rightBracket;
			    letterLine[j].copy(temp, leftBracket, length);
			    if (temp.compare(contactFlag.firstName) == 0)
			    {
			      letterLine[j].replace(leftBracket, length, donationContact[i].firstName);
			    }
			    else if(temp.compare(contactFlag.lastName) == 0)
			    {
			  	  letterLine[j].replace(leftBracket, length, donationContact[i].lastName);
			    }
			    else if(temp.compare(contactFlag.address) == 0)
			    {
				  letterLine[j].replace(leftBracket, length, donationContact[i].address);
			    }
			    else if(temp.compare(contactFlag.city) == 0)
			    {
				  letterLine[j].replace(leftBracket, length, donationContact[i].city);
			    }
			    else if(temp.compare(contactFlag.state) == 0)
			    {
				  letterLine[j].replace(leftBracket, length, donationContact[i].state);
			    }
			    else if(temp.compare(contactFlag.zipcde) == 0)
			    {
			  	  letterLine[j].replace(leftBracket, length, donationContact[i].zipcde);
			    }
			    else if(temp.compare(contactFlag.phoneNumber) == 0)
			    {
				  letterLine[j].replace(leftBracket, length, donationContact[i].phoneNumber);
			    }
			    else if(temp.compare(contactFlag.annualIncome) == 0)
			    {
				  letterLine[j].replace(leftBracket, length, donationContact[i].annualIncome);
			    }
			    else if(temp.compare(contactFlag.politicalParty) == 0)
			    {
				  letterLine[j].replace(leftBracket, length, donationContact[i].politicalParty);
			    }
			  }
			}
		  }
        }
		fout.close();
      }
      else 
      {
        cout << "Could not open file \"" << newFileName << "\"" << endl;
      }
    }
  }
}

