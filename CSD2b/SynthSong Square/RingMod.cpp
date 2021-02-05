#include "RingMod.h"
#include <cmath>


//Constructor Destructor

RingMod::RingMod(double samplerate, double frequency, double amplitude)
: Melody(samplerate, frequency, amplitude)
{}

RingMod::~RingMod()
{}

void RingMod::tick()
{
  phase += frequency / samplerate;
   sample = sin(M_PI * 2 * phase);
}
