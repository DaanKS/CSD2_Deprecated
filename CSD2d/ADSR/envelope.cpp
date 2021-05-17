#include "envelope.h"

Envelope::Envelope() : Generator(samplerate)
{

}

Envelope::~Envelope()
{}



double Envelope::ADSR(double input)
{
    if(stage == "attackMode"){
          multiplier += attackstack;
          std::cout << "Ik ben attackMode\n";
          return input * multiplier;

      }
      else if(stage == "decayMode"){
          multiplier -= decaystack;
          std::cout << "Ik ben decayMode\n";
          return input * multiplier;

      }
      else if(stage == "sustainMode") {
          multiplier = sustainLevel;
          std::cout << "Ik ben sustainMode!\n";
          return input * multiplier;
      }
      else if(stage == "releaseMode"){
        multiplier -= releasestack;
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
    attackstack = multiplier / attackTime; 
}

void Envelope::setDecayTime(double decay){
    double decayTime = round((samplerate / 1000.0) * decay); 
    decaystack = multiplier / decayTime;  
}
void Envelope::setSustainLevel(double sustain){
   this->sustainLevel = sustain;
}
void Envelope::setReleaseTime(double release){
    double releaseTime = round((samplerate / 1000.0) * adsr.release);
    releasestack = multiplier / releaseTime;
}

double Envelope::getAttackTime(){
    return attackstack;
}
double Envelope::getDecayTime(){
    return decaystack;
}
double Envelope::getSustainLevel(){
    return sustainLevel;
}
double Envelope::getReleaseTime(){
    return releasestack;
}

void Envelope::stageChanger()
{
    if(stageindex == 0 || stageindex < 5){
        stage = ADSRSTAGES[stageindex];
        stageindex++;
    }
    else{
        stageindex = 4;
    }
}

std::string Envelope::stagePusher()
{
    return stage;
}
