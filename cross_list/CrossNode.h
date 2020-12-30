#ifndef __CRO_NODE_H__
#define __CRO_NODE_H__

#include "triple.h"						// ��Ԫ����

// ʮ���������Ԫ�ؽ����
template<class ElemType>
struct CrossNode
{
// ���ݳ�Ա:
	Triple<ElemType> triElem;			// ��Ԫ��
	CrossNode<ElemType> *right, *down;	// ����Ԫ�������б����б�ĺ��ָ����

// ���캯��:
	CrossNode();						// �޲����Ĺ��캯��
	CrossNode(const Triple<ElemType> &e,// �в����Ĺ��캯��
		CrossNode<ElemType> *rLink = NULL, CrossNode<ElemType> *dLink = NULL);	
};

// ʮ���������Ԫ�ؽ�����ʵ�ֲ���
template<class ElemType>
CrossNode<ElemType>::CrossNode()
// �������������ָ����Ϊ�յĽ��
{
	right = NULL;	
	down = NULL;
}

template<class ElemType>
CrossNode<ElemType>::CrossNode(const Triple<ElemType> &e,
		CrossNode<ElemType> *rLink, CrossNode<ElemType> *dLink)
// �����������֪��Ԫ���ָ���������
{
	triElem.row = e.row;	
	triElem.col = e.col;	
	triElem.value = e.value;
	right = rLink;		
	down = dLink;			
}

#endif
