#pragma once
#include "FanState.h"
#include "Fan.h"
#include <iostream>
#include <chrono>
#include <thread>

class StateC : public FanState
{
public:
	void enter(Fan* fan);
	void toggle(Fan* fan);
	void exit(Fan* fan);
	static FanState& getInstance();

private:
	StateC() {}
	StateC(const StateC& other);
	StateC& operator=(const StateC& other);
    double delta = 0.5;
};

class StateB : public FanState
{
public:
	void enter(Fan* fan);
	void toggle(Fan* fan);
	void exit(Fan* fan);
	static FanState& getInstance();

private:
	StateB() {}
	StateB(const StateB& other);
	StateB& operator=(const StateB& other);
    double delta = -0.05;
};

class StateA : public FanState
{
public:
	void enter(Fan* fan);
	void toggle(Fan* fan);
	void exit(Fan* fan);
	static FanState& getInstance();

private:
	StateA() {}
	StateA(const StateA& other);
	StateA& operator=(const StateA& other);
    double delta = -0.2;
};