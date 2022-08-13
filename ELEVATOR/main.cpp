#include "Mainmenu.h"
#include <iostream>
#include "ControlEle.h"
using namespace std;
int main()
{
	
	ControlEle con;
	con.NewAnElevator();
	con.ele[0]->Running();
	return 0;

	//cout<<con.ele[0]->elevator_fakeheight;
	//Mainmenu M;
	//M.Welcome();
}