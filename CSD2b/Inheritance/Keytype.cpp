#include "Keytype.h"

using namespace std;

//constructor
Keytype::Keytype()
{
  cout << "Keytype Constructor\n";
}

Keytype::Keytype(int sound) : Instrument(sound)
{
  cout << "Keytype Constructor, sound\n";
}

Keytype::Keytype(string soundPlay, int keyAmount)
{
  cout << "Keytype Constructor, SoundPlay, keyAmount\n";
}

Keytype::~Keytype()
{
  cout << "Keytype destructor\n";
}

// setters getters
void Keytype::setKeyAmount(int keyAmount)
{
    cout << "How many keys you got? \n";
    cin >> keyAmount;
    if(keyAmount > 0){
    this->keyAmount = keyAmount;
    }else{
      cout << "Invalid input\n";
  }
}

int Keytype::getKeyAmount()
{
  cout << "Your Keytype instrument has " << keyAmount << " keys\n";
  return keyAmount;
}
//methods
void Keytype::hammer(int keyNumber)
{
  cout << "keyNumber to play: ";
  cin >> keyNumber;
  if(keyNumber <= keyAmount && keyNumber > 0){
    cout << "Instrument goes brrrrr\n";
  }else{
    cout << "invalid input\n";
  }
}
