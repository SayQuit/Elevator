#include "Elevator.h"
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cstdlib>
#include "Passengers.h"
#include <iomanip>
#include <fstream>
using namespace std;
Elevator::Elevator(void)
{
	this->Capacity=500;
	this->daytime=0;
	this->nowWeight=0;
	this->insideNum=0;//计数用
	this->elefloor=20;
	this->tofloor=20;
	this->stop=1;

	this->OverLoad=0;
	this->UporDown=0;
	//this->EnergyConsume=0;
	this->Volume=10000;
	this->elevator_width=40;
	this->elevator_realheight=10;
	this->elevator_width+=10;
	this->inNumber=0;

	this->Elevatordate.year=2021;
	this->Elevatordate.month=6;
	this->Elevatordate.day=20;

	this->elevator_fakeheight=(this->elevator_realheight+1)*2;
	this->elevator=new char *[this->elevator_fakeheight];
	for(int i=0;i<this->elevator_fakeheight;i++)
	{
		this->elevator[i]=new char[this->elevator_width];
	}
	
	//this->elevator=(char *)malloc(sizeof(char)*this->elevator_fakeheight*this->elevator_width);
}


Elevator::~Elevator(void)
{
}

void Elevator::Create()
{
	free(this->elevator);
	//this->elevator=(char *)malloc(sizeof(char)*this->elevator_fakeheight*this->elevator_width);

	this->elevator=new char *[this->elevator_fakeheight];
	for(int i=0;i<this->elevator_fakeheight;i++)
	{
		this->elevator[i]=new char[this->elevator_width];
	}

	for(int i=0;i<this->elevator_fakeheight;i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<this->elevator_width;j++)
			{
				if(j==0||j==this->elevator_width-11)
				{
					this->elevator[i][j]='|';
				}
				else 
				{
					this->elevator[i][j]=' ';
				}
				if(j>this->elevator_width-11)this->elevator[i][j]=' ';

				
			}

		}
		else
		{	
			for(int j=0;j<this->elevator_width;j++)
			{
				if(j==0||j==this->elevator_width-11)
				{
					this->elevator[i][j]='|';
					
				}
				else
				{
					this->elevator[i][j]='--';
				}
				if(j>this->elevator_width-11)this->elevator[i][j]=' ';
			}
			
		}
		
	}
}

void Elevator::Setelevator_width()
{
	int width;
	std::cout<<"请输入电梯宽度： ";
	cin>>width;
	this->elevator_width=width;

}
void Elevator::Setelevator_height()
{
	int height;
	std::cout<<"请输入电梯高度： ";
	cin>>height;
	this->elevator_fakeheight=(height+1)*2;
}

void Elevator::Print()
{
	cout<<endl;
	

	for(int i=0;i<this->elevator_fakeheight;i++)
	{
		cout<<"      ";


		if(i%2==0)
		{
			
			printf("%2d",this->elevator_realheight-i/2+1);
			
		}
		else cout<<"  ";


		if(i==this->elefloor)
		{
			std::cout<<"  ->";
		}
			
		else std::cout<<"    ";


		
		for(int j=0;j<this->elevator_width;j++)
		{
			cout<<this->elevator[i][j];
		}
		cout<<endl;
	}
	
}

