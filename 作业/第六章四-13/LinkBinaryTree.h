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
    //�����������ݳ�Ա
    BinaryTreeNode<ElemType> *root;  //��ָ��!���ڵ�
    //��������
    /***/
    BinaryTreeNode<ElemType> *CreateBinaryTree(const ElemType *t,const ElemType &invalid,int Size,int &index);
    BinaryTreeNode<ElemType> *CopyTree(BinaryTreeNode<ElemType> *t);//!!!!!���ƶ�����t
    void Destroy(BinaryTreeNode<ElemType> *&r);//!!!!!ɾ����rΪ���Ķ�����
    void PreOrder (BinaryTreeNode<ElemType> *r,void(*Visit)(const ElemType&))const;//���������rΪ���Ķ�����
    void InOrder (BinaryTreeNode<ElemType> *r,void(*Visit)(const ElemType&))const;//���������rΪ���Ķ�����
    void PostOrder (BinaryTreeNode<ElemType> *r,void(*Visit)(const ElemType&))const;//���������rΪ���Ķ�����
    int Height(const BinaryTreeNode<ElemType> *r) const;//����rΪ���Ķ������߶�
    int NodeCount(const BinaryTreeNode<ElemType> *r) const;//����rΪ���Ķ�����������
    BinaryTreeNode<ElemType>*Parent(BinaryTreeNode<ElemType>*r,const BinaryTreeNode<ElemType>*p) const;//����rΪ���Ķ���������p��˫��
public:
    BinaryTree();//�޲ι��캯��
    /***/
    BinaryTree(const ElemType *t,const ElemType&invalid,int Size);
    BinaryTree(const ElemType &e);//�����Ԫ��ֵΪe�Ķ�����
    BinaryTree(BinaryTreeNode<ElemType> *r);//������rΪ���Ķ�����
    virtual ~BinaryTree();//����
    BinaryTree(const BinaryTree<ElemType> &t);//���ƹ��캯��
    BinaryTree<ElemType> &operator=(const BinaryTree<ElemType> &t);//��ֵ���������
    BinaryTreeNode<ElemType> *GetRoot() const;//��������ĸ�
    bool IsEmpty() const;//�ж϶������Ƿ�Ϊ��
    Status GetElem(BinaryTreeNode<ElemType> *p,const ElemType &e) const;//ȡp�ڵ���ָ����Ԫ��ֵ
    Status SetElem(BinaryTreeNode<ElemType> *p,const ElemType &e);//�����p��ֵ��Ϊe
    void PreOrder(void(*Visit)(const ElemType &)) const;  //���������������
    void InOrder(void(*Visit)(const ElemType &)) const;  //���������������
    void PostOrder(void(*Visit)(const ElemType &)) const;  //�������ĺ������
    void LevelOrder(void(*Visit)(const ElemType &)) const;  //�������Ĳ�α���
    BinaryTreeNode<ElemType> *Find(const ElemType &e) const;//�ҵ�ֵΪe�Ľ��
    int NodeCount() const;  //��������Ľ�����
    BinaryTreeNode<ElemType> *LeftChild(const BinaryTreeNode<ElemType> *p) const;//��p��������
    BinaryTreeNode<ElemType> *RightChild(const BinaryTreeNode<ElemType> *p) const;//��p�����Һ���
    BinaryTreeNode<ElemType> *LeftSibling(const BinaryTreeNode<ElemType> *p) const;//��p�������ֵ�
    BinaryTreeNode<ElemType> *RightSibling(const BinaryTreeNode<ElemType> *p) const;//��p�������ֵ�
    BinaryTreeNode<ElemType> *Parent(const BinaryTreeNode<ElemType> *p) const;//��p����˫��
    void InsertLeftChild(BinaryTreeNode<ElemType> *p,const ElemType &e);//����һ�����e��Ϊp������
    void InsertRightChild(BinaryTreeNode<ElemType> *p,const ElemType &e);//����һ�����e��Ϊp���Һ���
    void DeleteLeftChild(BinaryTreeNode<ElemType> *p);//ɾ��p��������
    void DeleteRightChild(BinaryTreeNode<ElemType> *p);//ɾ��p��������
    int Height() const;//��������ĸ�
    int CountWidth() const;//��������������
    void LeafNode(int &num) const;//����Ҷ�ӽڵ���Ŀ
    //void InOrder2(BinaryTree<ElemType> &bt) const;//�����������������
    /***********/

};

