// Used calculations from Martin Finke's ADSR for exponential curves
// 
#include "../header/envelope.h"
#include <cmath>

Envelope::Envelope(Clock* klok) : Generator(klok, samplerate){
    stage = "IDLE";
    stageindex = 4;
    sampleIndex = 0;
    amp = 0;
}

Envelope::~Envelope(){    
}
//getSample
double Envelope::ADSR(){         
    if(stage == "sustainMode"){
        amp = sustainLevel;
    }
    else{   
        amp *= multiplier;
    }   
    if(amp < 0.00000000001){
        amp = 0.;
    }
    return amp;     
}
//TODO remove magic numbers
//Sample counter that moves through the ADSR states
 void Envelope::tick(){
   stage = ADSRSTAGES[stageindex];
   
        if(stage == "attackMode"){
          if(sampleIndex < attackTime){
              multiplier = 1.0 + (log(1.0) - log(0.0001)) / (attackTime);
              sampleIndex++;
          }
          else{
              stageindex++;
              sampleIndex = 0;
          }
          
      }
      else if(stage == "decayMode"){
          if(sampleIndex < decayTime){
              multiplier = 1.0 + (log(sustainLevel) - log(1.0)) / (decayTime); 
              sampleIndex++;
          }
          else{
              stageindex++;
              sampleIndex = 0;
          }    
      }
      else if(stage == "releaseMode"){
            if(sampleIndex < releaseTime){
                multiplier = 1.0 + (log(0.0001) - log(sustainLevel)) / (releaseTime); 
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
//trigger release state
void Envelope::soundEliminator(){
    stage = "releaseMode";
    stageindex = 3;
    sampleIndex = 0;
}
//trigger attack state
void Envelope::reset(){
    stage = "attackMode";
    stageindex = 0;
    sampleIndex = 0;    
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

double Envelope::returnMult(){
    return amp;   
}