#include "Sine.h"
#include <cmath>
//constructor destructor
Sine::Sine(double frequency, double samplerate)
{
  this->samplerate = samplerate;
  this->frequency = frequency;
}

Sine::~Sine()
{}

//Methods
//Ignoring protection for now
void Sine::setFrequency(double frequency)
{
  this->frequency = frequency;
}

double Sine::getFrequency()
{
  return frequency;
}
//getSample and tick
double Sine::getSample()
{
  return sampletje;
}

void Sine::tick()
{
  phase += frequency / samplerate;
  sampletje = sin(M_PI * 2 * phase);
}
