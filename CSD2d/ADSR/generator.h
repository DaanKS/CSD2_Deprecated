#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <iostream>

#pragma once


class Generator{
public:
    Generator(double samplerate);
    ~Generator();

    
    virtual double getSample();
    virtual void tick();
    virtual void setFrequency(double frequency);
    virtual double getFrequency();

    virtual void reset();
    virtual double ADSR(double INPUT);

    

protected:
    double samplerate = 44100;
    double sample;
    double frequency;
    double INPUT;
};

#endif