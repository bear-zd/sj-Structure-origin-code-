#ifndef __ADJ_MATRIX_UNDIR_GRAPH_H__
#define __ADJ_MATRIX_UNDIR_GRAPH_H__
#include "Assistance.h"                 // ���������

// ����ͼ���ڽӾ�����
template <class ElemType, class WeightType>
class AdjMatrixUndirNetwork 
{
protected:
// �ڽӾ�������ݳ�Ա:
	int vexNum, vexMaxNum, edgeNum;		// ������Ŀ������Ķ��������Ŀ�ͱ���
	int **arcs;							// ��ű���Ϣ�ڽӾ���
	ElemType *vertexes;					// ��Ŷ�����Ϣ������ 
	Status *tag;						// ��־����
	WeightType infinity;				// �����

public:
// �ڽӾ������͵ķ�������:
	AdjMatrixUndirNetwork(ElemType es[], int vertexNum, int vertexMaxNum = DEFAULT_SIZE,
							WeightType infinit = (WeightType)DEFAULT_INFINITY);	
		// ������es[]Ϊ����,�������ΪvertexNum,����Ķ��������ĿΪvertexMaxNum,����Ϊ0������ͼ
	AdjMatrixUndirNetwork(int vertexMaxNum = DEFAULT_SIZE, WeightType infinit = (WeightType)DEFAULT_INFINITY);	
		// ��������Ķ��������ĿΪvertexMaxNum,����Ϊ0������ͼ
	~AdjMatrixUndirNetwork();			// ��������
	void Clear();			            // ���ͼ			 
	bool IsEmpty();                 // �ж�����ͼ�Ƿ�Ϊ�� 
	int GetOrder(ElemType &e) const;// �󶥵�����	
	Status GetElem(int v, ElemType &e) const;// �󶥵��Ԫ��ֵ	
	Status SetElem(int v, const ElemType &e);// ���ö����Ԫ��ֵ
	WeightType GetInfinity() const;				// ���������			 
	int GetVexNum() const;					// ���ض������			 
	int GetEdgeNum() const;					// ���ر���			 
	int FirstAdjVex(int v) const;		// ���ض���v�ĵ�һ���ڽӵ�			 
	int NextAdjVex(int v1, int v2) const;		 // ���ض���v1�������v2����һ���ڽӵ�			 
	void InsertVex(const ElemType &e);			 // ����Ԫ��ֵΪe�Ķ���		 
	void DeleteVex(const ElemType &e);			 // ɾ��Ԫ��ֵΪe�Ķ���			 
	void InsertArc(int v1, int v2, WeightType w);	// ���붥��Ϊv1��v2,ȨΪw�ı�			 
	void DeleteArc(int v1, int v2);			// ɾ������Ϊv1��v2�ı�			 
	WeightType GetWeight(int v1, int v2) const;	// ���ض���Ϊv1��v2�ıߵ�Ȩֵ
	Status GetTag(int v) const;			         // ���ض���v�ı�־		 
	void SetTag(int v, Status val) const;	   // ���ö���v�ı�־Ϊval		 
	AdjMatrixUndirNetwork(const AdjMatrixUndirNetwork<ElemType, WeightType> &g);	// ���ƹ��캯��
	AdjMatrixUndirNetwork<ElemType, WeightType> &operator =(const AdjMatrixUndirNetwork<ElemType, WeightType> &g); 
		// ��ֵ�������
  void Display();	                         // ��ʾ�ڽӾ�������ͼ
};

// ����ͼ���ڽӾ������ʵ�ֲ���
template <class ElemType, class WeightType>
AdjMatrixUndirNetwork<ElemType, WeightType>::AdjMatrixUndirNetwork(ElemType es[], int vertexNum, int vertexMaxNum, WeightType infinit)
// �����������������Ԫ��Ϊes[],�������ΪvertexNum,����Ķ��������ĿΪvertexMaxNum,����Ϊ0������ͼ
{
	if (vertexMaxNum < 0)
    	throw Error("����Ķ��������Ŀ����Ϊ��!");        // �׳��쳣

	if (vertexMaxNum < vertexNum)
    	throw Error("������Ŀ���ܴ�������Ķ��������Ŀ!");// �׳��쳣

	vexNum = vertexNum;			
	vexMaxNum = vertexMaxNum; 
	edgeNum = 0;	
	infinity = infinit;
	
	vertexes = new ElemType[vexMaxNum];     	// �������ɶ�����Ϣ����
	tag = new Status[vexMaxNum];			 	// ���ɱ�־����
	arcs = (int **)new int *[vexMaxNum];     	// �����ڽӾ���
	for (int v = 0; v < vexMaxNum; v++) 
		arcs[v] = new int[vexMaxNum];	

	for (int v = 0; v < vexNum; v++) {
		vertexes[v] = es[v];
		tag[v] = UNVISITED;
		for (int u = 0; u < vexNum; u++)
			arcs[v][u] = infinity;
		arcs[v][v] = 0;
	}
}

