#ifndef LINKBINARYTREE_H
#define LINKBINARYTREE_H
#include "LinkBinaryTreeNode.h"
#include "Assistance.h"
#include "LinkQueue.h"
#include <iostream>
#include <stack> //!!!!!
#include <queue>//!!!!!
template <class ElemType>
class BinaryTree
{
protected:
    //二叉树的数据成员
    BinaryTreeNode<ElemType> *root;  //是指针!根节点
    //辅助函数
    /***/
    BinaryTreeNode<ElemType> *CreateBinaryTree(const ElemType *t,const ElemType &invalid,int Size,int &index);
    BinaryTreeNode<ElemType> *CopyTree(BinaryTreeNode<ElemType> *t);//!!!!!复制二叉树t
    void Destroy(BinaryTreeNode<ElemType> *&r);//!!!!!删除以r为根的二叉树
    void PreOrder (BinaryTreeNode<ElemType> *r,void(*Visit)(const ElemType&))const;//先序遍历以r为根的二叉树
    void InOrder (BinaryTreeNode<ElemType> *r,void(*Visit)(const ElemType&))const;//中序遍历以r为根的二叉树
    void PostOrder (BinaryTreeNode<ElemType> *r,void(*Visit)(const ElemType&))const;//后序遍历以r为根的二叉树
    int Height(const BinaryTreeNode<ElemType> *r) const;//求以r为根的二叉树高度
    int NodeCount(const BinaryTreeNode<ElemType> *r) const;//求以r为根的二叉树结点个数
    BinaryTreeNode<ElemType>*Parent(BinaryTreeNode<ElemType>*r,const BinaryTreeNode<ElemType>*p) const;//在以r为根的二叉树中求p的双亲
public:
    BinaryTree();//无参构造函数
    /***/
    BinaryTree(const ElemType *t,const ElemType&invalid,int Size);
    BinaryTree(const ElemType &e);//构造根元素值为e的二叉树
    BinaryTree(BinaryTreeNode<ElemType> *r);//建立以r为根的二叉树
    virtual ~BinaryTree();//析构
    BinaryTree(const BinaryTree<ElemType> &t);//复制构造函数
    BinaryTree<ElemType> &operator=(const BinaryTree<ElemType> &t);//赋值运算符重载
    BinaryTreeNode<ElemType> *GetRoot() const;//求二叉树的跟
    bool IsEmpty() const;//判断二叉树是否为空
    Status GetElem(BinaryTreeNode<ElemType> *p,const ElemType &e) const;//取p节点所指结点的元素值
    Status SetElem(BinaryTreeNode<ElemType> *p,const ElemType &e);//将结点p的值置为e
    void PreOrder(void(*Visit)(const ElemType &)) const;  //二叉树的先序遍历
    void InOrder(void(*Visit)(const ElemType &)) const;  //二叉树的中序遍历
    void PostOrder(void(*Visit)(const ElemType &)) const;  //二叉树的后序遍历
    void LevelOrder(void(*Visit)(const ElemType &)) const;  //二叉树的层次遍历
    BinaryTreeNode<ElemType> *Find(const ElemType &e) const;//找到值为e的结点
    int NodeCount() const;  //求二叉树的结点个数
    BinaryTreeNode<ElemType> *LeftChild(const BinaryTreeNode<ElemType> *p) const;//求p结点的左孩子
    BinaryTreeNode<ElemType> *RightChild(const BinaryTreeNode<ElemType> *p) const;//求p结点的右孩子
    BinaryTreeNode<ElemType> *LeftSibling(const BinaryTreeNode<ElemType> *p) const;//求p结点的左兄弟
    BinaryTreeNode<ElemType> *RightSibling(const BinaryTreeNode<ElemType> *p) const;//求p结点的右兄弟
    BinaryTreeNode<ElemType> *Parent(const BinaryTreeNode<ElemType> *p) const;//求p结点的双亲
    void InsertLeftChild(BinaryTreeNode<ElemType> *p,const ElemType &e);//插入一个结点e做为p的左孩子
    void InsertRightChild(BinaryTreeNode<ElemType> *p,const ElemType &e);//插入一个结点e做为p的右孩子
    void DeleteLeftChild(BinaryTreeNode<ElemType> *p);//删除p的左子树
    void DeleteRightChild(BinaryTreeNode<ElemType> *p);//删除p的右子树
    int Height() const;//求二叉树的高
    int CountWidth() const;//计算二叉树最大宽度
    void LeafNode(int &num) const;//计算叶子节点数目
    //void InOrder2(BinaryTree<ElemType> &bt) const;//？？？？？中序遍历
    /***********/

};

