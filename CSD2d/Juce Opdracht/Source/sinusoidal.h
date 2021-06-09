/*
  ==============================================================================

    sinusoidal.h
    Created: 5 Jun 2021 10:12:40pm
    Author:  Dean

  ==============================================================================
*/

#pragma once
#include "waveshaper.h"

class Sinus : public Waveshaper{
public:
    Sinus();
    ~Sinus();
    
    double tick(double drySignal) override;
    
};
