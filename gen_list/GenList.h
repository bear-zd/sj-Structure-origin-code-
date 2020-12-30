#ifndef __GEN_LIST_H__
#define __GEN_LIST_H__

#include "Assistance.h"				// ���������
#include "GenNode.h"					// ���������

// �������
template<class ElemType>
class GenList
{
protected:
// �����������ݳ�Ա:
	GenListNode<ElemType> *head;		// �����ͷָ��
	
// ��������
	void ShowHelp(GenListNode<ElemType> *hd) const;	
		// ��ʾ��hdΪͷ���Ĺ����
	int DepthHelp(const GenListNode<ElemType> *hd);	
		// ������hdΪ��ͷ�Ĺ��������
	void ClearHelp(GenListNode<ElemType> *hd);		
		// �ͷ���hdΪ��ͷ�Ĺ����ṹ
	void CopyHelp(const GenListNode<ElemType> *sourceHead, 
		 GenListNode<ElemType> *&destHead);	
		// ����destHeadΪͷ���Ĺ�����Ƴ���sourceHeadΪͷ����
		// �����
	static void CreateHelp(GenListNode<ElemType> *&first);
		// ������firstΪͷ���Ĺ����

public:
// �����������ͷ������������ر���ϵͳĬ�Ϸ�������:
	GenList();							// �޲����Ĺ��캯��
	GenList(GenListNode<ElemType> *hd);	// ��ͷ���ָ�빹������
	~GenList();							// ��������
	GenListNode<ElemType> *First() const;// ���ع����ĵ�һ��Ԫ��
	GenListNode<ElemType> *Next(GenListNode<ElemType> *p) const;	                                                                               
		// ����pָ��Ĺ����Ԫ�صĺ��
	bool IsEmpty() const;				// �жϹ�����Ƿ�Ϊ��
	void Insert(const ElemType &e);		// ��ԭ��Ԫ��e��Ϊ��ͷ���뵽�������ǰ��
	void Insert(GenList<ElemType> &subList);	
		// ���ӱ�subList��Ϊ��ͷ���뵽�������ǰ��
	Status Delete(int i);           // ɾ��������е�i��Ԫ��		
	int GetDepth();						// �����������
    int GetLength();	                // ������ĳ���
	GenList(const GenList<ElemType> &g);// ���ƹ��캯��
	GenList<ElemType> &operator =(const GenList<ElemType> &g);// ��ֵ�������
	void Input(void);					// ��������	
	void Show(void);					// ��ʾ�����	
};

// ��������ʵ�ֲ���
template <class ElemType>
GenList<ElemType>::GenList()
// �������������һ���չ����
{
	head = new GenListNode<ElemType>(HEAD);
	head->ref = 1;							// ������
}

template <class ElemType>
GenList<ElemType>::GenList(GenListNode<ElemType> *hd)
// �����������ͷ���ָ�빹������
{
	head = hd;								// ͷ���
}

template <class ElemType>
GenListNode<ElemType> *GenList<ElemType>::First() const
// ������������ع����ĵ�һ��Ԫ��
{
	return head->tLink;
}

template <class ElemType>
GenListNode<ElemType> *GenList<ElemType>::Next(GenListNode<ElemType> *p) const
// �������������pָ��Ĺ����Ԫ�صĺ��
{
	return p->tLink;
}

template <class ElemType>
bool GenList<ElemType>::IsEmpty() const
// ���������������Ϊ�գ��򷵻�true�����򷵻�false
{
	return head->tLink == NULL;
}

template <class ElemType>
void GenList<ElemType>::Insert(const ElemType &e)
// �����������ԭ��Ԫ��e��Ϊ��ͷ���뵽�������ǰ��
{
	GenListNode<ElemType> *p = new GenListNode<ElemType>(ATOM, head->tLink);
	p->atom = e;				// ������
	head->tLink = p;			// ��p������head��head->tLink֮�� 
}

