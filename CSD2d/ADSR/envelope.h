#ifndef ENVELOPE_H_
#define ENVELOPE_H_

#pragma once

#include "generator.h"
#include "adsrvalues.h"
#include <cmath>

class Envelope : public Generator
{
    public:
        Envelope();
        ~Envelope();

        
        
        double ADSR(double input) override;
        
        void reset() override;
    /*
        void setAttackTime(double attackTime);
        void setDecayTime(double decayTime);
        void setSustainLevel(double sustainLevel);
        void setReleaseTime(double releaseTime);

        double getAttackTime();
        double getDecayTime();
        double getSustainLevel();
        double getReleaseTime(); 
    */
        ADSRvalues adsr;

    
    protected:
        double attackTime = round((samplerate / 1000.0) * adsr.attack);
        double decayTime = round((samplerate / 1000.0) * adsr.decay);
        double sustainLevel = adsr.sustain;
        double releaseTime = round((samplerate / 1000.0) * adsr.release);
        double sample;
        double input;
        
        double multistack = 0.0;
        double multiplier = 1.0;
};


#endif