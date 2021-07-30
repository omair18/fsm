#include "Fan.h" 

int main() 
{ 
    class IFanState;

    double temp;

    std::cout<<"Enter initial temperature: ";
    std::cin>> temp;

    Fan fan(temp); 
    fan.toggle();

    return 0; 
}