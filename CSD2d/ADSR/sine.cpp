#include "sine.h"

Sine::Sine(double frequency) : Oscillator()
{
    this->frequency=frequency;
}

Sine::~Sine()
{}

void Sine::tick()
{
    phase += frequency / samplerate;
    sample = sin(M_PI * 2 * phase);
}