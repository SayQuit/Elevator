#pragma once
#include "Passengers.h"
#include "Time.h"
#include "Date.h"
#include "Record.h"
class Elevator
{
public:
	char **elevator;
	int elevator_width,elevator_realheight,elevator_fakeheight,Volume;
	int Capacity,nowWeight;
	int elefloor,tofloor,UporDown,stop;
	int EnergyConsume;
	Passengers *passengers[100];
	Record Dayrecord;
	Record *Pastrecord[100];
	Date Elevatordate;
	int inNumber,insideNum;
	Time Elevatortime;
	int daytime;

	int OverLoad;
	

	void Create();
	void Setelevator_width();
	void Setelevator_height();

	void Scan();
	bool Scanoptimize_Up();
	bool Scanoptimize_Down();
	void ScanUpDown();
	void FixInnumber();

	void Print();
	void Running();
	void Enter();
	void Leave(int weight,int);
	void Flash(int);
	bool Judge();
	bool JudgeThisFloor();
	void TakeThePassengers();
	void PassengersOrderLeftShift(int first,int last);
	void ChangeTheScreen();
	void PrintElevatorMessage();
	void PrintPassengersMessage();
	void GoDown();
	void DayChange();
	void CopyRecord();
	void ChangeStatic();
	int PedestrianVolume();

	void Queuecorrection();
	void CheckOutPastStatic();

	void Fix();



	
	
	
	Elevator(void);
	~Elevator(void);
private:
	
	
};

