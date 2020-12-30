#ifndef __CROSS_LIST_H__
#define __CROSS_LIST_H__

#include "Assistance.h"				// ���������
#include "crossnode.h"				// ʮ��������Ԫ������
#include "triple.h"					// ��Ԫ����

// ϡ�����ʮ��������
template<class ElemType>
class CrossList
{
protected:
//  ϡ�����ʮ���������ݳ�Ա:
	CrossNode<ElemType> **rowHead, **colHead;// ���������ͷ����
	int rows, cols, num;			// ϡ����������,����������Ԫ����

public:
// ϡ�����ʮ�����ķ�������:
	CrossList(int rs = DEFAULT_SIZE, int cs = DEFAULT_SIZE);
		// ����һ��rs��cs�еĿ�ϡ�����
	~CrossList();				// ��������
	void Clear();					// ���ϡ�����
	int GetRows() const { return rows; };			// ����ϡ���������
    int GetCols() const { return cols; };			// ����ϡ���������
    int GetNum() const { return num; };			// ����ϡ��������Ԫ����
	Status SetElem(int r, int c, const ElemType &v);	// ����ָ��λ�õ�Ԫ��ֵ
	Status GetElem(int r, int c, ElemType &v);			// ȡָ��λ�õ�Ԫ��ֵ
	CrossList(const CrossList<ElemType> &b);	// ���ƹ��캯��
	CrossList<ElemType> &operator =(const CrossList<ElemType> &b); 
		// ���ظ�ֵ����� 
	CrossList<ElemType> operator +(const CrossList<ElemType> &b); 
		// ���ؼӷ������ 
};

// ϡ�����ʮ���������ʵ�ֲ���
template <class ElemType>
CrossList<ElemType>::CrossList(int rs, int cs)
// �������������һ��rs��cs�еĿ�ϡ�����
{
	if (rs < 1 || cs < 1)							
		throw Error("������������Ч!");	// �׳��쳣
	rows = rs;							// ����
	cols = cs;							// ����
	num = 0;							// ����Ԫ����
	rowHead = new CrossNode<ElemType> *[rows];	// �����������ͷ����洢�ռ�
	colHead = new CrossNode<ElemType> *[cols];	// �����������ͷ����洢�ռ�
	for (int row = 0; row < rows; row++) 
		rowHead[row] = NULL;			// ��ʼ���������ͷ����
	for (int col = 0; col < cols; col++) 
		colHead[col] = NULL;			// ��ʼ���������ͷ����
}

template <class ElemType>
CrossList<ElemType>::~CrossList()
// ���������ϡ�������ռ�ÿռ�
{
	Clear();
	delete []rowHead;					// �ͷ��������ͷ����
	delete []colHead;					// �ͷ��������ͷ����
}

template <class ElemType>
void CrossList<ElemType>::Clear()
// ������������ϡ�����
{
    CrossNode<ElemType> *p;
	for (int i = 0; i < rows; i++)	
		while (rowHead[i] != NULL)	{   // �ͷŵ�row�еĽ�������ÿռ�
			p =  rowHead[i];		
			rowHead[i] = p->right;	
			delete p;
		}
	for (int j = 0; j < cols; j++) 
		colHead[j] = NULL;			// ��ʼ���������ͷ����
    num = 0;
}

template <class ElemType>
Status CrossList<ElemType>::SetElem(int r, int c, const ElemType &v)
// �������������±귶Χ��,�򷵻�RANGE_ERROR,���򷵻�SUCCESS
{
	if (r >= rows || c >= cols || r < 0 || c < 0)
		return RANGE_ERROR;				// �±귶Χ��
	
	CrossNode<ElemType> *pre, *p;
	if (v == 0) {  // �ѵ�r�С���c�е�ֵ�޸�Ϊ�� 
	    pre = NULL; p=rowHead[r];	// pָ����Ӧ��㣬preΪp��ǰ����� 
		while (p != NULL && p->triElem.col < c)	{
			pre = p;
            p = p->right;
		}
  
	    if (p != NULL && p->triElem.col == c)  {// ԭԪ��Ϊ����Ԫ�أ���ɾ��p���
            //  �޸���Ӧ���н���ָ��    
			if (rowHead[r] == p)
                rowHead[r] = p->right;
            else
                pre->right = p->right;

            //  �޸���Ӧ���н���ָ��    
			if (colHead[c] == p)  
			   colHead[c] = p->down;
            else {
                pre = colHead[c];
                while (pre->down != p) 
                    pre = pre->down;
                pre->down = p->down;
            }
            delete p;            
		    num--;				// ɾ�����,����Ԫ�ظ�����1
        }
    }        		
	else	{  // �ѵ�r�С���c�е�ֵ�޸�Ϊ����Ԫ�� 
	    pre = NULL; p=rowHead[r];	// pָ����Ӧ��㣬preΪp��ǰ����� 
		while (p != NULL && p->triElem.col < c)	{
			pre = p;	p = p->right;
		}
  
	    if (p != NULL && p->triElem.col == c)  	// ԭ���Ϊ����Ԫ�أ���ֱ���޸���ֵ 
            p->triElem.value == v;
        else { 	// ԭ���Ϊ0Ԫ�أ�����Ҫ������
            Triple<ElemType> e(r, c, v);		// ��Ԫ��
	        CrossNode<ElemType> *ePtr = new CrossNode<ElemType>(e);//���ɽ��
            // �ѽ����뵽��Ӧ����    	    
	        if (rowHead[r] == p)
                rowHead[r] = ePtr;
 	        else
			    pre->right = ePtr;
   	        ePtr->right = p;	
            // �ѽ����뵽��Ӧ����    	    
		    pre = NULL; p=colHead[c];
		    while (p != NULL && p->triElem.row < r)	{
			    pre = p;
   	            p = p->down;
		    }
	        if (colHead[c] == p)
                colHead[c] = ePtr;
 	        else
			    pre->down = ePtr;
   	        ePtr->down = p;	
		    num++;							// ��ɲ���������Ԫ�ظ�����һ 
	   }
	}	   
	return SUCCESS;							// �����޸ĳɹ�
}

