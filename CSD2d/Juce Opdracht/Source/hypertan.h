/*
  ==============================================================================

    hypertan.h
    Created: 5 Jun 2021 10:12:55pm
    Author:  Dean

  ==============================================================================
*/

#pragma once
#include "waveshaper.h"

class Tanh : public Waveshaper{
public:
    Tanh();
    ~Tanh();
    
    double tick(double drySignal) override;
    
};
