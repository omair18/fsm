// #ifdef STATE_A_H
// #define STATE_A_H

#include "IFanState.h"
#include "Fan.h"

class StateA : public IFanState
{
public:
	void enter(Fan* fan);
	void toggle(Fan* fan);
	void exit(Fan* fan);
	static IFanState& getInstance();

private:
	StateA() {}
	StateA(const StateA& other);
	StateA& operator=(const StateA& other);
    double delta = -0.2;
};

// #endif