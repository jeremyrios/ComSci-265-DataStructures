// 

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace::std;

const string inputFile ("C:\\Users\\Rios\\Desktop\\str.txt");
const string outputFile ("C:\\Users\\Rios\\Desktop\\str2.txt");

int main()
{
  bool gotWord, sorted;
  const int MAX_WORDS = 1000;
  int i, j, totalWords=0, nonRepeatedWords = 0, wordCounts[MAX_WORDS]={0};
  char l;
  ifstream fin (inputFile);
  ofstream fout (outputFile);
  string temp;
  string tempWords[MAX_WORDS];
  string words[MAX_WORDS];

  if(fin.is_open())
  {
	while(!fin.eof() && totalWords < MAX_WORDS)
	{
      fin >> temp;
	  for (i=0; i<temp.length(); ++i)
      {
        temp[i] = toupper(temp[i]);
      } 

	  gotWord = false;
	  for(i=0; i<temp.length() && !gotWord; i++)
	  {
		l = temp[i];                       // Checks each character in the input string to see if it not a
		if(!((l>64&&l<91)||(l>96&&l<123))) // lowercase/upercase letter (by ASCII code) 
	    {                                  
		  if(i == temp.length()-1)         // If the non-letter character is at the end of the 
		  {                                // string it replaces it with NULL char
		    temp[i] = NULL;
			temp = temp.substr(0, i);
			tempWords[totalWords] = temp;
		    ++totalWords;
			gotWord = true;
		  }
		  else
		  {
		    tempWords[totalWords] = temp.substr(0, i); // If the non-letter character is in the middle of 
			++totalWords;                              // the input string it splits the string into two  
			temp = temp.substr(i+1);                   // individual strings around the non-letter character
			i=0;                                       
		  }
	    }
		else if (i == temp.length()-1)
		{
		  tempWords[totalWords] = temp;
		  ++totalWords;
		  gotWord = true;
		}
	  }
	}
    fin.close();
  }
  else
  {
    cout << "Unable to open the input file Think.txt";
  }
  if(fout.is_open())
  {
    
	words[0] = tempWords[0];
	++wordCounts[0];
	++nonRepeatedWords;

	for(i=1; i<totalWords; i++)
	{
	  sorted = false;
	  for(j=0; !sorted; j++)
      {
        if(tempWords[i].compare(words[j]) == 0)
		{
		  ++wordCounts[j];
		  sorted = true;
		}
        else if( j==nonRepeatedWords && !sorted)
		{
	      words[j] = tempWords[i];
		  ++wordCounts[j];
		  ++nonRepeatedWords;
		  sorted = true;
		}
	  }
	}
	for (i=0; i<nonRepeatedWords; i++)
    {
	  cout << words[i] << " = " << wordCounts[i] << endl;
	  fout << words[i] << " = " << wordCounts[i] << endl;
    }
	fout.close();
  }
  else
  {
	cout << "Unable to open the output file WordCountOutput.txt";
  }
  
  system("pause");
  return 0;
}