void Elevator::Scan()
{
	while(1)
	{
		
		
		while(!this->Judge())
		{
			while(this->elefloor!=20)
			{
				this->GoDown();//BackTo_1stFloor,所有楼层没有人
				
			}
			if(this->elefloor==20)
			{
				while(!this->Judge())
				{
					this->elefloor=20;
					this->ChangeTheScreen();
				}
				
			}
			this->ChangeTheScreen();
			
		}
		
		while(!this->JudgeThisFloor())
		{
			//这层没有人
			this->stop=0;
			this->ScanUpDown();
			if(!this->Judge())
			{
				while(this->elefloor!=20)
				{
					this->GoDown();//BackTo_1stFloor,所有楼层没有人
				
				}
				if(this->elefloor==20)
				{
					while(!this->Judge())
					{
						this->elefloor=20;
						this->ChangeTheScreen();
					}
				
				}
				
			}
			

			
			else if(this->UporDown==1)
			{
				this->elefloor-=2;
				
				this->TakeThePassengers();//上升
				
			}
			else if(this->UporDown==-1)
			{
				this->elefloor+=2;
				
				this->TakeThePassengers();
				
			}
			for(int k=0;k<this->inNumber;k++)
			{
				
				
				if(this->passengers[k]->tofloor==this->elefloor&&this->passengers[k]->state==1)
				{
					//int temp=this->inNumber;
					
					this->Leave(this->passengers[k]->weight,k);

					

					//this->PassengersOrderLeftShift(k,this->inNumber);
					
					k--;
					
				}
				
			}

			//这里还要遍历一遍乘客的抵达floor用于出门

			
			
		}
		
		if(OverLoad==0)this->Enter();
		this->ScanUpDown();
		if(OverLoad==1)
		{
			if(!this->Judge())
			{
				while(this->elefloor!=20)
				{
					this->GoDown();//BackTo_1stFloor,所有楼层没有人
				
				}
				if(this->elefloor==20)
				{
					while(!this->Judge())
					{
						this->elefloor=20;
						this->ChangeTheScreen();
					}
				
				}
				
			}

			else if(this->UporDown==1)
			{
				this->elefloor-=2;
				this->TakeThePassengers();//上升
			}
			else if(this->UporDown==-1)
			{
				this->elefloor+=2;
				this->TakeThePassengers();
			}
			for(int k=0;k<this->inNumber;k++)
			{
				
				
				if(this->passengers[k]->tofloor==this->elefloor&&this->passengers[k]->state==1)
				{
					//int temp=this->inNumber;
					
					this->Leave(this->passengers[k]->weight,k);
					
				

					//this->PassengersOrderLeftShift(k,this->inNumber);
					k--;
					
				}
				
			}
		}
		this->OverLoad=0;
		if(this->elefloor==0)this->UporDown=-1;
		else if(this->elefloor==this->elevator_fakeheight-2)this->UporDown=1;
		


		
	}
}

void Elevator::Running()//(int floor,int *place)
{
	
	this->Scan();
}


void Elevator::Enter()
{
	this->OverLoad=0;
	int JudgeWeight=0,Judge=0,Passengernum=0,w=0;
	int leftBlank=0;
	this->stop=1;
	for(int i=0;i<this->elevator_width;i++)
	{
		if(this->elevator[this->elefloor][i]==' '&&((this->elevator[this->elefloor][i+1]=='*')||(this->elevator[this->elefloor][i+1]=='|')))
		{
			leftBlank=i;
		}
	}
	
	for(int i=this->elevator_width-10;i<this->elevator_width;i++)
	{
		if(this->elevator[this->elefloor][i]==' ')break;  
		else if(this->elevator[this->elefloor][i]=='*')
		{
			for(int j=0;j<this->inNumber;j++)//**************
			{
				if(this->passengers[j]->fromfloor==this->elefloor&&this->passengers[j]->state==0)//
				{
					if(JudgeWeight+this->nowWeight+this->passengers[j]->weight<=this->Capacity)
					{
						JudgeWeight+=this->passengers[j]->weight;
						Judge=1;
						Passengernum++;
					}
					else
					{
						this->OverLoad=1;
						break;
					}
				}
			}
			
			
		}
		
	}
	
	if(Judge)
	{
		this->elevator[this->elefloor][this->elevator_width-11]=' ';//开门
	
		this->ChangeTheScreen();
	
		for(int i=this->elevator_width-10;i<this->elevator_width;i++) //////////////////////////***************************
		{
			if(this->elevator[this->elefloor][i]==' ')break;  
			else if(this->elevator[this->elefloor][i]=='*'&&Passengernum)
			{
				for(int j=0;j<this->inNumber;j++)//**************
				{
					if(this->passengers[j]->fromfloor==this->elefloor&&this->passengers[j]->state==0&&this->nowWeight+this->passengers[j]->weight<=this->Capacity)//&&this->passengers[j]->weight+this->nowWeight<=this->Capacity
					{
						this->passengers[j]->state=1;
						this->insideNum++;
						this->nowWeight+=this->passengers[j]->weight;
					}
				}
				this->elevator[this->elefloor][i]=' ';
				this->elevator[this->elefloor][leftBlank]='*';
				Passengernum--;
				leftBlank--;
				
				this->ChangeTheScreen();

			
			
			}
			
				
			
			
			
		}                                ////////////////////////////****************************
		this->Fix();
		this->elevator[this->elefloor][this->elevator_width-11]='|';
		this->ChangeTheScreen();
		this->stop=0;
	}
	
	this->OverLoad=1;
	
	return;
}

