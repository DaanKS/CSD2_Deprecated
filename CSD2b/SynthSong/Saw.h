#include "Melody.h"

using namespace std;

class Saw : public Melody
{
public:
  Saw(double samplerate, double frequency, double amplitude);
  ~Saw();

  // setters getters and other methods

  void tick();

};
