#include "Melody.h"
#include "Saw.h"


Saw::Saw(double samplerate, double frequency, double amplitude)
: Melody(samplerate, frequency, amplitude)
{}

Saw::~Saw()
{}

void Saw::tick()
{
  //This calculation was given to me by Bas Maat
  phase += frequency / samplerate;
  // wrap phase from 0 to 1
  if(phase >= 1) phase = phase - 1;
  sample = (phase*2)-1;
}