void Elevator::Leave(int weight,int leavenum)
{
	this->OverLoad=0;
	this->stop=1;
	int side=0,door=0;
	for(int i=0;i<this->elevator_width;i++)
	{
		if(this->elevator[this->elefloor][i]=='|'&&i>0)
		{
			this->elevator[this->elefloor][i]=' ';
			door=i;
			break;
		}
	}
	this->ChangeTheScreen();
	for(int i=0;i<this->elevator_width;i++)
	{
		if(side==0&&this->elevator[this->elefloor][i]=='*')
		{
			this->elevator[this->elefloor][i]=' ';
			this->PassengersOrderLeftShift(leavenum,this->inNumber);
			side=1;
		}
		else if(side==1&&this->elevator[this->elefloor][i]==' '&&i!=door)
		{
			this->elevator[this->elefloor][i]='*';
			this->nowWeight-=weight;
			
			this->ChangeTheScreen();
			


			this->elevator[this->elefloor][i]=' ';
			this->ChangeTheScreen();
			this->Fix();
			this->elevator[this->elefloor][door]='|';
			this->ChangeTheScreen();
			break;
		}
	}
	
	
	this->stop=0;
}


void Elevator::Flash(int Volume)
{
	
	srand(time(NULL));
	for(int i=0;i<this->elevator_fakeheight;i++)
	{
		if(i%2!=0)continue;
		else if(i==this->elefloor)continue;
		if(rand()%Volume==0)
		{
			int j=0;
			while(this->elevator[i][this->elevator_width-10+j]=='*')j++;

			if(j==8)break;
			this->elevator[i][this->elevator_width-10+j]='*';

			this->passengers[this->inNumber]=new Passengers;
			
			while(this->passengers[this->inNumber]->tofloor==this->elefloor)
			{
				delete this->passengers[this->inNumber];
				this->passengers[this->inNumber]=new Passengers;
			}
			this->Dayrecord.SumofPeople++;
			this->passengers[this->inNumber]->state=0;
			this->passengers[this->inNumber]->fromfloor=i;
			this->inNumber++;
			
			

			this->tofloor=i;/////////////////////////////////////
			break;
		}
	}
}

bool Elevator::Judge()
{
	for(int i=0;i<this->elevator_fakeheight;i++)
	{
		for(int j=0;j<this->elevator_width;j++)
		{
			if(this->elevator[i][j]=='*')
			{
				
				return true;
			}
		}
	}
	return false;
}

bool Elevator::JudgeThisFloor()
{
	for(int i=this->elevator_width-11;i<this->elevator_width;i++)
	{
		
		if(this->elevator[this->elefloor][i]=='*')
		{
			return true;
		}
		
	}
	return false;
}

void Elevator::GoDown()
{
	this->elefloor+=2;
}

void Elevator::TakeThePassengers()
{
	if(this->UporDown==1)
	{
		for(int i=0;i<this->elevator_width;i++)
		{
			if(this->elevator[this->elefloor][i]=='|'&&i==0)continue;
			if(this->elevator[this->elefloor][i]=='|'&&i!=0)break;

			this->elevator[this->elefloor][i]=this->elevator[this->elefloor+2][i];
			this->elevator[this->elefloor+2][i]=' ';

			

		}
	}
	else if(this->UporDown==-1)
	{
		for(int i=0;i<this->elevator_width;i++)
		{
			if(this->elevator[this->elefloor][i]=='|'&&i==0)continue;
			if(this->elevator[this->elefloor][i]=='|'&&i!=0)break;

			this->elevator[this->elefloor][i]=this->elevator[this->elefloor-2][i];
			this->elevator[this->elefloor-2][i]=' ';

		}
	}
	this->ChangeTheScreen();
}

void Elevator::PassengersOrderLeftShift(int first,int last)
{
	for(int i=first;i<last;i++)
	{
		if(i==last-1)this->passengers[i]=NULL;
		else this->passengers[i]=this->passengers[i+1];
		
	}
	this->inNumber--;
	this->insideNum--;
	
}

void Elevator::ChangeTheScreen()
{
	//this->Dayrecord.AverageofWaitingTime=this->Dayrecord.SumofWaitingTime/this->Dayrecord.SumofPeople;///////
	
	//this->FixInnumber();
	this->ChangeStatic();
	
	for(int i=0;i<this->inNumber;i++)
	{
		this->passengers[i]->Waitingtime++;
	}
	this->Flash(this->PedestrianVolume());
	this->Queuecorrection();
	//this->FixInnumber();
	system("cls");
	this->PrintElevatorMessage();
	this->Print();
	this->PrintPassengersMessage();///////////////////////
	this->Elevatortime.Timegoesby();
	
	
	Sleep(1000);

	

	if(this->Elevatortime.hour==0&&this->Elevatortime.minutes==0)
	{
		ofstream static1;
		static1.open("static",ios::out|ios::app);
		static1<<this->Elevatordate.year<<" "<<this->Elevatordate.month<<" "<<this->Elevatordate.day<<" "<<endl;
		static1<<"平均等待时间:"<<this->Dayrecord.AverageofWaitingTime<<"   "<<"总等待时间:"<<this->Dayrecord.SumofWaitingTime<<"已载人数:"<<this->Dayrecord.SumofPeople<<endl;
		static1<<endl;
		static1.close();
		this->DayChange();

	}

	
	
}

