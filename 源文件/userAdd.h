extern void userAdd(int order)//两端口共用的注册函数，其中order为判断医生与用户的依据 ；用户为0，医生为1  
{
    if(order == 1)
	{
		int passw = 120120;//邀请码的定义 
		int pass;
		printf("\n\n\t\t\t\t请输入医院邀请码\n\n\t\t\t\t");
		scanf("%d",&pass);
		if(passw != pass)
		{
			printf("\t\t\t\t请输入正确的邀请码！！\n\n\t\t\t\t");
            system("PAUSE");
            return ;
		}
	}
	List list;
    list.head =list.tail = NULL;
    char u[30],n[30],p[30],c[30],o[30];
    usernumR(order);//文件中数据数量的读取 
    ioRead(&list,order);//将文件写入程序设置的链表list中 
    printf("\n\n\t\t\t\t请输入你的账号\n\n\t\t\t\t");
    scanf("%s",u);
    Patient *q;
    for ( q= list.head; q ; q = q->next)
    {
        if(strcmp(q->user,u) == 0)
        {
            printf("\t\t\t\t该账号已被注册，请重新申请！！\n\n\t\t\t\t");
            system("PAUSE");
            return ;
        }
    }
    printf("\n\n\t\t\t\t请输入你的姓名：\n\n\t\t\t\t");
    scanf("%s",n);
    if(order == 1)
    {
	    printf("\n\n\t\t\t\t请输入你的科室：\n\n\t\t\t\t");
		scanf("%s",o);
	}
    printf("\n\n\t\t\t\t请输入密码（密码长度不超过二十个字符）：\n\n\t\t\t\t");
    scanf("%s",c);
    printf("\n\n\t\t\t\t请再输入一次密码：\n\n\t\t\t\t");
    scanf("%s",p);
    if(strcmp(p, c) != 0){
        printf("\n\n\t\t\t\t两次密码不一致请重新申请\n\n\t\t\t\t");
        system("PAUSE");
        system("cls");
        printf("\n");
        return;
    }   
    printf("\t\t\t\t申请成功！\n\n\t\t\t\t");
    system("PAUSE");
    Add(&list,u,n,p,o,order);//为链表新增数据 
    ioWrite(&list,order);//将链表list的数据写入文件 
	usernumW(order);//将数据数量写入文件 
	freeList(&list);//释放链表的空间 
}

