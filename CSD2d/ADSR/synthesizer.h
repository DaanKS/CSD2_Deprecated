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
        void changeFreq(double frequency);
        void tick() override;
        double getGot();

        Sine sine{samplerate, 400};
        Envelope envelope;
    private: 
        double INPUT;
        double frequency;
        double OUTPUT;


};

#endif