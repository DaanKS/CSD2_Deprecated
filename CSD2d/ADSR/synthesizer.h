#ifndef SYNTHESIZER_H_
#define SYNTHESIZER_H_

#include "sine.h"
#include "envelope.h"
#include "generator.h"

#pragma once

class Synthesizer : public Generator
{
    public:
        Synthesizer();
        ~Synthesizer();

        void noteOn();
        void noteOff();
        double processENV(double INPUT);
        void changeFreq(double frequency);
        
        Sine sine{400};
        Envelope envelope;
    private: 
        double INPUT;
        double frequency;


};

#endif