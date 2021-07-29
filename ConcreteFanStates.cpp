#include "ConcreteFanStates.h"

void StateC::toggle(Fan* fan)
{
	// this->enter(fan);
	fan->setRPM(0);
	// Off -> Low
	while(this->mTemperature > 0)
	{
		if(this->mTemperature > 28)
		{
			fan->setState(StateB::getInstance());
			fan->toggle();
		}
		else if (this->mTemperature > 30)
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
	std::cout<<"FanState: C"<<std::endl;
    std::cout<<"Temperature: "<< this->getTemp() <<std::endl;
}

FanState& StateC::getInstance()
{
	static StateC singleton; 
	return singleton;
}

void StateB::enter(Fan* fan)
{
	this->mTemperature = fan->getTemp();
	std::cout<<"FanState: B"<<std::endl;
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

FanState& StateB::getInstance()
{
	static StateB singleton;
    std::cout<<"FanState: StateB"<<std::endl;
	return singleton;
}

void StateA::enter(Fan* fan)
{
	this->mTemperature = fan->getTemp();
	std::cout<<"FanState: A"<<std::endl;
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

FanState& StateA::getInstance()
{
	static StateA singleton;
    std::cout<<"FanState: StateA"<<std::endl;
	return singleton;
}