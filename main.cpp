#include "Fan.h" 
#include "ConcreteFanStates.h"

int main() 
{ 
    class FanState;

    double temp;

    std::cout<<"Enter initial temperature: ";
    std::cin>> temp;

    Fan fan(temp); 
    fan.toggle();

    return 0; 
}