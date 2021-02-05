#include "Instrument.h"
#include <iostream>

using namespace std;

Instrument::Instrument () : Instrument("fwoop")
{}
// constructor
Instrument::Instrument(string sound) : sound(sound){
  cout << "Instrument - Constructor Instrument(string sound)\n";
}

// deconstructor

Instrument::~Instrument()
{
  cout << "Instrument - destructor\n";
}

// setter

void Instrument::setSound(string sound)
{
  cout << "What sound does it make? (onomatopoeia): \n";
  cin >> sound;
  this->sound = sound;
}

//getter

string Instrument::getSound()
{
  cout << sound << endl;
  return sound;
}

// methods

void Instrument::play(string sound){
  cout << "instrument goes " << sound << endl;
}
