// #ifdef _STATE_C_H_
// #define _STATE_C_H_

#include "IFanState.h"
#include "Fan.h"

class StateC : public IFanState
{
public:
	void enter(Fan* fan);
	void toggle(Fan* fan);
	void exit(Fan* fan);
	static IFanState& getInstance();

private:
	StateC() {}
	StateC(const StateC& other);
	StateC& operator=(const StateC& other);
    double delta = 0.5;
};
// #endif