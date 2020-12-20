#ifndef __SQ_STACK_H__
#define __SQ_STACK_H__
#include "Assistance.h"	// ���������


// ˳��ջģ����
template<class ElemType>
class SeqStack
{
protected:
// ˳��ջ�����ݳ�Ա:
	int top;										// ջ��ָ��
	int maxSize;									// ջ���������
	ElemType *elems;								// Ԫ�ش洢�ռ�
	int top2;


public:
//  ˳��ջ�ķ������������ر���ϵͳĬ�Ϸ�������:
	SeqStack(int size = DEFAULT_SIZE);				// ���캯��
	virtual ~SeqStack();							// ��������
	int GetLength() const;							// ��ջ�ĳ���
	bool IsEmpty(char D) const;							// �ж�ջ�Ƿ�Ϊ��
	void Clear();									// ��ջ���
	void Traverse(void (*Visit)(const ElemType &)) const;	// ����ջ
	Status Push(const ElemType e);				    // ��ջ
	Status Top(ElemType &e,char D) const;				    // ȡ��Ԫ��
	SeqStack(const SeqStack<ElemType> &s);		// ���ƹ��캯��
	SeqStack<ElemType> &operator =(const SeqStack<ElemType> &s); // ��ֵ�������
	Status PushD(const ElemType e , char D='L');				    // ��ջ
	Status PopD(ElemType &e ,char D='L');					    // ��ջ
};



//��4�⣬˫ջ����һ������ռ�
template <class ElemType>
Status SeqStack<ElemType> :: PushD(const ElemType e , char D )
{
     if(top==top2-1)
        return OVER_FLOW;
    else
    {
        if(D=='L'||D=='l')
            {elems[++top]=e;return SUCCESS;}
        else if(D=='R'||D=='r')
            {elems[--top2]=e;return SUCCESS;}
        else
            return RANGE_ERROR;
    }
}

template <class ElemType>
Status SeqStack<ElemType> :: PopD(ElemType &e , char D )
{

    if(IsEmpty(D))return UNDER_FLOW;
    else
    {
        if(D=='L'||D=='l')
            {e=elems[top--];return SUCCESS;}
        else if(D=='R'||D=='r')
            {e=elems[top2++]=e;return SUCCESS;}
        else
            return RANGE_ERROR;
    }
}
// ˳��ջ���ʵ�ֲ���
template<class ElemType>
SeqStack<ElemType>::SeqStack(int size)
// �������������һ���������Ϊsize�Ŀ�ջ
{
	maxSize = size;						// ջ���������
	top2=size;
	if (elems != NULL) delete []elems;	// �ͷ����д洢�ռ�
	elems = new ElemType[maxSize];		// �����µĴ洢�ռ�
	top = -1;
}

template<class ElemType>
SeqStack<ElemType>::~SeqStack()
// �������������ջ
{
	delete []elems;					// �ͷ�ջ�Ĵ洢�ռ�
}

template <class ElemType>
int SeqStack<ElemType>::GetLength() const
// �������������ջ��Ԫ�ظ���
{
	return maxSize-(top2-top);
}

template<class ElemType>
bool SeqStack<ElemType>::IsEmpty(char D) const
// �����������ջΪ�գ��򷵻�true�����򷵻�false
{
    if (D=='L'||D=='l')
        return top == -1;
    if(D == 'R'||D=='r')
        return top2==maxSize;
    return false;
}

template<class ElemType>
void SeqStack<ElemType>::Clear()
// ������������ջ
{
	top = -1;
	top2 = maxSize-1;
}

template <class ElemType>
void SeqStack<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
    int i;
	for (i = 0; i <= top ; i++)
		(*Visit)(elems[i]);
    for(;i<top2;i++);
    for(;i<maxSize;i++)
        (*Visit)(elems[i]);
}

template<class ElemType>
Status SeqStack<ElemType>::Push(const ElemType e)
// �����������Ԫ��e׷�ӵ�ջ��,��ɹ��򷵼�SUCCESS,��ջ����������OVER_FLOW
{
	if (top == maxSize - 1) // ջ����
		return OVER_FLOW;
	else  {	// �����ɹ�
		elems[++top] = e;	// ��Ԫ��e׷�ӵ�ջ��
		return SUCCESS;
	}
}

template<class ElemType>
Status SeqStack<ElemType>::Top(ElemType &e,char D) const
// �����������ջ�ǿ�,��e����ջ��Ԫ��,��������SUCCESS,����������UNDER_FLOW
{
	if(IsEmpty(D))	 // ջ��
		return UNDER_FLOW;
	else	{ // ջ�ǿ�,�����ɹ�
		e = elems[top];	// ��e����ջ��Ԫ��
		return SUCCESS;
	}
}


template<class ElemType>
SeqStack<ElemType>::SeqStack(const SeqStack<ElemType> &s)
// �����������ջs������ջ--���ƹ��캯��
{
    maxSize = s.maxSize;			    // ջ���������
    if (elems != NULL) delete []elems;	// �ͷ����д洢�ռ�
    elems = new ElemType[maxSize];		// ����洢�ռ�
	top = s.top;					    // ����ջ��ָ��
	for (int i = 0; i <= top; i++)      // ��ջ�׵�ջ����ջs��ÿ��Ԫ�ؽ��и���
		elems[i] = s.elems[i];
}

template<class ElemType>
SeqStack<ElemType> &SeqStack<ElemType>::operator = (const SeqStack<ElemType> &s)
// �����������ջs��ֵ����ǰջ--��ֵ�������
{
	if (&s != this)	{
	    maxSize = s.maxSize;			    // ջ���������
	    if (elems != NULL) delete []elems;	// �ͷ����д洢�ռ�
	    elems = new ElemType[maxSize];		// ����洢�ռ�
		top = s.top;					    // ����ջ��ָ��
		for (int i = 0; i <= top; i++)		// ��ջ�׵�ջ����ջs��ÿ��Ԫ�ؽ��и���
			elems[i] = s.elems[i];
	}
	return *this;
}

#endif
