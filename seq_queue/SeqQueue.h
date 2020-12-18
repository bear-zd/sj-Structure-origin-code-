#ifndef __SQ_QUEUE_H__
#define __SQ_QUEUE_H__
#include "Assistance.h"	// ���������

// ѭ��������

template<class ElemType>
class SeqQueue 
{
protected:
	int front, rear;									 // ��ͷ��βָ�� 
	int maxSize;										 // �������� 
	ElemType *elems;									 // Ԫ�ش洢�ռ�

public:
	SeqQueue(int size = DEFAULT_SIZE);					 // ���캯��
	virtual ~SeqQueue();								 // ��������
	int GetLength() const;								 // ����г���			 
	bool IsEmpty() const;								 // �ж϶����Ƿ�Ϊ��
	void Clear();										 // ���������
	void Traverse(void (*Visit)(const ElemType &)) const;// ��������
	Status DelQueue(ElemType &e);					     // ���Ӳ���
	Status GetHead(ElemType &e) const;				     // ȡ��ͷ����
	Status EnQueue(const ElemType e);				     // ��Ӳ���
	SeqQueue(const SeqQueue<ElemType> &q);			 // ���ƹ��캯��
	SeqQueue<ElemType> &operator =(const SeqQueue<ElemType> &q);// ��ֵ�������
};

// ѭ���������ʵ�ֲ���

template<class ElemType>
SeqQueue<ElemType>::SeqQueue(int size)
// �������������һ������Ϊsize�Ŀ�ѭ������
{
	maxSize = size;							// ���ö�������
//	if (elems != NULL) delete []elems;	// �ͷ����д洢�ռ�
	elems = new ElemType[maxSize];			// ����Ԫ�ش洢�ռ�
	rear = front = 0;						// ��ʼ����ͷ���β
}

template <class ElemType>
SeqQueue<ElemType>::~SeqQueue()
// ������������ٶ���
{
	delete []elems;							// �ͷ�Ԫ�ش洢�ռ�
}

template<class ElemType>
int SeqQueue<ElemType>::GetLength() const
// ������������ض��г���			 
{
	return (rear - front + maxSize) % maxSize;
}

template<class ElemType>
bool SeqQueue<ElemType>::IsEmpty() const
// ��������������Ϊ�գ��򷵻�true�����򷵻�false
{
   return rear == front;
}

template<class ElemType>
void SeqQueue<ElemType>::Clear() 
// �����������ն���
{
	rear = front = 0;
}

template <class ElemType>
void SeqQueue<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
// ������������ζԶ��е�ÿ��Ԫ�ص��ú���(*visit)
{
	for (int i = front; i != rear; i = (i + 1) % maxSize)
		(*Visit)(elems[i]);
}


template<class ElemType>
Status SeqQueue<ElemType>::DelQueue(ElemType &e)
// ���������������зǿգ���ôɾ����ͷԪ�أ�����e������ֵ����������SUCCESS,
// ����������UNDER_FLOW��
{
	if (!IsEmpty()) 	{	// ���зǿ�
		e = elems[front];					// ��e���ض�ͷԪ��
		front = (front + 1) % maxSize;		// frontָ����һԪ��
		return SUCCESS;
	}
	else	// ����Ϊ��
		return UNDER_FLOW;
}

template<class ElemType>
Status SeqQueue<ElemType>::GetHead(ElemType &e) const
// ���������������зǿգ���ô��e���ض�ͷԪ�أ���������SUCCESS,
// ����������UNDER_FLOW��
{
	if (!IsEmpty()) 	{	    // ���зǿ�
		e = elems[front];		// ��e���ض�ͷԪ��
		return SUCCESS;
	}
	else
		return UNDER_FLOW;
}

template<class ElemType>
Status SeqQueue<ElemType>::EnQueue(const ElemType e)
// ��������������������������OVER_FLOW,
// �������Ԫ��eΪ�µĶ�β������SUCCESS
{
	if ((rear + 1) % maxSize == front)
		return OVER_FLOW;
	else	{	// ����δ������ӳɹ�
		elems[rear] = e;					// ����eΪ�¶�β
		rear = (rear + 1) % maxSize;		// rearָ���¶�β
		return SUCCESS;
	}
}

template<class ElemType>
SeqQueue<ElemType>::SeqQueue(const SeqQueue<ElemType> &q)
// ����������ɶ���q�����¶���--���ƹ��캯��
{
    maxSize = q.maxSize;				    // ���ö�������
    if (elems != NULL) delete []elems;		// �ͷŴ洢�ռ�
    elems = new ElemType[maxSize];			// ����洢�ռ�
	front = q.front;						// ���ƶ�ͷλ��	
	rear = q.rear;						// ���ƶ�βλ��
	for (int i = front; i != rear; i = (i + 1) % maxSize)
		elems[i] = q.elems[i];
}

template<class ElemType>
SeqQueue<ElemType> &SeqQueue<ElemType>::operator =(const SeqQueue<ElemType> &q)
// ���������������q��ֵ����ǰ����--��ֵ�������
{
	if (&q != this)	{
        maxSize = q.maxSize;				// ���ö�������
	    if (elems != NULL) delete []elems;	// �ͷŴ洢�ռ�
	    elems = new ElemType[maxSize];		// ����洢�ռ�
		front = q.front;					// ���ƶ�ͷλ��	
		rear = q.rear;					// ���ƶ�βλ��
		for (int i = front; i != rear; i = (i + 1) % maxSize)
			elems[i] = q.elems[i];
	}
	return *this;
}

#endif