template<class ElemType>
void DisplayBTWithTreeShape(BinaryTreeNode<ElemType> *r, int level);//!!!!!��״��ʾ��rΪ���Ķ�������level���������������Ϊ1
template<class ElemType>
void DisplayBTWithTreeShape(BinaryTree<ElemType> &bt, int flag = 0);//!!!!!��״��ʽ��ʾ������

//����ģ�庯��ʵ��������������
template <class ElemType>
void CreateBinaryTree(BinaryTreeNode<ElemType> *&r, ElemType pre[], ElemType in[],int preLeft,int preRight, int inLeft, int inRight)
//ģ�庯������֪����������������pre[preLeft..preRight]����������in[inLeft..inRight]������rΪ���Ķ�����
{
	if (inLeft > inRight)	// ������(һ��������ң���һ��С����)�޽��,�ն�����
		r = NULL;			// �ն�������Ϊ��
	else	// �������н��,�ǿն�����
    {
		r = new BinaryTreeNode<ElemType> (pre[preLeft]);// ���ɸ����
		int mid = inLeft;
		while (in[mid] != pre[preLeft]) 	// ͨ������������pre[preLeft]��in[]�е�λ��,Ҳ�������������и���λ��
			mid++;
		CreateBinaryTree(r->leftChild, pre, in, preLeft+1, preLeft + mid - inLeft, inLeft, mid - 1);// ����������
		CreateBinaryTree(r->rightChild, pre, in, preLeft + mid - inLeft + 1, preRight, mid + 1,inRight);// ����������								// ����������
	}
}

template <class ElemType>
BinaryTree<ElemType> &CreateBinaryTree(ElemType pre[], ElemType in[], int n)
//ģ�庯������֪������������й��������
{
	BinaryTreeNode<ElemType> *r;  // �������ĸ�
	CreateBinaryTree<ElemType>(r, pre, in, 0, n - 1, 0, n - 1);  // ��������������й�����rΪ���Ķ�����
	BinaryTree<ElemType> *bt = new BinaryTree<ElemType>(r);  // ���ɶ�����
	return *bt;
}

//����ģ�庯��ʵ�������������
template <class ElemType>
void CreateBinaryTree1(BinaryTreeNode<ElemType> *&r, ElemType post[], ElemType in[],int postLeft,int postRight, int inLeft, int inRight)
//ģ�庯������֪����������������post[postLeft..postRight]����������in[inLeft..inRight]������rΪ���Ķ�����
{
	if (inLeft > inRight)	// ������(һ��������ң���һ��С����)�޽��,�ն�����
		r = NULL;			// �ն�������Ϊ��
	else	// �������н��,�ǿն�����
    {
		r = new BinaryTreeNode<ElemType> (post[postRight]);// ���ɸ����
		int mid = inLeft;
		while (in[mid] != post[postRight]) 	// ͨ������������pre[preLeft]��in[]�е�λ��,Ҳ�������������и���λ��
			mid++;
        CreateBinaryTree1(r->leftChild, post, in, postLeft, postLeft+mid-inLeft-1, inLeft, mid - 1);// ����������
        CreateBinaryTree1(r->rightChild, post, in, postLeft+mid-inLeft, postRight-1, mid + 1,inRight);// ����������							// ����������
	}
}

template <class ElemType>
BinaryTree<ElemType> &CreateBinaryTree1(ElemType post[], ElemType in[], int n)
//ģ�庯������֪������������й��������
{
	BinaryTreeNode<ElemType> *r;  // �������ĸ�
	CreateBinaryTree1<ElemType>(r, post, in, 0, n - 1, 0, n - 1);  // ��������������й�����rΪ���Ķ�����
	BinaryTree<ElemType> *bt = new BinaryTree<ElemType>(r);  // ���ɶ�����
	return *bt;
}

//���к���ʵ��
template<class ElemType>
BinaryTree<ElemType>::BinaryTree()
//�޲ι��죺����һ���ն�����
{
    root=NULL;
}

template<class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::CreateBinaryTree(const ElemType *t,const ElemType &invalid,int Size,int &index)
//����������������������µ��вι������
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
//�вι��죺���ø���������ͨ��һ���������飨���򣩹��������
{
    int index=0;
    root=CreateBinaryTree(t,invalid,Size,index);
}

template<class ElemType>
BinaryTree<ElemType>::BinaryTree(const ElemType &e)
//�вι��죺�����Ԫ��ֵΪe�Ķ�����
{
    root=new BinaryTreeNode<ElemType>(e);
}

