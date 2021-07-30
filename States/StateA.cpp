#include "StateA.h"
#include "StateB.h"

void StateA::enter(Fan* fan)
{
	this->mTemperature = fan->getTemp();
	std::cout<<"IFanState: A"<<std::endl;
    std::cout<<"Temperature: "<< this->getTemp() <<std::endl;
}
void StateA::toggle(Fan* fan)
{
	// this->enter(fan);
	fan->setRPM(40);
	// High -> Low
	while(this->mTemperature > 0)
	{
		if(this->mTemperature <= 26){
			fan->setState(StateB::getInstance());
			fan->toggle();
		}
		this->mTemperature+=this->delta;
		fan->setTemp(this->mTemperature);
		std::cout<<"A: Current Temp: " << this->mTemperature << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));

	}

	}

IFanState& StateA::getInstance()
{
	static StateA singleton;
    std::cout<<"IFanState: StateA"<<std::endl;
	return singleton;
}