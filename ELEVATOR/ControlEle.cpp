#include "ControlEle.h"
#include "Elevator.h"

ControlEle::ControlEle(void)
{
	this->elevatornumber=0;
}


ControlEle::~ControlEle(void)
{
}

void ControlEle::NewAnElevator()
{
	this->ele[this->elevatornumber]=new Elevator;
	this->ele[this->elevatornumber]->Create();
}