template <class ElemType>
void GenList<ElemType>::Insert(GenList<ElemType> &subList)
// ������������ӱ�subList��Ϊ��ͷ���뵽�������ǰ��
{
	GenListNode<ElemType> *p = new GenListNode<ElemType>(LIST, head->tLink);
	p->hLink = subList.head;	// �ӱ�
	subList.head->ref++;		// subList�������Լ�1
	head->tLink = p;			// ��p������head��head->tLink֮�� 
}

template <class ElemType>
Status GenList<ElemType>::Delete(int i)
// ���������ɾ��������е�i��Ԫ�� 
{
	if (i < 1 || i > GetLength())		
		return RANGE_ERROR;      // ����λ�ô�
	else	{
	    GenListNode<ElemType> *pre = head, *p = head->tLink;
		for (int k = 1; k < i; k++)  {//  ʹp��pre�ֱ�ָ��ɾ��������ǰ����� 
			pre = p;
            p = p->tLink; 
        }
        pre->tLink = p->tLink;
        if (p->tag == LIST)
       	    ClearHelp(p->hLink); 
        delete p;
		return SUCCESS;	        // ����ɾ���ɹ�
	}
}


template <class ElemType>
void GenList<ElemType>::ShowHelp(GenListNode<ElemType> *hd) const
// �����������ʾ��hdΪͷ���Ĺ����
{
	bool frist = true;
	cout << "(";						// �������(��ʼ
	for (GenListNode<ElemType> *p = hd->tLink; p != NULL; p = p->tLink)
	{	// ���δ��������Ԫ�� 
		if (frist) frist = false;		// ��һ��Ԫ��
		else cout << ",";				// ��ͬԪ������ö��Ÿ���
		if (p->tag == ATOM)         	// ԭ�ӽ��
			cout << p->atom;
		else	                     	// ����
			ShowHelp(p->hLink);
	}
	cout << ")";						// �������)����
}

template <class ElemType>
void GenList<ElemType>::Show(void)
// �����������ʾ�����	
{
	ShowHelp(head);					// ���ø���������ʾ�����
}


template <class ElemType>
int GenList<ElemType>::DepthHelp(const GenListNode<ElemType> *hd)
// ���������������hdΪ��ͷ�Ĺ��������
{
	if (hd->tLink == NULL) return 1;// �չ��������Ϊ1
	
	int subMaxDepth = 0;			// �ӱ�������
	for (GenListNode<ElemType> *p = hd->tLink; p != NULL; p = p->tLink)
	{	// ���ӱ��������
		if (p->tag == LIST)
		{	// �ӱ�
			int curSubDepth = DepthHelp(p->hLink);	// �ӱ����
			if (subMaxDepth < curSubDepth) subMaxDepth = curSubDepth;
		}
	}
	return subMaxDepth + 1;				// ��������Ϊ�ӱ������ȼ�1
}

template <class ElemType>
int GenList<ElemType>::GetDepth()
// ������������ع�������
{
	return DepthHelp(head);
}

template <class ElemType>
int GenList<ElemType>::GetLength()
// ������������ع������
{
	GenListNode<ElemType> *p = head->tLink;	// ��ʱ���� 
	int length = 0;
	while (p) {
          p = p->tLink;
          length++;
    }
	return length;
}

template <class ElemType>
void GenList<ElemType>::ClearHelp(GenListNode<ElemType> *hd)
// ����������ͷ���hdΪ��ͷ�Ĺ����ṹ
{
	hd->ref--;						// �������Լ�1
	
	if (hd->ref == 0)
	{	// ������Ϊ0,�ͷŽ����ռ�ÿռ�
		GenListNode<ElemType> *pre = hd, *p;	// ��ʱ���� 
		for (p = hd->tLink; p != NULL; p = p->tLink)
		{	// ɨ������hd�Ķ���
			delete pre;					// �ͷ�pre
            pre = p;
			if (p->tag == LIST)			// pΪ�ӱ�
				ClearHelp(p->hLink);	// �ͷ��ӱ�
		}
		delete pre;						// �ͷ�β���pre
	}
}

