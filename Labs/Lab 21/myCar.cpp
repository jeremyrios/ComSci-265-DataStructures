#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const char* tab = "\t";

class Car{
  public:
	Car(bool,int, int, int, int, char);
	void startCar();
	int getGas();
	int getGear();
	void setGear();
	int getBattery();
	int getSpeed();
	int getDistance();
	char getDirection();
	void Accelerate();
	void goLeft();
	void goRight();
	void goBackward();
	void Brake();
	void disDashBoard();

  private:
	bool OnOff;
	int Gas;
	int Battery;
	int Speed;
	int Distance;
	char Direction;
};

Car::Car(bool onOrOff, int gasLevel, int batteryLevel, int Spd, int dis, char dir)
:OnOff(onOrOff),Gas(gasLevel),Battery(batteryLevel),Speed(Spd),Distance(dis),Direction(dir){}

int Car::getGas()
{
  if(Gas < 2)
  {
	cout << "Running Low On Gas" << endl;
  }
  return Gas;
}

int Car::getBattery()
{
  return Battery;
}

int Car::getSpeed()
{
  return Speed;
}

int Car::getDistance()
{
  return Distance;
}

char Car::getDirection()
{
  return Direction;
}

void Car::startCar()
{
  if(OnOff == false && Gas!=0 && Battery!=0)
  {
	cout << endl << "Engine On" << endl;
	OnOff = true;
  }
  else if (Gas==0 || Battery==0)
  {
	cout << endl << "Out of Gas or Charge" << endl;
  }
  else
  {
	cout << endl << "Engine is already running" << endl;
  }
}

void Car::Accelerate()
{
  Speed = Speed + 1;
  if (Speed <= 5)
  {
	Distance = Distance + 1;
	Gas = Gas - 1;
  }
  else if (Speed >5 && Speed <=10)
  {
	Distance = Distance + 2;
	Gas = Gas - 2;
  }
  else if (Speed >10 && Speed <20)
  {
	Distance = Distance + 4;
	Gas = Gas - 4;
  }
  else
  {
    cout << endl << "Cant Go Any Faster" << endl;
  }
  cout << endl << "We are going " << Speed << " units fast" << endl;
}

void Car::Brake()
{
  if(Speed != 0)
  {
	Speed = Speed - 5;
  }
  else
  {
    cout << endl << "Car Is Not Moving" << endl;
  }
}

void Car::goRight()
{
  if (Direction == 'N')
  {
	Direction = 'E';
	cout << endl << "We are going East" << endl;
  }
  else if (Direction == 'E')
  {
	Direction = 'S';
	cout << endl << "We are going South" << endl;
  }
  else if (Direction == 'S')
  {
	Direction = 'W';
	cout << endl << "We are going West" << endl;
  }
  else if (Direction == 'W')
  {
	Direction = 'N';
	cout << endl << "We are going North" << endl;
  }
}

void Car::goLeft()
{
  if (Direction == 'N')
  {
	Direction = 'W';
	cout << endl << "We are going West" << endl;
  }
  else if (Direction == 'W')
  {
    Direction = 'S';
	cout << endl << "We are going South" << endl;
  }
  else if (Direction == 'S')
  {
	Direction = 'E';
	cout << endl << "We are going Eest" << endl;
  }
  else if (Direction == 'E')
  {
	Direction = 'N';
	cout << endl << "We are going North" << endl;
  }
}

void Car::goBackward()
{
  if (Direction == 'N')
  {
	Direction = 'S';
	cout << endl << " We are going South" << endl;
  }
  else if (Direction == 'W')
  {
	Direction = 'E';
	cout << endl << " We are going East" << endl;
  }
  else if (Direction == 'S')
  {
	Direction = 'N';
	cout << endl << " We are going North" << endl;
  }
  else if (Direction == 'E')
  {
	Direction = 'W';
	cout << endl << " We are going West" << endl;
  }
}

void disDash()
{
	cout << endl
	     << tab << "A) Start Car"    << endl
	     << tab << "B) Accelerate"   << endl
	     << tab << "C) Go Left"      << endl
	     << tab << "D) Go Right"     << endl
	     << tab << "E) Brake"        << endl
	     << tab << "F) Go Backward"  << endl
	     << tab << "G) Get Gas"      << endl
	     << tab << "H) Get Charge"   << endl
	     << tab << "I) Turn Car Off" << endl << endl
		 << "     Please choice a option A - I " << endl
		 << "     Choice: ";
}

int main()
{
  bool OnOff = false;
  int Gas = 10;
  int Battery = 10;
  int Gear = 0;
  int Speed = 0;
  int Distance = 0;
  char Direction = 'N';
  char choice = '0';

  Car myCar(OnOff, Gas, Battery, Speed, Distance, Direction);

  cout << "\n\t\t\t" << "Hello Driver\n";

  while (choice != 'I')
  {
	disDash();
	cin >> choice;
	choice = toupper(choice);
	while(choice < 'A' || choice > 'I')
	{
	  cout << "\n\n\n"
		   << tab << "     *** E R R O R ***       " << endl
		   << tab << "       Invalid entry     \n\n" << endl;
	  disDash();
	  cin >> choice;
	  choice = toupper(choice);
	}	

	switch (choice)
	{
	  case 'A':
		myCar.startCar();
		break;
	  case 'B': cout << endl << "You have choosen to accelerate." << endl;
		myCar.Accelerate();
		break;
	  case 'C': cout << endl << "You have choosen to go left." << endl;
		myCar.goLeft();
		break;
	  case 'D': cout << endl << "You have choosen to go right." << endl;
		myCar.goRight();
		break;
	  case 'E': cout << endl << "You have choosen to brake." << endl;
		myCar.Brake();
		break;
	  case 'F': cout << endl << "You have choosen to go backward." << endl;
		myCar.goBackward();
		break;
	  case 'G': cout << endl << "You have choosen to get gas." << endl;
	    cout  << endl << "You currently have " << myCar.getBattery() << " gallons of gas." << endl;
		break;
	  case 'H': cout << endl << "You have choosen to get charge." << endl;
		cout  << endl << "Your battery power is currently" << myCar.getGas() << " Volts." << endl;
		break;
	}
  }
  return 0;
}