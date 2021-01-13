#ifndef __IN_THREAD_BINARY_TREE_H__
#define __IN_THREAD_BINARY_TREE_H__

#include "BinaryTree.h"			// ����������
#include "ThreadBinTreeNode.h"	// ����������������

// ����������������
template <class ElemType>
class InThreadBinTree
{
protected:
//  ���������������ݳ�Ա:
	ThreadBinTreeNode<ElemType> *root;

//	��������:
	void InThreadHelp(ThreadBinTreeNode<ElemType> *p, ThreadBinTreeNode<ElemType> *&pre);
		// ������������pΪ���Ķ�����,preΪp�е�һ������ǰ�����ָ�롣 
	ThreadBinTreeNode<ElemType> *TransformHelp(BinTreeNode<ElemType> *r);
		// ����rΪ���Ķ�����ת�����µ�δ����������������������,�����¶������ĸ�
	ThreadBinTreeNode<ElemType> *CopyTreeHelp(ThreadBinTreeNode<ElemType> *t);	
		// ��������������
	void DestroyHelp(ThreadBinTreeNode<ElemType> * &r);		// ������rΪ��������

public:
//  ����������������Ա:
	InThreadBinTree(const BinaryTree<ElemType> &bt);		
		// �ɶ���������������������������ת�����캯��
	virtual ~InThreadBinTree();								// ��������
	ThreadBinTreeNode<ElemType> *GetRoot() const;			// ���������������ĸ�
	void InThread();										// ����������������
	ThreadBinTreeNode<ElemType> *GetFirst() const;
	ThreadBinTreeNode<ElemType> *GetLast() const;
	ThreadBinTreeNode<ElemType> *GetNext(ThreadBinTreeNode<ElemType> *p) const;	
		// ȡָ�����p��������������һ����� 
	ThreadBinTreeNode<ElemType> *Find(const ElemType &e) const; // ����Ԫ��e 
	void InsertRightChild(ThreadBinTreeNode<ElemType> *p, const ElemType &e);// �����Һ���
	void DeleteLeftChild(ThreadBinTreeNode<ElemType> *p);   // ɾ��p�������� 

	void InOrder(void (*Visit)(const ElemType &)) const;	// ���������������	
	InThreadBinTree(const InThreadBinTree<ElemType> &t);	// ���ƹ��캯��
	InThreadBinTree<ElemType> &operator=(const InThreadBinTree<ElemType>& t);
		// ��ֵ���������
};

template <class ElemType>
void DisplayBTWithTreeShapeHelp(ThreadBinTreeNode<ElemType> *r, int level);
	//	����״��ʽ��ʾ��rΪ����������������levelΪ���������������Ĳ����Ϊ1
template <class ElemType>
void DisplayBTWithTreeShape(InThreadBinTree<ElemType> &bt);
	//	��״��ʽ��ʾ���������� 


// ���������ʵ�ֲ���
template <class ElemType>
void InThreadBinTree<ElemType>::InThreadHelp(ThreadBinTreeNode<ElemType> *p, 
	ThreadBinTreeNode<ElemType> *&pre)
// ���������������������pΪ���Ķ�����,preΪp�е�һ������ǰ�����ָ�� 
{
	if (p != NULL)	{
		InThreadHelp(p->leftChild, pre);// ������p��������
		
		if(p->leftChild == NULL)	{	// p������,��ǰ������ 
			p->leftChild = pre;			// p��ǰ��Ϊpre
			p->leftTag = 1;			    // ���־Ϊ����
		}
		else	                       // p������, ���־Ϊ���� 
			p->leftTag = 0;	
		
		if(pre != NULL && pre->rightChild == NULL)	{	// pre���Һ���, ������
			pre->rightChild = p;		// pre���Ϊp
			pre->rightTag = 1;			// �ұ�־Ϊ���� 
  		}
  		else if (pre != NULL)	        // p���Һ���, �ұ�־Ϊ���� 
			pre->rightTag = 0;

		pre = p;						// ������һ���ʱ,pΪ��һ����ǰ��
		
		InThreadHelp(p->rightChild, pre);// ������p��������
	}
}

template <class ElemType>
void InThreadBinTree<ElemType>::InThread()
// �������������������������
{
	ThreadBinTreeNode<ElemType> *pre = NULL;	// ���������е�һ������ǰ��Ϊ��
	InThreadHelp(root, pre);					// ������������rootΪ���Ķ�����
	pre->rightTag = 1;				            // ���������һ������ָ��Ϊ����
}

