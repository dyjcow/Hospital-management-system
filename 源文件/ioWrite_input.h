void ioWrite_input(Formlistp *pList,int order)//两端口共用的链表数据写入文件的函数，其中order为判断医生与用户的依据 ；用户为0，医生为1
{  

    FILE *fp; 
    if(order == 0)
	{
		fp = fopen("预约数据.txt", "w");
	}
	else
	{
		fp = fopen("出诊安排数据.txt", "w");
	}
	
    if (fp == NULL)  
    {  
        printf("请重试!\n");  
        return;  
    }  
    else
    {    
    Formp *p;
        for (p = pList->head; p ; p = p->next)  
        {  
			if(order == 0)
			{
                fprintf(fp,"%s\n",p->user); 
		        fprintf(fp,"%s\n",p->name);
			    fprintf(fp,"%d\n",p->timeYear);
				fprintf(fp,"%d\n",p->timeMon);
                fprintf(fp,"%d\n",p->timeDay);
                fprintf(fp,"%s\n",p->office);
                fprintf(fp,"%s\n",p->doctor);
                inputp++;//全局变量更新 
			}
            else
            {
			    fprintf(fp,"%s\n",p->doctor);
                fprintf(fp,"%d\n",p->timeYear);
				fprintf(fp,"%d\n",p->timeMon);
                fprintf(fp,"%d\n",p->timeDay);
                fprintf(fp,"%s\n",p->office);
                fprintf(fp,"%d\n",p->number);
                inputd++;
            }
			
        }
    }   
    fclose(fp);
    
	
}
