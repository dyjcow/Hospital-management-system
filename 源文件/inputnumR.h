void inputnumR(int order)//两端口共用的数据数量记录函数，其中order为判断医生与用户的依据 ；用户为0，医生为1
{
	FILE *fp;
	if(order == 0)
	{
		fp = fopen("预约数量.txt", "r");
	}
	else
	{
		fp = fopen("出诊安排数量.txt", "r");
	}
	
	
	if(fp == NULL)
	{
			inputd=0;//皆为记录的全局变量 
			inputp=0; 
	}
    else
    {
		
		if(order == 1)
		{
			fscanf(fp,"%d",&inputd);
		}
		else
		{
			fscanf(fp,"%d",&inputp);
		}
		
	    fclose(fp);
	}
}
