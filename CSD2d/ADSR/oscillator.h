#ifndef OSCILLATOR_H_
#define OSCILLATOR_H_

#include "generator.h"
#include <cmath>

class Oscillator : public Generator 
{
    public:
        Oscillator();
        ~Oscillator();

        void setFrequency(double frequency);
        double getFrequency();


    protected:
        double frequency;
        double phase;
};

#endif