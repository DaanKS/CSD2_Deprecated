#include "../header/HardClip.h"


Hardclip::Hardclip(Clock* klok, double samplerate) : Generator(klok, samplerate)
{}
Hardclip::~Hardclip()
{}

//Very complex calculation for distortion
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
//audio output
double Hardclip::getSample(){
  return wetSample;
}

// audio input
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
