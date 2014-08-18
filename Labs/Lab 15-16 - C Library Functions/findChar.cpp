#include<iostream>
#include<cstring>
using namespace std;

char* findChar(char* s, char c)
{
	for(;*s!= NULL && c!= *s ; s++);
       return s;
}

int main(){
	char* myS="hello world";
	cout << findChar(myS, 'q') << endl;
}