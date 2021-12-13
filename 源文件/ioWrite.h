void ioWrite(List *pList,int order)//两端口共用的登录数据写入函数，其中order为判断医生与用户的依据 ；用户为0，医生为1
{  

    FILE *fp; 
    if(order == 1)
	{
		fp = fopen("医生数据.txt", "w");
	}
	else
	{
		fp = fopen("用户数据.txt", "w");
	}
	
    if (fp == NULL)  
    {  
        printf("请重试!\n");  
        return;  
    }  
    else
    {    
    Patient *p;
        for (p = pList->head; p ; p = p->next)  
        {  
			fprintf(fp,"%s\n",p->user);
			fprintf(fp,"%s\n",p->name);
			fprintf(fp,"%s\n",p->password);
			if(order == 1)
			{
				fprintf(fp,"%s\n",p->office);
				m++;    //同时更新数据数量 
			}   
			else
			{
				n++;	//同时更新数据数量 
			}
			
        }
    }   
    fclose(fp);
    
	
}
