#ifndef POSTTHREADBINARYTREENODE_H
#define POSTTHREADBINARYTREENODE_H
template <class ElemType>
struct PostThreadBinaryTreeNode
{
    ElemType data;  //����
    PostThreadBinaryTreeNode<ElemType> *leftChild;//����
    PostThreadBinaryTreeNode<ElemType> *rightChild;//�Һ���
    int leftTag,rightTag;//���ұ�־��
    PostThreadBinaryTreeNode();//�޲ι���
    PostThreadBinaryTreeNode(const ElemType &d,
                             PostThreadBinaryTreeNode<ElemType> *lChild=NULL,PostThreadBinaryTreeNode<ElemType> *rChild=NULL,
                             int lTag=0,int rTag=0);//�вι���
};

template<class ElemType>
PostThreadBinaryTreeNode<ElemType>::PostThreadBinaryTreeNode()
//�޲ι���
{
    leftChild=rightChild=NULL;//ָ����Ϊ��
    leftTag=rightTag=0;//��־��Ϊ0
}

template<class ElemType>
PostThreadBinaryTreeNode<ElemType>::PostThreadBinaryTreeNode(const ElemType &d,
                        PostThreadBinaryTreeNode<ElemType> *lChild,PostThreadBinaryTreeNode<ElemType> *rChild,
                        int lTag,int rTag)//�вι���
{
    data=d;//����Ԫ��
    leftChild=lChild;//����
    rightChild=rChild;//�Һ���
    leftTag=lTag;//���־
    rightTag=rTag;//�ұ�־
}
#endif // POSTTHREADBINARYTREENODE_H
