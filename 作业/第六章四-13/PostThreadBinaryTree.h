#ifndef POSTTHREADBINARYTREE_H
#define POSTTHREADBINARYTREE_H
#include "LinkBinaryTree.h"
#include "PostThreadBinaryTreeNode.h"
// ����������������
template <class ElemType>
class PostThreadBinaryTree
{
protected:
    //���ݳ�Ա
    PostThreadBinaryTreeNode<ElemType> *root;
    //��������
    void PostThreadHelp(PostThreadBinaryTreeNode<ElemType> *p, PostThreadBinaryTreeNode<ElemType> *&pre);
    //������������pΪ���Ķ�����,preΪp�е�һ������ǰ�����ָ�롣
	PostThreadBinaryTreeNode<ElemType> *TransfromHelp(BinaryTreeNode<ElemType> *r);
    //����rΪ���Ķ�����ת�����µ�δ�������ĺ�������������,�����¶������ĸ�
	PostThreadBinaryTreeNode<ElemType> *CopyTreeHelp(PostThreadBinaryTreeNode<ElemType> *t);
    // ��������������
	void DestroyHelp(PostThreadBinaryTreeNode<ElemType> * &r);
	//������rΪ��������
	PostThreadBinaryTreeNode<ElemType> *Parent(PostThreadBinaryTreeNode<ElemType> *r, const PostThreadBinaryTreeNode<ElemType> *p) const;
    // ����������������rΪ���Ķ�����, ���p��˫��

public:
    //������Ա
    PostThreadBinaryTree(const BinaryTree<ElemType> &bt);//ת�����죺�ɶ����������������������
    virtual ~ PostThreadBinaryTree();//����
    PostThreadBinaryTreeNode<ElemType> *GetRoot() const;//���������������ĸ�
    void PostThread();//����������������
    PostThreadBinaryTreeNode<ElemType> *GetFirst() const;//ȡ�������������е�һ�����ָ��
    PostThreadBinaryTreeNode<ElemType> *GetLast() const;//ȡ�����������������һ�����ָ��
    PostThreadBinaryTreeNode<ElemType> *GetLast(PostThreadBinaryTreeNode<ElemType> *p) const;//ȡ������ָ�����p�������е���һ�����
    PostThreadBinaryTreeNode<ElemType> *Next(PostThreadBinaryTreeNode<ElemType> *p) const;//ȡ������ָ�����p�������е���һ�����
    PostThreadBinaryTreeNode<ElemType> *Find(const ElemType &e) const;//����e
    void InsertLeftChild(PostThreadBinaryTreeNode<ElemType> *p,const &e);//��������
    void InsertRightChild(PostThreadBinaryTreeNode<ElemType> *p,const &e);//�����Һ���
    void DeleteLeftChild(PostThreadBinaryTreeNode<ElemType> *p);//ɾ��p������
    void DeleteRightChild(PostThreadBinaryTreeNode<ElemType> *p);//ɾ��p������
    void PostOrder(void (*Visit)(const ElemType&)) const;//�������
    PostThreadBinaryTree(const PostThreadBinaryTree<ElemType> &t);//���ƹ���
    PostThreadBinaryTree<ElemType> &operator=(const PostThreadBinaryTree<ElemType>&t);//����=
    PostThreadBinaryTreeNode<ElemType> *Parent(const PostThreadBinaryTreeNode<ElemType> *p) const;//���ض��������p��˫��
};
//----------------------------------------------------------------------------------------------------------------------------------------------------------------



