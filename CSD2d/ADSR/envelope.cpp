#include "envelope.h"

Envelope::Envelope(Clock* klok) : Generator(klok, samplerate){
}

Envelope::~Envelope(){    
}

double Envelope::ADSR(){         
    amp *= multiplier;
}

void Envelope::multCalc()
// Used calculations from Martin Finke's ADSR for exponential curves
//TODO CLEAN MAGIC NUMBERS
{
    if(stage == "attackMode"){
          multiplier = 1.0 + (log(1.0) - log(0.0001)) / (attackTime);
      }
      else if(stage == "decayMode"){
           multiplier = 1.0 + (log(sustainLevel) - log(1.0)) / (decayTime);  
      }
      else if(stage == "sustainMode"){
          multiplier = sustainLevel;    
      }
      else if(stage == "releaseMode"){
        multiplier = 1.0 + (log(0.0001) - log(sustainLevel)) / (releaseTime);           
      }
      else{
        multiplier = 0;    
      } 

}

void Envelope::tick(){
   stage = ADSRSTAGES[stageindex];
        if(stage == "attackMode"){
          if(sampleIndex < attackTime){
              sampleIndex++;
          }
          else{
              stageindex++;
              sampleIndex = 0;
          }
          
      }
      else if(stage == "decayMode"){
          if(sampleIndex < decayTime){
              sampleIndex++;
          }
          else{
              stageindex++;
              sampleIndex = 0;
          }    
      }
      else if(stage == "releaseMode"){
            if(sampleIndex < releaseTime){
                sampleIndex++;
            }
            else{
                stageindex++; 
            }         
        }  
      else{
       sampleIndex = 0;  
         
      } 
}
void Envelope::soundEliminator(){
    stage = "releaseMode";
}

void Envelope::reset(){
    stage = "attackMode";
    stageindex = 0;
    sampleIndex = 0;
    
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

double Envelope::returnMult(){
    return amp;
}