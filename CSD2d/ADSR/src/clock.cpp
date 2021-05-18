#include "../header/clock.h"

Clock::Clock() = default;
Clock::~Clock() = default;

void Clock::attach(Generator *generator){
    generators.push_back(generator);
}

void Clock::tick(){
    for (long unsigned int x = 0; x < generators.size(); x++)
        generators[x]->tick();
}