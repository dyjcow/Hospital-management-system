void freeUser(int order)////两端口共用的账号注销函数，其中order为判断医生与用户的依据 ；用户为0，医生为1 
{
    system("cls");
	List list;
    list.head =list.tail = NULL;
    char u[30],n[30],p[30];
    int r,y;
    int flag = 0;
    usernumR(order);
    ioRead(&list,order);
    printf("\n\n\t\t\t\t需再次确认你的身份\n\t\t\t\t");
    printf("\n\t\t\t\t请输入你的账号\n\n\t\t\t\t");
    scanf("%s",u);
    Patient *q,*t;
    for ( t = NULL,q= list.head; q ; t = q,q = q->next)
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
    printf("\t\t\t\t请输入密码：\n\n\t\t\t\t");
    scanf("%s",p);
    if(strcmp(q->password, p) != 0){
        printf("\t\t\t\t密码错误，请重试！！！\n\n\t\t\t\t");
        system("PAUSE");
        system("cls");
        printf("\n");
        return;
    }
    printf("\t\t\t\t请输入验证码：\n\n\t\t\t\t");
    srand((unsigned)time(NULL));
    r = rand();
    printf("%d\n\n\t\t\t ",r);
	scanf("%d",&y);
    if (r == y)
    {
        //freeUserList(&list,u,n,p);
            if (t)
            {
                t->next = q->next;
            }
            else
            {
                list.head = q->next;
            }
            free(q);
            printf("\t\t\t\t注销成功！\n\n\t\t\t\t");
        	system("PAUSE");
    }
    else
    {
        printf("\t\t\t\t验证码错误，请重试\n\n\t\t\t\t");
        system("PAUSE");
        system("cls");
    }
    ioWrite(&list,order);
    usernumW(order);
    freeList(&list);
    
}
