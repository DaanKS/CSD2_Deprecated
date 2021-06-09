/*
  ==============================================================================

    waveshaper.h
    Created: 5 Jun 2021 10:12:30pm
    Author:  Dean

  ==============================================================================
*/

#pragma once
#include <cmath>

class Waveshaper{
public:
    Waveshaper();
    ~Waveshaper();

    virtual double tick(double drySignal);
    void setDrive(double drive);
    double getDrive();
    void setPostGain(double postGain);
    double getPostGain();

protected:
    double drySignal;
    double drive;
    double wetSignal;
    double postGain;
};
