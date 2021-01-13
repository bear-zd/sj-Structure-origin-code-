#ifndef __SQ_BINNARY_TREE_H__
#define __SQ_BINNARY_TREE_H__
#include "Assistance.h"						// ���������
#include "LinkQueue.h"						// ������

// ˳���������
template <class ElemType>
class SqBinaryTree
{
protected:
//  ˳������������ݳ�Ա:
	int maxSize;					       // ˳������������洢�ռ� 
	int *tag;	                           // ���ʹ�ñ�־
	ElemType *elems;					   // ���洢�ռ�

//	��������:
	int NodeCount(int r) const;							// ͳ����rΪ���Ķ������н�����
	void SetNodeEmpty(int p);							// �����p�ÿ�
	void Destroy(int r);								// ɾ����rΪ���Ķ�����
	void PreOrder(int r, void (*Visit)(const ElemType &)) const;// ���������rΪ���Ķ�����
	void InOrder(int r, void (*Visit)(const ElemType &)) const;	// ���������rΪ���Ķ�����
	void PostOrder(int r, void (*Visit)(const ElemType &)) const;// ���������rΪ���Ķ�����
    int Height(int r) const;							// ����rΪ���Ķ������ĸ߶� 

public:
//  ˳��������ĺ�����Ա:
	SqBinaryTree(int size = DEFAULT_SIZE);				// ���캯��
	virtual ~SqBinaryTree();							// ��������
	int GetRoot() const;					            // ��������и���� 
	bool IsNodeEmpty(int p) const;					    // �жϽ��p�Ƿ�Ϊ��
	Status GetElem(int p, ElemType &e);				    // ���ؽ��p��Ԫ��ֵ
	Status SetElem(int p, const ElemType &e);			// �����p��ֵ��Ϊe
	bool IsEmpty() const;								// �ж϶������Ƿ�Ϊ��
	void InOrder(void (*Visit)(const ElemType &)) const;// �������������	
	void PreOrder(void (*Visit)(const ElemType &)) const;// �������������
	void PostOrder(void (*Visit)(const ElemType &)) const;// �������������
	void LevelOrder(void (*Visit)(const ElemType &)) const;// ��α���������
	int NodeCount() const;								// ��������Ľ�����
	int LeftChild(const int p) const;					// ��������н��p������
	int RightChild(const int p) const;				    // ��������н��p���Һ���
	int LeftSibling(const int p) const;					// ��������н��p�����ֵ� 
	int RightSibling(const int p) const;				// ��������н��p�����ֵ�
	int Parent(const int p) const;					    // ��������н��p��˫��
	int Find(const ElemType &e) const;						// ���Ҷ�������Ԫ��e 
	Status InsertLeftChild(int p, const ElemType &e);	// ����Ԫ����Ϊ���p����
	Status InsertRightChild(int p, const ElemType &e);  // ����Ԫ����Ϊ���p�Һ���
	Status DeleteLeftChild(int p);					    // ɾ���������н��p������
	Status DeleteRightChild(int p);					    // ɾ���������н��p���Ӵ�
	int	Height() const;									// ��������ĸ�
	SqBinaryTree(const ElemType &e, int size = DEFAULT_SIZE);   // ������eΪ���Ķ�����
	SqBinaryTree(const SqBinaryTree<ElemType> &t);		    // ���ƹ��캯��
	SqBinaryTree(ElemType es[], int ta[], int size = DEFAULT_SIZE);	
		// ��es[]��ta[]��size���������
	SqBinaryTree<ElemType> &operator=(const SqBinaryTree<ElemType>& t);		
		// ��ֵ���������
};


template <class ElemType>
void DisplayBTWithTreeShape(int r, int level);
	//	����״��ʽ��ʾ��rΪ���Ķ�������levelΪ�������������Ĳ����Ϊ1
template <class ElemType>
void DisplayBTWithTreeShape(SqBinaryTree<ElemType> &bt);
	//	��״��ʽ��ʾ������ 
template <class ElemType>
void CreateBinaryTree(ElemType es[], int ta[], int r, ElemType pre[], ElemType in[], 
	int preLeft, int preRight, int inLeft, int inRight);	
	// ��֪����������������pre[preLeft..preRight]����������in[inLeft..inRight]������rΪ���Ķ�����
template <class ElemType>
SqBinaryTree<ElemType> &CreateBinaryTree(ElemType pre[], ElemType in[], int n, int size = DEFAULT_SIZE);
	// ��֪������������й��������

