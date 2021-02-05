#include "Oscillator.h"


Oscillator::Oscillator(double samplerate, double frequency, double amplitude)
: Synth(samplerate)
{
  this->samplerate = samplerate;
  this->frequency = frequency;
  this->amplitude = amplitude;
}

Oscillator::~Oscillator()
{}

void Oscillator::setFrequency(double frequency)
{
  if(frequency > 0 && frequency < 20000){
    this->frequency=frequency;
  }else{
    std::cout << "INVALID FREQUENCY\n";
  }
}
double Oscillator::getFrequency()
{
  return frequency;
}
void Oscillator::setAmplitude(double amplitude)
{
  if(amplitude > 0 && amplitude <= 1){
    this->amplitude = amplitude;
  }else{
    std::cout << "INVALID AMPLITUDE\n";
  }
}

double Oscillator::getSample()
{
  return sample;
}
