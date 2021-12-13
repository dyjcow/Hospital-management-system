void DoctorFunction(char u[],char n[],char office[])//医生端功能模块，同时接受传入的账号、姓名、科室 
{
	//定义要显示的菜单 
	char *menu3D[] = 
	{
	"＊    安排出诊    ＊",
	"＊查看预约我的病人＊",
	"＊查看我的出诊信息＊",
	"＊    取消出诊    ＊",
	"＊    修改出诊    ＊",
	"＊    注销账号    ＊",
	"＊   返回上一级   ＊",
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
    	showmenu(hOut , menu3D , NR(menu3D) , index);
		ret = get_userinput(&index , NR(menu3D));
		if(ret == ESC)
			break ;
		if(ret == ENTER)
		{
			switch(index)
			{
				case 0:         lnput(u,n,office,1);  
					break ;  	//安排出诊 
				
				case 1:         DoctorLook(u,n,office);   
					break ;  	//查看预约我的病人 
				
				case 2:         findD(u,n,office); 
					break ;  	//查看我的出诊信息
				
				case 3:			cancel(u,n,office,1);
					break ;  	//取消出诊 
				
				case 4:			cancel(u,n,office,1);lnput(u,n,office,1);
					break ;  	//修改出诊信息 
					
				case 5:			freeUser(1);
					break ;  	//用户注销自己的账号 
					
				case 6:           
					return;     //返回上一级 
			}
		}
	}
    return ;
}