// ˳����������ʵ�ֲ���
template <class ElemType>
bool SqBinaryTree<ElemType>::IsNodeEmpty(int p) const
// ���������������pΪ��,�򷵻�true,���򷵻�false
{
	if(p < 0 || p >= maxSize || tag[p] == 0)
        return true;	// ��ʱ���Ϊ��
	else
        return false;
}

template <class ElemType>
Status SqBinaryTree<ElemType>::GetElem(int p, ElemType &e)
// �����������e���ؽ��p��Ԫ��ֵ,������ɹ�,��������SUCCESS,���򷵻�FAIL
{
	if (IsNodeEmpty(p))
        return FAIL;                // ����ʧ��
	else	{
		e = elems[p];				// ��e���ؽ��p��Ԫ��ֵ
		return SUCCESS;				// �����ɹ�
	}
}

template <class ElemType>
Status SqBinaryTree<ElemType>::SetElem(int p, const ElemType &e)
// �����������������ڽ��p,�򷵻�FAIL,���򷵻�SUCCESS,�������p��ֵ����Ϊe
{
	if (IsNodeEmpty(p))
        return FAIL;		        // ����ʧ��
	else	{	// ���ڽ��p
		elems[p] = e;				// �����p��ֵ����Ϊe
		return SUCCESS;				// ����SUCCESS
	}
}

template <class ElemType>
void SqBinaryTree<ElemType>::SetNodeEmpty(int p)
// ��������������p�ÿ�
{
	if (p >= 0 && p < maxSize && (2 * p + 1 >= maxSize || tag[2 * p + 1] == 0)
        && (2 * p + 2 >= maxSize || tag[2 * p + 2] == 0))
        tag[p] = 0;	// ��p�ÿ�
}

template <class ElemType>
SqBinaryTree<ElemType>::SqBinaryTree(int size)
// �������������һ�ÿն�����
{
	maxSize = size;			             // ���ö�������������� 
	elems = new ElemType[maxSize];	     // ��������Ԫ�صĴ洢�ռ�
	tag = new int[maxSize];	// ����������Ĵ洢�ռ�
	for (int i = 0; i <maxSize; i++)	 // �����н���ʶΪ��
		tag[i] = 0;
}

template <class ElemType>
SqBinaryTree<ElemType>::~SqBinaryTree()
// ���������ɾ��������
{
	delete []elems;					// �ͷ�Ԫ�ش洢�ռ�
	delete []tag;					// �ͷű�Ǵ洢�ռ�
}

template <class ElemType>
int SqBinaryTree<ElemType>::GetRoot() const
// ������������ض������ĸ���� 
{
	if (tag[0] == 1)
      return  0;
    else 
      return  -1 ; 
}

template <class ElemType>
bool SqBinaryTree<ElemType>::IsEmpty() const
// ����������ж϶������Ƿ�Ϊ��
{
	return IsNodeEmpty(0);
}

template <class ElemType>
void SqBinaryTree<ElemType>::PreOrder(int r, void (*Visit)(const ElemType &)) const
// ������������������rΪ���Ķ�����
{
	if (!IsNodeEmpty(r)) 	{	            // ���ǿ�
		(*Visit)(elems[r]);			        // ���ʸ����
		PreOrder(LeftChild(r), Visit);		// ����������
		PreOrder(RightChild(r), Visit);		// ����������
	}
}

template <class ElemType>
void SqBinaryTree<ElemType>::PreOrder(void (*Visit)(const ElemType &)) const
// ����������������������
{
	PreOrder(0, Visit);	
}	

template <class ElemType>
void SqBinaryTree<ElemType>::InOrder(int r, void (*Visit)(const ElemType &)) const
// ������������������rΪ���Ķ�����
{
	if (!IsNodeEmpty(r)) 	{	            // ���ǿ�
		InOrder(LeftChild(r), Visit);		// ����������
		(*Visit)(elems[r]);					// ���ʸ����
		InOrder(RightChild(r), Visit);		// ����������
	}
}

template <class ElemType>
void SqBinaryTree<ElemType>::InOrder(void (*Visit)(const ElemType &)) const
// ����������������������
{
	InOrder(0, Visit);	
}	

