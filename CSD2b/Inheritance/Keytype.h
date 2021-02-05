#include "Instrument.h"

using namespace std;

class Keytype: public Instrument
{
public:
// constructor destructor
  Keytype();
  Keytype(int sound);
  Keytype(string soundPlay, int keyAmount);
  // Keytype(int keyAmount);
  ~Keytype();


  // setters and getters

  void setKeyAmount(int keyAmount);
  int getKeyAmount();

  //methods
  void hammer(int keyNumber);

protected:
  int keyAmount;
  int keyNumber;
  string soundPlay = "Tung";
};
