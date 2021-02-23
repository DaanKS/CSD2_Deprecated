#ifndef _SYNTHESIZER_H_
#define _SYNTHESIZER_H_

#include <iostream>

//Creating the class
class Synthesizer{
//acces specifier
public:
  Synthesizer(double samplerate, double frequency, double amplitude);
  ~Synthesizer();

  //methods
void setFrequency(double frequency);
double getFrequency();

void setAmplitude(double amplitude);
double getAmplitude();

double getSample();
void tick();

void setDrive(int drive);
int getDrive();

double scSoftclip(double sampletje, int drive);

protected:
  double samplerate;
  double frequency;
  double amplitude;
  double phase;
  double sample;
  int drive = 1;
  double sampletje;
};

#endif
