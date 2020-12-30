#ifndef __TRI_SPARSE_MATRIX_H__
#define __TRI_SPARSE_MATRIX_H__

#include "Assistance.h"				// ���������
#include "triple.h"					// ��Ԫ����

// ϡ�������Ԫ��˳�����
template<class ElemType>
class TriSparseMatrix
{
protected:
// ϡ�������Ԫ��˳�������ݳ�Ա:
	Triple<ElemType> *triElems;		// �洢ϡ��������Ԫ���
	int maxSize;					// ����Ԫ��������
	int rows, cols, num;			// ϡ����������,����������Ԫ����

public:
// ϡ�������Ԫ��˳���ĺ�����Ա�� 
	TriSparseMatrix(int rs = DEFAULT_SIZE, int cs = DEFAULT_SIZE, int size = DEFAULT_SIZE);
		// ����һ��rs��cs�з���Ԫ��������Ϊsize�Ŀ�ϡ�����
	~TriSparseMatrix();				// ��������
    int GetRows() const;			// ����ϡ���������
    int GetCols() const;			// ����ϡ���������
    int GetNum() const;				// ����ϡ��������Ԫ����
	Status SetElem(int r, int c, const ElemType &v);	// ����ָ��λ�õ�Ԫ��ֵ
	Status GetElem(int r, int c, ElemType &v);			// ��ָ��λ�õ�Ԫ��ֵ
	TriSparseMatrix(const TriSparseMatrix<ElemType> &copy);	// ���ƹ��캯��
	TriSparseMatrix<ElemType> &operator =(const TriSparseMatrix<ElemType> &copy); 
		// ��ֵ���������
	void SimpleTranspose(TriSparseMatrix<ElemType> &b);// ϡ�����ļ�ת���㷨
	void FastTranspose(TriSparseMatrix<ElemType> &b);// ϡ�����Ŀ���ת���㷨
};

// ϡ�������Ԫ��˳������ʵ�ֲ���
template <class ElemType>
TriSparseMatrix<ElemType>::TriSparseMatrix(int r, int c, int size)
// ��������� ����һ��r��c�з���Ԫ��������Ϊsize�Ŀ�ϡ�����
{
	if (r < 1 || c < 1)							
		throw Error("������������Ч!");	// �׳��쳣
	maxSize = size;						// ����Ԫ��������
	rows = r;							// ����
	cols = c;							// ����
	num = 0;							// ����Ԫ�ظ���
	triElems = new Triple<ElemType>[maxSize];	// ����洢�ռ�
} 

template <class ElemType>
TriSparseMatrix<ElemType>::~TriSparseMatrix()
// ���������ϡ�������ռ�ÿռ�
{
	if (triElems != NULL) delete []triElems; // �ͷŴ洢�ռ�
}

template <class ElemType>
int TriSparseMatrix<ElemType>::GetRows() const
// �������������ϡ���������
{
	return rows;					// ��������
}

template <class ElemType>
int TriSparseMatrix<ElemType>::GetCols() const
// �������������ϡ���������
{
	return cols;					// ��������
}

template <class ElemType>
int TriSparseMatrix<ElemType>::GetNum() const
// �������������ϡ��������Ԫ����
{
	return num;						// ���ط���Ԫ����
}

template <class ElemType>
Status TriSparseMatrix<ElemType>::SetElem(int r, int c, const ElemType &v)
// �������������±귶Χ��,�򷵻�RANGE_ERROR,������,�򷵻�OVER_FLOW,����
//	��SUCCESS
{
	if (r >= rows || c >= cols || r < 0 || c < 0)
		return RANGE_ERROR;					// �±귶Χ��
	
	int i, j;								// ��������
	for (j = num - 1; j >= 0 && 
		(r < triElems[j].row || r == triElems[j].row && c < triElems[j].col); j--);// ������Ԫ��λ��

	if (j >= 0 && triElems[j].row == r && triElems[j].col == c)	{	// �ҵ���Ԫ��
		if (v == 0)	{	// ɾ����Ԫ��
			for (i = j + 1; i < num; i++)
				triElems[i - 1] = triElems[i];	// ǰ�ƴ�j+1��ʼ����Ԫ��
			num--;								// ɾ����Ԫ���,����Ԫ�����Լ�1
		}
		else	// �޸�Ԫ��ֵ
			triElems[j].value = v;
		return SUCCESS;						// �ɹ�
	}
	else if (v != 0)	{	
		if (num < maxSize)		{	// ����Ԫ��(r, c, v)���뵽��Ԫ�����
			for (i = num - 1; i > j; i--)	// ����Ԫ��	
				triElems[i + 1] = triElems[i];
			// j + 1Ϊ�ճ��Ĳ���λ��
			triElems[j + 1].row = r;		// ��
			triElems[j + 1].col = c;		// ��
			triElems[j + 1].value = v;		// ����Ԫ��ֵ
			num++;							// ������Ԫ���,����Ԫ�����Լ�1
			return SUCCESS;					// �ɹ�
		}
		else	// ���
			return OVER_FLOW;				// ���ʱ����OVER_FLOW
	}
	return SUCCESS;							// �ɹ�
}

