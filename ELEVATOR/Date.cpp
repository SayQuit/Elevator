#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(void)
{
}

void Date::Goesby()
{
	if(this->day<=27)this->day++;
	else
	{
		if(this->day==28)
		{
			if(this->month==2)
			{
				if(this->year%100==0)
				{
					if(this->year%400==0)
					{
						this->day++;
					}
				}
				else
				{
					if(this->year%4==0)
					{
						this->day++;
					}
				}
			}
		}
		else if(this->day==29)
		{
			if(this->month==2)
			{
				this->day=1;
				this->month++;
			}
		}
		else if(this->day==30)
		{
			if(this->month==1||this->month==3||this->month==5||this->month==7||this->month==8||this->month==10||this->month==12)
			{
				this->day++;
			}
			else if(this->month==4||this->month==6||this->month==9||this->month==11)
			{
				this->day=1;
				this->month++;
			}
		}
		else if(this->day==31)
		{
			this->day=1;
			this->month++;
			if(this->month>12)
			{
				this->month=1;
				this->year++;
			}
		}
	}
}

void Date::show()
{
	cout<<this->year<<".";
	cout<<this->month<<".";
	cout<<this->day;
}

Date::~Date(void)
{
}


