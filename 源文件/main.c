#include "stdio.h"
#include "stdlib.h"
#include "extern.h"
#include "conio.h"
#include "string.h"
#include "Windows.h"
#include "time.h"
#include "menu.h"
#define   NR(x)   (sizeof(x)/sizeof(x[0]+0))
#include "Doctor.h"
#include "Patient.h"
#include "PatientFunction.h"
#include "DoctorFunction.h" 
#include "ioRead.h"
#include "ioWrite.h"
#include "Add.h"
#include "userAdd.h"
#include "freeList.h"
#include "usernumR.h"
#include "usernumW.h"
#include "userLogin.h"
#include "findPassword.h"
#include "changPassword.h"
#include "freeUser.h"
#include "Input.h"
#include "inputnumR.h"
#include "ioRead_input.h"
#include "timeJudge.h"
#include "Addinput.h"
#include "ioWrite_input.h"
#include "inputnumW.h"
#include "freeFormlistp.h"
#include "appointmentCheck.h"
#include "otherLook.h"
#include "look.h"
#include "timecpy.h"
#include "findP.h"
#include "findD.h"
#include "findMe.h"
#include "cancel.h"
#include "DoctorLook.h"
#include "illustrate.h"

//程序主界面 
int main()
{
	//定义要显示的菜单 
	char *menu1[] = 
	{
	"＊   医生端   ＊",
	"＊   用户端   ＊",
	"＊  使用手册  ＊",
	"＊    退出    ＊",
	};

    int i;
    int ret ;
    int index = 0 ;
    HANDLE hOut;
    SetConsoleTitleA(Program);
    //获取当前的句柄---设置为标准输出句柄 
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //获取光标信息
    GetConsoleCursorInfo(hOut, &cci); 
	//设置光标大小   
    cci.dwSize = 1; 
	//设置光标不可见 FALSE   
    cci.bVisible =  0; 
    //设置(应用)光标信息
    SetConsoleCursorInfo(hOut, &cci);   
    while(1)
    {
    	showmenu(hOut , menu1 , NR(menu1) , index);
		ret = get_userinput(&index , NR(menu1));
		if(ret == ESC)
			break ;
		if(ret == ENTER)
		{
			switch(index)
			{
				case 0:   Doctorway();      
					break ;  	//医生通道 
				
				case 1:   Patientway();        
					break ;  	//病人通道 
					
				case 2:   illustrate();        
					break ;  	//使用手册 
								
				case 3:           
					return 0 ;//退出系统 
			}
		}
	}
    return 0;
}

 
