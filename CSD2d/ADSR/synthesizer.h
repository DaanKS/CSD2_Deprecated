#ifndef SYNTHESIZER_H_
#define SYNTHESIZER_H_

#include "sine.h"
#include "envelope.h"
#include "generator.h"

#pragma once

class Synthesizer : public Generator
{
    public:
        Synthesizer(double samplerate);
        ~Synthesizer();

        void noteOn();
        void noteOff();
        double processENV(double INPUT);
        double changeFreq(double frequency);
        void tick() override;
        double getSample() override;

        
        
    private:  
        Generator *envelope;
        Generator *generator;

       
        double INPUT;
        double frequency;
        double OUTPUT;


};

#endif