#ifndef LINKBINARYTREENODE_H
#define LINKBINARYTREENODE_H
#include <stdlib.h>
template <class ElemType>
struct BinaryTreeNode
{
    ElemType data;  //����
    BinaryTreeNode<ElemType> *leftChild;  //����
    BinaryTreeNode<ElemType> *rightChild;  //�Һ���
    BinaryTreeNode();  //�޲ι���
    BinaryTreeNode(const ElemType &d,BinaryTreeNode<ElemType> *lChild=NULL,BinaryTreeNode<ElemType> *rChild=NULL);//�вι���
};

template<class ElemType>
BinaryTreeNode<ElemType>::BinaryTreeNode()
//�޲ι��죬����սڵ㣬���Һ��Ӷ�Ϊ��
{
    leftChild=NULL;  //����Ϊ��
    rightChild=NULL;  //�Һ���Ϊ��
}

template<class ElemType>
BinaryTreeNode<ElemType>::BinaryTreeNode(const ElemType &d,BinaryTreeNode<ElemType> *lChild,BinaryTreeNode<ElemType> *rChild)
//�вι��죬���ݺ����Һ��ӷֱ�ֵ
{
    data=d;
    leftChild=lChild;
    rightChild=rChild;
}
#endif // LINKBINARYTREENODE_H

