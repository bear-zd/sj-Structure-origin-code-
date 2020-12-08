#ifndef __LK_LIST_H__
#define __LK_LIST_H__

#include "Assistance.h"				// 辅助软件包
#include "Node.h"					// 结点类

// 单链表类
template <class ElemType>
class LinkList
{
protected:
//  单链表的数据成员
	Node<ElemType> *head;				// 头结点指针
	int length;							// 单链表长度

public:
//  单链表的函数成员
	LinkList();							// 无参数的构造函数
	LinkList(ElemType v[], int n);		// 有参数的构造函数
	virtual ~LinkList();				// 析构函数
	int GetLength() const;				// 求单链表长度
	bool IsEmpty() const;	 			// 判断单链表是否为空
	void Clear();						// 将单链表清空
	void Traverse(void (*Visit)(const ElemType &)) const;// 遍历单链表
	Status LocateElem(const ElemType &e, int & position) const;	         // 元素定位
	Status GetElem(int position, ElemType &e) const;	 // 求指定位置的元素
	Status SetElem(int position, const ElemType &e);	 // 设置指定位置的元素值
	Status DeleteElem(int position, ElemType &e);		 // 删除元素
	Status InsertElem(int position, const ElemType &e);	 // 在制定位置插入元素
	Status InsertElem(const ElemType &e);	             // 在表尾插入元素
	LinkList(const LinkList<ElemType> &la);            // 复制构造函数
	LinkList<ElemType> & operator =(const LinkList<ElemType> &la); // 重载赋值运算
	LinkList <ElemType> & LinkCatSort(const LinkList <ElemType> &lb); //链表连接并排序
	LinkList <ElemType> &LinkCat(const LinkList <ElemType> &lb);//链表连接
	//int Find(const  ElemType & i);
};


// 单链表类的实现部分



template <class ElemType>
LinkList<ElemType>::LinkList()
// 操作结果：构造一个空链表
{
	head = new Node<ElemType>;		// 构造头结点
	head=NULL;                  // 构造头结点失败，终止程序运行
	length = 0;						// 初始化单链表长度为0
}

template <class ElemType>
LinkList<ElemType>::LinkList(ElemType v[], int n)
{
    Node<ElemType> *p;
	p = head = new Node<ElemType>(v[0],NULL);	// 构造头结点
	for (int i = 1; i < n; i++)
    {
	    p->next = new Node<ElemType>(v[i],NULL);
	    p = p->next;
    }
	length = n;						// 初始化单链表长度为n
}

template <class ElemType>
LinkList<ElemType>::~LinkList()
// 操作结果：销毁单链表
{
	Clear();			// 清空单链表
	delete head;		// 释放头结点所指空间
}

template <class ElemType>
int LinkList<ElemType>::GetLength() const
// 操作结果：返回单链表的长度
{
	return length;
}

template <class ElemType>
bool LinkList<ElemType>::IsEmpty() const
// 操作结果：如单链表为空，则返回true，否则返回false
{
	return head == NULL;
}

template <class ElemType>
void LinkList<ElemType>::Clear()
// 操作结果：清空单链表,删除单链表中所有元素结点
{
	while (head != NULL)
	{
        Node<ElemType> *p = head;
		head=head->next;
        delete p;
	}
	length = 0;
}

template <class ElemType>
void LinkList<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
// 操作结果：依次对单链表的每个元素调用函数(*visit)访问
{
    Node<ElemType> *p = head;
	while (p != NULL) {
		(*Visit)(p->data);	// 对单链表中每个元素调用函数(*visit)访问
		p = p->next;
	}
}

template <class ElemType>
Status LinkList<ElemType>::LocateElem(const ElemType &e , int & position) const
{
    Node<ElemType> *p = head;
    position = 0;
	while (p != NULL && p->data != e) {
	    position++;
		p = p->next ;
	}
	if(p==NULL)
    {position = -1;return RANGE_ERROR;}
    return SUCCESS;

}

template <class ElemType>
Status LinkList<ElemType>::GetElem(int i, ElemType &e) const
// 操作结果：当单链表存在第i个元素时，用e返回其值，函数返回ENTRY_FOUND,
//	否则函数返回NOT_PRESENT
{
	if (i < 0 || i >= length||IsEmpty())
		return RANGE_ERROR;
 	else	{
		Node<ElemType> *p = head;
		int count;
		for (count = 0; count <i; count++)
            p = p->next;
		e = p->data;				// 用e返回第i个元素的值
		return ENTRY_FOUND;
        }
	}


