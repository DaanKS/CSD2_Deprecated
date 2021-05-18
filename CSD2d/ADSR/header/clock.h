#ifndef CLOCK_H_
#define CLOCK_H_

#include "generator.h"
#include <vector>
#include <string>

#pragma once



class Clock{
    std::vector<class Generator*> generators;
public:
    Clock();
    ~Clock();
    
    void attach(class Generator* generator);
    void tick(); //notify()

protected:
  

};


#endif