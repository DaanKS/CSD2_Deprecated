#include "envelope.h"

Envelope::Envelope() : Generator(samplerate)
{
 //   samplerate = 44100;
   // adsr.attack = 500;
   // adsr.decay = 960;
   // attackTime = round((samplerate / 1000.0) * adsr.attack);
    std::cout << attackTime << std::endl;
    multistack = multiplier / attackTime;

}

Envelope::~Envelope()
{}



double Envelope::ADSR(double input)
{
    if(multiplier < 1.0){
        multiplier += multistack; 
    }
    else {
        multiplier = 1.0;
    }    
    return input * multiplier;

}

void Envelope::reset()
{
    multiplier = 0.0;
}