void Elevator::PrintElevatorMessage()
{
	cout<<endl;
	//要打印电梯人数，目前状态，目前楼层，前往楼层
	cout<<setw(15)<<"当前日期:";
	this->Elevatordate.show();
	cout<<setw(26)<<"今日数据:";
	//cout<<setw(14)<<"昨日数据:";
	cout<<endl;
	this->Elevatortime.PrintTime();
	cout<<setw(12)<<"目前状态:";
	if(this->stop==1)cout<<"停止";          
	else if(this->UporDown==1)cout<<"上升";
	else if(this->UporDown==-1)cout<<"下降";

	cout<<setw(18)<<"平均等待时间:"<<this->Dayrecord.AverageofWaitingTime<<endl;

	cout<<setw(17)<<"电梯内人数:"<<this->insideNum;
	cout<<setw(14)<<"等待人数:"<<this->inNumber-this->insideNum;

	cout<<setw(17-this->insideNum/10)<<"已载人数:"<<this->Dayrecord.SumofPeople<<endl;///////////////11qQ

	cout<<setw(15)<<"所在楼层:"<<(this->elevator_fakeheight-this->elefloor)/2;
	cout<<setw(16-(this->elevator_fakeheight-this->elefloor)/20)<<"前往楼层:"<<(this->elevator_fakeheight-this->tofloor)/2;

	cout<<setw(19-(this->elevator_fakeheight-this->tofloor)/20)<<"总等待时间:"<<this->Dayrecord.SumofWaitingTime<<endl;

	cout<<setw(15)<<"最大载重:"<<this->Capacity;
	cout<<setw(14)<<"当前载重:"<<this->nowWeight<<endl;
	//cout<<"InNumber   "<<this->inNumber<<endl;
	///cout<<"InsideNum  "<<this->insideNum<<endl;
	//cout<<"OutsideNum "<<this->inNumber-this->insideNum<<endl;
	
	
	
}

void Elevator::PrintPassengersMessage()
{
	cout<<endl;
	cout<<"      "<<"前往楼层 "<<"体重/kg "<<"等待时间 ";//<<"目前状态";
	cout<<endl;
	for(int i=0;i<this->inNumber;i++)
	{
		
		if(this->passengers[i]->state==1)
		{
			//cout<<"state="<<this->passengers[i]->state<<" ";
			this->passengers[i]->PrintMessage();
			
		
		}
	}
}

int Elevator::PedestrianVolume()
{
	
	if(this->Elevatortime.hour>23||this->Elevatortime.hour<=6)
	{
		return 1999;
	}
	else if(this->Elevatortime.hour>6&&this->Elevatortime.hour<=7)
	{
		return 907;
	}
	
	else if(this->Elevatortime.hour>7&&this->Elevatortime.hour<10)
	{
		return 51;
		//return 11;
	}
	else if(this->Elevatortime.hour>=10&&this->Elevatortime.hour<=11)
	{
		return 101;
	}
	else if(this->Elevatortime.hour>11&&this->Elevatortime.hour<13)
	{
		return 57;
	}
	else if(this->Elevatortime.hour>=13&&this->Elevatortime.hour<=17)
	{
		return 101;
	}
	else if(this->Elevatortime.hour>17&&this->Elevatortime.hour<=19)
	{
		return 51;
	}
	else if(this->Elevatortime.hour>19&&this->Elevatortime.hour<=23)
	{
		return 101;
	}
}

void Elevator::DayChange()
{
	this->Elevatordate.Goesby();
	//this->CopyRecord();
	this->Dayrecord.Initialize();
	int number=0;

	for(int i=0;i<this->elevator_realheight;i++)
	{
		for(int j=0;j<this->elevator_width;j++)
		{
			if(this->elevator[i][j]=='*')
			{
				number++;
			}
		}
	}
	this->Dayrecord.SumofPeople=number;
	//this->daytime++;
	
}