template<class ElemType>
void DisplayBTWithTreeShape(BinaryTreeNode<ElemType> *r, int level);//!!!!!树状显示以r为根的二叉树，level层数，设根结点层数为1
template<class ElemType>
void DisplayBTWithTreeShape(BinaryTree<ElemType> &bt, int flag = 0);//!!!!!树状形式显示二叉树

//利用模板函数实现先序中序构造树
template <class ElemType>
void CreateBinaryTree(BinaryTreeNode<ElemType> *&r, ElemType pre[], ElemType in[],int preLeft,int preRight, int inLeft, int inRight)
//模板函数：已知二叉树的先序序列pre[preLeft..preRight]和中序序列in[inLeft..inRight]构造以r为根的二叉树
{
	if (inLeft > inRight)	// 二叉树(一定先左后右，左一定小于右)无结点,空二叉树
		r = NULL;			// 空二叉树根为空
	else	// 二叉树有结点,非空二叉树
    {
		r = new BinaryTreeNode<ElemType> (pre[preLeft]);// 生成根结点
		int mid = inLeft;
		while (in[mid] != pre[preLeft]) 	// 通过遍历，查找pre[preLeft]在in[]中的位置,也就是中序序列中根的位置
			mid++;
		CreateBinaryTree(r->leftChild, pre, in, preLeft+1, preLeft + mid - inLeft, inLeft, mid - 1);// 生成左子树
		CreateBinaryTree(r->rightChild, pre, in, preLeft + mid - inLeft + 1, preRight, mid + 1,inRight);// 生成右子树								// 生成右子树
	}
}

template <class ElemType>
BinaryTree<ElemType> &CreateBinaryTree(ElemType pre[], ElemType in[], int n)
//模板函数：已知先序和中序序列构造二叉树
{
	BinaryTreeNode<ElemType> *r;  // 二叉树的根
	CreateBinaryTree<ElemType>(r, pre, in, 0, n - 1, 0, n - 1);  // 由先序和中序序列构造以r为根的二叉树
	BinaryTree<ElemType> *bt = new BinaryTree<ElemType>(r);  // 生成二叉树
	return *bt;
}

//利用模板函数实现中序后序构造树
template <class ElemType>
void CreateBinaryTree1(BinaryTreeNode<ElemType> *&r, ElemType post[], ElemType in[],int postLeft,int postRight, int inLeft, int inRight)
//模板函数：已知二叉树的先序序列post[postLeft..postRight]和中序序列in[inLeft..inRight]构造以r为根的二叉树
{
	if (inLeft > inRight)	// 二叉树(一定先左后右，左一定小于右)无结点,空二叉树
		r = NULL;			// 空二叉树根为空
	else	// 二叉树有结点,非空二叉树
    {
		r = new BinaryTreeNode<ElemType> (post[postRight]);// 生成根结点
		int mid = inLeft;
		while (in[mid] != post[postRight]) 	// 通过遍历，查找pre[preLeft]在in[]中的位置,也就是中序序列中根的位置
			mid++;
        CreateBinaryTree1(r->leftChild, post, in, postLeft, postLeft+mid-inLeft-1, inLeft, mid - 1);// 生成左子树
        CreateBinaryTree1(r->rightChild, post, in, postLeft+mid-inLeft, postRight-1, mid + 1,inRight);// 生成右子树							// 生成右子树
	}
}

template <class ElemType>
BinaryTree<ElemType> &CreateBinaryTree1(ElemType post[], ElemType in[], int n)
//模板函数：已知后序和中序序列构造二叉树
{
	BinaryTreeNode<ElemType> *r;  // 二叉树的根
	CreateBinaryTree1<ElemType>(r, post, in, 0, n - 1, 0, n - 1);  // 由先序和中序序列构造以r为根的二叉树
	BinaryTree<ElemType> *bt = new BinaryTree<ElemType>(r);  // 生成二叉树
	return *bt;
}

