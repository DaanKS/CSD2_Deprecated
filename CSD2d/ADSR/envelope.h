#ifndef ENVELOPE_H_
#define ENVELOPE_H_

#pragma once

#include "generator.h"
#include "adsrvalues.h"
#include <cmath>

class Envelope : public Generator
{
    public:
        Envelope(Clock* klok);
        ~Envelope();

        
        
        double ADSR() override;
        void tick() override;
        
        void reset() override;
       
        void setAttackTime(double attack);
        void setDecayTime(double decay);
        void setSustainLevel(double sustain);
        void setReleaseTime(double release);

        double getAttackTime();
        double getDecayTime();
        double getSustainLevel();
        double getReleaseTime();  

        void multCalc() override;
        void soundEliminator() override;

        double returnMult();
       
    
     ADSRvalues adsr{
         .attack = 1,
         .decay = 10,
         .sustain = 0.02,
         .release = 100
     };
   
    protected:
    //mstosamps
        double attackTime = round((samplerate / 1000.0) * adsr.attack);
        double decayTime = round((samplerate / 1000.0) * adsr.decay);
        double sustainLevel = adsr.sustain;
        double releaseTime = round((samplerate / 1000.0) * adsr.release);
        double sample;
        double input;
        double amp = 1.0;
        double multiplier = 1.0;
        std::string stage;
        std::string ADSRSTAGES[5]{"attackMode", 
                                    "decayMode", 
                                    "sustainMode", 
                                    "releaseMode",
                                    "IDLE"};
        int stageindex = 0;
        int sampleIndex = 0;
};


#endif