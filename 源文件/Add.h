void Add(List *pList,char number[],char number1[],char number2[],char number3[],int order)//两端口共用的链表新增函数，其中order为判断医生与用户的依据 ；用户为0，医生为1
{
    //申请空间 
    Patient *p = (Patient*)malloc(sizeof(Patient));
    strcpy(p->password,number2);
    strcpy(p->name,number1);
    strcpy(p->user,number);
    if(order == 1)
    {
    	strcpy(p->office,number3);
	}
    p->next = NULL;
    //判断head是否为空 
    Patient *First = pList->head;
    if (First)
    {
        pList->tail->next = p;//赋予tail->next 
        pList->tail = pList->tail->next;
    }
    //head为空 
    else
    {
        pList->head = pList->tail = p;//赋予head 
    }
    
}
