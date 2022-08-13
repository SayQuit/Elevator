#include "Passengers.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <Windows.h>
using namespace std;
Passengers::Passengers(void)
{
	srand(time(NULL));
	this->tofloor=rand()%22;
	//cout<<rand()<<endl;
	while(this->tofloor%2!=0)
	{
		this->tofloor=rand()%22;
		//cout<<rand()<<endl;
	}
	this->weight=rand()%90;
	//cout<<rand()<<endl;
	while(this->weight<50)
	{
		this->weight=rand()%90;
		//cout<<rand()<<endl;
	}
	//Sleep(10000);

	this->Waitingtime=0;
	this->state=0;

	
}

void Passengers::PrintMessage()
{
	printf("%14d%8d%9d",(22-this->tofloor)/2,this->weight,this->Waitingtime);
	//if(this->state==0)cout<<"   电梯外  ";
	//else if(this->state==1)cout<<"   电梯内  ";
	cout<<endl;
	//cout<<"        "<<"      "<<(this->elevator_fakeheight-this->tofloor)/2<<"       "<<this->weight<<endl;
}

Passengers::~Passengers(void)
{
}
