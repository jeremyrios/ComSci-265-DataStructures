#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MAX_NUM = 10;
const string directory ("E:\\Computer Programing\\COMSC 265\\Labs\\Lab 9\\Statitics Program\\");
const string inputFileName ("inputNumbers.txt");
const string outputFileName ("summarystats.txt");

void getData(string &inputFileLocation, int inputNumbers[][MAX_NUM]);
int averageFinder(int intArray[][MAX_NUM]);
void getOverUnder(int intArray[][MAX_NUM], int average, int &greaterThan, int &lessThan);
void findMinAndMax(int intArray[][MAX_NUM], int &minimumNum, int &maximumNum);
void printAndStoreData(string outputFileLocation, int avg, int greaterThan, int lessThan, int min, int max);

int main()
{
  int average, greaterThan=0, lessThan=0, minimumNum=0, maximumNum=0;
  int inputNumbers[MAX_NUM][MAX_NUM];

  string inputFileLocation;
  string outputFileLocation;
  
  inputFileLocation += directory;
  inputFileLocation += inputFileName;
  outputFileLocation += directory;
  outputFileLocation += outputFileName;

  getData(inputFileLocation, inputNumbers);
  average = averageFinder(inputNumbers);
  getOverUnder(inputNumbers, average, greaterThan, lessThan);
  findMinAndMax(inputNumbers, minimumNum, maximumNum);
  printAndStoreData(outputFileLocation, average, greaterThan, lessThan, minimumNum, maximumNum);

  system("pause");
  return 0;
}
void getData(string &inputFileLocation, int inputNumbers[][MAX_NUM])
{
  ifstream fin(inputFileLocation);
  if(fin.is_open())
  {
	while(!fin.eof())
	{
	  for(int i=0; i<MAX_NUM; i++)
	  {
	    for(int j=0; j<MAX_NUM; j++)
	    {
	   	  fin >> inputNumbers[i][j];
		}
	  }
	}
    fin.close();
  }
  else
  {
	cout << "Unable to open input file \""<< inputFileLocation << "\"";
  }
}

int averageFinder(int intArray[][MAX_NUM])
{
  int sum = 0, totalNums = (MAX_NUM * MAX_NUM), average = 0;
  for(int i=0; i<MAX_NUM; i++)
  {
	for(int j=0; j<MAX_NUM; j++)
	{
	  sum += intArray[i][j];
	}
  }
  average = sum/totalNums;
  return average;
}

void getOverUnder(int intArray[][MAX_NUM], int average, int &greaterThan, int &lessThan)
{
  for(int i=0; i<MAX_NUM; i++)
  {
	for(int j=0; j<MAX_NUM; j++)
	{
	  if(intArray[i][j] < average)
	  {
        ++lessThan;
	  }
	  else if(intArray[i][j] > average)
	  {
        ++greaterThan;
	  }
	}
  }
}

void findMinAndMax(int intArray[][MAX_NUM], int &minimumNum, int &maximumNum)
{
  {
  minimumNum = intArray[0][0];
  maximumNum = intArray[0][0];
  for(int i=0; i<MAX_NUM; i++)
  {
	for(int j=0; j<MAX_NUM; j++)
	{
	  if(minimumNum > intArray[i][j])
	  {
        minimumNum = intArray[i][j];
	  }
	  if(maximumNum < intArray[i][j])
	  {
        maximumNum = intArray[i][j];
	  }
	}
  }
}
}

void printAndStoreData(string outputFileLocation, int avg, int greaterThan, int lessThan, int min, int max)
{
  ofstream fout(outputFileLocation);
  if(fout.is_open())
  {
	cout << "The average is: " << avg << endl;
	fout << "The average is: " << avg << endl;
	cout << "There are " << greaterThan << " numbers greater than the average." << endl;
    fout << "There are " << greaterThan << " numbers greater than the average." << endl;
    cout << "There are " << lessThan << " numbers less than the average." << endl;
	fout << "There are " << lessThan << " numbers less than the average." << endl;
	cout << "The maximum number is: " << max << endl;
	fout << "The maximum number is: " << max << endl;
	cout << "The minimum number is: " << min << endl;
	fout << "The minimum number is: " << min << endl;
	fout.close();
  }
  else
  {
    cout << "Unable to open output file \""<< outputFileLocation << "\"";
  }
}