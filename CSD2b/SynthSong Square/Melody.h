#ifndef _MELODY_H_
#define _MELODY_H_

#include "Oscillator.h"
#include <vector>
#include <thread>

using namespace std;

class Melody : public Oscillator
{
public:
  Melody(double samplerate, double frequency, double amplitude);
  ~Melody();

  //methods
  void setbeatsPermin(int bPm);
  int getbeatsPermin();

  void play(double frequency, int bPm);

protected:

  vector<double> lick {0.749159091, 1.0, 1.122454545, 1.189204545, 1.334840909, 1.122454545, 0.890909091, 1.0};
  vector<int> timing {1, 1, 1, 1, 1, 2, 1, 1};
  int bPm;
  int bpm;
  double freq;

};

#endif
