#pragma once
#include "FanState.h"

// Forward declaration to resolve circular dependency/include
class FanState;

class Fan
{
public:
	// Fan();
	Fan(double temp);
	inline FanState* getCurrentState() const { return currentState; }
	void toggle();
	// This is where the magic happens
	void setState(FanState& newState);
	void setRPM(int value){this->mRPM = value;};
	int getRPM(){ return mRPM; }
	void setTemp(double value){this->mTemperature = value;}
	double getTemp(){return mTemperature;}

private:
	FanState* currentState;
	int mRPM;
	double mTemperature;

};