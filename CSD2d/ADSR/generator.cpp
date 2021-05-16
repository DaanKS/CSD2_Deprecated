#include "generator.h"

Generator::Generator(double samplerate)
{
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