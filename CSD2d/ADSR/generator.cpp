#include "generator.h"

Generator::Generator(Clock* klok, double samplerate)
{
    clock = klok;
    clock->attach(this);
    samplerate = 44100.0;
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

void Generator::setFrequency(double frequency)
{}

double Generator::getFrequency()
{}

void Generator::reset()
{}

double Generator::ADSR(double INPUT)
{}

void Generator::sampleCounter()
{}