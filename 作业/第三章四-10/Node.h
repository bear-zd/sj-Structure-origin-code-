#ifndef __NODE_H__
#define __NODE_H__

#include "GlobalAssitence.h"

template <class ElemType>
struct Node
{
	ElemType data;				// 数据域
	Node<ElemType> *next;		// 指针域

	Node();						// 无参构造
	Node(ElemType e, Node<ElemType> *link = NULL);	// 转换构造
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
