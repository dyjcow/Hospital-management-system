void usernumR(int order)//两端口共用的登录数据数量记录函数，其中order为判断医生与用户的依据 ；用户为0，医生为1
{
	FILE *fp;
	if(order == 1)
	{
		fp = fopen("医生数量.txt", "r");
	}
	else
	{
		fp = fopen("用户数量.txt", "r");
	}
	
	
	if(fp == NULL)
	{
		if(order == 1)
		{
			m=0;//医生数量全局变量 
		}
		else
		{
			n=0;//用户数量全局变量
		}
	}
    else
    {
		
		if(order == 1)
		{
			fscanf(fp,"%d",&m);
		}
		else
		{
			fscanf(fp,"%d",&n);
		}
		
	    fclose(fp);
	}
}
