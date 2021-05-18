#include "../header/generator.h"

Generator::Generator(Clock* klok, double samplerate){
    clock = klok;
    clock->attach(this);
    samplerate = 44100.0;
    this->samplerate=samplerate;
}

Generator::~Generator(){}

double Generator::getSample(){
    return sample;
}

void Generator::tick(){}

void Generator::setFrequency(double frequency){}
double Generator::getFrequency(){}

void Generator::reset(){}
double Generator::ADSR(){}
void Generator::multCalc(){}
void Generator::soundEliminator(){}

void Generator::setDrive(int DRIVE){}
int Generator::getDrive(){}
double Generator::Catch(double driveInput){}