template <class ElemType>
GenList<ElemType>::~GenList()
// ����������ͷŹ����ṹ������������
{
	ClearHelp(head);
}

template <class ElemType>
void GenList<ElemType>::CopyHelp(const GenListNode<ElemType> *sourceHead, 
	GenListNode<ElemType> *&destHead)	
// ��ʼ����: ��sourceHeadΪͷ���Ĺ����Ϊ�ǵݹ�����
// �������: ����sourceHeadΪͷ���Ĺ�����Ƴ���destHeadΪͷ���Ĺ����
{
	destHead = new GenListNode<ElemType>(HEAD);		// ����ͷ���
	GenListNode<ElemType> *destPtr = destHead;		// destHead�ĵ�ǰ���
	destHead->ref = 1;								// ������Ϊ1
	for (GenListNode<ElemType> *p = sourceHead->tLink; p != NULL; 
		p = p->tLink)
	{	// ɨ������sourceHead�Ķ���
		destPtr = destPtr->tLink = new GenListNode<ElemType>(p->tag);	
			// �����½��
		if (p->tag == LIST)
		{	// �ӱ�
			CopyHelp(p->hLink, destPtr->hLink);// �����ӱ�
		}
		else
		{	// ԭ�ӽ��
			destPtr->atom = p->atom;				// ����ԭ�ӽ��
		}
	}
}

template <class ElemType>
GenList<ElemType>::GenList(const GenList<ElemType> &g)
// ����������ɹ����g�����¹����--���ƹ��캯��
{
	CopyHelp(g.head, head);
}

template<class ElemType>
GenList<ElemType> &GenList<ElemType>::operator =(const GenList<ElemType> &g)
// ����������������g��ֵ����ǰ�����--��ֵ�������
{
	if (&g != this)	{
		ClearHelp(head);			// ��յ�ǰ�����
		CopyHelp(g.head, head);		// ���ƹ����
	}
	return *this;
}

template<class ElemType>
void GenList<ElemType>::CreateHelp(GenListNode<ElemType> *&first)
// ���������������firstΪͷ���Ĺ����
{
	char ch = GetChar();			// �����ַ�
	switch (ch)
	{
	case ')':						// ����������
		return;				
	case '(':						// �ӱ�
		// ��ͷΪ�ӱ�
		first = new GenListNode<ElemType>(LIST);// ���ɱ���
		
		GenListNode<ElemType> *subHead;	// �ӱ�ָ��
		subHead = new GenListNode<ElemType>(HEAD);// �����ӱ��ͷ���
		subHead->ref = 1;				// ������Ϊ1	
		first->hLink = subHead;			// subHeadΪ�ӱ�
		CreateHelp(subHead->tLink);		// �ݹ齨���ӱ�
		
		ch = GetChar();					// ����','
		if (ch != ',') cin.putback(ch);	// �粻��','����ch���˵�������
		CreateHelp(first->tLink);		// �����������һ���
		break;
	default:							// ԭ��
		// ��ͷΪԭ��
		cin.putback(ch);				// ��ch���˵�������
		ElemType amData;				// ԭ�ӽ������
		cin >> amData;					// ����ԭ�ӽ������
		first = new GenListNode<ElemType>(ATOM);// ����ԭ����
		first->atom = amData;			// ԭ�ӽ������
		
		ch = GetChar();					// ����','
		if (ch != ',') cin.putback(ch);	// �粻��','����ch���˵�������
		CreateHelp(first->tLink);		// �����������һ���
		break;
	}
}

template<class ElemType>
void GenList<ElemType>::Input(void)
// �����������������
{
	ClearHelp(head);
	head = new GenListNode<ElemType>(HEAD);	// ���ɹ����ͷ���
	head->ref = 1;							// ������Ϊ1
	
	GetChar();								// �����һ��'('
//	cout <<"ss"<<endl;
	GenList<ElemType>::CreateHelp(head->tLink);
		// ������head->tLinkΪ��ͷ�Ĺ����
}

#endif
