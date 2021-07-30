#include "Fan.h"
// #include "ConcreteFanStates.h"
#include "States/StateA.h"
#include "States/StateB.h"
#include "States/StateC.h"

Fan::Fan(double temp)
{
	this->mTemperature = temp;
	// All fans are initially turned off
	currentState = &StateC::getInstance();
	currentState->enter(this);
}

void Fan::setState(IFanState& newState)
{
	// currentState->exit(this);  // do stuff before we change state
	currentState = &newState;  // actually change states now
	currentState->enter(this); // do stuff after we change state
}

void Fan::toggle()
{
		// Delegate the task of determining the next state to the current state
		currentState->toggle(this);
}