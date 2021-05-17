#ifndef CLOCK_H_
#define CLOCK_H_

#include "generator.h"
#include <vector>
#include <string>

#pragma once



class Clock{
    std::vector<Generator*> generators;
public:
    
    void attach();
    void tick();

protected:
  

};


#endif