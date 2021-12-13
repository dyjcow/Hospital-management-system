void ioRead(List *pList,int order)//两端口共用的注册函数，其中order为判断医生与用户的依据 ；用户为0，医生为1
{ 
	
	int i;
	FILE *fp;
	//读取全局变量 
	if(order == 1)
	{
		fp = fopen("医生数据.txt", "r");
		i = m;
	}
	else
	{
		fp = fopen("用户数据.txt", "r");
		i = n;
	}
	
    if (fp == NULL)  
    {  
          
        return; 
    }  
        while(i) //利用全局变量得知需要申请多少次空间 
        {  
        	Patient *p = (Patient*)malloc(sizeof(Patient));	
			fscanf(fp,"%s",p->user); 
			fscanf(fp,"%s",p->name);
			fscanf(fp,"%s",p->password);
			if(order == 1)
			{
				fscanf(fp,"%s",p->office);
			}
			p->next = NULL;
			Patient *First = pList->head;
		    if (First)//head不为空，写入tail->next 
		    {
		        pList->tail->next = p;
		        pList->tail = pList->tail->next;
		    }
		    //head 为空，写入head 
		    else
		    {
		        pList->head = pList->tail = p;
		    }
		    
    		i--;
        }
        if(order == 1)
		{
			m = i;
		}
		else
		{
			n = i;
		}
		
	fclose(fp);

}
