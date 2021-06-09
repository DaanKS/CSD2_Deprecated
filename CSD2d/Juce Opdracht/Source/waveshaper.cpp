/*
  ==============================================================================

    waveshaper.cpp
    Created: 5 Jun 2021 10:12:30pm
    Author:  Dean

  ==============================================================================
*/

#include "waveshaper.h"

Waveshaper::Waveshaper(){}
Waveshaper::~Waveshaper(){}

double Waveshaper::tick(double input){}

void Waveshaper::setDrive(double drive){
    this->drive=drive;
}

double Waveshaper::getDrive(){
    return drive;
}
void Waveshaper::setPostGain(double postGain){
    this->postGain=postGain;
}
double Waveshaper::getPostGain(){
    return postGain;
}
