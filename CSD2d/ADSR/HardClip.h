#ifndef HARDCLIP_H_
#define HARDCLIP_H_

#include "clock.h"
#include "generator.h"
#include <iostream>

//Class Initiation
class Hardclip : public Generator{
//acces specifier
public:
  Hardclip(Clock* klok, double samplerate);
  ~Hardclip();


void tick() override;
double getSample() override;


void setDrive(int drive) override;
int getDrive() override;

//Catching the inbuf[i]
double Catch(double driveInput) override;

//Acces specifier
protected:

  double drySample;
  double wetSample;
  int drive;
  double driveInput;
};

#endif
