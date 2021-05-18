#include "synthesizer.h"
#include "sine.h"


Synthesizer::Synthesizer(Clock* klok, double samplerate) : Generator(klok, samplerate){
    envelope=new Envelope(klok);
    generator=new Sine(klok ,samplerate, 200);
    hardclip=new Hardclip(klok, samplerate);
     
}

Synthesizer::~Synthesizer()
{}

void Synthesizer::noteOn(){
   envelope->reset();
}

void Synthesizer::noteOff(){
    envelope->soundEliminator();
}


double Synthesizer::changeFreq(double frequency){
    this->generator->setFrequency(frequency);
    frequency = this->generator->getFrequency();
    return frequency;
}

int Synthesizer::changeDrive(double DRIVE){
    this->hardclip->setDrive(DRIVE);
    DRIVE = this->hardclip->getDrive();
    return DRIVE; 
}

void Synthesizer::tick(){
    this->generator->tick();
    this->envelope->tick();
    this->hardclip->tick();
    this->envelope->multCalc(); 
    changeFreq((envelope->returnMult()* 500) + 20);  
}

double Synthesizer::getSample(){
    hardclip->Catch(envelope->ADSR() * generator->getSample());
    return hardclip->getSample();
}
