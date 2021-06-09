/*
  ==============================================================================

    hypertan.cpp
    Created: 5 Jun 2021 10:12:55pm
    Author:  Dean

  ==============================================================================
*/

#include "hypertan.h"
Tanh::Tanh() : Waveshaper()
{}
Tanh::~Tanh(){}

double Tanh::tick(double drySignal){
    wetSignal = tanh(drySignal * drive);
    return wetSignal * postGain;
}
