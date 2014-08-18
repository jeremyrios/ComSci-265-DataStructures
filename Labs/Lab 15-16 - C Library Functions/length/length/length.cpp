
#include "stdafx.h"
#include<iostream>
using namespace std;



char *NewConcat(char *s1, char *s2);


int main()
{
  char str1[90]= {"Test"};
  char* str2= {"String"};
  cout << "Before Concat str1 = " << str1 << " and str2 = " << str2 << endl;
  cout << "After concat the new str3 = " << NewConcat(str1, str2) << endl;
  system("pause");
}

char *NewConcat(char *s1, char *s2)
{
  int i, j, len1 = strlen(s1), len2 = strlen(s2), len3 = len1+len2;
  char *s3 = new char[len3];
  if(!s1 || !s2 || sizeof(s3)==0)
  {
    return NULL;
  }
  for(i=0; s1[i]; i++)
  {
	  s3[i] = s1[i];
  }
  for(j=0; s2[j]; j++)
  {
    s3[len1+j] = s2[j];
  }
  s3[len1+j] = NULL;
  return s3;
}