#include "Stringtype.h"

using namespace std;


// int stringAmount;

//constructor
Stringtype::Stringtype()
{
  cout << "Stringtype Constructor\n";
}



Stringtype::Stringtype(int sound) : Instrument(sound)
{
  cout << "Stringtype Constructor, sound\n";
}

Stringtype::Stringtype(string soundPlay, int stringAmount)
{
  cout << "Stringtype Constructor, SoundPlay, stringAmount\n";
}

//destructor
Stringtype::~Stringtype()
{
  cout << "Stringtype destructor\n";
}

//setters and getters
void Stringtype::setStringAmount(int stringAmount)
{
  cout << "How many strings you got? \n";
  cin >> stringAmount;
  if(stringAmount > 0){
    this->stringAmount = stringAmount;
      }else{
  cout << "Invalid Input \n";
    }
}

int Stringtype::getStringAmount()
{
    cout << "Your Stringtype instrument has " << stringAmount << "strings \n";
    return stringAmount;
}

//methods
void Stringtype::pluck(int stringNumber)
{
  cout << "stringNumber to play: \n";
  cin >> stringNumber;
  if(stringNumber <= stringAmount && stringNumber > 0){
    cout << "Instrument goes toing\n";
  }else{
    cout << "invalid input\n";
  }
}
