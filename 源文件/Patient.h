void Patientway(void)//用户端的界面函数 
{
	//定义要显示的菜单 
	char *menu2P[] = 
	{
	"＊ 登录(用户) ＊",
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
    	showmenu(hOut , menu2P , NR(menu2P) , index);
		ret = get_userinput(&index , NR(menu2P));
		if(ret == ESC)
			break ;
		if(ret == ENTER)
		{
			switch(index)
			{
				case 0:         userLogin(0);   
					break ;  	//用户登录 
				
				case 1:         userAdd(0);    
					break ;  	//用户注册 
				
				case 2:         findPassword(0);  
					break ;  	//用户寻回密码 
				
				case 3:			changPassword(0);
					break ;  	//用户修改密码 
				
				case 4:           
					return  ;//返回上一级 
			}
		}
	}
    return ;
}
