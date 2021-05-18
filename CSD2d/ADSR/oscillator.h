#ifndef OSCILLATOR_H_
#define OSCILLATOR_H_

#include "generator.h"
#include <cmath>

class Oscillator : public Generator 
{
    public:
        Oscillator(Clock* klok, double samplerate);
        ~Oscillator();

        void setFrequency(double frequency) override;
        double getFrequency() override;


    protected:
        
        double phase;
};

#endif