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
    cout<<"��";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"ӭ";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"��";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"��";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"ģ";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"��";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"��";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"��";
    cout<<endl;
	this->Choose();



}

void Mainmenu::Choose()
{
	system("cls");
      

    Sleep(WelcomeFuntionSleeTime);
    cout<<"��";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"ѡ";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"��";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"��";
    cout<<endl<<"    ";
    cout<<"1.����ģʽ"<<endl<<"    ";

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
    cout<<"��";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"ѡ";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"��";
    Sleep(WelcomeFuntionSleeTime);
    cout<<"��";
    cout<<endl<<"    ";
    cout<<"1.�ֶ�ģʽ"<<endl<<"    ";
    cout<<"2.�Զ�ģʽ"<<endl<<"    ";

    int choosemodel;
    cin>>choosemodel;
	if(choosemodel==2)
	{
		ControlEle con;
		con.NewAnElevator();
	}



}