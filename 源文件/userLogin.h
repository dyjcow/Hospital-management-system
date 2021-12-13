extern void userLogin(int order)//两端口共用的登录函数，其中order为判断医生与用户的依据 ；用户为0，医生为1 
{
   	system("cls");
	List list;
    list.head =list.tail = NULL;
    char u[30],n[30],p[30],office[30];
    int r,y;
    int flag = 0;
    usernumR(order);//文件中数据数量的读取 
    ioRead(&list,order);//将文件写入程序设置的链表list中 
    printf("\n\n\t\t\t\t请输入你的账号\n\n\t\t\t\t");
    scanf("%s",u);
    Patient *q;
    for ( q= list.head; q ; q = q->next)
    {
        if(strcmp(q->user,u) == 0) 
        {
        	flag = 1;
           break;
        }
    }
    if(!flag)//利用标记判断是否有相应账号 
	{
		printf("\n\t\t\t\t你未注册，请注册后再使用！！！\t\t\t\t");
            system("PAUSE");
            return ;
	}
    else
	{
	    printf("\t\t\t\t请输入密码：\n\n\t\t\t\t");
	    scanf("%s",p);
	    if(strcmp(q->password, p) != 0)
		{
	        printf("\t\t\t\t密码错误，请重试！！！\n\n\t\t\t\t");
	        system("PAUSE");
	        system("cls");
	        printf("\n");
	        return;
	    }
	    printf("\t\t\t\t请输入验证码：\n\n\t\t\t\t");
	    srand((unsigned)time(NULL));//随机数种子设置 
	    r = rand();
		printf("%d\n\n\t\t\t\t",r);
	    scanf("%d",&y);
	    if (r == y)
	    {
	    	if(order == 1)
	    	{
	    		strcpy(n,q->name);
	    		strcpy(office,q->office);
	    		DoctorFunction(u,n,office); //进入医生功能函数 
			}
			else
			{
				strcpy(n,q->name);
				PatientFunction(u,n);//进入用户功能函数 
			}
	    }
	    else
	    {
			printf("\t\t\t\t验证码错误，请重新登录\n\n\t\t\t\t");
	        system("PAUSE");
	        system("cls");
	    }
	    freeList(&list);//释放链表申请的空间 
	    }
}

