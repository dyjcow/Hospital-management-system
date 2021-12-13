void PatientFunction(char u[],char n[])//用户端功能模块，同时接受传入的账号、姓名
{
	//定义要显示的菜单 
	char *menu3P[] = 
	{
	"＊  预约挂号  ＊",
	"＊ 查看预约单 ＊",
	"＊  取消预约  ＊",
	"＊  修改预约  ＊",
	"＊  注销账号  ＊",
	"＊ 返回上一级 ＊",
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
    	showmenu(hOut , menu3P , NR(menu3P) , index);
		ret = get_userinput(&index , NR(menu3P));
		if(ret == ESC)
			break ;
		if(ret == ENTER)
		{
			switch(index)
			{
				case 0:         look(u,n);
					break;		//预约挂号 
				
				case 1:         findP(u,n);  
					break ;  	//用户查看自己的预约信息 
				
				case 2:			cancel(u,n,"office",0);
					break ;  	//用户取消自己的预约 
				
				case 3:			cancel(u,n,"office",0);look(u,n);
					break ;  	//修改预约信息
					
				case 4:			freeUser(0);
					break ;  	//用户注销自己的账号 
					
				case 5:           
					return;     //返回上一级 
			}
		}
	}
    return ;
}
