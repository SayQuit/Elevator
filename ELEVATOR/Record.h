#pragma once
#include "Date.h"
class Record
{
public:
	Record(void);
	~Record(void);

	Date RecordDate;
	int SumofWaitingTime;
	int SumofPeople;
	int AverageofWaitingTime;

	void Initialize();
};

