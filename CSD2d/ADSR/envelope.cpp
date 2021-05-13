#include "envelope.h"

Envelope::Envelope() : Generator(samplerate)
{
    adsr.attack = 40;
    adsr.decay = 960;
    multistack = multiplier / attackTime;
}

Envelope::~Envelope()
{}

double Envelope::ADSR()
{
    return sample;
}

void Envelope::inputSample(double input)
{
    if(multiplier < 1.0){
        multiplier += multistack; 
    }
    else {
        multiplier = 1.0;
    }    
    sample = sample * multiplier;

}

void Envelope::reset()
{
    multiplier = 0.0;
}


