void look(char u[],char n[])//用户端功能模块，查看预约的科室的医生和可约数 
{
	//定义要显示的菜单 
	char *menu4P1[] = 
	{
	"＊      内科      ＊",
	"＊      外科      ＊",
	"＊      妇科      ＊",
	"＊      儿科      ＊",
	"＊     中医科     ＊",
	"＊  眼耳鼻咽喉科  ＊",
	"＊     口腔科     ＊",
	"＊   康复保健科   ＊",
	"＊     放射科     ＊",
	"＊     检验科     ＊",
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
    	showmenu(hOut , menu4P1 , NR(menu4P1) , index);
		ret = get_userinput(&index , NR(menu4P1));
		if(ret == ESC)
			break ;
		if(ret == ENTER)
		{
			switch(index)
			{
				case 0:         otherLook(u,n,"l","内科",0,1);
					break ;  	
				
				case 1:         otherLook(u,n,"l","外科",0,1);
					break ;  	
				
				case 2:         otherLook(u,n,"l","妇科",0,1); 
					break ;  	
				
				case 3:			otherLook(u,n,"l","儿科",0,1);
					break ;  	
					
				case 4:			otherLook(u,n,"l","中医科",0,1);
					break ;  	
					
				case 5:			otherLook(u,n,"l","眼耳鼻咽喉科",0,1);
					break ;  	
				
				case 6:			otherLook(u,n,"l","口腔科",0,1);
					break ;  	
					
				case 7:			otherLook(u,n,"l","康复保健科",0,1);
					break ;  	
					
				case 8:			otherLook(u,n,"l","放射科",0,1);
					break ;  	
					
				case 9:			otherLook(u,n,"l","检验科",0,1);
					break ;  	
				
				case 10:           
					return  ;//返回上一级 
			}
		}
	}
    return ;
}
