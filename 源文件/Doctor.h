void Doctorway(void)//医生端的界面函数 
{
	//定义要显示的菜单 
	char *menu2D[] = 
	{
	"＊ 登录(医生) ＊",
	"＊ 新账号注册 ＊",
	"＊  找回密码  ＊",
	"＊  修改密码  ＊",
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
    	showmenu(hOut , menu2D , NR(menu2D) , index);
		ret = get_userinput(&index , NR(menu2D));
		if(ret == ESC)
			break ;
		if(ret == ENTER)
		{
			switch(index)
			{
				case 0:         userLogin(1);  
					break ;  	//医生登录 
				
				case 1:          userAdd(1);
					break ;  	//医生注册 
				
				case 2:          findPassword(1); 
					break ;  	//医生寻回密码 
				
				case 3:			changPassword(1);
					break ;  	//医生修改密码 
				
				case 4:           
					return  ;//返回上一级 
			}
		}
	}
    return ;
}
