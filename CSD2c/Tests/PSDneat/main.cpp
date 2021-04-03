#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "circBuffer.h"
#include "Saw.h"
#include "HardClip.h"
#include "TapeShifter.h"

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

// 10 seconds if samplerate = 44100
/*#define MAX_DELAY_SIZE 441000
#define DELAY_TIME_SEC 1.0f

#define PI_2 6.28318530717959
#define PI 3.14159265358979323846264338327950288419716939937510
*/
// Run program and set delaytime as argument (in seconds)

int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  float samplerate = jack.getSamplerate();

  TapeShifter tapeShifter1;
//  tapeShifter1.initializeShifter();
  Hardclip hard1;
  //assign a function to the JackModule::onProces
  jack.onProcess = [&tapeShifter1, &hard1](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      // write input to delays
      tapeShifter1.signalToBeShifted(inBuf[i]);

      // read delayed output and distort it.
      hard1.Catch(tapeShifter1.pitchshiftedSignal());
      //calculate distortion
      hard1.Hard();
      //read distorted signal
      outBuf[i] = hard1.Clip();
    }
    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;

  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
      case 'c':
        tapeShifter1.changeSawFrequency();
        break;
      case 'd':
        hard1.setDrive();
        hard1.getDrive();
        break;
    }
  }

  //end the program
  return 0;
} // main()