template<class ElemType>
PostThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::Next(PostThreadBinaryTreeNode<ElemType> *p) const
//ȡ������ָ�����p����j���
{
    PostThreadBinaryTreeNode<ElemType> *q=Parent(root,p);
    if(p == root)
        return NULL;//���ڵ�û�к��
   else if (p->rightTag == 1)
        return  p->rightChild; //�Һ���
	else if (q->rightChild==p||q->rightTag==1)
        {
        return q;
        }
    else
        {
        q = q->rightChild;
        while(q->leftTag == 0||q->rightTag == 0)
        {
            if(q->leftTag == 0)
                q = q->leftChild;
            else
                q = q->rightChild;
        }
	return q;
        }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------


template<class ElemType>
void PostThreadBinaryTree<ElemType>::PostThreadHelp(PostThreadBinaryTreeNode<ElemType> *p, PostThreadBinaryTreeNode<ElemType> *&pre)
//����������������������pΪ���Ķ�����(����),preΪp�е�һ������ǰ�����ָ��
{
    if(p!=NULL)
    {
        PostThreadHelp(p->leftChild,pre);//������p��������
        PostThreadHelp(p->rightChild,pre);//������p��������
        if(p->leftChild==NULL)//p�����ӣ���ǰ������
        {
            p->leftChild=pre;//p��ǰ�����Ϊpre
            p->leftTag=1;//���־Ϊ����
        }
       // else
         //   p->leftTag=0;
        if(pre!=NULL&&pre->rightChild==NULL)//pre���Һ��ӣ�������
        {
            pre->rightChild=p;//pre�ĺ��Ϊp
            pre->rightTag=1;//�ұ�־Ϊ����
        }
       // else
         //   pre->rightTag=0;
        pre=p;//������һ��㣬pΪ��һ����ǰ��
    }
}

template<class ElemType>
void PostThreadBinaryTree<ElemType>::PostThread()
//����������������
{
    PostThreadBinaryTreeNode<ElemType> *pre=NULL;//��һ������ǰ��Ϊ��
    PostThreadHelp(root,pre);//������������rootΪ���Ķ�����
    PostThreadBinaryTreeNode<ElemType> *p;
    if(root->rightChild==NULL)//������������ʵ��Ǹ���㣬û�취�ɶԷŽ�help�����У�Ҫ��������
        root->rightTag=1;//Ĭ��tagΪ0
}

template<class ElemType>
PostThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::TransfromHelp(BinaryTreeNode<ElemType> *r)
//��������������rΪ���Ķ�����ת�����µ�  δ�������ĺ�������������, �����¶������ĸ�
{
    if(r==NULL)
        return NULL;
    else
    {
        PostThreadBinaryTreeNode<ElemType> *lChild=TransfromHelp(r->leftChild);
        PostThreadBinaryTreeNode<ElemType> *rChild=TransfromHelp(r->rightChild);
        PostThreadBinaryTreeNode<ElemType> *rt=new PostThreadBinaryTreeNode<ElemType>(r->data,lChild,rChild);
        return rt;
    }
}

template<class ElemType>
PostThreadBinaryTree<ElemType>::PostThreadBinaryTree(const BinaryTree<ElemType> &bt)
//ת�����죺�ɶ��������� ��������������
//�������һ����ͨ������
{
    root=TransfromHelp(bt.GetRoot());//ת����Ϊ�������Ķ�����
    PostThread();//����������
}

template<class ElemType>
void PostThreadBinaryTree<ElemType>:: DestroyHelp(PostThreadBinaryTreeNode<ElemType> * &r)
//����������������rΪ��������
{
    if(r!=NULL)
    {
        if(r->leftTag==0)
            DestroyHelp(r->leftChild);
        if(r->rightTag==0)
            DestroyHelp(r->rightChild);
        delete r;
        r=NULL;//ɾ����Ҫ�ÿ�
    }
}

template<class ElemType>
PostThreadBinaryTree<ElemType>:: ~ PostThreadBinaryTree()
//����
{
    DestroyHelp(root);
}

template<class ElemType>
PostThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::GetRoot() const
//���������������ĸ�
{
    return root;
}

template<class ElemType>
PostThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::GetFirst() const
//ȡ�������������е�һ�����ָ��
{
    if(root==NULL)//���������ؿ�
        return NULL;
    else
    {
        PostThreadBinaryTreeNode<ElemType> *p=root;
        while(p->leftTag==0||p->rightTag==0)//����Ҷ�ӽ��
        {
            if(p->leftTag==0)//����������������
                p=p->leftChild;
            else             //������������������
                p=p->rightChild;
        }
        return p;
    }
}

template<class ElemType>
PostThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::GetLast() const
//ȡ�����������������һ�����ָ��
{
    if (root==NULL)
        return NULL;
    else
        return root;
}

template<class ElemType>
PostThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::Find(const ElemType &e) const
//����e
{
    PostThreadBinaryTreeNode<ElemType> *p=GetFirst();
    while(p!=NULL&&p->data!=e)
        p=Next(p);
    return p;
}

template<class ElemType>
void PostThreadBinaryTree<ElemType>::InsertRightChild(PostThreadBinaryTreeNode<ElemType> *p,const &e)
//p�ǿգ������Һ��� ��p�Һ��ӷǿգ���pԭ����������Ϊe��������
{
    PostThreadBinaryTreeNode<ElemType> *x,*q;
    if(p==NULL)
        return;
    else
    {
        if(p->rightTag==0)//p���Һ���
        {
            x= new PostThreadBinaryTreeNode<ElemType>(e,p->rightChild , p->rightChild, 1,0);//p���Һ���������
                                                                                //p���Һ���������
            if(p->rightChild->rightTag==1)//p���Һ��� û�к��ӻ�������û���Һ��ӣ�p���Һ��� û���Һ��ӣ�
            {                              //p���Һ��� û������
                p->rightChild->rightChild=x;
            }
        }
        else//p���Һ��ӣ�
        {
            x= new PostThreadBinaryTreeNode<ElemType>(e,p->leftChild , p, p->leftTag, 1);  //p���Һ���������
                                                                                           //p���Һ���������
            if(p->leftTag==0 && p->leftChild->rightTag==1)//p��������p�������Һ���
            {
                p->leftChild->rightChild=x;
            }
            q=p->leftChild;//p�����ӣ�qΪp��ǰ�����
            if(p->leftTag==1&&q->rightTag==1)
            {
                q->rightChild=x;
                p->leftChild=x;
            }
        }
        p->rightChild = x;
        p->rightTag = 0;
    }
}


template<class ElemType>
PostThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::CopyTreeHelp(PostThreadBinaryTreeNode<ElemType> *t)
//������������������������,�����µĶ������ĸ�
{
    if(t==NULL)
        return NULL;
    else
    {
        PostThreadBinaryTreeNode<ElemType> *lChild;
        PostThreadBinaryTreeNode<ElemType> *rChild;
        if (t->leftTag==0)
            lChild=CopyTreeHelp(t->leftChild);
        else
            lChild=NULL;
        if(t->rightTag==0)
            rChild=CopyTreeHelp(t->rightChild);
        else
            rChild=NULL;
        PostThreadBinaryTreeNode<ElemType> *r=new PostThreadBinaryTreeNode<ElemType> (t->data,rChild,lChild);
        return r;
    }
}

template<class ElemType>
PostThreadBinaryTree<ElemType> &PostThreadBinaryTree<ElemType>::operator=(const PostThreadBinaryTree<ElemType>&t)
//����=
{
    if (&t != this)
    {
		DestroyHelp(root);							// �ͷ�ԭ������������ռ�ÿռ�
		root = CopyTreeHelp(t.root);				// ��������������
		PostThread();								// ����������������
	}
	return *this;
}

template <class ElemType>
PostThreadBinaryTreeNode<ElemType> * PostThreadBinaryTree<ElemType>::Parent(PostThreadBinaryTreeNode<ElemType> *r, const PostThreadBinaryTreeNode<ElemType> *p) const
// ����������������rΪ���Ķ�����, ���p��˫��
{
	if (r == NULL)
       return NULL;		// �ն�����
	else if (r->leftChild == p || r->rightChild == p)
       return r; // rΪp��˫��
	else	{	// ����������˫��
		PostThreadBinaryTreeNode<ElemType> *tmp;
		tmp = Parent(r->leftChild, p);	// ������������p��˫��
		if (tmp != NULL)
           return tmp;			        // ˫������������
		tmp = Parent(r->rightChild, p);	// ������������p��˫��
		if (tmp != NULL)
           return tmp;			        // ˫������������
		else
           return NULL;				    // ��ʾp��˫��
	}
}

template <class ElemType>
PostThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::Parent(const PostThreadBinaryTreeNode<ElemType> *p) const
// ������������ض��������p��˫��
{
	return Parent(root, p);
}

#endif // POSTTHREADBINARYTREE_H
