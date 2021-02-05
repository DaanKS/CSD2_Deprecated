#include <iostream>
#include <thread>
#include "jack_module.h"
#include <cmath>
#include "RingMod.h"
#include "Noise.h"
#include "Melody.h"
#include "Saw.h"
#include "Square.h"

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 * THIS CODE WAS TAKEN AND ALTERED FROM CISKA VRIEZENGA AND MARC GROENEWEGEN
 */

#define PI_2 6.28318530717959

int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();

  Square sine1(samplerate, 440.0, 1.0);



  //assign a function to the JackModule::onProces
  jack.onProcess = [&sine1](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    static float amplitude = 0.15;

    for(unsigned int i = 0; i < nframes; i++) {

      outBuf[i] = (sine1.getSample() * amplitude);
      sine1.tick();

    }
    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\n Controls:\n";
  std::cout << " q to quit\n";
  std::cout << " c to change pitch\n";
  std::cout << " b to change BPM\n";
  std::cout << " m to play a fine tune\n";
  bool running = true;
      double frequency = 440.0;
      int bPm = 120;

  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        {running = false;
        jack.end();
        break;}
      case 'c':{
      std::cout << "\n Enter new frequency: ";
      std::cin >> frequency;
      sine1.setFrequency(frequency);
      sine1.getFrequency();

        break;
      }
      case 'b':
    {
      sine1.setbeatsPermin(bPm);
    bPm = sine1.getbeatsPermin();

      break;
    }
     case 'm':
        {
          sine1.play(frequency, bPm);
      break;
    }
   }
  }

  //end the program
  return 0;
} // main()
