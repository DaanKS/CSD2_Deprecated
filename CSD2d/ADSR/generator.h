#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <iostream>

#pragma once


class Generator{
public:
    Generator(double samplerate);
    ~Generator();

    double getSample();
    virtual void tick();

protected:
    double samplerate = 44100;
    double sample;

};

#endif