template <class ElemType>
ThreadBinTreeNode<ElemType> *InThreadBinTree<ElemType>::TransformHelp(BinTreeNode<ElemType> *r)
// ���������rΪ���Ķ�����ת�����µ�δ����������������������,�����¶������ĸ�
{
	if (r == NULL)	// �ն�����ת�����µĿ�����������
		return NULL;							// ��������������Ϊ��	
	else  {	// ת���ǿն�����
		ThreadBinTreeNode<ElemType> *lChild = TransformHelp(r->leftChild);	// ת��������
		ThreadBinTreeNode<ElemType> *rChild = TransformHelp(r->rightChild);	// ת��������
		ThreadBinTreeNode<ElemType> *rt = new ThreadBinTreeNode<ElemType>(r->data, lChild, rChild);
			// ת�������
		return rt;															// ���ظ����
	}
}

template <class ElemType>
InThreadBinTree<ElemType>::InThreadBinTree(const BinaryTree<ElemType> &bt)
// ����������ɶ���������������������������ת�����캯��
{
	root = TransformHelp(bt.GetRoot());			// ת����δ�������Ķ�����
	InThread();									// ������������
}

template <class ElemType>
void InThreadBinTree<ElemType>::DestroyHelp(ThreadBinTreeNode<ElemType> * &r)
// ���������������rΪ��������������
{
	if(r != NULL)	{	// r�ǿ�,ʵʩ����
		if (r->leftTag == 0) DestroyHelp(r->leftChild);		// ����������
		if (r->rightTag == 0) DestroyHelp(r->rightChild);	// ����������
		delete r;											// ���ٸ����
		r = NULL;					
	}
}

template <class ElemType>
ThreadBinTreeNode<ElemType> *InThreadBinTree<ElemType>::GetNext(ThreadBinTreeNode<ElemType> *p) const
// �����������������������p�ĺ�̽��
{	
    if (p->rightTag == 1)	    // ��ָ��Ϊ���������Ϊp->rightChild
        p = p->rightChild;
	else	{	                // ��ָ��Ϊ���ӣ�p�����������Ľ��Ϊ���
 		p = p->rightChild;		// pָ�����Һ���	
		while (p->leftTag == 0) 
			p = p->leftChild;	// ����ԭp�������������Ľ��
	}
	return p;
}


template <class ElemType>
InThreadBinTree<ElemType>::~InThreadBinTree()
// �����������������������--��������
{
	DestroyHelp(root);
}

template <class ElemType>
ThreadBinTreeNode<ElemType> *InThreadBinTree<ElemType>::GetRoot() const
// ������������������������ĸ�
{	
	return root;
}

template <class ElemType>
ThreadBinTreeNode<ElemType> *InThreadBinTree<ElemType>::GetFirst() const
// ������������������������������еĵ�һ�����
{	
	if (root ==  NULL)
       return  NULL;
    else {
       ThreadBinTreeNode<ElemType> *p = root;
	   while (p->leftTag == 0)
			p = p->leftChild;	
	   return p;
    }         
}

template <class ElemType>
ThreadBinTreeNode<ElemType> *InThreadBinTree<ElemType>::GetLast() const
// ������������������������������е����һ�����
{	
	if (root ==  NULL)
       return  NULL;
    else {
       ThreadBinTreeNode<ElemType> *p = root;
	   while (p->rightTag == 0)
			p = p->rightChild;	
	   return p;
    }         
}

template <class ElemType>
ThreadBinTreeNode<ElemType> *InThreadBinTree<ElemType>::Find(const ElemType &e) const
// �������������Ԫ��e,���ҳɹ�������ָ�룬���򷵻�NULL. 
{	
	ThreadBinTreeNode<ElemType> *p = GetFirst();	// �Ӹ���ʼ����
	while (p != NULL && p->data != e)
		p = GetNext(p);
	return p;
}

template <class ElemType>
void InThreadBinTree<ElemType>::InsertRightChild(ThreadBinTreeNode<ElemType> *p, const ElemType &e)
// ��ʼ������p�ǿգ�
// �������������Ԫ��ֵΪe�Ľ��Ϊp���Һ��ӣ����p���Һ��ӷǿգ���pԭ����������Ϊe��������
{
	ThreadBinTreeNode<ElemType> *x, *q; 
  	if (p == NULL)	                // p�գ�����
		return;
	else 	{
		x =  new ThreadBinTreeNode<ElemType>(e, p, p->rightChild, 1, p->rightTag);
        // ����Ԫ��ֵΪe���x
		if (p->rightTag == 0)	{ 
           q = p->rightChild;
           while (q->leftTag == 0)
               q = q->leftChild;
           q->leftChild = x;
        }
        p->rightChild = x;
        p->rightTag = 0;      
		return;
	}
}

