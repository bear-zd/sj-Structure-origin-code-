#ifndef POSTTHREADBINARYTREENODE_H
#define POSTTHREADBINARYTREENODE_H
template <class ElemType>
struct PostThreadBinaryTreeNode
{
    ElemType data;  //数据
    PostThreadBinaryTreeNode<ElemType> *leftChild;//左孩子
    PostThreadBinaryTreeNode<ElemType> *rightChild;//右孩子
    int leftTag,rightTag;//左右标志域
    PostThreadBinaryTreeNode();//无参构造
    PostThreadBinaryTreeNode(const ElemType &d,
                             PostThreadBinaryTreeNode<ElemType> *lChild=NULL,PostThreadBinaryTreeNode<ElemType> *rChild=NULL,
                             int lTag=0,int rTag=0);//有参构造
};

template<class ElemType>
PostThreadBinaryTreeNode<ElemType>::PostThreadBinaryTreeNode()
//无参构造
{
    leftChild=rightChild=NULL;//指针域为空
    leftTag=rightTag=0;//标志域为0
}

template<class ElemType>
PostThreadBinaryTreeNode<ElemType>::PostThreadBinaryTreeNode(const ElemType &d,
                        PostThreadBinaryTreeNode<ElemType> *lChild,PostThreadBinaryTreeNode<ElemType> *rChild,
                        int lTag,int rTag)//有参构造
{
    data=d;//数据元素
    leftChild=lChild;//左孩子
    rightChild=rChild;//右孩子
    leftTag=lTag;//左标志
    rightTag=rTag;//右标志
}
#endif // POSTTHREADBINARYTREENODE_H
