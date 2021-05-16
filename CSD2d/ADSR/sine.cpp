#include "sine.h"

Sine::Sine(double samplerate, double frequency) : Oscillator(samplerate)
{
    this->frequency=frequency;
    this->samplerate=samplerate;
}

Sine::~Sine()
{}

void Sine::tick()
{
    phase += frequency / samplerate;
    sample = sin(M_PI * 2 * phase);
   
}

double Sine::getSamplerate()
{
    return samplerate;
}