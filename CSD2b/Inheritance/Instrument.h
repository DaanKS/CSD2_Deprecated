#ifndef _INSTRUMENT_H_
#define _INSTRUMENT_H_

#include <iostream>
#pragma once
using namespace std;

class Instrument{

public:
  Instrument();
  Instrument(int sound);
  ~Instrument();

  // setters and getters
  void setSound(int sound);
  int getSound();

  //methods
  void play(int sound);

protected:
  int sound;
};

#endif