template<class ElemType>
BinaryTree<ElemType>::BinaryTree(BinaryTreeNode<ElemType> *r)
//���죿��������rΪ���Ķ�����
{
    root=r; //���ƶ�����
}

template<class ElemType>
void BinaryTree<ElemType>::Destroy(BinaryTreeNode<ElemType> *&r)
//�����������ݹ飬ɾ����rΪ���Ķ�����
{
    if(r!=NULL)
    {
        Destroy(r->leftChild);//ɾ��������
        Destroy(r->rightChild);//ɾ��������
        delete r;//ɾ�����ڵ�
        r=NULL;
    }
}

template<class ElemType>
BinaryTree<ElemType>::~BinaryTree()
//������ɾ��������
{
    Destroy(root);
}

template<class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::CopyTree(BinaryTreeNode<ElemType> *t)
//�����������ݹ齫��tΪ���Ķ��������Ƴ��µĶ������������µĶ������ĸ�
{
    if(t==NULL)  //���ƿն�����
        return NULL;  //�ն��������ڵ�Ϊ��
    else
    {
        BinaryTreeNode<ElemType> *lChild=CopyTree(t->leftChild);//����������
        BinaryTreeNode<ElemType> *rChild=CopyTree(t->rightChild);//����������
        BinaryTreeNode<ElemType> *r=new BinaryTreeNode<ElemType>(t->data,lChild,rChild);//���Ƹ��ڵ�
        return r;//�����¶��������ڵ�
    }
}

template<class ElemType>
BinaryTree<ElemType>::BinaryTree(const BinaryTree<ElemType> &t)
//���ƹ��캯��:����֪�����������¶�����
{
    root=CopyTree(t.root);
}

template<class ElemType>
BinaryTree<ElemType> &BinaryTree<ElemType>::operator=(const BinaryTree<ElemType> &t)
//��ֵ��������أ�����֪������t���Ƶ���ǰ������
{
    if(this==&t)  //�ж��Ƿ�Ϊ���Ҹ�ֵ
        return *this;
    Destroy(root);
    root=CopyTree(t.root);
    return *this;
}

template<class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetRoot() const
//���ض������ĸ�
{
    return root;
}

template<class ElemType>
bool BinaryTree<ElemType>::IsEmpty() const
//�ж϶������Ƿ�Ϊ��
{
    return root==NULL;
}

template<class ElemType>
Status BinaryTree<ElemType>::GetElem(BinaryTreeNode<ElemType> *p,const ElemType &e) const
//��e�������ã������أ����p��Ԫ��ֵ,������p����NOT_PRESENT������p����ENTRY_FOUND
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
//�����ڽ��p����FAIL������p����SUCCESS,����pֵ��Ϊe
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
//�������������������rΪ���Ķ�����
{
    if(r!=NULL)
    {
        (*Visit)(r->data);  //���ȷ��ʸ��ڵ�
        PreOrder(r->leftChild,Visit);  //�ٱ���r��������
        PreOrder(r->rightChild,Visit);  //������r��������
    }
}

template<class ElemType>
void BinaryTree<ElemType>::PreOrder(void(*Visit)(const ElemType &)) const
//���������������
{
    PreOrder(root,Visit);
}

template<class ElemType>
void BinaryTree<ElemType>::InOrder(BinaryTreeNode<ElemType> *r,void(*Visit)(const ElemType &)) const
//�������������������rΪ���Ķ�����
{
    if(r!=NULL)
    {
        InOrder(r->leftChild,Visit);  //���ȱ���r��������
        (*Visit)(r->data);  //�ٷ��ʸ��ڵ�r
        InOrder(r->rightChild,Visit);  //������r��������
    }
}

template<class ElemType>
void BinaryTree<ElemType>::InOrder(void(*Visit)(const ElemType &)) const
//���������������
{
    InOrder(root,Visit);
}

template<class ElemType>
void BinaryTree<ElemType>::PostOrder(BinaryTreeNode<ElemType> *r,void(*Visit)(const ElemType &)) const
//�������������������rΪ���Ķ�����
{
    if(r!=NULL)
    {
        PostOrder(r->leftChild,Visit);  //���ȱ���r��������
        PostOrder(r->rightChild,Visit);  //�ٱ���r��������
        (*Visit)(r->data);  //�����ʸ��ڵ�r
    }
}

template<class ElemType>
void BinaryTree<ElemType>::PostOrder(void(*Visit)(const ElemType &)) const
//�������ĺ������
{
    PostOrder(root,Visit);
}

