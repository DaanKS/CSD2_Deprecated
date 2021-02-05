#ifndef _INSTRUMEMT_H_
#define _INSTRUMENT_H_

#include <string>
#include <iostream>
#pragma once

using namespace std;

class Instrument{

public:
  Instrument();
  Instrument(string sound);
  ~Instrument();

  //setters and getters
  void setSound(string sound);
  string getSound();

// methods
void play(string sound);

protected:
  string sound;


};

#endif
