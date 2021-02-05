#include "Melody.h"

class RingMod : public Melody
{
  //Two Oscillators at different speeds, one that multiplies the other one
public:
  //Constructor Destructor
  RingMod(double samplerate, double frequency, double amplitude);
  ~RingMod();

  //methods

  void tick();
};