template <class ElemType>
void SqBinaryTree<ElemType>::PostOrder(int r, void (*Visit)(const ElemType &)) const
// ������������������rΪ���Ķ�����
{
	if (!IsNodeEmpty(r)) 	{	            // ���ǿ�
		PostOrder(LeftChild(r), Visit);		// ����������
		PostOrder(RightChild(r), Visit);	// ����������
		(*Visit)(elems[r]);					// ���ʸ����
	}
}

template <class ElemType>
void SqBinaryTree<ElemType>::PostOrder(void (*Visit)(const ElemType &)) const
// ����������������������
{
	PostOrder(0, Visit);	
}	

template <class ElemType>
void SqBinaryTree<ElemType>::LevelOrder(void (*Visit)(const ElemType &)) const
// �����������α���������
{
	LinkQueue<int> q;					// ���帨������
	int t = 0;							// �Ӹ���㿪ʼ���в�α���
	
	if (!IsNodeEmpty(t))
        q.EnQueue(t);		// ������ǿ�,�����
	while (!q.IsEmpty())	{	// q�ǿ�,˵�����н��δ����
		q.DelQueue(t);     
		(*Visit)(elems[t]);
		if (!IsNodeEmpty(LeftChild(t)))				// ���ӷǿ�
			q.EnQueue(LeftChild(t));				// �������
		if (!IsNodeEmpty(RightChild(t)))			// �Һ��ӷǿ�
			q.EnQueue(RightChild(t));			// �Һ������
	}
}

template <class ElemType>
int SqBinaryTree<ElemType>::Height(int r) const
// ���������������rΪ���Ķ������ĸ�
{
	if(IsNodeEmpty(r))		// �ն������ĸ�Ϊ0
		return 0;
	else	{	
		int lHeight, rHeight;
		lHeight = Height(LeftChild(r));		// ��r���������ĸ�
		rHeight = Height(RightChild(r));	// ��r���������ĸ�
		return (lHeight > rHeight ? lHeight + 1: rHeight + 1);
			// �ǿն�������Ϊ���������ĸߵ����ֵ�ټ�1
	}
}

template <class ElemType>
int SqBinaryTree<ElemType>::Height() const
// ������������ض������ĸ�
{
	return Height(0);
}

template <class ElemType>
int SqBinaryTree<ElemType>::NodeCount(int r) const
// ���������������rΪ���Ķ������Ľ�����
{
	if (IsNodeEmpty(r))
       return 0;// �ն�����������Ϊ0
	else
       return 1 + NodeCount(LeftChild(r)) + NodeCount(RightChild(r));
                // �ǿն���������Ϊ���������Ľ�����֮���ټ�1
}

template <class ElemType>
int SqBinaryTree<ElemType>::NodeCount() const
// ������������ض������Ľ�����
{
	return NodeCount(0);
}

template <class ElemType>
int SqBinaryTree<ElemType>::LeftChild(const int p) const
// ������������ض��������p������
{
	if (2 * p + 1 < maxSize && tag[2 * p + 1] == 1)
      return  2 * p + 1;
    else 
      return  -1 ; 
}

template <class ElemType>
int SqBinaryTree<ElemType>::RightChild(const int p) const
// ������������ض��������p���Һ���
{
	if (2 * p + 2 < maxSize && tag[2 * p + 2] == 1)
      return  2 * p + 2;
    else 
      return  -1 ; 
}

template <class ElemType>
int SqBinaryTree<ElemType>::LeftSibling(const int p) const
// ������������ض��������p�����ֵ� 
{
	if (p % 2 == 1 || p == 0 || tag[p - 1] == 0)
        return -1;
    else 
        return p - 1; 
}

template <class ElemType>
int SqBinaryTree<ElemType>::RightSibling(const int p) const
// ������������ض��������p�����ֵ�
{
	if (p % 2 == 0 || p + 1 >= maxSize || tag[p + 1] == 0)
        return -1;
    else 
        return p + 1; 
}

template <class ElemType>
int SqBinaryTree<ElemType>::Parent(const int p) const
// ������������ض��������p��˫��
{
	return p > 0 ? (p - 1) / 2 : -1;
}

template <class ElemType>
int SqBinaryTree<ElemType>::Find(const ElemType &e) const
// ������������Ҷ�������Ԫ��e�����ҳɹ���������������±꣬���򷵻�-1. 
{
	LinkQueue<int> q;					// ���帨������
	int t = 0;							
	
	if (!IsNodeEmpty(t))
        q.EnQueue(t);					// ������ǿ�,�����
	while (!q.IsEmpty())	{			// q�ǿ�,˵�����н��δ����
		q.DelQueue(t);     
		if (elems[t] == e)
			return t;
		if (!IsNodeEmpty(LeftChild(t)))				// ���ӷǿ�
			q.EnQueue(LeftChild(t));				// �������
		if (!IsNodeEmpty(RightChild(t)))			// �Һ��ӷǿ�
			q.EnQueue(RightChild(t));			// �Һ������
	}
	return -1;
}


