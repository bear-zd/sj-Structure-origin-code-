#ifndef __LK_LIST_H__
#define __LK_LIST_H__

#include "Assistance.h"				// ���������
#include "Node.h"					// �����

// ��������
template <class ElemType>
class LinkList
{
protected:
//  ����������ݳ�Ա
	Node<ElemType> *head;				// ͷ���ָ��
	int length;							// ��������

public:
//  ������ĺ�����Ա
	LinkList();							// �޲����Ĺ��캯��
	LinkList(ElemType v[], int n);		// �в����Ĺ��캯��
	virtual ~LinkList();				// ��������
	int GetLength() const;				// ��������
	bool IsEmpty() const;	 			// �жϵ������Ƿ�Ϊ��
	void Clear();						// �����������
	void Traverse(void (*Visit)(const ElemType &)) const;// ����������
	Status LocateElem(const ElemType &e, int & position) const;	         // Ԫ�ض�λ
	Status GetElem(int position, ElemType &e) const;	 // ��ָ��λ�õ�Ԫ��
	Status SetElem(int position, const ElemType &e);	 // ����ָ��λ�õ�Ԫ��ֵ
	Status DeleteElem(int position, ElemType &e);		 // ɾ��Ԫ��
	Status InsertElem(int position, const ElemType &e);	 // ���ƶ�λ�ò���Ԫ��
	Status InsertElem(const ElemType &e);	             // �ڱ�β����Ԫ��
	LinkList(const LinkList<ElemType> &la);            // ���ƹ��캯��
	LinkList<ElemType> & operator =(const LinkList<ElemType> &la); // ���ظ�ֵ����
	LinkList <ElemType> & LinkCatSort(const LinkList <ElemType> &lb); //�������Ӳ�����
	LinkList <ElemType> &LinkCat(const LinkList <ElemType> &lb);//��������
	//int Find(const  ElemType & i);
};


// ���������ʵ�ֲ���



template <class ElemType>
LinkList<ElemType>::LinkList()
// �������������һ��������
{
	head = new Node<ElemType>;		// ����ͷ���
	head=NULL;                  // ����ͷ���ʧ�ܣ���ֹ��������
	length = 0;						// ��ʼ����������Ϊ0
}

template <class ElemType>
LinkList<ElemType>::LinkList(ElemType v[], int n)
{
    Node<ElemType> *p;
	p = head = new Node<ElemType>(v[0],NULL);	// ����ͷ���
	for (int i = 1; i < n; i++)
    {
	    p->next = new Node<ElemType>(v[i],NULL);
	    p = p->next;
    }
	length = n;						// ��ʼ����������Ϊn
}

template <class ElemType>
LinkList<ElemType>::~LinkList()
// ������������ٵ�����
{
	Clear();			// ��յ�����
	delete head;		// �ͷ�ͷ�����ָ�ռ�
}

template <class ElemType>
int LinkList<ElemType>::GetLength() const
// ������������ص�����ĳ���
{
	return length;
}

template <class ElemType>
bool LinkList<ElemType>::IsEmpty() const
// ����������絥����Ϊ�գ��򷵻�true�����򷵻�false
{
	return head == NULL;
}

