#include <cmath>
#include "TapeShifter.h"


#define MAX_DELAY_SIZE 441000
#define DELAY_TIME_SEC 1.0f

#define PI_2 6.28318530717959
#define PI 3.14159265358979323846264338327950288419716939937510

TapeShifter::TapeShifter() : circBuffer(numSamplesDelay * 2), circBuffer2(numSamplesDelay * 2), saw1(1, samplerate)
{
  //put this before the buffer loop in the main.cpp
    circBuffer.setDistanceRW(numSamplesDelay);
    circBuffer2.setDistanceRW(numSamplesDelay);
}

TapeShifter::~TapeShifter()
{}

void TapeShifter::signalToBeShifted(double inputFromInbuff)
{
//Put this in the buffer loop where inputFromIbuff = inbuf[i]
  circBuffer.write(inputFromInbuff);
  circBuffer2.write(inputFromInbuff);
}

double TapeShifter::pitchshiftedSignal()
{
  /*
  * Put this in the buffer loop
  * below is a windowing calculation: So you don't have to read it I will describe it here
  * Output = X1 * (SawWave_Output * cos)
  * Output = X2 * (SawWave_Output -- Phaseshifted -- * cos)
  */

    outPutSample = ((circBuffer.read() * 0.5) * cos((saw1.getSample() -0.5) * PI)) + ((circBuffer2.read() * 0.5) * cos((std::fmod((saw1.getSample() + 0.5), 1.0) -0.5) * PI));
    circBuffer.tick();
    circBuffer2.tick();
  // Delay time modulation
    circBuffer.setDistanceRW(((saw1.getSample() * 100.0) + 5.0) * 44.1);
  //second buffer modulation at half a wavelength difference
    circBuffer2.setDistanceRW(((std::fmod((saw1.getSample() + 0.5), 1.0 ) * 100.0) + 5.0) * 44.1);
    saw1.tick();

    return outPutSample;
}

void TapeShifter::changeSawFrequency(double sawFrequency)
{
  saw1.setFrequency(sawFrequency);
  saw1.getFrequency();
}