template <class ElemType>
Status SqBinaryTree<ElemType>::InsertLeftChild(int p, const ElemType &e)
// �������������eΪp�����ӡ����pΪ�ա�����p�����ӷǿա����߻���p������λ�ò���������Ч��Χ���������ʧ��
{
	if (IsNodeEmpty(p))
		return FAIL;
	else 	{	// ��������    
		if (2 * p + 1 < maxSize && 2 * p + 1 > 0 && tag[2 * p + 1] == 0)	{	// p����Ϊ��,��λ�úϷ�
			elems[2 * p + 1] = e;				// ��������Ԫ��ֵ
			tag[2 * p + 1] = 1;		            // �������ӱ�־
			return SUCCESS;						// ����SUCCESS
		}
		else
		    return FAIL;
	}
}

template <class ElemType>
Status SqBinaryTree<ElemType>::InsertRightChild(int p, const ElemType &e)
// �������������eΪp���Һ��ӡ����pΪ�ա�����p���Һ��ӷǿա����߻���p���Һ���λ�ò���������Ч��Χ���������ʧ��
{
	if (IsNodeEmpty(p))
		return FAIL;
	else	{	// �����Һ���
		if (2 * p + 2 < maxSize && 2 * p + 2 > 0 && tag[2 * p + 2] == 0)	{	// p����Ϊ��,��λ�úϷ�
			elems[2 * p + 2] = e;				// ��������Ԫ��ֵ
			tag[2 * p + 2] = 1;		            // �������ӱ�־
			return SUCCESS;						    // ����SUCCESS
		}
		else
            return FAIL;
	}
}

template <class ElemType>
Status SqBinaryTree<ElemType>::DeleteLeftChild(int p)
// ������������p�ǿգ���ɾ��p���������������ʧ�ܡ� 
{
	if (IsNodeEmpty(p))
		return FAIL;
	else  { 
		Destroy(LeftChild(p));
		return SUCCESS;			
	}
}

template <class ElemType>
Status SqBinaryTree<ElemType>::DeleteRightChild(int p)
// ������������p�ǿգ���ɾ��p���������������ʧ�ܡ� 
{
	if (IsNodeEmpty(p))
		return FAIL;
	else	{
		Destroy(RightChild(p));	
		return SUCCESS;		
	}
}

template <class ElemType>
void SqBinaryTree<ElemType>::Destroy(int r)
// ���������ɾ����rΪ���Ķ�����
{
	if(r >=0 && r < maxSize && !IsNodeEmpty(r))	{ // r�ǿ�,ʵʩɾ��
		Destroy(LeftChild(r));		// ɾ��������
		Destroy(RightChild(r));		// ɾ��������
		tag[r] = 0;			// ��r�ÿ�
	}
}

template <class ElemType>
SqBinaryTree<ElemType>::SqBinaryTree(const ElemType &e, int size)
// ���������������eΪ������������Ϊsize�Ķ�����
{
	maxSize = size;					// ��������
	elems = new ElemType[maxSize];	// ��������Ԫ�صĴ洢�ռ�
	tag = new int[maxSize];	        // ����������Ĵ洢�ռ�
	for (int i = 1; i <maxSize; i++)// �����н���ʶΪ��
		tag[i] = 0;
	tag[0] = 1;	                    // ���ø���־
	elems[0] = e;			        // ���ø�������Ԫ��ֵ
}


template <class ElemType>
SqBinaryTree<ElemType>::SqBinaryTree(const SqBinaryTree<ElemType> &t)
// �������������֪�����������¶������������ƹ��캯��
{
	maxSize = t.maxSize;			// ��������
	elems = new ElemType[maxSize];	// ��������Ԫ�صĴ洢�ռ�
	tag = new int[maxSize];	        // ����������Ĵ洢�ռ�
	for (int i = 0; i <maxSize; i++)	{
		elems[i] = t.elems[i];           // ���ƽ��Ԫ�� 
		tag[i] = t.tag[i];             // ���ƽ����
    }
}

