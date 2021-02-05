#include "Square.h"
#include <cmath>


//Constructor Destructor

Square::Square(double samplerate, double frequency, double amplitude)
: Melody(samplerate, frequency, amplitude)
{}


Square::~Square()
{}

void Square::tick()
{
  //if sine is 0 or higher make it one. If not make it -1.
  phase += frequency / samplerate;
   sampletje = sin(M_PI * 2 * phase);
   if(sampletje >= 0){
     sample = 1;
   }else{
     sample = -1;
   }
}
