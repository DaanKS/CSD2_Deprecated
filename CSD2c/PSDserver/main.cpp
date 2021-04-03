#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "circBuffer.h"
#include "Saw.h"
#include "HardClip.h"
#include "Server.h"
#include <mutex>
#include <future>


/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

// 10 seconds if samplerate = 44100
#define MAX_DELAY_SIZE 441000
#define DELAY_TIME_SEC 1.0f

#define PI_2 6.28318530717959
#define PI 3.14159265358979323846264338327950288419716939937510
// Run program and set delaytime as argument (in seconds)

int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  float samplerate = jack.getSamplerate();

  // retrieve either default or console line argument delaytime
  float delayTimeSec = DELAY_TIME_SEC;
  if(argc >= 2) delayTimeSec = (float) atof(argv[1]);
  std::cout <<  "\nDelay time in seconds: " << delayTimeSec << "\n";

  // transform delay time in seconds to delay time in number of samples
  int numSamplesDelay = samplerate * delayTimeSec;
  std::cout << "\ninput is delay by " << numSamplesDelay << " number of samples\n";

  // instantiate circular buffer, 2x larger then delay time and set delay


  CircBuffer circBuffer(numSamplesDelay * 2);
  circBuffer.setDistanceRW(numSamplesDelay);
  circBuffer.logAllSettings();

  // second circular buffer for windowing
  CircBuffer circBuffer2(numSamplesDelay * 2);
  circBuffer2.setDistanceRW(numSamplesDelay);
  circBuffer2.logAllSettings();
  //creating sawwave
  Saw saw1(1, samplerate);
  Hardclip hard1;
  TCPservertje server1(54000);
//  server1.startTheServer();
    auto future2 = std::async(&TCPservertje::startTheServer, server1);
    auto future = std::async(&TCPservertje::sliderOutput, server1);
  //assign a function to the JackModule::onProces
  jack.onProcess = [&circBuffer, &circBuffer2, &saw1, &hard1, &future](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      // write input to delays
      circBuffer.write(inBuf[i]);
      circBuffer2.write(inBuf[i]);
      // read delayed output and distort it.
      hard1.Catch(((circBuffer.read() * 0.5) * cos((saw1.getSample() -0.5) * PI)) + ((circBuffer2.read() * 0.5) * cos((std::fmod((saw1.getSample() + 0.5), 1.0) -0.5) * PI)));
      // update delay --> next sample
      circBuffer.tick();
      circBuffer2.tick();
      //calculate distortion
      hard1.Hard();
      future.get();
      //read distorted signal
      outBuf[i] = hard1.Clip();

      //Delay Modulation with mstosamps
      circBuffer.setDistanceRW(((saw1.getSample() * 100.0) + 5.0) * 44.1);
      //second buffer modulation at half a wavelength difference
      circBuffer2.setDistanceRW(((std::fmod((saw1.getSample() + 0.5), 1.0 ) * 100.0) + 5.0) * 44.1);
      saw1.tick();
    }

    return 0;
  };

  jack.autoConnect();
  // int sliderVariabel2;


  hard1.setDrive(1);
  hard1.getDrive();
  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  double frequency = 1;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
    //    server1.~TCPservertje();
        break;
      case 'c':
        saw1.setFrequency(frequency);
        saw1.getFrequency();
        break;
    //  case 'd':
    //    hard1.setDrive();
    //    hard1.getDrive();
    }
  }

  //end the program

//  serverthread2.join();
  return 0;
} // main()
