#include <iostream>
#include <thread>
#include "../header/jack_module.h"
#include <cmath>
#include "../header/synthesizer.h"
#include <chrono>


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

  Clock klok;
  Synthesizer synth(&klok, samplerate);


  //assign a function to the JackModule::onProces
  jack.onProcess = [&synth, &klok](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    static float amplitude = 0.15;

    for(unsigned int i = 0; i < nframes; i++) {

      outBuf[i] =(synth.getSample() * amplitude);
      klok.tick();
      
    }
    return 0;
  };

  jack.autoConnect();

  
  bool running = true;
     double frequency;
     int drive;
      
  while (running)
  {

    switch (std::cin.get())
    {
      case 'q':
        {running = false;
        jack.end();
        break;}     
      case 'd':
        std::cout << "Place new Drive: ";
        std::cin >> drive;
        drive = synth.changeDrive(drive);
        break;
      case 'r':
        synth.noteOn();
        break;
      case 't':
        synth.noteOff();
      case 'p':
        synth.noteOn();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        synth.noteOff();
        break;      
   }
  }

  //end the program
  return 0;
} // main()
