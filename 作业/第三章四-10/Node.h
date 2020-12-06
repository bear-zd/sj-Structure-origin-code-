#ifndef __NODE_H__
#define __NODE_H__

#include "GlobalAssitence.h"

template <class ElemType>
struct Node
{
	ElemType data;				// ������
	Node<ElemType> *next;		// ָ����

	Node();						// �޲ι���
	Node(ElemType e, Node<ElemType> *link = NULL);	// ת������
};


template<class ElemType>
Node<ElemType>::Node()
{
   next = NULL;
}

template<class ElemType>
Node<ElemType>::Node(ElemType e, Node<ElemType> *link)
{
   data = e;
   next = link;
}

#endif
