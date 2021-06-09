/*
  ==============================================================================

    sinusoidal.cpp
    Created: 5 Jun 2021 10:12:40pm
    Author:  Dean

  ==============================================================================
*/

#include "sinusoidal.h"

Sinus::Sinus() : Waveshaper()
{}
Sinus::~Sinus(){}

double Sinus::tick(double drySignal){
    wetSignal = sin(drySignal * drive);
    return wetSignal * postGain;
}
