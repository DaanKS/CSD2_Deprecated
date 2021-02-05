#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_
#include "Synth.h"

class Oscillator : public Synth
{
public:
  //Constructor Destructor
  Oscillator(double samplerate, double frequency, double amplitude);
  ~Oscillator();

  //methods and setters and getters
  void setFrequency(double frequency);
  double getFrequency();

  void setAmplitude(double amplitude);
  double getAmplitude();

  double getSample();

protected:
  double frequency;
  double amplitude;
  double sample;
  double phase;

};

#endif