template <class ElemType>
Status CrossList<ElemType>::GetElem(int r, int c, ElemType &v)
// �������������±귶Χ��,�򷵻�RANGE_ERROR,���򷵻�SUCCESS,����v����ָ��λ��Ԫ��ֵ
{
	if (r >= rows || c >= cols || r < 0 || c < 0)
		return RANGE_ERROR;			// �±귶Χ��
	
	CrossNode<ElemType> *p;
	for (p=rowHead[r]; p != NULL && p->triElem.col < c; p = p->right);
		// Ѱ���ڵ�r�������е���Ԫ��λ��
	if (p != NULL && p->triElem.col == c)	// �ҵ���Ԫ��
		v = p->triElem.value;
	else	// δ�ҵ���Ԫ��
		v = 0;						// ������ָ��λ��(r, c)����Ԫ��,��ʾ0Ԫ��

	return SUCCESS;					// �ɹ�
}

template <class ElemType>
CrossList<ElemType>::CrossList(const CrossList<ElemType> &b)
// �����������ϡ�����b������ϡ����󡪡����ƹ��캯��
{
    CrossNode<ElemType> *p;
	rows = b.rows;					// ��������
	cols = b.cols;					// ��������
	num = 0;						// ��ʼ������Ԫ����
	rowHead = new CrossNode<ElemType> *[rows];	// �����������ͷ����洢�ռ�
	colHead = new CrossNode<ElemType> *[cols];	// �����������ͷ����洢�ռ�
	for (int i = 0; i < rows; i++) 
		rowHead[i] = NULL;			// ��ʼ���������ͷ����
	for (int i = 0; i < cols; i++) 
		colHead[i] = NULL;			// ��ʼ���������ͷ����
	
	for (int i = 0; i < rows; i++)
		for (p = b.rowHead[i]; p != NULL; p = p->right)
			SetElem(p->triElem.row, p->triElem.col, p->triElem.value);
}

template <class ElemType>
CrossList<ElemType> &CrossList<ElemType>::operator =(const CrossList<ElemType> &b)
// �����������ϡ�����b��ֵ����ǰϡ����󡪡���ֵ�������
{
    if (rows != b.rows || cols != b.cols)
        throw Error("���������������!");	// �׳��쳣

	if (&b != this) {
	    CrossNode<ElemType> *p;
		Clear();						// ���ϡ�����
		num = b.num;					// ��ʼ������Ԫ����
		for (int i = 0; i < rows; i++)
			for (p = b.rowHead[i]; p != NULL; p = p->right)
			   SetElem(p->triElem.row, p->triElem.col, p->triElem.value);
	}
	return *this;

}

template <class ElemType>
CrossList<ElemType> CrossList<ElemType>::operator +(const CrossList<ElemType> &b)
// �����������ϡ�����b��ֵ�ӵ���ǰϡ������С����ӷ����������
{
    if (rows != b.rows || cols != b.cols)
        throw Error("���������������!");	// �׳��쳣

    CrossList<ElemType> temp(b.rows,b.cols);
    ElemType v;
    CrossNode<ElemType> *p, *q;

	for (int i = 0; i < rows; i++) {
		p = rowHead[i]; q = b.rowHead[i];
        while (p != NULL && q != NULL)  
           if (p->triElem.col < q->triElem.col) {
		       temp.SetElem(p->triElem.row, p->triElem.col, p->triElem.value);
		       p = p->right;
           }
           else  if (p->triElem.col > q->triElem.col) {
		       temp.SetElem(q->triElem.row, q->triElem.col, q->triElem.value);
		       q = q->right;
           }
           else  {
               v = p->triElem.value + q->triElem.value;
               if (v != 0)
		          temp.SetElem(q->triElem.row, q->triElem.col, v);
		       p = p->right;
		       q = q->right;
           }
        while (p != NULL)  {
 		   temp.SetElem(p->triElem.row, p->triElem.col, p->triElem.value);
		   p = p->right;
        }
        while (q != NULL)  {
           temp.SetElem(q->triElem.row, q->triElem.col, q->triElem.value);
		   q = q->right;
        }
	}			   
	return temp;

}
#endif
