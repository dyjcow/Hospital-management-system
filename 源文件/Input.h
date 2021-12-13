extern void lnput(char u[],char n[],char office[],int order)//两端口共用的预约出诊输入函数，其中order为判断医生与用户的依据 ；用户为0，医生为1，且有用户数据输入 
{
	Formlistp listp;
    listp.head =listp.tail = NULL;
    int year,month,day,number;
    int flag = 0;
    char doctor[30];
    inputnumR(order);//导入诊单数据数量到全局变量 
    ioRead_input(&listp,order);//导入文件诊单数据到链表listp
    printf("\n\n\t\t\t\t格式示例：2022年1月1日，分别输2022 1 1 即可\n\t\t\t\t");
    printf("\n\t\t\t\t下边将按年、月、日进行输入\n\t\t\t");
    printf("\n\n\t\t\t\t请输入年份\n\n\t\t\t\t");
    scanf("%d",&year);
    printf("\n\n\t\t\t\t请输入月份：\n\n\t\t\t\t");
    scanf("%d",&month);
    printf("\n\n\t\t\t\t请输入日期：\n\n\t\t\t\t");
	scanf("%d",&day);
    if (order == 0)
    {
    printf("\n\n\t\t\t\t请输入医生姓名：\n\n\t\t\t\t");
    scanf("%s",doctor);
    }
    else
    {
        printf("\n\n\t\t\t\t请输入当天见诊人数：\n\n\t\t\t\t");
        scanf("%d",&number);
        strcpy(doctor,n);
    }
    
    if (timeJudge(year,month,day) >= 0)//时间判断 
    {
        printf("\n\n\t\t\t\t请重试，输入今后的时间\n\n\t\t\t\t");
        system("PAUSE");
	    system("cls");
        return;
    }
    if(order == 0)
    {
    Formp *q;
    for ( q= listp.head; q ; q = q->next)
    {
        if(!strcmp(q->user,u)&&!strcmp(q->name,n)&&!strcmp(q->doctor,doctor)&&q->timeYear==year&&q->timeMon==month&&q->timeDay == day)
        {
            printf("\t\t\t\t你已申请过该段时间！！\n\n\t\t\t\t");
            system("PAUSE");
            return ;
        }
        
    }
    } 
    if(order == 1)
    {
    Formp *q;
    for ( q= listp.head; q ; q = q->next)//写一个判断是否重复预约 
    {
        if(!strcmp(q->doctor,doctor)&&q->timeYear==year&&q->timeMon==month&&q->timeDay==day)
        {
            printf("\t\t\t\t你已注册过该段时间！！\n\n\t\t\t\t");
            system("PAUSE");
            return ;
        }
    }
	}
	if(order == 0)
	{
		flag = appointmentCheck(year,month,day,doctor,office);// 检查是否有相关出诊数据，或者是否有预约名额 
		if(flag == 0)
		{
			printf("\t\t\t\t没有相关的出诊数据（可能满额了），请重新确认！！\n\n\t\t\t\t");
            system("PAUSE");
			return;	
		}
	}
    Addinput(&listp,u,n,year,month,day,doctor,office,number,order);//将输入的数据新增到链表listp中 
    ioWrite_input(&listp,order);//链表数据写入文件 
	inputnumW(order);//数据数量写入文件 
	freeFormlistp(&listp);//释放申请到的空间 
	printf("\t\t\t\t申请成功！！\n\n\t\t\t\t");
    system("PAUSE");
}

