#ifndef LINKBINARYTREENODE_H
#define LINKBINARYTREENODE_H
#include <stdlib.h>
template <class ElemType>
struct BinaryTreeNode
{
    ElemType data;  //数据
    BinaryTreeNode<ElemType> *leftChild;  //左孩子
    BinaryTreeNode<ElemType> *rightChild;  //右孩子
    BinaryTreeNode();  //无参构造
    BinaryTreeNode(const ElemType &d,BinaryTreeNode<ElemType> *lChild=NULL,BinaryTreeNode<ElemType> *rChild=NULL);//有参构造
};

template<class ElemType>
BinaryTreeNode<ElemType>::BinaryTreeNode()
//无参构造，构造空节点，左右孩子都为空
{
    leftChild=NULL;  //左孩子为空
    rightChild=NULL;  //右孩子为空
}

template<class ElemType>
BinaryTreeNode<ElemType>::BinaryTreeNode(const ElemType &d,BinaryTreeNode<ElemType> *lChild,BinaryTreeNode<ElemType> *rChild)
//有参构造，数据和左右孩子分别赋值
{
    data=d;
    leftChild=lChild;
    rightChild=rChild;
}
#endif // LINKBINARYTREENODE_H

