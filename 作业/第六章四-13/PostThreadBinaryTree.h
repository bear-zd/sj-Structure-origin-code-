#ifndef POSTTHREADBINARYTREE_H
#define POSTTHREADBINARYTREE_H
#include "LinkBinaryTree.h"
#include "PostThreadBinaryTreeNode.h"
// 后序线索二叉树类
template <class ElemType>
class PostThreadBinaryTree
{
protected:
    //数据成员
    PostThreadBinaryTreeNode<ElemType> *root;
    //辅助函数
    void PostThreadHelp(PostThreadBinaryTreeNode<ElemType> *p, PostThreadBinaryTreeNode<ElemType> *&pre);
    //后序线索化以p为根的二叉树,pre为p中第一个结点的前驱结点指针。
	PostThreadBinaryTreeNode<ElemType> *TransfromHelp(BinaryTreeNode<ElemType> *r);
    //将以r为根的二叉树转换成新的未线索化的后序线索二叉树,返回新二叉树的根
	PostThreadBinaryTreeNode<ElemType> *CopyTreeHelp(PostThreadBinaryTreeNode<ElemType> *t);
    // 复制线索二叉树
	void DestroyHelp(PostThreadBinaryTreeNode<ElemType> * &r);
	//销毁以r为根二叉树
	PostThreadBinaryTreeNode<ElemType> *Parent(PostThreadBinaryTreeNode<ElemType> *r, const PostThreadBinaryTreeNode<ElemType> *p) const;
    // 辅助函数：返回以r为根的二叉树, 结点p的双亲

public:
    //方法成员
    PostThreadBinaryTree(const BinaryTree<ElemType> &bt);//转换构造：由二叉树构造后序线索二叉树
    virtual ~ PostThreadBinaryTree();//析构
    PostThreadBinaryTreeNode<ElemType> *GetRoot() const;//返回线索二叉树的根
    void PostThread();//后序线索化二叉树
    PostThreadBinaryTreeNode<ElemType> *GetFirst() const;//取二叉树后序序列第一个结点指针
    PostThreadBinaryTreeNode<ElemType> *GetLast() const;//取二叉树后序序列最后一个结点指针
    PostThreadBinaryTreeNode<ElemType> *GetLast(PostThreadBinaryTreeNode<ElemType> *p) const;//取二叉树指定结点p后序序列的上一个结点
    PostThreadBinaryTreeNode<ElemType> *Next(PostThreadBinaryTreeNode<ElemType> *p) const;//取二叉树指定结点p后序序列的下一个结点
    PostThreadBinaryTreeNode<ElemType> *Find(const ElemType &e) const;//查找e
    void InsertLeftChild(PostThreadBinaryTreeNode<ElemType> *p,const &e);//插入左孩子
    void InsertRightChild(PostThreadBinaryTreeNode<ElemType> *p,const &e);//插入右孩子
    void DeleteLeftChild(PostThreadBinaryTreeNode<ElemType> *p);//删除p左子树
    void DeleteRightChild(PostThreadBinaryTreeNode<ElemType> *p);//删除p右子树
    void PostOrder(void (*Visit)(const ElemType&)) const;//后序遍历
    PostThreadBinaryTree(const PostThreadBinaryTree<ElemType> &t);//复制构造
    PostThreadBinaryTree<ElemType> &operator=(const PostThreadBinaryTree<ElemType>&t);//重载=
    PostThreadBinaryTreeNode<ElemType> *Parent(const PostThreadBinaryTreeNode<ElemType> *p) const;//返回二叉树结点p的双亲
};
//----------------------------------------------------------------------------------------------------------------------------------------------------------------



