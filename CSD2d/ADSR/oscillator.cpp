#include "oscillator.h"

Oscillator::Oscillator(Clock* klok, double samplerate) : Generator(klok, samplerate)
{}

Oscillator::~Oscillator()
{}

void Oscillator::setFrequency(double frequency)
{
    if(frequency > 0 && frequency < 20000){
        this->frequency=frequency;
    }else{
        std::cout << frequency << " is an impossible frequency\n";
    }
}

double Oscillator::getFrequency()
{
    return frequency;
}