#pragma once
#include "Fan.h"

// Forward declaration to resolve circular dependency/include
class Fan;

class FanState
{
public:
	virtual void enter(Fan* fan) = 0;
	virtual void toggle(Fan* fan) = 0;
	void exit(Fan* fan){}
	void setTemp(double val) {this->mTemperature = val;}
	double getTemp(){this->mTemperature;}
	virtual ~FanState() {}
protected:
	double mTemperature;
};