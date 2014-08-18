#include<iostream>
using namespace std;

char *newConcat(char *s1, char *s2){

	int len= strlen(s1);
	if(s1==NULL ||s2==NULL)
		return s1;
	for(int i=0;i<=len;i++){
			s1[len+i]=s2[i];
	}
	return s1;
}

int main(){
	char myS[90]= {"helllllo world"};
	char* myS2= {"helllllo world"};
	cout << newConcat(myS,myS2) << endl;
}