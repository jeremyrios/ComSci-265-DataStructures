#include<iostream>
using namespace std;


int length(char* s){
	int len;
	for(len=0; *s!= NULL; s++){
		len++;
	}
	return len;
}

int main(){
	char* myS="hello world";
	cout << length(myS) << endl;
}