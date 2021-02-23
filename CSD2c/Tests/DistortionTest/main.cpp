#include <iostream>
#include <thread>
#include "jack_module.h"
#include <cmath>
#include "Synthesizer.h"

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

#define PI_2 6.28318530717959

int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
  Synthesizer sine(samplerate, 220, 1.0);

  //assign a function to the JackModule::onProces
  jack.onProcess = [&sine](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    static float amplitude = 0.15;

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = inBuf[i];
      sine.tick();
    }

    return 0;
  };

  jack.autoConnect();
  int drive = 1;
  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      {case 'q':
        running = false;
        jack.end();
        break;}
      {case 'd':
        sine.setDrive(drive);
        sine.getDrive();
    }
  }
}

  //end the program
  return 0;
} // main()
