#ifndef _SYNTH_H_
#define _SYNTH_H_
#include <iostream>

class Synth
{
public:
  //Constructor Destructor
  Synth(double samplerate);
  ~Synth();

protected:
  double samplerate;


};

#endif