template <class ElemType, class WeightType>
AdjMatrixUndirNetwork<ElemType, WeightType>::AdjMatrixUndirNetwork(int vertexMaxNum, WeightType infinit)
// �������������������������ĿΪvertexMaxNum�Ŀ�����ͼ
{
	if (vertexMaxNum < 0)
    	throw Error("����Ķ��������Ŀ����Ϊ��!");// �׳��쳣

	vexNum = 0;			
	vexMaxNum = vertexMaxNum;
	edgeNum = 0;	
	infinity = infinit;

	vertexes = new ElemType[vexMaxNum];     // �������ɶ�����Ϣ����
	tag = new Status[vexMaxNum];			      // ���ɱ�־����
	arcs = (int **)new int *[vexMaxNum];    // �����ڽӾ���
	for (int v = 0; v < vexMaxNum; v++) 
		arcs[v] = new int[vexMaxNum];	
 }

template <class ElemType, class WeightType>
void AdjMatrixUndirNetwork<ElemType, WeightType>::Clear()
// ���������������ͼ�Ķ������ͱ�������Ϊ0.			 
{
    vexNum = 0;
	edgeNum = 0;	
}

template <class ElemType, class WeightType>
bool AdjMatrixUndirNetwork<ElemType, WeightType>::IsEmpty()
// ����������������ͼΪ�շ���true,���򷵻�false.
{
	return vexNum == 0;
}

template <class ElemType, class WeightType>
AdjMatrixUndirNetwork<ElemType, WeightType>::~AdjMatrixUndirNetwork()
// ����������ͷŶ�����ռ�õĿռ�
{
	delete []vertexes;					// �ͷŶ�������
	delete []tag;						    // �ͷű�־

	for (int v = 0; v < vexMaxNum; v++)	// �ͷ��ڽӾ������
		delete []arcs[v];
	delete []arcs;					    // �ͷ��ڽӾ���
}

template <class ElemType, class WeightType>
int AdjMatrixUndirNetwork<ElemType, WeightType>::GetOrder(ElemType &e) const
// ����������󶥵�e�����.�������Ŵ�0��ʼ��ͼ�в����ڶ���eʱ������-1. 
{
    for (int v = 0; v < vexNum; v++)
        if (vertexes[v] == e)
		   return v;	    // ����e����,����������� 
	return -1;	        // ����e������,����-1
}	

template <class ElemType, class WeightType>
Status AdjMatrixUndirNetwork<ElemType, WeightType>::GetElem(int v, ElemType &e) const
// ��������������Ϊv�Ķ���ֵ, v��ȡֵ��ΧΪ0 �� v �� vexNum, v�Ϸ�ʱ����
// ͨ��eȡ�ö���ֵ��������ENTRY_FOUND������������NOT_PRESENT
{
	if (v < 0 || v >= vexNum)
		return NOT_PRESENT;	// v��Χ��,����Ԫ�ز�����
	else	{
		e = vertexes[v];	  // ������v��Ԫ��ֵ����e
		return ENTRY_FOUND;	// ����Ԫ�ش���
	}
}	

template <class ElemType, class WeightType>
Status AdjMatrixUndirNetwork<ElemType, WeightType>::SetElem(int v, const ElemType &e)
// ������������ö����Ԫ��ֵv��ȡֵ��ΧΪ0 �� v �� vexNum, v�Ϸ�ʱ��������
//	SUCCESS, ����������RANGE_ERROR
{
	if (v < 0 || v >= vexNum)
		return RANGE_ERROR;	// v��Χ��,����λ�ô�
	else	{
		vertexes[v] = e;		// ������Ԫ�ص�ֵ��Ϊe 
		return SUCCESS;		  // �����޸ĳɹ�
	}
}

template <class ElemType, class WeightType>
WeightType AdjMatrixUndirNetwork<ElemType, WeightType>::GetInfinity() const
// ������������������
{
	return infinity;
}

template <class ElemType, class WeightType>
int AdjMatrixUndirNetwork<ElemType, WeightType>::GetVexNum() const
// ������������ض������			 
{
	return vexNum;
}

template <class ElemType, class WeightType>
int AdjMatrixUndirNetwork<ElemType, WeightType>::GetEdgeNum() const
// ������������ر���
{
	return edgeNum;
}		 