template<class ElemType>
void BinaryTree<ElemType>::LevelOrder(void(*Visit)(const ElemType &)) const
//��α���������
{
    LinkQueue<BinaryTreeNode<ElemType> *> q;//�����������������q
    BinaryTreeNode<ElemType> *p;
    if(root!=NULL)   //������ǿգ������
        q.EnQueue(root);
    while(!q.IsEmpty())  //q�ǿգ�˵�����нڵ�δ����
    {
        q.DelQueue(p);  //��ͷԪ�س��ӣ�������֮
        (*Visit)(p->data);  //����
        if(p->leftChild!=NULL)  //��ͷԪ�����ӷǿ�
            q.EnQueue(p->leftChild);  //�������
        if(p->rightChild!=NULL)  //��ͷԪ���Һ��ӷǿ�
            q.EnQueue(p->rightChild);  //�Һ������
    }
}

template<class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::Find(const ElemType &e) const
//�ҵ�ֵΪe�Ľ�㣨���ò�α�����
{
    LinkQueue<BinaryTreeNode<ElemType> *> q;	// �������q
	BinaryTreeNode<ElemType> *p;
	if (root != NULL) // ������ǿ�,�����
        q.EnQueue(root);
	while (!q.IsEmpty())	// q�ǿ�,˵�����н��δ����
	{
		q.DelQueue(p);                      // ��ͷԪ�س��ӣ�������֮
		if (p->data == e) //���q��ֵΪe������p
			return p;
		if (p->leftChild != NULL)			// ��ͷԪ�����ӷǿ�
			q.EnQueue(p->leftChild);		// �������
		if (p->rightChild != NULL)			// ��ͷԪ���Һ��ӷǿ�
			q.EnQueue(p->rightChild);		// �Һ������
	}
	return NULL;
}

template<class ElemType>
int BinaryTree<ElemType>::NodeCount(const BinaryTreeNode<ElemType> *r) const
//��������������rΪ���Ķ�����������
{
    if(r==NULL)
        return 0;
    else
        return NodeCount(r->leftChild)+NodeCount(r->rightChild)+1;
}

template<class ElemType>
int BinaryTree<ElemType>::NodeCount() const
//��������Ľ�����
{
    return NodeCount(root);
}

template<class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::LeftChild(const BinaryTreeNode<ElemType> *p) const
//��p��������
{
    return p->leftChild;
}

template<class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::RightChild(const BinaryTreeNode<ElemType> *p) const
//��p�����Һ���
{
    return p->rightChild;
}

template<class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::LeftSibling(const BinaryTreeNode<ElemType> *p) const
//����p�����ֵ�
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
//����p�����ֵ�
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
//�ݹ飺����rΪ���Ķ�����������p��˫��
{
    if(r==NULL)
        return NULL;  //�ն�����
    else if(r->leftChild==p||r->rightChild==p)
        return r;  //rΪp��˫��
    else  //��r����������p��˫��
    {
        BinaryTreeNode<ElemType> *tmp;
        tmp=Parent(r->leftChild,p);  //������������p��˫��
        if(tmp!=NULL)
            return tmp;  //˫������������
        tmp=Parent(r->rightChild,p);  //������������p��˫��
        if(tmp!=NULL)
            return tmp;  //˫������������
        else
            return NULL;  //p��˫��
    }
}

template<class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::Parent(const BinaryTreeNode<ElemType> *p) const
//��p����˫��
{
    return Parent(root,p);
}

template<class ElemType>
void BinaryTree<ElemType>::InsertLeftChild(BinaryTreeNode<ElemType> *p,const ElemType &e)
//p�ǿ�ʱ������Ԫ��ֵΪe�Ľ����Ϊp�����ӣ���p���ӷǿգ���ԭp����������Ϊe��������
{
    if(p==NULL)
        return;
    else
    {
        BinaryTreeNode<ElemType> *child=new BinaryTreeNode<ElemType>(e); //e��Ϊchild��dataֵ
        if(p->leftChild!=NULL)  //p�����ӷǿ�
            child->leftChild=p->leftChild;  //pԭ����������Ϊe��������
        p->leftChild=child;  //e��Ϊp������
        return;
    }
}

template<class ElemType>
void BinaryTree<ElemType>::InsertRightChild(BinaryTreeNode<ElemType> *p,const ElemType &e)
//p�ǿ�ʱ������Ԫ��ֵΪe�Ľ����Ϊp���Һ��ӣ���p�Һ��ӷǿգ���ԭp����������Ϊe��������
{
    if(p==NULL)
        return;
    else
    {
        BinaryTreeNode<ElemType> *child=new BinaryTreeNode<ElemType>(e); //e��Ϊchild��dataֵ
        if(p->rightChild!=NULL)  //p���Һ��ӷǿ�
            child->rightChild=p->rightChild;  //pԭ����������Ϊe��������
        p->rightChild=child;  //e��Ϊp���Һ���
        return;
    }
}

