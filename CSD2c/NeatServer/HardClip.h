#ifndef _HARDCLIP_H_
#define _HARDCLIP_H_

#include <iostream>
#include <mutex>

//Class Initiation
class Hardclip{
//acces specifier
public:
  Hardclip();
  ~Hardclip();
//Calculation
void hardClipCalc();
double getClipCalc();

//setters and getters
void setDrive(int drive);
int getDrive();
void changeDrive(int drive, std::mutex& theMutex);

//Catching the inbuf[i]
double readInputSamples(double input);

//Acces specifier
protected:
//variabeles
double sampletje;
double sample;
 int drive;
double input;
};

#endif