//类中函数实现
template<class ElemType>
BinaryTree<ElemType>::BinaryTree()
//无参构造：构造一个空二叉树
{
    root=NULL;
}

template<class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::CreateBinaryTree(const ElemType *t,const ElemType &invalid,int Size,int &index)
//辅助函数：给定数组情况下的有参构造调用
{
    BinaryTreeNode<ElemType> *node=NULL;
    if(index<Size&&t[index]!=invalid)
    {
        node=new BinaryTreeNode<ElemType> (t[index]);
        node->leftChild=CreateBinaryTree(t,invalid,Size,++index);
        node->rightChild=CreateBinaryTree(t,invalid,Size,++index);
        return node;
    }
    return node;
}

template<class ElemType>
BinaryTree<ElemType>::BinaryTree(const ElemType *t,const ElemType&invalid,int Size)
//有参构造：利用辅助函数，通过一个给定数组（先序）构造二叉树
{
    int index=0;
    root=CreateBinaryTree(t,invalid,Size,index);
}

template<class ElemType>
BinaryTree<ElemType>::BinaryTree(const ElemType &e)
//有参构造：构造根元素值为e的二叉树
{
    root=new BinaryTreeNode<ElemType>(e);
}

template<class ElemType>
BinaryTree<ElemType>::BinaryTree(BinaryTreeNode<ElemType> *r)
//构造？：建立以r为根的二叉树
{
    root=r; //复制二叉树
}

template<class ElemType>
void BinaryTree<ElemType>::Destroy(BinaryTreeNode<ElemType> *&r)
//辅助函数：递归，删除以r为根的二叉树
{
    if(r!=NULL)
    {
        Destroy(r->leftChild);//删除左子树
        Destroy(r->rightChild);//删除右子树
        delete r;//删除根节点
        r=NULL;
    }
}

template<class ElemType>
BinaryTree<ElemType>::~BinaryTree()
//析构：删除二叉树
{
    Destroy(root);
}

template<class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::CopyTree(BinaryTreeNode<ElemType> *t)
//辅助函数：递归将以t为根的二叉树复制成新的二叉树，返回新的二叉树的根
{
    if(t==NULL)  //复制空二叉树
        return NULL;  //空二叉树根节点为空
    else
    {
        BinaryTreeNode<ElemType> *lChild=CopyTree(t->leftChild);//复制左子树
        BinaryTreeNode<ElemType> *rChild=CopyTree(t->rightChild);//复制右子树
        BinaryTreeNode<ElemType> *r=new BinaryTreeNode<ElemType>(t->data,lChild,rChild);//复制根节点
        return r;//返回新二叉树根节点
    }
}

template<class ElemType>
BinaryTree<ElemType>::BinaryTree(const BinaryTree<ElemType> &t)
//复制构造函数:由已知二叉树构造新二叉树
{
    root=CopyTree(t.root);
}

template<class ElemType>
BinaryTree<ElemType> &BinaryTree<ElemType>::operator=(const BinaryTree<ElemType> &t)
//赋值运算符重载：由已知二叉树t复制到当前二叉树
{
    if(this==&t)  //判断是否为自我赋值
        return *this;
    Destroy(root);
    root=CopyTree(t.root);
    return *this;
}

template<class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetRoot() const
//返回二叉树的根
{
    return root;
}

template<class ElemType>
bool BinaryTree<ElemType>::IsEmpty() const
//判断二叉树是否为空
{
    return root==NULL;
}

template<class ElemType>
Status BinaryTree<ElemType>::GetElem(BinaryTreeNode<ElemType> *p,const ElemType &e) const
//用e！引！用！返！回！结点p的元素值,不存在p返回NOT_PRESENT；存在p返回ENTRY_FOUND
{
    if(p==NULL)
        return NOT_PRESENT;
    else
    {
        e=p->data;
        return ENTRY_FOUND;
    }
}

