#ifndef SINE_H_
#define SINE_H_

#include "oscillator.h"

class Sine : public Oscillator
{
    public:
        
        Sine(double frequency);
        ~Sine();

        void tick() override;

};

#endif