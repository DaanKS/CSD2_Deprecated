#ifndef SINE_H_
#define SINE_H_

#include "oscillator.h"

class Sine : public Oscillator
{
    public:
        
        Sine(double samplerate, double frequency);
        ~Sine();

        void tick() override;
       

        double getSamplerate();

};

#endif