template<class ElemType>
Status BinaryTree<ElemType>::SetElem(BinaryTreeNode<ElemType> *p,const ElemType &e)
//不存在结点p返回FAIL；存在p返回SUCCESS,并将p值设为e
{
    if(p==NULL)
        return FAIL;
    else
    {
        p->data=e;
        return SUCCESS;
    }
}

template<class ElemType>
void BinaryTree<ElemType>::PreOrder(BinaryTreeNode<ElemType> *r,void(*Visit)(const ElemType &)) const
//辅助函数：先序遍历以r为根的二叉树
{
    if(r!=NULL)
    {
        (*Visit)(r->data);  //首先访问根节点
        PreOrder(r->leftChild,Visit);  //再遍历r的左子树
        PreOrder(r->rightChild,Visit);  //最后遍历r的右子树
    }
}

template<class ElemType>
void BinaryTree<ElemType>::PreOrder(void(*Visit)(const ElemType &)) const
//二叉树的先序遍历
{
    PreOrder(root,Visit);
}

template<class ElemType>
void BinaryTree<ElemType>::InOrder(BinaryTreeNode<ElemType> *r,void(*Visit)(const ElemType &)) const
//辅助函数：中序遍历以r为根的二叉树
{
    if(r!=NULL)
    {
        InOrder(r->leftChild,Visit);  //首先遍历r的左子树
        (*Visit)(r->data);  //再访问根节点r
        InOrder(r->rightChild,Visit);  //最后遍历r的右子树
    }
}

template<class ElemType>
void BinaryTree<ElemType>::InOrder(void(*Visit)(const ElemType &)) const
//二叉树的中序遍历
{
    InOrder(root,Visit);
}

template<class ElemType>
void BinaryTree<ElemType>::PostOrder(BinaryTreeNode<ElemType> *r,void(*Visit)(const ElemType &)) const
//辅助函数：后序遍历以r为根的二叉树
{
    if(r!=NULL)
    {
        PostOrder(r->leftChild,Visit);  //首先遍历r的左子树
        PostOrder(r->rightChild,Visit);  //再遍历r的右子树
        (*Visit)(r->data);  //最后访问根节点r
    }
}

template<class ElemType>
void BinaryTree<ElemType>::PostOrder(void(*Visit)(const ElemType &)) const
//二叉树的后序遍历
{
    PostOrder(root,Visit);
}

template<class ElemType>
void BinaryTree<ElemType>::LevelOrder(void(*Visit)(const ElemType &)) const
//层次遍历二叉树
{
    LinkQueue<BinaryTreeNode<ElemType> *> q;//！！！！！定义队列q
    BinaryTreeNode<ElemType> *p;
    if(root!=NULL)   //如果根非空，则入队
        q.EnQueue(root);
    while(!q.IsEmpty())  //q非空，说明还有节点未访问
    {
        q.DelQueue(p);  //队头元素出队，并访问之
        (*Visit)(p->data);  //访问
        if(p->leftChild!=NULL)  //队头元素左孩子非空
            q.EnQueue(p->leftChild);  //左孩子入队
        if(p->rightChild!=NULL)  //队头元素右孩子非空
            q.EnQueue(p->rightChild);  //右孩子入队
    }
}

template<class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::Find(const ElemType &e) const
//找到值为e的结点（利用层次遍历）
{
    LinkQueue<BinaryTreeNode<ElemType> *> q;	// 定义队列q
	BinaryTreeNode<ElemType> *p;
	if (root != NULL) // 如果根非空,则入队
        q.EnQueue(root);
	while (!q.IsEmpty())	// q非空,说明还有结点未访问
	{
		q.DelQueue(p);                      // 队头元素出队，并访问之
		if (p->data == e) //如果q的值为e，返回p
			return p;
		if (p->leftChild != NULL)			// 队头元素左孩子非空
			q.EnQueue(p->leftChild);		// 左孩子入队
		if (p->rightChild != NULL)			// 队头元素右孩子非空
			q.EnQueue(p->rightChild);		// 右孩子入队
	}
	return NULL;
}

