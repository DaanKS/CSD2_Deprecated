#include "Melody.h"
#include <thread>
#include <chrono>

Melody::Melody(double samplerate, double frequency, double amplitude) : Oscillator(samplerate, frequency, amplitude)
{}

Melody::~Melody()
{}

void Melody::play(double frequency, int bPm)
{
  for(int i = 0; i <= 7; i++){
    freq = (frequency * lick[i]);
    this->frequency = freq;
    std::this_thread::sleep_for(std::chrono::milliseconds(timing[i]*bPm));
  }
}

void Melody::setbeatsPermin(int bPm)
{
  cout << "\n Enter BPM: ";
  cin >> bpm;
  bPm = 60000 / bpm;
  this->bPm = bPm;
}

int Melody::getbeatsPermin()
{
  return bPm;
}
