#include <bits/stdc++.h>
#include "Node.h"

 template <class ElemType>
 class LinkList
{
protected:
    Node <ElemType> *head;
    int length;
public:
    LinkList();
    LinkList(ElemType a[],int n);//转换构造
    virtual ~LinkList();
    bool IsEmpty() const ;
    void Clear();
    bool GetElem(int position,ElemType &el) const ;
    bool SetElem(int position,ElemType el) ;
    bool InsertElem(int position ,ElemType el);
    bool  InsertElem(ElemType el);
    LinkList (const LinkList <ElemType> &ll);
    void CreateLink();
    LinkList<ElemType> & LinkCat(const LinkList<ElemType> & ll);
    LinkList<ElemType> & Sort();
    void Display() const ;

};

//无参构造
template <class ElemType>
LinkList <ElemType>:: LinkList()
{
    head= new Node<ElemType> ;
    length = 0;
}
//转换构造
template <class ElemType>
LinkList <ElemType>:: LinkList (ElemType v[],int n)
{
    Node <ElemType> *p;
    head = new Node <ElemType>(v[0],NULL);
    p=head;
    for(int i =1;i<n;i++)
        {
            p->next = new Node<ElemType> (v[i],NULL);
            p=p->next;
        }
        length=n;
}
template <class ElemType>
LinkList <ElemType>:: ~ LinkList()
{
    Clear();
    delete head;
}
template <class ElemType>
bool LinkList <ElemType> :: IsEmpty() const
{
     return head==NULL;
}
template <class ElemType>
void LinkList <ElemType>:: Clear()
{
    while(head!=NULL)
    {
        Node <ElemType> *p=head;
        head=head ->next;
        delete p;
    }
    length = 0;
}
//获取元素
template <class ElemType>
bool  LinkList<ElemType> ::GetElem(int position,ElemType &el) const
{
    if(position<0||position >= length)
        return false ;
    else{
        Node <ElemType> *p=head;
        for (int i=0;i<position;i++)
            p=p->next;
        el=p->data;
        return true ;
    }
}
template <class ElemType>
bool  LinkList<ElemType> :: SetElem(int position,ElemType el)
{
    if(position<0||position >=length)
        return false ;
    else
    {
        Node <ElemType> *p=head;
        for (int i=0;i<position ;i++)
            p=p->next;
        p->data=el;
        return true;
    }
}
template <class ElemType>
bool  LinkList<ElemType> :: InsertElem(int position ,ElemType el)
{
    if (position < 1 || position > length )
        return false ;
    else
    {
        Node <ElemType> *p=head,*q ;
        for ( int i = 1 ; i <=position ; i ++)
                p=p->next;
        q=new Node<ElemType>(el,p->next);
        p->next=q;
        length++;
        return true;
    }
}

template <class ElemType>
bool  LinkList<ElemType> :: InsertElem(ElemType el)
{
     Node <ElemType> *p=head,*q;
     q=new Node <ElemType> (el,NULL);
     for (p = head; p->next != NULL; p = p->next) ;
     p->next=q;
     length++;
     return true;
}


template <class ElemType>
LinkList <ElemType> :: LinkList (const LinkList <ElemType> &ll)
{
	int llLength = ll.length;	// 取被复制单链表的长度
	ElemType e;
	head = new Node<ElemType>;
	length = 0;						// 初始化元素个数
	for (int i = 0; i < llLength; i++)	{	// 复制数据元素
		ll.GetElem(i, e);	       // 取出第i个元素的值放在e中
		InsertElem(e);		       // 将e插入到当前单链表的表尾
	}
}
template <class ElemType>
void LinkList <ElemType> :: CreateLink()
{
    for (int i=1;i<=length;i++)
    {
        ElemType e;
        cin>>e;
        SetElem(i,e);
    }
    return ;
}
template <class ElemType>
LinkList<ElemType> & LinkList<ElemType>::LinkCat(const LinkList<ElemType> & ll)
{
    Node<ElemType> *p=head,*q=ll.head;
    while(p->next!=NULL)
        p=p->next;
    while(q!=NULL)
        {p->next=new Node<ElemType>(q->data,NULL);
        p=p->next;
        q=q->next;}
    length+=ll.length;
return *this;
}
/*template <class ElemType>
LinkList <ElemType> & LinkList<ElemType> :: Sort(const LinkList <ElemType>)*/
template <class ElemType>
void LinkList<ElemType>::Display() const
{
    if(IsEmpty()==false)
    {
        Node <ElemType> *p=head;
        for(;p->next!=NULL;p=p->next)
            cout<<p->data<<"->";
        cout<<p->data<<endl;
    }
    return ;
}