template <class ElemType, class WeightType>
int AdjMatrixUndirNetwork<ElemType, WeightType>::FirstAdjVex(int v) const
// ������������ض���v�ĵ�1���ڽӵ�����		 
{
	if (v < 0 || v >= vexNum)
       throw Error("v���Ϸ�!");// �׳��쳣

	for (int u = 0; u < vexNum; u++)
		if (arcs[v][u] != 0 && arcs[v][u] != infinity)
       		return u;

	return -1;					// ����-1��ʾ���ڽӵ�
}

template <class ElemType, class WeightType>
int AdjMatrixUndirNetwork<ElemType, WeightType>::NextAdjVex(int v1, int v2) const
// ������������ض���v1�������v2����һ���ڽӵ�			 
{
	if (v1 < 0 || v1 >= vexNum)
       throw Error("v1���Ϸ�!");	// �׳��쳣
	if (v2 < 0 || v2 >= vexNum)
       throw Error("v2���Ϸ�!");	// �׳��쳣
	if (v1 == v2) throw
       Error("v1���ܵ���v2!");		// �׳��쳣

	for (int u = v2 + 1; u < vexNum; u++)
		if (arcs[v1][u] != 0 && arcs[v1][u] != infinity)
       		return u;

	return -1;						// ����-1��ʾ����һ���ڽӵ�
}

template <class ElemType, class WeightType>
void AdjMatrixUndirNetwork<ElemType, WeightType>::InsertVex(const ElemType &e)
// ������������붥��e			 
{
	if (vexNum == vexMaxNum)
    throw Error("ͼ�Ķ��������ܳ�������������!");	// �׳��쳣

	vertexes[vexNum] = e;
	tag[vexNum] = UNVISITED;
	
	for (int v = 0; v < vexNum; v++) {
		arcs[vexNum][v] = infinity;
		arcs[v][vexNum] = infinity;
  	}
  	arcs[vexNum][vexNum] = 0;
  	vexNum++;
}

template <class ElemType, class WeightType>
void AdjMatrixUndirNetwork<ElemType, WeightType>::InsertArc(int v1, int v2, WeightType w)
// ���������������������v1��v2�ı�			 
{
	if (v1 < 0 || v1 >= vexNum)
    throw Error("v1���Ϸ�!");	// �׳��쳣
	if (v2 < 0 || v2 >= vexNum)
    throw Error("v2���Ϸ�!");	// �׳��쳣
	if (v1 == v2)
    throw Error("v1���ܵ���v2!");// �׳��쳣

	if (arcs[v1][v2] == infinity)	{	  // ԭ����ͼ��û�б�(v1, v2) 
	   edgeNum++;
	   arcs[v1][v2] = w;	
       arcs[v2][v1] = w;
    }
}

template <class ElemType, class WeightType>
void AdjMatrixUndirNetwork<ElemType, WeightType>::DeleteVex(const ElemType &e)
// ���������ɾ��Ԫ��Ϊe�Ķ���			 
{
   int v;
   for (v = 0; v < vexNum; v++)
     if	(vertexes[v] == e)
        break;
   if (v == vexNum)
      throw Error("ͼ�в�����Ҫɾ���Ķ���!");	// �׳��쳣

   for (int u = 0; u < vexNum; u++)             // ɾ���붥��e������ı� 
	  if (u != v && arcs[v][u] != infinity) { 
		edgeNum--;
	    arcs[v][u] = infinity;	
        arcs[u][v] = infinity;	
    } 
	      
   vexNum--; 
   if (v < vexNum) {
      vertexes[v] = vertexes[vexNum];
	  tag[v] = tag[vexNum];
	  for (int u = 0; u <= vexNum; u++) 
		 arcs[v][u] = arcs[vexNum][u];
	  for (int u = 0; u <= vexNum; u++) 
         arcs[u][v] = arcs[u][vexNum];
   } 
}

template <class ElemType, class WeightType>
void AdjMatrixUndirNetwork<ElemType, WeightType>::DeleteArc(int v1, int v2)
// ���������ɾ����������v1��v2�ı�			 
{
	if (v1 < 0 || v1 >= vexNum)
    throw Error("v1���Ϸ�!");	// �׳��쳣
	if (v2 < 0 || v2 >= vexNum)
    throw Error("v2���Ϸ�!");	// �׳��쳣
	if (v1 == v2)
    throw Error("v1���ܵ���v2!");// �׳��쳣

	if (arcs[v1][v2] != infinity)	{	// ԭ����ͼ���ڱ�(v1, v2)
		edgeNum--;
	    arcs[v1][v2] = infinity;	
        arcs[v2][v1] = infinity;	
    } 
}

