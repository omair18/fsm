#include "StateC.h"
#include "StateA.h"
#include "StateB.h"

void StateC::toggle(Fan* fan)
{
	// this->enter(fan);
	fan->setRPM(0);
	// Off -> Low
	while(this->mTemperature > 0)
	{
		if(this->mTemperature > 30)
		{
			fan->setState(StateB::getInstance());
			fan->toggle();
		}
		else if (this->mTemperature > 32)
			fan->setState(StateA::getInstance());
		
		this->mTemperature+=this->delta;
		fan->setTemp(this->mTemperature);
		std::cout<<"C: Current Temp: " << this->mTemperature << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}
void StateC::enter(Fan* fan)
{
	this->mTemperature = fan->getTemp();
	std::cout<<"IFanState: C"<<std::endl;
    std::cout<<"Temperature: "<< this->getTemp() <<std::endl;
}

IFanState& StateC::getInstance()
{
	static StateC singleton; 
	return singleton;
}