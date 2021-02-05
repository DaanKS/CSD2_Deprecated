#include <iostream>
#include "Instrument.h"
using namespace std;


string sound;

int main()
{
Instrument instrument1; {
  instrument1.setSound(sound);
  instrument1.getSound();
  instrument1.play(sound);
  }
Instrument instrument2; {
  instrument2.setSound(sound);
  instrument2.getSound();
  instrument2.play(sound);
}
  return 0;
}