template <class ElemType>
SqBinaryTree<ElemType>::SqBinaryTree(ElemType es[], int ta[], int size)
// �����������Ԫ������es[]�ͱ������ta[]�������ռ�Ϊsize�Ķ�����, 
{
	maxSize = size;					// �������ռ�
	elems = new ElemType[maxSize];	// ��������Ԫ�صĴ洢�ռ�
	tag = new int[maxSize];	        // ����������Ĵ洢�ռ�
	for (int i = 0; i <maxSize; i++)	{
		elems[i] = es[i];           // ���ƽ��Ԫ�� 
		tag[i] = ta[i];             // ���ƽ����
    }
}

template <class ElemType>
SqBinaryTree<ElemType> &SqBinaryTree<ElemType>::operator=(const SqBinaryTree<ElemType> &t)
// �������������֪������t���Ƶ���ǰ������--��ֵ���������
{
	if (&t != this)	{
		delete []elems;					// �ͷŴ洢�ռ�
		maxSize = t.maxSize;		    // �������ռ�
	    elems = new ElemType[maxSize];	// ��������Ԫ�صĴ洢�ռ�
        tag = new int[maxSize];	        // ����������Ĵ洢�ռ�

		for (int i = 0; i <maxSize; i++){
		    elems[i] = t.elems[i];           // ���ƽ��Ԫ�� 
		    tag[i] = t.tag[i];             // ���ƽ����
        }
	}
	return *this;
}

template <class ElemType>
void DisplayBTWithTreeShape(SqBinaryTree<ElemType> &bt, int r, int level)
//	�������������״��ʽ��ʾ������bt����rΪ����������levelΪ�������
{
	if(!bt.IsNodeEmpty(r))	{	        //��������ʽ��ֻ��ʽ�ǿ���
		DisplayBTWithTreeShape<ElemType>(bt, bt.RightChild(r), level + 1);//��ʾ������
		cout << endl;					//��ʾ����	
		for(int i = 0; i < level - 1; i++)
			cout << "  ";				//ȷ���ڵ�level����ʾ���
		ElemType e;
		bt.GetElem(r, e);
		cout << e;						//��ʾ���
		DisplayBTWithTreeShape<ElemType>(bt, bt.LeftChild(r), level + 1);//��ʾ������
	}
}

template <class ElemType>
void DisplayBTWithTreeShape(SqBinaryTree<ElemType> &bt)
//	�����������״��ʽ��ʾ������ 
{
	DisplayBTWithTreeShape<ElemType>(bt, 0, 1);	
		// ��״��ʾ������bt
	cout << endl;
}

template <class ElemType>
void CreateBinaryTree(ElemType es[], int ta[], int r, ElemType pre[], ElemType in[], 
	int preLeft, int preRight, int inLeft, int inRight)	
// �����������֪����������������pre[preLeft..preRight]����������in[inLeft..inRight]����
//	��rΪ���Ķ�����
{
	if (inLeft <= inRight)	{	// �������н��,�ǿն�����
		es[r] = pre[preLeft]; ta[r] = 1; // ���ɸ����
		int mid = inLeft;
		while (in[mid] != pre[preLeft]) // ����pre[preLeft]��in[]�е�λ��,Ҳ�������������и���λ��
			mid++;
		CreateBinaryTree(es, ta, 2 * r + 1, pre, in, preLeft+1, preLeft + mid - inLeft, inLeft, mid - 1);
                                        // ����������
		CreateBinaryTree(es, ta, 2 * r + 2, pre, in, preLeft + mid - inLeft + 1, preRight, mid + 1, 
			inRight);					// ����������
	}
} 

template <class ElemType>
SqBinaryTree<ElemType> &CreateBinaryTree(ElemType pre[], ElemType in[], int n, int size)
// �����������֪������������й��������
{
	ElemType *es = new ElemType[size];	// ����Ԫ���������ʱ�ռ�
    int *ta = new int[size];	        // �������������ʱ�ռ�
	int r = 0;							// �������ĸ�
	for (int i = 0; i < size; i++)
	    ta[i] = 0;
	CreateBinaryTree<ElemType>(es, ta, r, pre, in, 0, n - 1, 0, n - 1);
		// ��������������й�����rΪ���Ķ����� 
	SqBinaryTree<ElemType> *bt = new SqBinaryTree<ElemType>(es, ta, size);	// ���ɶ�����
	delete []es;
    delete []ta;						// �ͷ���ʱ�ռ�
	return *bt;
}

#endif
