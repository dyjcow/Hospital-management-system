void cancel(char u[],char n[],char office[],int order)//两端口共用的取消出诊或预约函数，其中order为判断医生与用户的依据 ；用户为0，医生为1
{
	system("cls");
	if (order == 1)
	{
		int f = 0;
		Formlistp listp,listd;
		listp.head =listp.tail = NULL;
		listd.head =listd.tail = NULL;
		int year,month,day;
		inputnumR(1);
		ioRead_input(&listp,1);
		Formp *k,*b;
		printf("\n\n\t\t\t\t注意：这是取消出诊页面\n\n");
		printf("\n\t\t\t\t下边将按年、月、日进行输入\n");
		printf("\n\n\t\t\t\t请输入年份\n\n\t\t\t\t");
		scanf("%d",&year);
		printf("\n\n\t\t\t\t请输入月份：\n\n\t\t\t\t");
		scanf("%d",&month);
		printf("\n\n\t\t\t\t请输入日期：\n\n\t\t\t\t");
		scanf("%d",&day);
		if (timeJudge(year,month,day) >= 0)//时间判断 
	    {
	        printf("\n\n\t\t\t\t请重试，输入今后的时间\n\n\t\t\t\t");
	        system("PAUSE");
		    system("cls");
	        return;
	    }
		for (k = NULL, b = listp.head; b ;k = b,b = b->next)
			{
				if (b->timeYear==year&&b->timeMon==month&&b->timeDay==day&&!strcmp(b->doctor,n)&&!strcmp(b->office,office))
				{
					f = 1;
					if (k)
					{
						k->next = b->next;
					}
					else
					{
						listp.head = b->next;
					}
					free(b);
					break;
				}

			}
		if (f == 0)
		{
			printf("\t\t\t\t该时段不存在！！\n\n\t\t\t\t");
			system("PAUSE");
			return;
		}
		
		ioWrite_input(&listp,1);
		inputnumW(1);
		freeFormlistp(&listp);
		inputnumR(0);
		ioRead_input(&listd,0);
		for (k = NULL, b = listd.head; b ;k = b,b = b->next)
			{
				if (b->timeYear==year&&b->timeMon==month&&b->timeDay==day&&!strcmp(b->doctor,n)&&!strcmp(b->office,office))
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
		ioWrite_input(&listd,0);
		inputnumW(0);
		freeFormlistp(&listd);
		printf("\t\t\t\t取消成功！！\n\n\t\t\t\t");
		system("PAUSE");
	}
	
	else
	{
		int f = 0;
		Formlistp listp,listd;
		listp.head =listp.tail = NULL;
		listd.head =listd.tail = NULL;
		int year,month,day;
		char doctor[30],office1[30];
		inputnumR(0);
		ioRead_input(&listp,0);
		Formp *k,*b;
		printf("\n\n\t\t\t\t注意：这是取消就诊页面\n\n");
		printf("\n\t\t\t\t下边将按年、月、日进行输入\n");
		printf("\n\n\t\t\t\t请输入年份\n\n\t\t\t\t");
		scanf("%d",&year);
		printf("\n\n\t\t\t\t请输入月份：\n\n\t\t\t\t");
		scanf("%d",&month);
		printf("\n\n\t\t\t\t请输入日期：\n\n\t\t\t\t");
		scanf("%d",&day);
		printf("\n\n\t\t\t\t请输入医生姓名：\n\n\t\t\t\t");
		scanf("%s",&doctor);
		printf("\n\n\t\t\t\t请输入科室：\n\n\t\t\t\t");
		scanf("%s",&office1);
		if (timeJudge(year,month,day) >= 0)//时间判断 
	    {
	        printf("\n\n\t\t\t\t请重试，输入今后的时间\n\n\t\t\t\t");
	        system("PAUSE");
		    system("cls");
	        return;
	    }
		for (k = NULL, b = listp.head; b ;k = b,b = b->next)
			{
				if (b->timeYear==year&&b->timeMon==month&&b->timeDay==day&&!strcmp(b->doctor,doctor)&&!strcmp(b->office,office1)&&!strcmp(b->name,n)&&!strcmp(b->user,u))
				{
					f = 1;
					if (k)
					{
						k->next = b->next;
					}
					else
					{
						listp.head = b->next;
					}
					free(b);
					break;
				}

			}
		if (f == 0)
		{
			printf("\t\t\t\t未检测到该预约，请查看是否输入正确！！\n\n\t\t\t");
			system("PAUSE");
			return;
		}
		
		ioWrite_input(&listp,0);
		inputnumW(0);
		freeFormlistp(&listp);
		inputnumR(1);
		ioRead_input(&listd,1);
		for ( b = listd.head; b ;b = b->next)
			{
				if (b->timeYear==year&&b->timeMon==month&&b->timeDay==day&&!strcmp(b->doctor,doctor)&&!strcmp(b->office,office1))
				{
					b->number++;
					break;
				}

			}
		ioWrite_input(&listd,1);
		inputnumW(1);
		freeFormlistp(&listd);
		printf("\t\t\t\t取消成功！！\n\n\t\t\t");
		system("PAUSE");
	}
	
}