template<class ElemType>
int BinaryTree<ElemType>::NodeCount(const BinaryTreeNode<ElemType> *r) const
//辅助函数：求以r为根的二叉树结点个数
{
    if(r==NULL)
        return 0;
    else
        return NodeCount(r->leftChild)+NodeCount(r->rightChild)+1;
}

template<class ElemType>
int BinaryTree<ElemType>::NodeCount() const
//求二叉树的结点个数
{
    return NodeCount(root);
}

template<class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::LeftChild(const BinaryTreeNode<ElemType> *p) const
//求p结点的左孩子
{
    return p->leftChild;
}

template<class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::RightChild(const BinaryTreeNode<ElemType> *p) const
//求p结点的右孩子
{
    return p->rightChild;
}

template<class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::LeftSibling(const BinaryTreeNode<ElemType> *p) const
//求结点p的左兄弟
{
    BinaryTreeNode<ElemType> *r=Parent(root,p);
    if(r==NULL)
        return NULL;
    else if(r->rightChild==p)
        return p->leftChild;
    else
        return NULL;
}

template<class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::RightSibling(const BinaryTreeNode<ElemType> *p) const
//求结点p的右兄弟
{
    BinaryTreeNode<ElemType> *r=Parent(root,p);
    if(r==NULL)
        return NULL;
    else if(r->leftChild==p)
        return p->rightChild;
    else
        return NULL;
}

template<class ElemType>
BinaryTreeNode<ElemType>*BinaryTree<ElemType>::Parent(BinaryTreeNode<ElemType> *r,const BinaryTreeNode<ElemType>*p) const
//递归：在以r为根的二叉树中求结点p的双亲
{
    if(r==NULL)
        return NULL;  //空二叉树
    else if(r->leftChild==p||r->rightChild==p)
        return r;  //r为p的双亲
    else  //在r的子树上求p的双亲
    {
        BinaryTreeNode<ElemType> *tmp;
        tmp=Parent(r->leftChild,p);  //在左子树上求p的双亲
        if(tmp!=NULL)
            return tmp;  //双亲在左子树上
        tmp=Parent(r->rightChild,p);  //在右子树上求p的双亲
        if(tmp!=NULL)
            return tmp;  //双亲在右子树上
        else
            return NULL;  //p无双亲
    }
}

template<class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::Parent(const BinaryTreeNode<ElemType> *p) const
//求p结点的双亲
{
    return Parent(root,p);
}

template<class ElemType>
void BinaryTree<ElemType>::InsertLeftChild(BinaryTreeNode<ElemType> *p,const ElemType &e)
//p非空时，插入元素值为e的结点作为p的左孩子，若p左孩子非空，则原p的左子树成为e的左子树
{
    if(p==NULL)
        return;
    else
    {
        BinaryTreeNode<ElemType> *child=new BinaryTreeNode<ElemType>(e); //e作为child的data值
        if(p->leftChild!=NULL)  //p的左孩子非空
            child->leftChild=p->leftChild;  //p原有左子树成为e的左子树
        p->leftChild=child;  //e成为p的左孩子
        return;
    }
}

template<class ElemType>
void BinaryTree<ElemType>::InsertRightChild(BinaryTreeNode<ElemType> *p,const ElemType &e)
//p非空时，插入元素值为e的结点作为p的右孩子，若p右孩子非空，则原p的右子树成为e的右子树
{
    if(p==NULL)
        return;
    else
    {
        BinaryTreeNode<ElemType> *child=new BinaryTreeNode<ElemType>(e); //e作为child的data值
        if(p->rightChild!=NULL)  //p的右孩子非空
            child->rightChild=p->rightChild;  //p原有右子树成为e的右子树
        p->rightChild=child;  //e成为p的右孩子
        return;
    }
}

template<class ElemType>
void BinaryTree<ElemType>::DeleteLeftChild(BinaryTreeNode<ElemType> *p)
//p非空时，删除p的左子树
{
    if(p==NULL)
        return;
    else
    {
        Destroy(p->leftChild);//不用返回啦！
    }
}

template<class ElemType>
void BinaryTree<ElemType>::DeleteRightChild(BinaryTreeNode<ElemType> *p)
//p非空时，删除p的右子树
{
    if(p==NULL)
        return;
    else
    {
        Destroy(p->rightChild);
    }
}

