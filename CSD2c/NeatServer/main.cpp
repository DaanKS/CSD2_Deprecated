#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "circBuffer.h"
#include "Saw.h"
#include "HardClip.h"
#include "TapeShifter.h"
#include "Server.h"
#include <mutex>

#include <atomic>

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */
int tussenStap;

int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
//  float samplerate = jack.getSamplerate();

  TapeShifter tapeShifter1;
  std::mutex myMutex;
  Hardclip hard1;
  hard1.setDrive(1);
  hard1.getDrive();
  TCPservertje server1(54000);

    //assign a function to the JackModule::onProces
  std::atomic_bool running(true);

  jack.onProcess = [&tapeShifter1, &hard1, &server1](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      // write input to delays
      tapeShifter1.signalToBeShifted(inBuf[i]);

      hard1.readInputSamples(tapeShifter1.pitchshiftedSignal());
      hard1.hardClipCalc();
      outBuf[i] = hard1.getClipCalc();
    }
    return 0;
  };

  jack.autoConnect();



  //run the server outside on the jack on processing in a new thread. 
  //all this time I thought the jack on process was the issue, but it wasn't. 
  //Gunna make a new thread here for the server. 
  std::thread serverThread( [&]()
  {
    server1.startTheServer();
    while(running)
    {
      tussenStap = server1.sliderOutput(myMutex);
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  });
  
  std::thread hardClipThread( [&]()
  {
    while(running)
    {
      hard1.changeDrive(tussenStap, myMutex);
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  });
  std::thread switchThread( [&]()
  {
    while(running)
    {
      switch (std::cin.get())
      {
      case 'q':
        running = false;
        jack.end();
        break;    
      }
    }
  });
  
  switchThread.join();
  serverThread.join();
  hardClipThread.join();
  //end the program
  return 0;
} // main()
