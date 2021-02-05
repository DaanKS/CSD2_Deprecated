#include "Noise.h"
#include <stdlib.h>



//Constructor Destroctor

Noise::Noise(double samplerate, double frequency, double amplitude)
: Melody(samplerate, frequency, amplitude)
{}

Noise::~Noise()
{}

void Noise::tick()
{
  double scaling = 100.0;
  sample = ((((rand() % 100.0) / scaling) * 2.0) - 1.0);
}
