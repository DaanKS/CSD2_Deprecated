#ifndef CLOCK_H_
#define CLOCK_H_

#include <vector>
#include <string>

#pragma once



class Clock{
    
public:
    
    
    void tick();

protected:
    std::string ADSRSTAGES[5]{"attackMode", 
    "decayMode", 
    "sustainMode", 
    "releaseMode",
    "IDLE"};

};


#endif