void Elevator::CopyRecord()
{
	this->Pastrecord[daytime]->AverageofWaitingTime=this->Dayrecord.AverageofWaitingTime;
	this->Pastrecord[daytime]->RecordDate=this->Elevatordate;
	this->Pastrecord[daytime]->SumofPeople=this->Dayrecord.SumofPeople;
	this->Pastrecord[daytime]->SumofWaitingTime=this->Dayrecord.SumofWaitingTime;

}



void Elevator::ChangeStatic()
{

	this->Dayrecord.SumofWaitingTime+=this->inNumber;
	if(this->Dayrecord.SumofPeople)this->Dayrecord.AverageofWaitingTime=this->Dayrecord.SumofWaitingTime/this->Dayrecord.SumofPeople;
}

void Elevator::Queuecorrection()
{
	for(int i=0;i<this->elevator_fakeheight;i++)
	{
		int dooroutside=0;
		for(int j=0;j<this->elevator_width;j++)
		{
			if(this->elevator[i][j]=='|'&&j>5)
			{
				dooroutside=1;
			}
			else if(dooroutside==1&&this->elevator[i][j]=='*'&&this->elevator[i][j-1]==' '&&j-1!=this->elevator_width-11)
			{
				this->elevator[i][j]=' ';
				this->elevator[i][j-1]='*';
			}
		}
	}
}

void Elevator::CheckOutPastStatic()
{
	
	system("cls");
	int choose;
	cout<<"输入1进入下一天;";
	cout<<"输入2查看其他日期的数据;";
	cin>>choose;
	if(choose==1)
	{
		
		return;
	}
	else if(choose==2)
	{
		system("cls");
		for(int i=1;i<=this->daytime;i++)
		{
			cout<<"i="<<i<<",选择";
			this->Pastrecord[i-1]->RecordDate.show();
			cout<<endl;
		}
		int daychoose;
		cin>>daychoose;
		//this->Pastrecord[daychoose-1]->show();//////////////
	}
	

}

void Elevator::Fix()
{
	//FIX函数里出现了bug，insidenum和innumber
	int pound=0,firstplace=0;
	for(int i=0;i<this->elevator_width-11;i++)
	{
		if(this->elevator[this->elefloor][i]=='*')
		{
			pound++;
			if(firstplace==0)firstplace=i;
		}
	}
	//cout<<endl<<"pound="<<pound<<endl;
	
	if(pound<this->insideNum)
	{
		//system("pause");
		int u=this->insideNum-pound;
		for(int i=1;i<=u;i++)
		{
			this->elevator[this->elefloor][firstplace-i]='*';
			//this->inNumber++;

		}
		//Sleep(10000);
		
	}
	else if(pound>this->insideNum)
	{
		//system("pause");
		int u=pound-this->insideNum;
		for(int i=0;i<u;i++)
		{
			this->elevator[this->elefloor][firstplace+i]=' ';
			//this->inNumber--;
		}
		//Sleep(10000);
		
	}
	

}

bool Elevator::Scanoptimize_Down()
{
	for(int i=0;i<this->elefloor;i++)//上面没有人
	{
		for(int j=this->elevator_width-10;j<this->elevator_width;j++)
		{
			if(this->elevator[i][j]=='*')
			{
				return false;
			}
		}

	}
	for(int i=0;i<this->inNumber;i++)
	{
		if(this->passengers[i]->state==1&&this->passengers[i]->tofloor<this->elefloor)
			return false;
	}
	this->UporDown=-1;
	return true;
}

bool Elevator::Scanoptimize_Up()
{
	for(int i=this->elevator_fakeheight-1;i>this->elefloor;i--)//下面没有人
	{
		for(int j=this->elevator_width-10;j<this->elevator_width;j++)
		{
			if(this->elevator[i][j]=='*')
			{
				return false;
			}
		}

	}
	for(int i=0;i<this->inNumber;i++)//目标楼不在下面
	{
		if(this->passengers[i]->state==1&&this->passengers[i]->tofloor>this->elefloor)
			return false;
	}
	this->UporDown=1;
	return true;
}

void Elevator::ScanUpDown()
{
	if(this->elefloor==0)this->UporDown=-1;
	else if(this->elefloor==this->elevator_fakeheight-2)this->UporDown=1;
	else if(this->Scanoptimize_Down());
	else if(this->Scanoptimize_Up());
}

void Elevator::FixInnumber()
{
	int number=0;
	for(int i=0;i<this->elevator_realheight;i++)
	{
		for(int j=0;j<this->elevator_width;j++)
		{
			if(this->elevator[i][j]=='*')
			{
				number++;
			}
		}
	}
	if(number==0)this->inNumber=number;
}