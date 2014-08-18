#include <iostream>;
using namespace std;

struct item{
  char letter;
  item* prev;
};

int main()
{
  item *Top = NULL;
  return 0;
}

bool isEmpty()
{
  return (top==NULL) ? true:false;
}

void push(char l)
{
  item* temp = new item;
  temp->letter = l;
  temp -> prev = top;
  top = temp;
}

char pop()
{
  item* temp = top;
  top = temp ->prev ;
  char l = temp -> letter;
  delete temp;
  return l;
}

