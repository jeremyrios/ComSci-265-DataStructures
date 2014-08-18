#include<iostream>
using namespace std;

char *copy(char* s1, char* s2)
{
	int len= strlen(s2);
	for(int i=0; i<=len; i++)
  {
		s1[i]=s2[i];
	}
	return s1;
}

int main(){
	char* str1 = {"helllllo world"};
	char st2[40];
	copy(st1, st2);
	cout << st2 << endl;
}