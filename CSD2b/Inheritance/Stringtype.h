#include "Instrument.h"

using namespace std;

class Stringtype : public Instrument
{
public:
//constructor destructor
  Stringtype();
  Stringtype(int sound);
  Stringtype(string soundPlay, int stringAmount);
  //Stringtype(int stringAmount);
  ~Stringtype();

  //setters getters
  void setStringAmount(int stringAmount);
  int getStringAmount();

  //methods
  void pluck(int stringNumber);
//  void bow(int stringNumber);

protected:
  int stringAmount;
  int stringNumber;
  string soundPlay = "Wuuu\n";
};
