#include "Record.h"


Record::Record(void)
{
	this->AverageofWaitingTime=0;
	this->SumofPeople=0;
	this->SumofWaitingTime=0;
}
void Record::Initialize()
{
	this->AverageofWaitingTime=0;
	this->SumofPeople=0;
	this->SumofWaitingTime=0;
	this->RecordDate.Goesby();
}

Record::~Record(void)
{
}
