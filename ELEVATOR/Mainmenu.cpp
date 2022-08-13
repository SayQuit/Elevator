#include "Mainmenu.h"
#include <Windows.h>
#include <iostream>
#include "ControlEle.h"
#define WelcomeFuntionSleeTime 500

using namespace std;
Mainmenu::Mainmenu(void)
{

}


Mainmenu::~Mainmenu(void)
{
}
void Mainmenu::Welcome()
{
    
    Sleep(WelcomeFuntionSleeTime);
    cout<<"欢";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"迎";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"来";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"到";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"模";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"拟";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"电";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"梯";
    cout<<endl;
	this->Choose();



}

void Mainmenu::Choose()
{
	system("cls");
      

    Sleep(WelcomeFuntionSleeTime);
    cout<<"请";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"选";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"择";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"：";
    cout<<endl<<"    ";
    cout<<"1.电梯模式"<<endl<<"    ";

    int model;
    cin>>model;
    if(model==1)
	{
		this->elevatormodel();
	}
}

void Mainmenu::elevatormodel()
{

    system("cls");
    Sleep(WelcomeFuntionSleeTime);
    cout<<"请";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"选";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"择";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"：";
    cout<<endl<<"    ";
    cout<<"1.手动模式"<<endl<<"    ";
    cout<<"2.自动模式"<<endl<<"    ";

    int choosemodel;
    cin>>choosemodel;
	if(choosemodel==2)
	{
		ControlEle con;
		con.NewAnElevator();
	}



}