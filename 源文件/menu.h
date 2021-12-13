#ifndef _MENU_H_
#define _MENU_H_
#define  Program "题目:校医院管理系统"
#define  Author  "作者:DYJ"
#define  Class   "班级:计算机20级14班"
//定义结构体
CONSOLE_CURSOR_INFO cci; 
//定义默认的坐标位置  	
COORD pos = {0,0};


//定义枚举Keyboard的键值数据 
enum 
{
	UP = 72,
	DOWN = 80 ,
	LEFT = 75 ,
	RIGHT = 77 ,
	ENTER = 13 ,
	ESC = 27 ,
};

//显示菜单 
void showmenu(HANDLE hOut ,char **menu , int size , int index)
{
	int i ; 
	system("cls");	
	//设置显示的文本的颜色 
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | 0x8); 
	//初始化控制台显示的X,Y轴的坐标 
	pos.X = 30;
	pos.Y = 0 ;
	//设置显示到控制台终端的具体位置 
	SetConsoleCursorPosition(hOut,pos);    
	//调用printf在控制台对应的位置上输出 
	printf("%s",Program);
	pos.X = 30;
	pos.Y = 1 ;
	SetConsoleCursorPosition(hOut,pos);    
	printf("%s",Author);
	pos.X = 30;
	pos.Y = 2 ;
	SetConsoleCursorPosition(hOut,pos);    
	printf("%s",Class);
	for(i = 0 ; i < size ; i++)
	{
		//如果i==index表示在当前选项的位置，默认初始化显示是第一项，显示为红色，
		//当按下上下按键选择的时候，光标会移动，也就看到了列表选择的现象 
		if(i == index)
		{
			//红色 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8); 
			pos.X = 30;
    		pos.Y = 5+i;
    		//设置光标坐标
    		SetConsoleCursorPosition(hOut,pos);    
    		printf("%s",menu[i]);
		}
		//否则显示为白色 
		else
		{
			//白色 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
			pos.X = 30;
    		pos.Y = 5+i;
    		//设置光标坐标
    		SetConsoleCursorPosition(hOut,pos);    //设置光标坐标
    		printf("%s",menu[i]);
		}
	}
	//刷新标准输出缓冲区 
	fflush(stdout);
}
 
//获取用户输入的接口 
int  get_userinput(int *index , int size)
{
	int ch ;
	ch = getch();
	switch(ch)
	{
		//上 
		//如果选择上，那么光标向上移动 
		case UP : if(*index > 0)  *index -= 1 ;  break; 
		//下 
		//如果选择下，那么光标向下移动 
		case DOWN :if(*index < size -1)  *index += 1 ;  break;
		//左 
		case LEFT: 
		case 97:return 0 ;
		//右 
		case RIGHT:return 0 ;
		//回车 
		case ENTER: return ENTER ;
		//ESC
		case ESC: return ESC ;
	}
	return 0 ;
}
#endif