template <class ElemType, class WeightType>
WeightType AdjMatrixUndirNetwork<ElemType, WeightType>::GetWeight(int v1, int v2) const
// ������������ض���Ϊv1��v2�ıߵ�Ȩֵ
{
	if (v1 < 0 || v1 >= vexNum) throw Error("v1���Ϸ�!");	// �׳��쳣
	if (v2 < 0 || v2 >= vexNum) throw Error("v2���Ϸ�!");	// �׳��쳣

	return arcs[v1][v2];
}

template <class ElemType, class WeightType>
Status AdjMatrixUndirNetwork<ElemType, WeightType>::GetTag(int v) const
// ������������ض���v�ı�־		 
{
	if (v < 0 || v >= vexNum)
    throw Error("v���Ϸ�!");	// �׳��쳣

	return tag[v];
}

template <class ElemType, class WeightType>
void AdjMatrixUndirNetwork<ElemType, WeightType>::SetTag(int v, Status val) const 
// ������������ö���v�ı�־Ϊval		 
{
	if (v < 0 || v >= vexNum)
    throw Error("v���Ϸ�!");	// �׳��쳣

	tag[v] = val;
}

template <class ElemType, class WeightType>
AdjMatrixUndirNetwork<ElemType, WeightType>::AdjMatrixUndirNetwork(const AdjMatrixUndirNetwork<ElemType, WeightType> &g)
// ���������������ͼ���ڽӾ���g����������ͼ���ڽӾ���g�������ƹ��캯��
{
	vexNum = g.vexNum;	
	vexMaxNum = g.vexMaxNum;
	edgeNum = g.edgeNum;	
	infinity = g.infinity;
	
	vertexes = new ElemType[vexMaxNum];		// ���ɶ�����������
	tag = new Status[vexMaxNum];			// ���ɱ�־����
	arcs = (int **)new int *[vexMaxNum];	// �����ڽӾ���
	for (int v = 0; v < vexMaxNum; v++) 
		arcs[v] = new int[vexMaxNum];	

	for (int v = 0; v < vexNum; v++)	{	// ���ƶ�����������
		vertexes[v] = g.vertexes[v];
		tag[v] = g.tag[v];
		for (int u = 0; u < vexNum; u++)
			arcs[v][u] = g.arcs[v][u];
	}
}

template <class ElemType, class WeightType>
AdjMatrixUndirNetwork<ElemType, WeightType> &AdjMatrixUndirNetwork<ElemType, WeightType>::operator =(const AdjMatrixUndirNetwork<ElemType, WeightType> &g)
// ���������������ͼ���ڽӾ���g��ֵ����ǰ����ͼ���ڽӾ��󡪡���ֵ�������
{
	if (&g != this)	{
		delete []vertexes;				// �ͷŶ�������
		delete []tag;						  // �ͷű�־

	  	for (int v = 0; v < vexMaxNum; v++)	// �ͷ��ڽӾ������
	 		delete []arcs[v];
    	delete []arcs;					  // �ͷ��ڽӾ���
		vexNum = g.vexNum;	
    	vexMaxNum = g.vexMaxNum;
		edgeNum = g.edgeNum;	
		infinity = g.infinity;
	
		vertexes = new ElemType[vexMaxNum];	 // ���ɶ�����������
		tag = new Status[vexMaxNum];			   // ���ɱ�־����
		arcs = (int **)new int *[vexMaxNum]; // �����ڽӾ���
		for (int v = 0; v < vexMaxNum; v++) 
			arcs[v] = new int[vexMaxNum];	

		for (int v = 0; v < vexNum; v++)	{	 // ���ƶ�����������
			vertexes[v] = g.vertexes[v];
			tag[v] = g.tag[v];
			for (int u = 0; u < vexNum; u++)
	    		arcs[v][u] = g.arcs[v][u];
		}
	}
	return *this;
}

template <class ElemType, class WeightType>
void AdjMatrixUndirNetwork<ElemType, WeightType>::Display()
// �������: ��ʾ�ڽӾ�������ͼ
{
              
	for (int v = 0; v < vexNum; v++)
 		cout << "\t" << vertexes[v];
	cout << endl;

	for (int v = 0; v < vexNum; v++)	{
		cout << vertexes[v];
		for (int u = 0; u < vexNum; u++)
			if (arcs[v][u] == infinity)
				cout << "\t" << "��";
			else
				cout << "\t" << arcs[v][u];
		cout << endl;
	}
}

#endif
