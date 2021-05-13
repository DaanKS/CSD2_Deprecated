#include "synthesizer.h"
#include "sine.h"


Synthesizer::Synthesizer(double samplerate) : Generator(samplerate)
{}

Synthesizer::~Synthesizer()
{}

void Synthesizer::noteOn()
{
    envelope.reset();
}

void Synthesizer::noteOff()
{

}

double Synthesizer::processENV(double INPUT)
{
    envelope.inputSample(INPUT);
    OUTPUT = envelope.ADSR();
    return OUTPUT;
}


void Synthesizer::changeFreq(double frequency)
{
    sine.setFrequency(frequency);
    sine.getFrequency();
}

void Synthesizer::tick()
{
    sine.tick();
}

double Synthesizer::getGot()
{
    std::cout << sine.getSamplerate();
}
