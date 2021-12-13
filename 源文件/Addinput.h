void Addinput(Formlistp *pList,char u[],char n[],int year,int month,int day,char doctor[],char office[],int number,int order)
{
    //add to linked-list
    Formp *p = (Formp*)malloc(sizeof(Formp));//两端口共用的将输入的数据新增到链表的函数，其中order为判断医生与用户的依据 ；用户为0，医生为1
    if(order == 1)
    {
        strcpy(p->doctor,doctor);
    	strcpy(p->office,office);
        p->timeYear = year;
        p->timeMon = month;
        p->timeDay = day;
        p->number = number;
	}
    else
    {
        strcpy(p->user,u);
        strcpy(p->name,n);
        strcpy(p->doctor,doctor);
    	strcpy(p->office,office);
        p->timeYear = year;
        p->timeMon = month;
        p->timeDay = day;
    }
    
    p->next = NULL;
    //head不为空 
    Formp *First = pList->head;
    if (First)
    {
        pList->tail->next = p;//加到尾链 
        pList->tail = pList->tail->next;
    }
    //head为空 
    else
    {
        pList->head = pList->tail = p;
    }
    
}
