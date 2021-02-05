#include "Instrument.h"
#include <iostream>

using namespace std;

Instrument::Instrument () : Instrument(0)
{}
//constructor
Instrument::Instrument(int sound) : sound(sound){
  cout << " Instrument Constructor - Instrument(int sound)\n";
}

//destructor

Instrument::~Instrument()
{
  cout << "Instrument Destructor\n";
}

//setter

void Instrument::setSound(int sound)
{
  cout << "what instrument is this? 1 or 2 \n"
  << "1: Keytype\n"
  << "2: Stringtype\n";
  cin >> sound;
  this->sound = sound;
}

//getter

int Instrument::getSound()
{
//  cout << sound << endl;
  return sound;
}

// methods
void Instrument::play(int sound){
  if(sound == 1){
    cout << "You picked Keytype \n";
  }else if (sound == 2){
    cout << "You picked Stringtype \n";
  }else{
    cout << "Invalid Entry\n";
  }
}
