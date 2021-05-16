#include <iostream>
#include <thread>
#include "jack_module.h"
#include <cmath>
#include "synthesizer.h"

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


  Synthesizer synth(samplerate);


  //assign a function to the JackModule::onProces
  jack.onProcess = [&synth](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    static float amplitude = 0.15;

    for(unsigned int i = 0; i < nframes; i++) {

      outBuf[i] = synth.processENV(synth.getSample() * amplitude);
      synth.tick();
    }
    return 0;
  };

  jack.autoConnect();

  
  bool running = true;
      double frequency;
      
  while (running)
  {

    switch (std::cin.get())
    {
      case 'q':
        {running = false;
        jack.end();
        break;}     
      case 'c':
      {
        std::cout << "Place new Frequency: ";
        std::cin >> frequency;
        frequency = synth.changeFreq(frequency);
        
        break;
      case 'r':
        synth.noteOn();
        break;
      }
   }
  }

  //end the program
  return 0;
} // main()
