#include <iostream>
#include "Stringtype.h"
#include "Keytype.h"
#include "Instrument.h"

using namespace std;

int main()
{
int sound;
int keyAmount;
int keyNumber;
int stringAmount;
int stringNumber;

/*  Instrument instrument1;
   instrument1.setSound(sound);
   instrument1.getSound();
   instrument1.play(sound);
    if(sound == 1){ */
      Keytype keytype1;
       keytype1.setKeyAmount(keyAmount);
        keytype1.getKeyAmount();
        keytype1.hammer(keyNumber);

  //  }else if(sound == 2){
      Stringtype stringtype1;
        stringtype1.setStringAmount(stringAmount);
        stringtype1.getStringAmount();
        stringtype1.pluck(stringNumber);


  //  }else{
    //  cout << "invalid input";
  //  }



//  Keytype akeytype();
//  Stringtype astringtype();

  return 0;
}