template <class ElemType>
Status TriSparseMatrix<ElemType>::GetElem(int r, int c, ElemType &v)
// �������������±귶Χ��,�򷵻�RANGE_ERROR,���򷵻�SUCCESS,����v����ָ��λ��Ԫ��ֵ
{
	if (r >= rows || c >= cols || r < 0 || c < 0)
		return RANGE_ERROR;			// �±귶Χ��

	int j;							// ��������

	
	for (j = num - 1; j >= 0 && 
		(r < triElems[j].row || r == triElems[j].row && c < triElems[j].col); j--);// ����ָ��λ�õ���Ԫ��
	
	if (j >= 0 && triElems[j].row == r && triElems[j].col == c)	// �ҵ���Ԫ��
		v = triElems[j].value;		// ��v����ָ��λ��Ԫ��ֵ
	else	// δ�ҵ���Ԫ��
		v = 0;						// δ�ҵ���Ԫ��,��ʾ0Ԫ��ֵ
	return SUCCESS;					// �ɹ�
}

template <class ElemType>
TriSparseMatrix<ElemType>::TriSparseMatrix(const TriSparseMatrix<ElemType> &copy)
// �����������ϡ�����copy������ϡ����󡪡����ƹ��캯��
{
	maxSize = copy.maxSize;							// ������Ԫ�ظ���
	triElems = new Triple<ElemType>[maxSize];		// ����洢�ռ�
	rows = copy.rows;								// ��������
	cols = copy.cols;								// ��������
	num = copy.num;									// ���Ʒ���Ԫ�ظ���
	triElems = new Triple<ElemType>[maxSize];		// Ϊ��Ԫ�����洢�ռ�
	for (int i = 0; i < num; i++)	// ������Ԫ��
		triElems[i] = copy.triElems[i];
}

template <class ElemType>
TriSparseMatrix<ElemType> &TriSparseMatrix<ElemType>::operator =(const TriSparseMatrix<ElemType> &copy)
// �����������ϡ�����copy��ֵ����ǰϡ����󡪡���ֵ���������
{
	if (&copy != this)	{
		maxSize = copy.maxSize;						// ������Ԫ�ظ���
		if (triElems != NULL) delete []triElems;	// �ͷŴ洢�ռ�
		triElems = new Triple<ElemType>[maxSize];	// ����洢�ռ�
		rows = copy.rows;							// ��������
		cols = copy.cols;							// ��������
		num = copy.num;								// ���Ʒ���Ԫ�ظ���

		for (int i = 0; i < num; i++)	// ������Ԫ��
			triElems[i] = copy.triElems[i];
	}
	return *this;
}

template<class ElemType>
void TriSparseMatrix<ElemType>::SimpleTranspose(TriSparseMatrix<ElemType> &b)
// ���������ϡ�����ļ�ת���㷨�����������Ԫ��˳���b�� 
{
	b.rows = cols;
	b.cols = rows;
	b.num = num;
	b.maxSize = maxSize;
	delete []b.triElems;
	b.triElems = new Triple<ElemType>[b.maxSize];

	if (b.num > 0)	{
		int i = 0;						// ϡ�����b����һ����Ԫ��Ĵ��λ��
		for (int col = 0; col < cols; col++)	
			for (int j = 0; j < num; j++)	// ����a�����е�col�е���Ԫ��
				if (triElems[j].col == col)	{
					b.triElems[i].row = triElems[j].col;
					b.triElems[i].col = triElems[j].row;
					b.triElems[i].value = triElems[j].value;
					i++;							
				}
	}
}

template<class ElemType>
void TriSparseMatrix<ElemType>::FastTranspose(TriSparseMatrix<ElemType> &b)
// ���������ϡ�����Ŀ���ת���㷨�����������Ԫ��˳���b�� 
{
	b.rows = cols;
	b.cols = rows;
	b.num = num;
	b.maxSize = maxSize;
	delete []b.triElems;
	b.triElems = new Triple<ElemType>[b.maxSize];

	int *cNum = new int[cols + 1];	// ���ԭ������ÿһ�еķ���Ԫ����
	int *cPos = new int[cols + 1];	// ���ԭ������ÿһ�еĵ�һ������Ԫ��b�еĴ洢λ��
	int col;
	int i;			        

	if (b.num > 0)	{
		for (col = 0; col < cols; col++) cNum[col] = 0;	// ��ʼ��cNum
		for (i = 0; i < num; i++)
			++cNum[triElems[i].col];		// ͳ��ԭ������ÿһ�еķ���Ԫ����
		cPos[0] = 0;						// ��һ�еĵ�һ������Ԫ��b�洢����ʼλ��
		for (col = 1; col < cols; col++)	// ѭ����ÿһ�еĵ�һ������Ԫ��b�洢����ʼλ��
			cPos[col] = cPos[col - 1] + cNum[col - 1];	

		for (i = 0; i < num; i++){	// ѭ������ԭ�������Ԫ��
			int j = cPos[triElems[i].col];	
				// ���ڱ�ʾb��ǰ�е���һ������Ԫ��Ԫ��Ĵ洢λ��
			b.triElems[j].row = triElems[i].col;
			b.triElems[j].col = triElems[i].row;
			b.triElems[j].value = triElems[i].value;
			++cPos[triElems[i].col];				
				// b��ǰ�е���һ������Ԫ��Ԫ��Ĵ洢��λ��
		}
	}

	delete []cNum;	
	delete []cPos;	
}


#endif
