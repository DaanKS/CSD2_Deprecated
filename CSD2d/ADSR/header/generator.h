#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <iostream>
#include "clock.h"
#pragma once


class Generator{
public:
    Generator(class Clock* klok, double samplerate);
    ~Generator();

    
    virtual double getSample();
    virtual void tick();
    virtual void setFrequency(double frequency);
    virtual double getFrequency();

    virtual void reset();
    virtual double ADSR();
    virtual void multCalc();
    virtual void soundEliminator();

    virtual double Catch(double driveInput);
    virtual void setDrive(int DRIVE);
    virtual int getDrive();

protected:
    Clock* clock;
    double samplerate = 44100;
    double sample;
    double frequency;
    
    double driveInput;
    
};

#endif