#ifndef SYNTHESIZER_H_
#define SYNTHESIZER_H_

#include "sine.h"
#include "envelope.h"
#include "generator.h"
#include "HardClip.h"

#pragma once

class Synthesizer : public Generator
{
    public:
        Synthesizer(Clock* klok, double samplerate);
        ~Synthesizer();

        void noteOn();
        void noteOff();
        double changeFreq(double frequency);
        void tick() override;
        double getSample() override;

        int changeDrive(double DRIVE);

        
        
    private:  
        Envelope *envelope;
        Generator *generator;
        Generator *hardclip;

       
        double INPUT;
        double DRIVE;
       
        


};

#endif