template <class ElemType>
void LinkList<ElemType>::Clear()
// �����������յ�����,ɾ��������������Ԫ�ؽ��
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
// ������������ζԵ������ÿ��Ԫ�ص��ú���(*visit)����
{
    Node<ElemType> *p = head;
	while (p != NULL) {
		(*Visit)(p->data);	// �Ե�������ÿ��Ԫ�ص��ú���(*visit)����
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
// �������������������ڵ�i��Ԫ��ʱ����e������ֵ����������ENTRY_FOUND,
//	����������NOT_PRESENT
{
	if (i < 0 || i >= length||IsEmpty())
		return RANGE_ERROR;
 	else	{
		Node<ElemType> *p = head;
		int count;
		for (count = 0; count <i; count++)
            p = p->next;
		e = p->data;				// ��e���ص�i��Ԫ�ص�ֵ
		return ENTRY_FOUND;
        }
	}


template <class ElemType>
Status LinkList<ElemType>::SetElem(int i, const ElemType &e)
// �����������������ĵ�i��λ�õ�Ԫ�ظ�ֵΪe,
//	i��ȡֵ��ΧΪ1��i��length,
//	i�Ϸ�ʱ��������SUCCESS,����������RANGE_ERROR
{
	if (i < 0 || i >= length||IsEmpty())
		return RANGE_ERROR;
	else	{
		Node<ElemType> *p = head;
		int count;
		for (count = 0; count < i; count++)
		  p = p->next;	           // ȡ��ָ���i������ָ��
		p->data = e;			   // �޸ĵ�i��Ԫ�ص�ֵΪe
		return SUCCESS;
	}
}

template <class ElemType>
Status LinkList<ElemType>::DeleteElem(int i, ElemType &e)
// ���������ɾ��������ĵ�i��λ�õ�Ԫ��, ����e������ֵ,
//	i��ȡֵ��ΧΪ1��i��length,
//	i�Ϸ�ʱ��������SUCCESS,����������RANGE_ERROR
{
	if (i < 0 || i >= length||IsEmpty())
		return RANGE_ERROR;   // i��Χ��
 	else	{
		Node<ElemType> *p = head, *q;
		int count;
		if(length==1&&i==0)
            {Clear();return SUCCESS;}
		for (count = 0; count < i-1; count++)
		  p = p->next;	      // pָ���i-1�����
		q = p->next;	      // qָ���i�����
		p->next = q->next;	  // ɾ�����
		e = q->data;		  // ��e���ر�ɾ���Ԫ��ֵ
		length--;			  // ɾ���ɹ���Ԫ�ظ�����1
		delete q;			  // �ͷű�ɾ���
		return SUCCESS;
	}
}

template <class ElemType>
Status LinkList<ElemType>::InsertElem(int i, const ElemType &e)
// ����������ڵ�����ĵ�i��λ��ǰ����Ԫ��e
//	i��ȡֵ��ΧΪ1��i��length+1
//	i�Ϸ�ʱ����SUCCESS, ����������RANGE_ERROR
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
		  p = p->next;	                    // pָ���i-1�����
		q = new Node<ElemType>(e, p->next); // �����½��q
		p->next = q;				        // ��q���뵽������
		length++;							// ����ɹ��󣬵������ȼ�1
		return SUCCESS;
	}
}

template <class ElemType>
Status LinkList<ElemType>::InsertElem(const ElemType &e)
// ����������ڵ�����ı�βλ�ò���Ԫ��e
{
    if (head==NULL)
        {head=new Node<ElemType>(e,NULL);length++;return SUCCESS;}
    else{
	Node<ElemType> *p, *q;
	q = new Node<ElemType>(e, NULL);    // �����½��q
	for (p = head; p->next != NULL; p = p->next) ;	// pָ���β���
    p->next = q;                        // �ڵ�����ı�βλ�ò����½��
	length++;							// ����ɹ��󣬵������ȼ�1
	return SUCCESS;
    }
}

template <class ElemType>
LinkList<ElemType>::LinkList(const LinkList<ElemType> &la)
// ������������ƹ��캯�����ɵ�����la�����µ�����
{
	int laLength = la.GetLength();	// ȡ�����Ƶ�����ĳ���
	ElemType e;
	length = 0;						// ��ʼ��Ԫ�ظ���
    head=NULL;
	for (int i = 0; i < laLength; i++)	{	// ��������Ԫ��
		la.GetElem(i, e);	       // ȡ����i��Ԫ�ص�ֵ����e��
		InsertElem(e);		       // ��e���뵽��ǰ������ı�β

	}
}

template <class ElemType>
LinkList<ElemType> &LinkList<ElemType>::operator =(const LinkList<ElemType> &la)
// ������������ظ�ֵ���������������la��ֵ����ǰ������
{
	if (&la != this)	{
		int laLength = la.GetLength();// ȡ����ֵ������ĳ���
		ElemType e;
		Clear();							// ��յ�ǰ������
		for (int i = 0; i < laLength; i++)		{
			la.GetElem(i, e);		    // ȡ����i��Ԫ�ص�ֵ����e��
			InsertElem(e);		            // ��e���뵽��ǰ������ı�β
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

