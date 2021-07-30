#include "StateB.h"
#include "StateA.h"
#include "StateC.h"

void StateB::enter(Fan* fan)
{
	this->mTemperature = fan->getTemp();
	std::cout<<"IFanState: B"<<std::endl;
    std::cout<<"Temperature: "<< this->mTemperature <<std::endl;
}
void StateB::toggle(Fan* fan)
{
	// Low -> High 
	fan->setRPM(20);
	while(this->mTemperature > 0)
	{
		this->mTemperature+=this->delta;

		if(this->mTemperature > 28){
			fan->setState(StateA::getInstance());
			fan->toggle();
		}
		else if (this->mTemperature < 24){
			fan->setState(StateC::getInstance());
			fan->toggle();
		}
		
		fan->setTemp(this->mTemperature);
		std::cout<<"B: Current Temp: " << this->mTemperature << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	// fan->setState(StateA::getInstance());
}

IFanState& StateB::getInstance()
{
	static StateB singleton;
    std::cout<<"IFanState: StateB"<<std::endl;
	return singleton;
}