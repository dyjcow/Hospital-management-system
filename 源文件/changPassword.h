extern void changPassword(int order)//两端口共用的密码更改函数，其中order为判断医生与用户的依据 ；用户为0，医生为1
{
    system("cls");
	List list;
    list.head =list.tail = NULL;
    char u[30],n[30],p[30],c[30];
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
    printf("\t\t\t\t请输入原密码：\n\n\t\t\t\t");
    scanf("%s",p);
    if(strcmp(q->password, p) != 0){
        printf("\t\t\t\t密码错误，请重试！！！\n\n\t\t\t\t");
        system("PAUSE");
        system("cls");
        printf("\n");
        return;
    }
    printf("\n\n\t\t\t\t请输入更改后的密码（密码长度不超过二十个字符）：\n\n\t\t\t\t");
    scanf("%s",c);
    printf("\n\n\t\t\t\t请再次输入更改后的密码：\n\n\t\t\t\t");
    scanf("%s",p);
    if(strcmp(p, c) != 0){
        printf("\n\n\t\t\t\t两次密码不一致请重新申请\n\n\t\t\t\t");
        system("PAUSE");
        system("cls");
        printf("\n");
        return;
    }
    printf("\t\t\t\t请输入验证码：\n\n\t\t\t\t");
    srand((unsigned)time(NULL));//随机数种子的设置 
    r = rand();
    printf("%d\n\n\t\t\t\t",r);
	scanf("%d",&y);
    if (r == y)
    {
        strcpy(q->password,p);
        printf("\t\t\t\t密码更改成功！\n\n\t\t\t\t");
        system("PAUSE");
    }
    else
    {
        printf("\t\t\t\t验证码错误，请重新登录\n\n\t\t\t\t");
        system("PAUSE");
        system("cls");
    }
    ioWrite(&list,order);////将链表list写入文件中  
    freeList(&list);//释放链表list的空间
}
