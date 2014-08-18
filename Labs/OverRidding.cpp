// OverRidding.cpp 
// author: Jeremy Rios-Martinez
// Extra Credit - in class assignment
// 9/1/2010

#include "stdafx.h"
#include <iostream>
#include <typeinfo>

using std::cin;
using std::cout;
using std::endl;

template <class T1, class T2, class T3, class T4>
void print(T1 a, T2 b, T3 c, T4 d);

int main()
{

  print(1, 3.0, 'M', "hello");
  system("pause"); 
  return 0;
}

template <class T1, class T2, class T3, class T4>
void print(T1 a, T2 b, T3 c, T4 d)
{
  cout << "T1 = " << typeid(a).name() << endl 
       << "T2 = " << typeid(b).name() << endl 
       << "T3 = " << typeid(c).name() << endl 
       << "T4 = " << typeid(d).name() << endl;
}

/*
Screen Print Out

T1 = int
T2 = double
T3 = char
T4 = char const *
Press any key to continue . . .

*/