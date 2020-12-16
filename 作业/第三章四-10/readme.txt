在沈俊老师给出的链表成员函数的声明基础上进行了编写，将整个类设计为无头节点的链表。同时沿用了神骏老师的测试代码，当键入9时连接两个链表。当键入a时则重新生成链表并在合并的过程中进行降序。为了增加程序的扩展性，程序在两个链表非升序输入的情况下仍能以降序合并，利用结点插入的方法实现。时间复杂度应为O(n^2)。
```
template <class ElemType>
LinkList <ElemType> & LinkList <ElemType> :: LinkCatSort(const LinkList <ElemType> &lb)
{
LinkList <ElemType> lc;
Node <ElemType> *p=head,*q=lb.head,*r=lc.head;
int i;
for(;p!=NULL;p=p->next)
    {if(lc.head==NULL)
        {lc.InsertElem(p->data);}
    else
    {
        if(p->data>lc.head->data)
                    lc.InsertElem(0,p->data);
        else
            {for(i=1,r=lc.head;r->next!=NULL;i++)
            {
                if(p->data<=r->data&&p->data>=r->next->data)
                    {lc.InsertElem(i,p->data);break;}
                else
                    r=r->next;
            }
            if(r->next==NULL)
                lc.InsertElem(p->data);
            }
    }
}
for(;q!=NULL;q=q->next)
    {if(lc.head==NULL)
        {lc.InsertElem(q->data);}
    else
    {
        if(q->data>lc.head->data)
                    lc.InsertElem(0,q->data);
        else
            {for(i=1,r=lc.head;r->next!=NULL;i++)
            {
                if(q->data<=r->data&&q->data>=r->next->data)
                    {lc.InsertElem(i,q->data);break;}
                else
                    r=r->next;
            }
            if(r->next==NULL)
                lc.InsertElem(q->data);
            }
    }
}
*this = lc;
return *this;
}
```
