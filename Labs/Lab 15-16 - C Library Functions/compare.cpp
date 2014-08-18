#include<iostream>
using namespace std;

int compare(char *s1, char *s2);

int main()
{
	char* myS="hello world";
	char* myS1="hello world";
	cout << compare(myS,myS1) << endl;

	char* myS2="hello world";
	char* myS3="helloo world";
	cout << compare(myS2,myS3) << endl;

	char* myS4="hellooo world";
	char* myS5="helloo world";
	cout << compare(myS4,myS5) << endl;
}

int compare(char *s1, char *s2)
{
	while (*s1==*s2)
	{
		if(*s1==NULL)
			return(0);
		s1++;
		s2++;
	}
	return(*s1-*s2);
}