void ioRead_input(Formlistp *pList,int order)//两端口共用的导入文件诊单数据到链表的函数，其中order为判断医生与用户的依据 ；用户为0，医生为1
{ 
	
	int i;
	FILE *fp;
	if(order == 0)
	{
		fp = fopen("预约数据.txt", "r");
		i = inputp;//数量的全局变量 
	} 
	else
	{
		fp = fopen("出诊安排数据.txt", "r");
		i = inputd;
	}
	
    if (fp == NULL)  
    {  
        return; 
    }  
        while(i) //根据全局变量判断申请多少次空间 
        {  
        	Formp *p = (Formp*)malloc(sizeof(Formp));	

			if(order == 0)
			{
                fscanf(fp,"%s",p->user); 
		        fscanf(fp,"%s",p->name);
			    fscanf(fp,"%d",&p->timeYear);
				fscanf(fp,"%d",&p->timeMon);
                fscanf(fp,"%d",&p->timeDay);
                fscanf(fp,"%s",p->office);
                fscanf(fp,"%s",p->doctor);
			}
            else
            {
			    fscanf(fp,"%s",p->doctor);
                fscanf(fp,"%d",&p->timeYear);
				fscanf(fp,"%d",&p->timeMon);
                fscanf(fp,"%d",&p->timeDay);
                fscanf(fp,"%s",p->office);
                fscanf(fp,"%d",&p->number);
            }
            
			p->next = NULL;
			Formp *First = pList->head;
		    if (First)
		    {
		        pList->tail->next = p;//加到尾链 
		        pList->tail = pList->tail->next;
		    }
		    //头为空 
		    else
		    {
		        pList->head = pList->tail = p;
		    }
		    
    		i--;
        }
        if(order == 1)
		{
			inputd = i;
		}
		else
		{
			inputp = i;
		}
		
	fclose(fp);

}

