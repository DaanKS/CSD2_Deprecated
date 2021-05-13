#include "synthesizer.h"

Synthesizer::Synthesizer() : Generator(samplerate)
{}

Synthesizer::~Synthesizer()
{}

void Synthesizer::noteOn()
{
    envelope.reset();
}

void Synthesizer::noteOff()
{}

double Synthesizer::processENV(double INPUT)
{
    envelope.inputSample(INPUT);
}


void Synthesizer::changeFreq(double frequency)
{
    sine.setFrequency(frequency);
    sine.getFrequency();
}