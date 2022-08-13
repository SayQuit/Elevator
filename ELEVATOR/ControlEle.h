#pragma once
#include "Elevator.h"
class ControlEle
{
public:
	Elevator *ele[100];
	int elevatornumber;


	void NewAnElevator();

	ControlEle(void);
	~ControlEle(void);
};

