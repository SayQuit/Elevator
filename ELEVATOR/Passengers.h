#pragma once
#include <iostream>
using namespace std;
class Passengers
{
public:
	Passengers(void);
	~Passengers(void);
	int tofloor,fromfloor;
	int weight;
	int state;
	int Waitingtime;
	string name;

	void PrintMessage();
	

	
};

