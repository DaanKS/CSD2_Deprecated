//A wave to modulate the delay time
//To start I am going to test it with a sine wave. AFterwards I will
//use a unipolar sawtoothwave
// Duplicate the delay heads and add windowing -- final step

#ifndef _SINE_H_
#define _SINE_H_



//Class
class Sine {
public:
  Sine(double frequency, double samplerate);
  ~Sine();

//methods:

//Frequency (Amplitude must be 100% at all times) Will add scaling after calculation
void setFrequency(double frequency);
double getFrequency();
//getsample and tick
double getSample();
void tick();

//protected variables
protected:
double samplerate = 44100;
double frequency;
double phase;
double amplitude = 1.0;
double sampletje;

};

#endif