template <class ElemType>
Status LinkList<ElemType>::SetElem(int i, const ElemType &e)
// 操作结果：将单链表的第i个位置的元素赋值为e,
//	i的取值范围为1≤i≤length,
//	i合法时函数返回SUCCESS,否则函数返回RANGE_ERROR
{
	if (i < 0 || i >= length||IsEmpty())
		return RANGE_ERROR;
	else	{
		Node<ElemType> *p = head;
		int count;
		for (count = 0; count < i; count++)
		  p = p->next;	           // 取出指向第i个结点的指针
		p->data = e;			   // 修改第i个元素的值为e
		return SUCCESS;
	}
}

template <class ElemType>
Status LinkList<ElemType>::DeleteElem(int i, ElemType &e)
// 操作结果：删除单链表的第i个位置的元素, 并用e返回其值,
//	i的取值范围为1≤i≤length,
//	i合法时函数返回SUCCESS,否则函数返回RANGE_ERROR
{
	if (i < 0 || i >= length||IsEmpty())
		return RANGE_ERROR;   // i范围错
 	else	{
		Node<ElemType> *p = head, *q;
		int count;
		if(length==1&&i==0)
            {Clear();return SUCCESS;}
		for (count = 0; count < i-1; count++)
		  p = p->next;	      // p指向第i-1个结点
		q = p->next;	      // q指向第i个结点
		p->next = q->next;	  // 删除结点
		e = q->data;		  // 用e返回被删结点元素值
		length--;			  // 删除成功后元素个数减1
		delete q;			  // 释放被删结点
		return SUCCESS;
	}
}

template <class ElemType>
Status LinkList<ElemType>::InsertElem(int i, const ElemType &e)
// 操作结果：在单链表的第i个位置前插入元素e
//	i的取值范围为1≤i≤length+1
//	i合法时返回SUCCESS, 否则函数返回RANGE_ERROR
{
	if (i < 0 || i >= length)
		return RANGE_ERROR;
    if(IsEmpty()&&i==0)
    {InsertElem(e);return SUCCESS;}
    if(i==0)
    {
        Node<ElemType> *q;
        q=new Node<ElemType>(e,head);
        head=q;
        length++;
        return SUCCESS;
    }
 	else	{
		Node<ElemType> *p = head, *q;
		int count;
		for (count = 0; count < i - 1 ; count++)
		  p = p->next;	                    // p指向第i-1个结点
		q = new Node<ElemType>(e, p->next); // 生成新结点q
		p->next = q;				        // 将q插入到链表中
		length++;							// 插入成功后，单链表长度加1
		return SUCCESS;
	}
}

template <class ElemType>
Status LinkList<ElemType>::InsertElem(const ElemType &e)
// 操作结果：在单链表的表尾位置插入元素e
{
    if (head==NULL)
        {head=new Node<ElemType>(e,NULL);length++;return SUCCESS;}
    else{
	Node<ElemType> *p, *q;
	q = new Node<ElemType>(e, NULL);    // 生成新结点q
	for (p = head; p->next != NULL; p = p->next) ;	// p指向表尾结点
    p->next = q;                        // 在单链表的表尾位置插入新结点
	length++;							// 插入成功后，单链表长度加1
	return SUCCESS;
    }
}

template <class ElemType>
LinkList<ElemType>::LinkList(const LinkList<ElemType> &la)
// 操作结果：复制构造函数，由单链表la构造新单链表
{
	int laLength = la.GetLength();	// 取被复制单链表的长度
	ElemType e;
	length = 0;						// 初始化元素个数
    head=NULL;
	for (int i = 0; i < laLength; i++)	{	// 复制数据元素
		la.GetElem(i, e);	       // 取出第i个元素的值放在e中
		InsertElem(e);		       // 将e插入到当前单链表的表尾

	}
}

template <class ElemType>
LinkList<ElemType> &LinkList<ElemType>::operator =(const LinkList<ElemType> &la)
// 操作结果：重载赋值运算符，将单链表la赋值给当前单链表
{
	if (&la != this)	{
		int laLength = la.GetLength();// 取被赋值单链表的长度
		ElemType e;
		Clear();							// 清空当前单链表
		for (int i = 0; i < laLength; i++)		{
			la.GetElem(i, e);		    // 取出第i个元素的值放在e中
			InsertElem(e);		            // 将e插入到当前单链表的表尾
		}
	}
	return *this;
}
template <class ElemType>
LinkList <ElemType> & LinkList <ElemType> :: LinkCat(const LinkList <ElemType> &lb)
{
    Node <ElemType> *p=head,*q=lb.head;
    if ( IsEmpty()) {*this=lb;return *this;}
    while(p->next!=NULL)
        p=p->next;
    while(q!=NULL)
    {
        p->next=new Node<ElemType>(q->data,NULL);
        p=p->next;
        q=q->next;
    }
    length+=lb.length;
    return *this;
}
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
#endif

