#include<iostream>
using namespace std;

char* copyN(char* s1,char* s2, int n){
	int len= strlen(s2);
	if (len<n){
		for(int i=0;i<=len;i++){
			s1[i]=s2[i];
			s1[i+1]=NULL;
		}
		return s1;
	}
	else {
		for(int i=0;i<=n;i++){
			s1[i]=s2[i];
			s1[n]=NULL;
		}
		return s1;
	}
}

int main(){
	char* myS= {"helllllo world"};
	char myS2[40];
	copyN(myS2,myS,2);
	cout << myS2 << endl;
}