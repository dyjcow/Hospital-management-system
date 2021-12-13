void freeList(List *pList)//Á´±í¿Õ¼äÊÍ·Å 
{
    Patient *p,*q;
    for (p = pList->head; p ;p = q)
    {
        q = p->next;
        free(p);
    }
    
}
