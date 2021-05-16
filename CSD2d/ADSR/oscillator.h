#ifndef OSCILLATOR_H_
#define OSCILLATOR_H_

#include "generator.h"
#include <cmath>

class Oscillator : public Generator 
{
    public:
        Oscillator(double samplerate);
        ~Oscillator();

        void setFrequency(double frequency) override;
        double getFrequency() override;


    protected:
        
        double phase;
};

#endif