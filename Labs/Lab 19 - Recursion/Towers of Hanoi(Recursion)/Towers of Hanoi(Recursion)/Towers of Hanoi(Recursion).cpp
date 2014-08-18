// Towers of Hanoi(Recursion).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void move(int n,char *t1,char *t2,char *t3);

void main()
{
  int n;
  cout << "\n**********************************************************\n";
  cout << "Sequence of steps to solve the Towers of Hanoi problem";
  cout << "\n**********************************************************\n\n";
  cout << "Enter the no. of rings ";
  cin >> n;
  move(n, "tower 1", "tower 2 ", "tower 3");
  system("pause");
}

void move(int n,char *t1,char *t2,char *t3) 
{                              // t1 stands for tower 1/source tower              
  if(n>0)                      // t2 stands for tower 2/intermediate tower          
  {                            // t3 stands for tower 3/destination tower
    move(n-1, t1, t3, t2); 
         // move n-1 disks from source to intermediate tower
    cout << "disk " << n << " is moved from " << t1 << " to " << t3 << endl;  
	     // move the disk from to source to destination
    move(n-1, t2, t1, t3); 
	     // move n-1 disks from intermediate to destination
  }
}