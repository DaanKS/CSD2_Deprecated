#include "Melody.h"

using namespace std;

class Noise : public Melody
{
public:
  //Constructor Destructor
  Noise(double samplerate, double frequency, double amplitude);
  ~Noise();

  void tick();


};
