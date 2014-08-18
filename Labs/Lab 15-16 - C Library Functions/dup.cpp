#include<iostream>
using namespace std;

char *dup(char *s){
	int len= strlen(s);
	char *sDup = new char[len];
	for(int i=0;i<=len;i++){
		sDup[i]=s[i];
	}
	return sDup;
}

int main(){
	char* myS= {"helllllo world"};
	cout << dup(myS) << endl;
}