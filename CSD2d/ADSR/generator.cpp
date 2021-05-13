#include "generator.h"

Generator::Generator(double samplerate)
{
    this->samplerate=samplerate;
}

Generator::~Generator()
{}

double Generator::getSample()
{
    return sample;
}

void Generator::tick()
{}

