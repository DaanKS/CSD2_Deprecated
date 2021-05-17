#include "envelope.h"

Envelope::Envelope() : Generator(samplerate)
{
 //   samplerate = 44100;
   // adsr.attack = 500;
   // adsr.decay = 960;
   // attackTime = round((samplerate / 1000.0) * adsr.attack);
    std::cout << attackTime << std::endl;
    multistack = multiplier / attackTime;

}

Envelope::~Envelope()
{}



double Envelope::ADSR(double input)
{
    if(stage == "attackMode"){
          multiplier += multistack;
          std::cout << "Ik ben attackMode\n";
          return input * multiplier;

      }
      else if(stage == "decayMode"){
          multiplier -= multistack;
          std::cout << "Ik ben decayMode\n";
          return input * multiplier;

      }
      else if(stage == "sustainMode") {
          multiplier = sustainLevel;
          std::cout << "Ik ben sustainMode!\n";
          return input * multiplier;
      }
      else if(stage == "releaseMode"){
        multiplier -= multistack;
        std::cout << "Ik ben releaseMode\n";
        return input * multiplier;
      }
      else{
        multiplier = 0;
        return input * multiplier;
      } 

}

void Envelope::reset()
{
    multiplier = 0.0;
}

void Envelope::setAttackTime(double attack){
    double attackTime = round((samplerate / 1000.0) * attack);  
}

void Envelope::setDecayTime(double decay){
    double decayTime = round((samplerate / 1000.0) * decay);   
}
void Envelope::setSustainLevel(double sustain){
   this->sustainLevel = sustain;
}
void Envelope::setReleaseTime(double release){
    double releaseTime = round((samplerate / 1000.0) * adsr.release);
}

double Envelope::getAttackTime(){
    return attackTime;
}
double Envelope::getDecayTime(){
    return decayTime;
}
double Envelope::getSustainLevel(){
    return sustainLevel;
}
double Envelope::getReleaseTime(){
    return releaseTime;
}
