#include "clock.h"

Clock::Clock(){}
Clock::~Clock(){}

void Clock::attach(Generator *generator){
    generators.push_back(generator);
}



void Clock::tick(){
    for (int x = 0; x < generators.size(); x++)
        generators[x]->tick();
}