// #ifdef STATE_B_H
// #define STATE_B_H

#include "IFanState.h"
#include "Fan.h"

class StateB : public IFanState
{
public:
	void enter(Fan* fan);
	void toggle(Fan* fan);
	void exit(Fan* fan);
	static IFanState& getInstance();

private:
	StateB() {}
	StateB(const StateB& other);
	StateB& operator=(const StateB& other);
    double delta = -0.05;
};
// #endif