template <class ElemType>
void InThreadBinTree<ElemType>::DeleteLeftChild(ThreadBinTreeNode<ElemType> *p)
// ��ʼ������p�ǿգ�
// ���������ɾ��p��������
{
	ThreadBinTreeNode<ElemType> *x, *q; 
  	if (p == NULL || p->leftTag != 0)	// p�գ�����
		return;
	else 	{	
		q = p->leftChild;
        while (q->leftTag == 0)
           q = q->leftChild;
        q = q->leftChild;
        DestroyHelp(p->leftChild);
        p->leftChild = q;
        p->leftTag = 1;      
		return;
	}
}

template <class ElemType>
void InThreadBinTree<ElemType>::InOrder(void (*Visit)(const ElemType &)) const
// ������������������������	
{
	ThreadBinTreeNode<ElemType> *p;	// �Ӹ���ʼ����
	for (p = GetFirst(); p != NULL; p = GetNext(p))	{		// ���������Ľ�㣬�˽� 
		(*Visit)(p->data);					// ���ʵ�ǰ���
		if (p->leftTag == 1)
		    cout << "����ָ��Ϊ����ָ�룬ָ��";
        else 
		    cout << "����ָ��Ϊ����ָ�룬ָ��";
        if (p->leftChild != NULL)
 		    cout << p->leftChild->data ; 
        else
 		    cout << "NULL" ; 
		if (p->rightTag == 1)
		    cout << "������ָ��Ϊ����ָ�룬ָ��";
        else 
		    cout << "������ָ��Ϊ����ָ�룬ָ��";
        if (p->rightChild != NULL)
 		    cout << p->rightChild->data << endl; 
        else
 		    cout << "NULL" << endl; 
     }
}

template <class ElemType>
ThreadBinTreeNode<ElemType> *InThreadBinTree<ElemType>::CopyTreeHelp(ThreadBinTreeNode<ElemType> *t)	
// �������������tΪ�����������������Ƴ��µ�δ�������Ķ�����,�����¶������ĸ�
{
	if (t == NULL)	// ���ƿ�����������
		return NULL;								// ��������������Ϊ��	
	else	{	// ���Ʒǿ�����������
		ThreadBinTreeNode<ElemType> *lChild;
		ThreadBinTreeNode<ElemType> *rChild;
		if (t->leftTag == 0)
			lChild = CopyTreeHelp(t->leftChild);	// ����������
		else
            lChild = NULL;							// ������Ϊ��
		if (t->rightTag == 0)
			rChild = CopyTreeHelp(t->rightChild);// ����������
		else
            rChild = NULL;							// ������Ϊ��
		ThreadBinTreeNode<ElemType> *r = new ThreadBinTreeNode<ElemType>(t->data, lChild, rChild);
			// ���Ƹ����
		return r;
	}
}

template <class ElemType>
InThreadBinTree<ElemType>::InThreadBinTree(const InThreadBinTree<ElemType> &t)
// �������������֪���������������������������������ƹ��캯��
{
	root = CopyTreeHelp(t.root);					// ��������������
	InThread();										// ����������������
}

template <class ElemType>
InThreadBinTree<ElemType> &InThreadBinTree<ElemType>::operator=(const InThreadBinTree<ElemType> &t)
// �������������֪����������t���Ƶ���ǰ����������--��ֵ���������
{
	if (&t != this)	{
		DestroyHelp(root);							// �ͷ�ԭ������������ռ�ÿռ�
		root = CopyTreeHelp(t.root);				// ��������������
		InThread();									// ����������������
	}
	return *this;
}

template <class ElemType>
void DisplayBTWithTreeShapeHelp(ThreadBinTreeNode<ElemType> *r, int level)
//	�������������״��ʽ��ʾ��rΪ����������������levelΪ���������������Ĳ����Ϊ1
{
	if(r != NULL)	{	//��������ʽ��ֻ��ʽ�ǿ���
		if (r->rightTag == 0)
			DisplayBTWithTreeShapeHelp<ElemType>(r->rightChild, level + 1);//��ʾ������
		cout << endl;								//��ʾ����	
		for(int i = 0; i < level - 1; i++)
			cout << "  ";							//ȷ���ڵ�level����ʾ���
		cout << r->data;							//��ʾ���
		if (r->leftTag == 0)
			DisplayBTWithTreeShapeHelp<ElemType>(r->leftChild, level + 1);//��ʾ������
	}
}

template <class ElemType>
void DisplayBTWithTreeShape(InThreadBinTree<ElemType> &bt)
//	�����������״��ʽ��ʾ���������� 
{
	DisplayBTWithTreeShapeHelp<ElemType>(bt.GetRoot(), 1);	
		// ��״��ʾ��bt.GetRoot()Ϊ��������������
	cout << endl;
}

#endif
