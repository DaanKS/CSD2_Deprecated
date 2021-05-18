#include "HardClip.h"


//Class Initiation
Hardclip::Hardclip(Clock* klok, double samplerate) : Generator(klok, samplerate)
{}
Hardclip::~Hardclip()
{}

void Hardclip::tick(){
  drive = std::max(drive, 0); 
  double x1 = drySample * drive;
    if(x1 > 1){
      wetSample = 1;
    }else if(x1 < -1){
      wetSample = -1;
    }else{
      wetSample = x1;
    }
}

double Hardclip::getSample(){
  return wetSample;
}

double Hardclip::Catch(double input){
  drySample = input;
  return drySample;
}

void Hardclip::setDrive(int drive){
  this->drive = drive;
}

int Hardclip::getDrive(){
  return drive;
}
