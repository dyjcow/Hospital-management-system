void otherLook(char u[],char n[],char doctor1[],char office[],int order,int time)//两端口共用的查看对方表单信息函数，其中order为判断医生与用户的依据 ；用户为0，医生为1，且有数据传入 
{	system("cls");
	if (order == 0)
	{
		int f = 0,i = 0,j = 0;
		Formlistp listp,listd;
		listp.head =listp.tail = NULL;
		listd.head =listd.tail = NULL;
		inputnumR(1);
		ioRead_input(&listp,1);
		printf("\n\n\t\t\t\t下边是可预约的信息\n\n\t\t\t\t表单按时间先后排序\n\n");
		Formp *q;
		for ( q= listp.head; q ; q = q->next)//找出相关的到链表listd 
    	{
			if(!strcmp(q->office,office)&&timeJudge(q->timeYear,q->timeMon,q->timeDay)<=0)
			{
				Addinput(&listd,"k","k",q->timeYear,q->timeMon,q->timeDay,q->doctor,office,q->number,1);//链表新增 
				f++;//获取数据个数 
			}
		}
		if(f == 0)
		{
			printf("\n\n\t\t\t\t未来没有%s的就诊信息\n\n",office);
			system("PAUSE");
			return;
		}
		Formp *b;
		Formp *k;
		int year,month,day;
		int number;
		Formp *p = listd.head;
		char doctor[30];
		for (i=0; i<f-1; i++) 
		{
			p = listd.head;
			year = p->next->timeYear;
			month = p->next->timeMon;
			day = p->next->timeDay;
        	for (p = listd.head;p;p = p->next) 
			{

			if (timecpy(year,month,day,p->timeYear,p->timeMon,p->timeDay)<=0)//诊单时间排序，获取小值 
			{
				year = p->timeYear;
				month = p->timeMon;
				day = p->timeDay;
				strcpy(doctor,p->doctor);
				number = p->number;
			}
        	}

		for (k = NULL, b = listd.head; b ;k = b,b = b->next)// 释放小值数据 
	    {
	        if (b->timeYear==year&&b->timeMon==month&&b->timeDay==day&&!strcmp(b->doctor,doctor))
	        {
	            if (k)
	            {
	                k->next = b->next;
	            }
	            else
	            {
	                listd.head = b->next;
	            }
	            free(b);
	            break;
	        }
	
	    }
		printf("\t\t\t\t医生：%s\n\t\t\t\t科室：%s\n\t\t\t\t时间：%d年%d月%d日\n\t\t\t\t剩余人数：%d\n\n",doctor,office,year,month,day,number);
		
		}
		p = listd.head; 
		printf("\t\t\t\t医生：%s\n\t\t\t\t科室：%s\n\t\t\t\t时间：%d年%d月%d日\n\t\t\t\t剩余人数：%d\n\n\n\n",p->doctor,p->office,p->timeYear,p->timeMon,p->timeDay,p->number);//zuihoude*/
		system("PAUSE");
		freeFormlistp(&listp);
		freeFormlistp(&listd);
		lnput(u,n,office,0);
	}
	else
	{
		int f = 0,i = 0,j = 0;
		Formlistp listp,listd;
		listp.head =listp.tail = NULL;
		listd.head =listd.tail = NULL;
		inputnumR(0);
		ioRead_input(&listp,0);
		printf("\n\n\t\t\t\t表单按时间先后排序\n\n");
		Formp *q;
		if(time == 1)
		{
			for ( q= listp.head; q ; q = q->next)//找出相关的到链表listd 
	    	{
				if(!strcmp(q->doctor,doctor1)&&!strcmp(q->office,office)&&timeJudge(q->timeYear,q->timeMon,q->timeDay)<=0)
				{
					Addinput(&listd,q->user,q->name,q->timeYear,q->timeMon,q->timeDay,q->doctor,office,q->number,0);//链表新增 
					f++;//获取数据个数 
				}
			}
		}
		else
		{
			for ( q= listp.head; q ; q = q->next)//找出相关的到链表listd 
	    	{
				if(!strcmp(q->doctor,doctor1)&&!strcmp(q->office,office)&&timeJudge(q->timeYear,q->timeMon,q->timeDay)>=0)
				{
					Addinput(&listd,q->user,q->name,q->timeYear,q->timeMon,q->timeDay,q->doctor,office,q->number,0);//链表新增 
					f++;//获取数据个数 
				}
			}	
		}
		if(f == 0&&time == 1)
		{
			printf("\n\n\t\t\t\t暂未有人预约你的就诊\n\n");
			system("PAUSE");
			return;
		}
		if(f == 0&&time == 0)
		{
			printf("\n\n\t\t\t\t过去你未有就诊信息\n\n");
			system("PAUSE");
			return;
		}
		Formp *p = listd.head;
		Formp *b;
		Formp *k;
		int year,month,day;
		char name[30];
		for (i=0; i<f-1; i++) 
		{
			p = listd.head;
			year = p->next->timeYear;
			month = p->next->timeMon;
			day = p->next->timeDay;
        	for (p = listd.head;p;p = p->next) 
			{

			if (timecpy(year,month,day,p->timeYear,p->timeMon,p->timeDay)<=0)//诊单时间排序，获取小值
			{
				year = p->timeYear;
				month = p->timeMon;
				day = p->timeDay;
				strcpy(office,p->office);
				strcpy(doctor1,p->doctor);
				strcpy(name,p->name);
			}
        	}

		for (k = NULL, b = listd.head; b ;k = b,b = b->next)// 释放小值数据 
		{
			if (b->timeYear==year&&b->timeMon==month&&b->timeDay==day&&!strcmp(b->doctor,doctor1)&&!strcmp(b->office,office)&&!strcmp(b->name,name))
			{
				if (k)
				{
					k->next = b->next;
				}
				else
				{
					listd.head = b->next;
				}
				free(b);
				break;
			}

		}
		printf("\t\t\t\t时间：%d年%d月%d日\n\t\t\t\t病人：%s\n\n",year,month,day,name);
		
		}
		p = listd.head;
		printf("\t\t\t\t时间：%d年%d月%d日\n\t\t\t\t病人：%s\n\n\n\n",p->timeYear,p->timeMon,p->timeDay,p->name);
		system("PAUSE");
		freeFormlistp(&listp);//释放链表空间 
		freeFormlistp(&listd);//释放链表空间 
	}
	
		
	
}
