#include "Melody.h"

using namespace std;

class Square : public Melody
{
public:
  //Constructor Deconstructor
  Square(double samplerate ,double frequency, double amplitude);
  ~Square();

  //methods

  void tick();

protected:
  double sampletje;
};
