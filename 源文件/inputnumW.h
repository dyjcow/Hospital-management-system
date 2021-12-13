void inputnumW(int order)//两端口共用的数据数量写入文件的函数，其中order为判断医生与用户的依据 ；用户为0，医生为1
{
	FILE *fp;
	if(order == 0)
	{
		fp = fopen("预约数量.txt", "w");
	}
	else
	{
		fp = fopen("出诊安排数量.txt", "w");
	}
	
    if(fp ==NULL)
	{
		
		return;
	}
	if(order == 1)
	{
		fprintf(fp,"%d\n",inputd);
	}
	else
	{
		fprintf(fp,"%d\n",inputp);
	}

    fclose(fp);
}

