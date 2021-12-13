extern void findPassword(int order)//两端口共用的密码寻回函数，其中order为判断医生与用户的依据 ；用户为0，医生为1
{
    system("cls");
	List list;
    list.head =list.tail = NULL;
    char u[30],n[30],p[30];
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
	if(!flag)
    {
        printf("\n\t\t\t\t你未注册，请注册后再使用！！！\t\t\t\t");
        system("PAUSE");
        return ;
    }
    else
    {
    printf("\t\t\t\t请输入你的姓名：\n\n\t\t\t\t");
    scanf("%s",n);
    if(strcmp(q->name, n) != 0){
        printf("\t\t\t\t请检查你的用户名是否有误，再行重试！！！\n\n\t\t\t\t");
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
        printf("\t\t\t\t你的密码是：%s\n\n\t\t\t\t",q->password);
        system("PAUSE");
    }
    else
    {
        printf("\t\t\t\t验证码错误，请重新尝试\n\n\t\t\t\t");
        system("PAUSE");
        system("cls");
    }
    freeList(&list);//释放链表的空间 
	}
}