template<class ElemType>
PostThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::Next(PostThreadBinaryTreeNode<ElemType> *p) const
//取二叉树指定结点p后序j结点
{
    PostThreadBinaryTreeNode<ElemType> *q=Parent(root,p);
    if(p == root)
        return NULL;//根节点没有后继
   else if (p->rightTag == 1)
        return  p->rightChild; //右孩子
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
//辅助函数：后序线索化以p为根的二叉树(子树),pre为p中第一个结点的前驱结点指针
{
    if(p!=NULL)
    {
        PostThreadHelp(p->leftChild,pre);//线索化p的左子树
        PostThreadHelp(p->rightChild,pre);//线索化p的右子树
        if(p->leftChild==NULL)//p无左孩子，加前驱线索
        {
            p->leftChild=pre;//p的前驱结点为pre
            p->leftTag=1;//左标志为线索
        }
       // else
         //   p->leftTag=0;
        if(pre!=NULL&&pre->rightChild==NULL)//pre无右孩子，加线索
        {
            pre->rightChild=p;//pre的后继为p
            pre->rightTag=1;//右标志为线索
        }
       // else
         //   pre->rightTag=0;
        pre=p;//遍历下一结点，p为下一结点的前驱
    }
}

template<class ElemType>
void PostThreadBinaryTree<ElemType>::PostThread()
//后序线索化二叉树
{
    PostThreadBinaryTreeNode<ElemType> *pre=NULL;//第一个结点的前驱为空
    PostThreadHelp(root,pre);//后序线索化以root为根的二叉树
    PostThreadBinaryTreeNode<ElemType> *p;
    if(root->rightChild==NULL)//后序遍历最后访问的是根结点，没办法成对放进help函数中，要单独讨论
        root->rightTag=1;//默认tag为0
}

template<class ElemType>
PostThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::TransfromHelp(BinaryTreeNode<ElemType> *r)
//辅助函数：将以r为根的二叉树转换成新的  未线索化的后序线索二叉树, 返回新二叉树的根
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
//转换构造：由二叉树构造 后序线索二叉树
//传入的是一个普通二叉树
{
    root=TransfromHelp(bt.GetRoot());//转换成为线索化的二叉树
    PostThread();//后序线索化
}

template<class ElemType>
void PostThreadBinaryTree<ElemType>:: DestroyHelp(PostThreadBinaryTreeNode<ElemType> * &r)
//辅助函数：销毁以r为根二叉树
{
    if(r!=NULL)
    {
        if(r->leftTag==0)
            DestroyHelp(r->leftChild);
        if(r->rightTag==0)
            DestroyHelp(r->rightChild);
        delete r;
        r=NULL;//删除后要置空
    }
}

template<class ElemType>
PostThreadBinaryTree<ElemType>:: ~ PostThreadBinaryTree()
//析构
{
    DestroyHelp(root);
}

template<class ElemType>
PostThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::GetRoot() const
//返回线索二叉树的根
{
    return root;
}

template<class ElemType>
PostThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::GetFirst() const
//取二叉树后序序列第一个结点指针
{
    if(root==NULL)//空树，返回空
        return NULL;
    else
    {
        PostThreadBinaryTreeNode<ElemType> *p=root;
        while(p->leftTag==0||p->rightTag==0)//不是叶子结点
        {
            if(p->leftTag==0)//能往左走先往左走
                p=p->leftChild;
            else             //不能往左走再往右走
                p=p->rightChild;
        }
        return p;
    }
}

template<class ElemType>
PostThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::GetLast() const
//取二叉树后序序列最后一个结点指针
{
    if (root==NULL)
        return NULL;
    else
        return root;
}

template<class ElemType>
PostThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::Find(const ElemType &e) const
//查找e
{
    PostThreadBinaryTreeNode<ElemType> *p=GetFirst();
    while(p!=NULL&&p->data!=e)
        p=Next(p);
    return p;
}

template<class ElemType>
void PostThreadBinaryTree<ElemType>::InsertRightChild(PostThreadBinaryTreeNode<ElemType> *p,const &e)
//p非空，插入右孩子 若p右孩子非空，则p原有右子树成为e的右子树
{
    PostThreadBinaryTreeNode<ElemType> *x,*q;
    if(p==NULL)
        return;
    else
    {
        if(p->rightTag==0)//p有右孩子
        {
            x= new PostThreadBinaryTreeNode<ElemType>(e,p->rightChild , p->rightChild, 1,0);//p有右孩子有左孩子
                                                                                //p有右孩子无左孩子
            if(p->rightChild->rightTag==1)//p的右孩子 没有孩子或有左孩子没有右孩子（p的右孩子 没有右孩子）
            {                              //p的右孩子 没有左孩子
                p->rightChild->rightChild=x;
            }
        }
        else//p无右孩子，
        {
            x= new PostThreadBinaryTreeNode<ElemType>(e,p->leftChild , p, p->leftTag, 1);  //p无右孩子有左孩子
                                                                                           //p无右孩子无左孩子
            if(p->leftTag==0 && p->leftChild->rightTag==1)//p有左孩子且p左孩子无右孩子
            {
                p->leftChild->rightChild=x;
            }
            q=p->leftChild;//p无左孩子，q为p的前驱结点
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
//辅助函数：复制线索二叉树,返回新的二叉树的根
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
//重载=
{
    if (&t != this)
    {
		DestroyHelp(root);							// 释放原线索二叉树所占用空间
		root = CopyTreeHelp(t.root);				// 复制线索二叉树
		PostThread();								// 后序线索化二叉树
	}
	return *this;
}

template <class ElemType>
PostThreadBinaryTreeNode<ElemType> * PostThreadBinaryTree<ElemType>::Parent(PostThreadBinaryTreeNode<ElemType> *r, const PostThreadBinaryTreeNode<ElemType> *p) const
// 辅助函数：返回以r为根的二叉树, 结点p的双亲
{
	if (r == NULL)
       return NULL;		// 空二叉树
	else if (r->leftChild == p || r->rightChild == p)
       return r; // r为p的双亲
	else	{	// 在子树上求双亲
		PostThreadBinaryTreeNode<ElemType> *tmp;
		tmp = Parent(r->leftChild, p);	// 在左子树上求p的双亲
		if (tmp != NULL)
           return tmp;			        // 双亲在左子树上
		tmp = Parent(r->rightChild, p);	// 在右子树上求p的双亲
		if (tmp != NULL)
           return tmp;			        // 双亲在右子树上
		else
           return NULL;				    // 表示p无双亲
	}
}

template <class ElemType>
PostThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::Parent(const PostThreadBinaryTreeNode<ElemType> *p) const
// 操作结果：返回二叉树结点p的双亲
{
	return Parent(root, p);
}

#endif // POSTTHREADBINARYTREE_H
