#include "SoftClip.h"


//Class Initiation
Softclip::Softclip()
{
//  this->drive = drive;
}
Softclip::~Softclip()
{}
//SoftClip
void Softclip::Soft()
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

double Softclip::Clip()
{
  return sample;
}
//Catch functie
double Softclip::Catch(double input)
{
  sampletje = input;
  return sampletje;
}
//setters getters
void Softclip::setDrive()
{
  int drive;
  std::cout << "Input New Drive Amount: ";
  std::cin >> drive;
  this->drive = drive;
}

int Softclip::getDrive()
{
  return drive;
}