template<class ElemType>
void BinaryTree<ElemType>::DeleteLeftChild(BinaryTreeNode<ElemType> *p)
//p�ǿ�ʱ��ɾ��p��������
{
    if(p==NULL)
        return;
    else
    {
        Destroy(p->leftChild);//���÷�������
    }
}

template<class ElemType>
void BinaryTree<ElemType>::DeleteRightChild(BinaryTreeNode<ElemType> *p)
//p�ǿ�ʱ��ɾ��p��������
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
//��������������rΪ���Ķ������߶�
{
    if(r==NULL)//�ն��������߶�Ϊ0
        return 0;
    else//�ǿն��������߶�Ϊ�������������߶ȼ�1
    {
        int lHeight,rHeight;
        lHeight=Height(r->leftChild); //�������ĸ�
        rHeight=Height(r->rightChild); //�������ĸ�
        return (lHeight>rHeight?lHeight:rHeight)+1;
    }
}

template<class ElemType>
int BinaryTree<ElemType>::Height() const
//��������ĸ�
{
    return Height(root);
}

template <class ElemType>
int BinaryTree<ElemType>::CountWidth() const
//�������������ȣ����ڲ�α�����
{
    LinkQueue<BinaryTreeNode<ElemType> *> q;  //����
    BinaryTreeNode<ElemType> *p;  //���
    int width=0, n=0, Count=0;  //width����ȣ�n��¼ÿ���ȣ�Count���ڼ���������ÿ����
    if(root !=NULL)  //���ڵ�ǿ�ʱ�����ڵ���ӣ��������Ϊ1���˲���nҲ��Ϊ1
    {
        q.EnQueue(root);
        width=1;
        n=1;
    }
    while(!q.IsEmpty())
    {
        Count = 0;  //��ÿһ��Ԫ�صĳ�ʼ�������Ϊ0
        for(int i = 0; i < n; i++)  //������һ���ÿһ��Ԫ��
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
        n = Count;  //��¼�˲���
        if(Count > width)  //����˲��ȴ��ڵ�ǰ����ȣ�����������
            width = Count;
    }
    return width;
}



template<class ElemType>
void BinaryTree<ElemType>::LeafNode(int &num) const
{
    LinkQueue<BinaryTreeNode<ElemType> *> q;//�������q
    BinaryTreeNode<ElemType> *p;
    if(root!=NULL)   //������ǿգ������
        q.EnQueue(root);
    while(!q.IsEmpty())  //q�ǿգ�˵�����нڵ�δ����
    {
        q.DelQueue(p);  //��ͷԪ�س��ӣ�������֮
        //(*Visit)(p->data);  //����
        if(p->leftChild==NULL&&p->rightChild==NULL)
            num++;
        if(p->leftChild!=NULL)  //��ͷԪ�����ӷǿ�
            q.EnQueue(p->leftChild);  //�������
        if(p->rightChild!=NULL)  //��ͷԪ���Һ��ӷǿ�
            q.EnQueue(p->rightChild);  //�Һ������
    }

}


int p[100] = {0};
template<class ElemType>
void DisplayBTWithTreeShape(BinaryTreeNode<ElemType> *r, int level)
//��״��ʾ��rΪ���Ķ�������level���������������Ϊ1
{
    if(r != NULL)	// ��������ʽ��ֻ��ʽ�ǿ���
    {
		DisplayBTWithTreeShape<ElemType>(r->rightChild, level + 1);//��ʾ������
		cout << endl;					//��ʾ����
		p[level-1]++;
		for(int i = 0; i < level - 1; i++)
			cout << "  ";				//ȷ���ڵ�level����ʾ���
		cout << r->data;				//��ʾ���
		DisplayBTWithTreeShape<ElemType>(r->leftChild, level + 1);//��ʾ������
	}
}


template <class ElemType>
void DisplayBTWithTreeShape(BinaryTree<ElemType> &bt, int flag)
//��״��ʽ��ʾ������
{
	if(flag == 0)
    {
        DisplayBTWithTreeShape<ElemType>(bt.GetRoot(), 1);
		// ��״��ʾ��bt.GetRoot()Ϊ���Ķ�����
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

