#include "Time.h"
#include <iostream>
#define BEGINHOUR 8
#define BEGINMIN 0
using namespace std;

void Time::Timegoesby()
{
	this->minutes++;
	if(this->minutes==60)
	{
		this->hour++;
		this->minutes=0;
	}
	if(this->hour==24)
	{
		this->hour=0;
	}

}

void Time::PrintTime()
{
	if(this->hour>=10)cout<<"      "<<"当前时间:"<<this->hour<<":";
	else cout<<"      "<<"当前时间:0"<<this->hour<<":";
	if(this->minutes>=10)cout<<this->minutes;
	else cout<<"0"<<this->minutes;
}
Time::Time(void)
{
	this->hour=BEGINHOUR;
	this->minutes=BEGINMIN;
}


Time::~Time(void)
{
}
