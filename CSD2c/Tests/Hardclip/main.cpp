#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "SoftClip.h"

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

// 10 seconds if samplerate = 44100
// #define MAX_DELAY_SIZE 441000
// #define DELAY_TIME_SEC 1.0f

// #define PI_2 6.28318530717959

// Run program and set delaytime as argument (in seconds)

int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();

  // retrieve either default or console line argument delaytime
//  float delayTimeSec = DELAY_TIME_SEC;
//  if(argc >= 2) delayTimeSec = (float) atof(argv[1]);
//  std::cout <<  "\nDelay time in seconds: " << delayTimeSec << "\n";

  // transform delay time in seconds to delay time in number of samples
//  int numSamplesDelay = samplerate * delayTimeSec;
//  std::cout << "\ninput is delay by " << numSamplesDelay << " number of samples\n";

  // instantiate circular buffer, 2x larger then delay time and set delay
//  CircBuffer circBuffer(numSamplesDelay * 2);
//  circBuffer.setDistanceRW(numSamplesDelay);
//  circBuffer.logAllSettings();
  //creating sinewave
//  Sine sine1(1, samplerate);

//Creating Softclipper
Softclip softy1;

  //assign a function to the JackModule::onProces
  jack.onProcess = [&softy1](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {

      // write input to distortion
      softy1.Catch(inBuf[i]);
      // calculate distortion
      softy1.Soft(); //"drive was not declared in this scope"
      // read distorted
      outBuf[i] = softy1.Clip();



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
      case 'd':
        softy1.setDrive();
        softy1.getDrive();
    }
  }

  //end the program
  return 0;
} // main()
