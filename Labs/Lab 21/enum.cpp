#include <iostream>
using namespace std;

enum DayNames {   Sunday,
                  Monday,
                  Tuesday,
                  Wednesday,
                  Thursday,
                  Friday,
                  Saturday };


void main(){
	
	enum DayNames dayOfWeek;

	cout << "value for sun is: " << Sunday << endl;
	cout << "value for mon is: " << Monday << endl;
	cout << "value for tue is: " << Tuesday << endl;
	cout << "value for wed is: " << Wednesday << endl;
	cout << "value for thur is: " << Thursday << endl;
	cout << "value for fri is: " << Friday << endl;
	cout << "value for sat is: " << Saturday << endl;

	if (dayOfWeek == Sunday ){
		Monday = 7;
	}

}