template<class ElemType>
int BinaryTree<ElemType>::Height(const BinaryTreeNode<ElemType> *r) const
//辅助函数：求以r为根的二叉树高度
{
    if(r==NULL)//空二叉树，高度为0
        return 0;
    else//非空二叉树，高度为左右子树的最大高度加1
    {
        int lHeight,rHeight;
        lHeight=Height(r->leftChild); //左子树的高
        rHeight=Height(r->rightChild); //右子树的高
        return (lHeight>rHeight?lHeight:rHeight)+1;
    }
}

template<class ElemType>
int BinaryTree<ElemType>::Height() const
//求二叉树的高
{
    return Height(root);
}

template <class ElemType>
int BinaryTree<ElemType>::CountWidth() const
//计算二叉树最大宽度（基于层次遍历）
{
    LinkQueue<BinaryTreeNode<ElemType> *> q;  //队列
    BinaryTreeNode<ElemType> *p;  //结点
    int width=0, n=0, Count=0;  //width最大宽度；n记录每层宽度；Count用于计数，计算每层宽度
    if(root !=NULL)  //根节点非空时，根节点入队，最大宽度设为1，此层宽度n也设为1
    {
        q.EnQueue(root);
        width=1;
        n=1;
    }
    while(!q.IsEmpty())
    {
        Count = 0;  //将每一层元素的初始宽度设置为0
        for(int i = 0; i < n; i++)  //遍历上一层的每一个元素
        {
            q.DelQueue(p);
            if(p->leftChild != NULL)
            {
                q.EnQueue(p->leftChild);
                Count++;
            }
            if(p->rightChild != NULL)
            {
                q.EnQueue(p->rightChild);
                Count++;
            }
        }
        n = Count;  //记录此层宽度
        if(Count > width)  //如果此层宽度大于当前最大宽度，则更改最大宽度
            width = Count;
    }
    return width;
}



template<class ElemType>
void BinaryTree<ElemType>::LeafNode(int &num) const
{
    LinkQueue<BinaryTreeNode<ElemType> *> q;//定义队列q
    BinaryTreeNode<ElemType> *p;
    if(root!=NULL)   //如果根非空，则入队
        q.EnQueue(root);
    while(!q.IsEmpty())  //q非空，说明还有节点未访问
    {
        q.DelQueue(p);  //队头元素出队，并访问之
        //(*Visit)(p->data);  //访问
        if(p->leftChild==NULL&&p->rightChild==NULL)
            num++;
        if(p->leftChild!=NULL)  //队头元素左孩子非空
            q.EnQueue(p->leftChild);  //左孩子入队
        if(p->rightChild!=NULL)  //队头元素右孩子非空
            q.EnQueue(p->rightChild);  //右孩子入队
    }

}


int p[100] = {0};
template<class ElemType>
void DisplayBTWithTreeShape(BinaryTreeNode<ElemType> *r, int level)
//树状显示以r为根的二叉树，level层数，设根结点层数为1
{
    if(r != NULL)	// 空树不显式，只显式非空树
    {
		DisplayBTWithTreeShape<ElemType>(r->rightChild, level + 1);//显示右子树
		cout << endl;					//显示新行
		p[level-1]++;
		for(int i = 0; i < level - 1; i++)
			cout << "  ";				//确保在第level列显示结点
		cout << r->data;				//显示结点
		DisplayBTWithTreeShape<ElemType>(r->leftChild, level + 1);//显示左子树
	}
}


template <class ElemType>
void DisplayBTWithTreeShape(BinaryTree<ElemType> &bt, int flag)
//树状形式显示二叉树
{
	if(flag == 0)
    {
        DisplayBTWithTreeShape<ElemType>(bt.GetRoot(), 1);
		// 树状显示以bt.GetRoot()为根的二叉树
    }
    else
    {
        int num=0, width=0;
        while(p[num])
        {
            if(p[num] > width)
                width = p[num];
            num++;
        }
        cout << width;
    }
	cout << endl;
}





#endif // LINKBINARYTREE_H

