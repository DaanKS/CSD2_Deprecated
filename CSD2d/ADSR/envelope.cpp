#include "envelope.h"

Envelope::Envelope(Clock* klok) : Generator(klok, samplerate)
{
    attackstack = multiplier / attackTime; 
    decaystack = multiplier / decayTime;
    releasestack = multiplier / releaseTime;

}

Envelope::~Envelope()
{}

double Envelope::ADSR(double input)
{
    if(stage == "attackMode"){
          std::cout << "Ik ben attackMode\n";
          return input * multiplier;
      }
      else if(stage == "decayMode"){         
          std::cout << "Ik ben decayMode\n";
          return input * multiplier;
      }
      else if(stage == "sustainMode") {         
          std::cout << "Ik ben sustainMode!\n";
          return input * multiplier;
      }
      else if(stage == "releaseMode"){     
        std::cout << "Ik ben releaseMode\n";
        return input * multiplier;
      }
      else{  
        return input * multiplier;
      } 

}

void Envelope::tick()
{
    if(stage == "attackMode"){
          multiplier += attackstack;
      }
      else if(stage == "decayMode"){
          multiplier -= decaystack;    
      }
      else if(stage == "sustainMode") {
          multiplier = sustainLevel;    
      }
      else if(stage == "releaseMode"){
        multiplier -= releasestack;   
      }
      else{
        multiplier = 0;    
      } 

}

void Envelope::sampleCounter(){
   stage = ADSRSTAGES[stageindex];
        if(stage == "attackMode"){
          if(sampleIndex > attackTime){
              sampleIndex++;
          }
          else{
              stageindex++;
              sampleIndex = 0;
          }
          
      }
      else if(stage == "decayMode"){
          if(sampleIndex > decayTime){
              sampleIndex++;
          }
          else{
              stageindex++;
              sampleIndex = 0;
          }    
      }
      else if(stage == "sustainMode") {
          stageindex++;    
      }
      else if(stage == "releaseMode"){
        if(sampleIndex > releaseTime){
            stageindex++;
            sampleIndex = 0;
        }  
      }
      else{
       sampleIndex = 0;    
      } 
}

void Envelope::reset(){
    stage = "attackMode";
    
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

