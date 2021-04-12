#include "HardClip.h"
#include <unistd.h>

//Class Initiation
Hardclip::Hardclip()
{
//  this->drive = drive;
}
Hardclip::~Hardclip()
{}
//HardClip
void Hardclip::hardClipCalc()
{
  drive = std::max(drive, 0); //Protection against negative numbers
  float x1 = sampletje * drive;

    if(x1 > 1){
      sample = 1;
    }else if(x1 < -1){
      sample = -1;
    }else{
      sample = x1;
    }

}

double Hardclip::getClipCalc()
{
  return sample;
}
//Catch functie
double Hardclip::readInputSamples(double input)
{
  sampletje = input;
  return sampletje;
}
//setters getters
void Hardclip::setDrive(int drive)
{
  
  this->drive = drive;
  
}

int Hardclip::getDrive()
{
  return drive;
}

void Hardclip::changeDrive(int drive, std::mutex& theMutex)
{
  std::unique_lock<std::mutex> myLock(theMutex);
  setDrive(drive);
  getDrive();
  myLock.unlock();
}