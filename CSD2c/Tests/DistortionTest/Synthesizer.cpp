#include "Synthesizer.h"
#include <cmath>
//Constructor Destructor
Synthesizer::Synthesizer(double samplerate, double frequency, double amplitude)
{
this->samplerate=samplerate;
this->frequency=frequency;
this->amplitude=amplitude;
}

Synthesizer::~Synthesizer()
{}

void Synthesizer::setFrequency(double frequency)
{
  //protection against illegal inputs
  if(frequency > 0 && frequency < 20001){
    //if the frequency is within the accepted range it changes.
    this->frequency=frequency;
  }else{
    std::cout << "INVALID FREQUENCY";
  }
}

double Synthesizer::getFrequency()
{
  return frequency;
}

void Synthesizer::setAmplitude(double amplitude)
{
  if(amplitude >= 0 && amplitude <= 1){
    this->amplitude=amplitude;
  }else{
    std::cout << "INVALID AMPLITUDE";
  }
}

double Synthesizer::getSample()
{
  return sample;
}

void Synthesizer::tick()
{
  phase += frequency / samplerate;
  sampletje = sin(M_PI * 2 * phase);
  scSoftclip(sampletje, drive);
}

void Synthesizer::setDrive(int drive)
{
  std::cout << "input drive amount: \n";
  std::cin >> drive;
  this->drive = drive;
}

int Synthesizer::getDrive()
{
  return drive;
}
double Synthesizer::scSoftclip(double sampletje, int drive) {
//Drive amount
drive = std::max(drive, 0); //Protection against negative numbers
float x1 = sampletje * drive;
float x2 = (x1 * x1) + 0.25;
sample = x1 / x2;
return sample;
}
