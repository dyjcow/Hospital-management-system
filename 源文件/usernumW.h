void usernumW(int order)//两端口共用的登录数据数量写入函数，其中order为判断医生与用户的依据 ；用户为0，医生为1
{
	FILE *fp;
	if(order == 1)
	{
		fp = fopen("医生数量.txt", "w");
	}
	else
	{
		fp = fopen("用户数量.txt", "w");
	}
	
    if(fp ==NULL)
	{
		
		return;
	}
	if(order == 1)
	{
		fprintf(fp,"%d",m);//写入数据数量 
	}
	else
	{
		fprintf(fp,"%d",n);//写入数据数量 
	}

    fclose(fp);
}
