#pragma once
#include "States/IFanState.h"
#include <iostream>
#include <chrono>
#include <thread>

// Forward declaration to resolve circular dependency/include
class IFanState;

class Fan
{
public:
	// Fan();
	Fan(double temp);
	inline IFanState* getCurrentState() const { return currentState; }
	void toggle();
	// This is where the magic happens
	void setState(IFanState& newState);
	void setRPM(int value){this->mRPM = value;};
	int getRPM(){ return mRPM; }
	void setTemp(double value){this->mTemperature = value;}
	double getTemp(){return mTemperature;}

private:
	IFanState* currentState;
	int mRPM;
	double mTemperature;

};