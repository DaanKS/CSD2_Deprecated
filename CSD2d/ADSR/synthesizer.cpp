#include "synthesizer.h"
#include "sine.h"


Synthesizer::Synthesizer(Clock* klok, double samplerate) : Generator(klok, samplerate){
    envelope=new Envelope(klok);
    generator=new Sine(klok ,samplerate, 200);
    
}

Synthesizer::~Synthesizer()
{}

void Synthesizer::noteOn(){
   envelope->reset();
}

void Synthesizer::noteOff()
{}

double Synthesizer::processENV(double INPUT){
   return envelope->ADSR(INPUT);
    
}


double Synthesizer::changeFreq(double frequency){
    this->generator->setFrequency(frequency);
    frequency = this->generator->getFrequency();
    std::cout << frequency << std::endl;
    return frequency;
}

void Synthesizer::tick(){
    this->generator->tick();
    this->envelope->tick();
    this->envelope->sampleCounter();
     
}

double Synthesizer::getSample(){
  
  return generator->getSample();
}
