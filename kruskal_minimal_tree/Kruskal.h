#ifndef __KRUSKAL_H__
#define __KRUSKAL_H__
#include "AdjMatrixUndirNetwork.h"		// �ڽӱ�������
#include "UFSets.h"		                // ������
#include "MineHeap.h"

// Kruskal����
template <class ElemType, class WeightType>
class KruskalEdge
{
public:
	ElemType vertex1, vertex2;		// �ߵĶ���
	WeightType weight;				// �ߵ�Ȩֵ
	KruskalEdge(ElemType v1, ElemType v2, WeightType w);	// ���캯��
	KruskalEdge(){};	            // ���캯��
	KruskalEdge<ElemType, WeightType> &operator =(const KruskalEdge<ElemType, WeightType> &Ed); // ��ֵ�������
	bool operator <=(const KruskalEdge<ElemType, WeightType> &Ed);		// ����<=��ϵ���� 
	bool operator >(const KruskalEdge<ElemType, WeightType> &Ed);		// ����>��ϵ����
};

template <class ElemType, class WeightType>
KruskalEdge<ElemType, WeightType>::KruskalEdge(ElemType v1, ElemType v2, WeightType w)
// �������: �ɶ���v1��v2��Ȩw����ߡ������캯��
{	// ���캯��
	vertex1 = v1;					// ����vertex1
	vertex2 = v2;					// ����vertex2
	weight = w;						// Ȩweight
}

template <class ElemType, class WeightType>
bool KruskalEdge<ElemType, WeightType>::operator <= (const KruskalEdge<ElemType, WeightType> &Ed)
// �������������<=��ϵ����
{
	return (weight <= Ed.weight);
}

template <class ElemType, class WeightType>
bool KruskalEdge<ElemType, WeightType>::operator > (const KruskalEdge<ElemType, WeightType> &Ed)
// �������������>��ϵ����
{
	return (weight > Ed.weight);
}


template<class ElemType,  class WeightType>
KruskalEdge<ElemType, WeightType> &KruskalEdge<ElemType, WeightType>::operator = (const KruskalEdge<ElemType, WeightType> &Ed)
// �����������ջcopy��ֵ����ǰջ--��ֵ�������
{
	if (&Ed != this)	{
	   vertex1 = Ed.vertex1;					// ����vertex1
	   vertex2 = Ed.vertex2;					// ����vertex2
	   weight = Ed.weight;						// Ȩweight
	}
	return *this;
}


template <class ElemType, class WeightType>
void MiniSpanTreeKruskal(const AdjMatrixUndirNetwork<ElemType, WeightType> &g)
// ��ʼ������������g
// �����������Kruskal�㷨������g����С����������
{
	int count, VexNum = g.GetVexNum();
    KruskalEdge<ElemType, WeightType> KEdge;
 	MinHeap<KruskalEdge<ElemType, WeightType> > ha(g.GetEdgeNum());
    ElemType  *kVex, v1, v2;
	kVex = new ElemType[VexNum];	// ���嶥������,�洢������Ϣ 
	for (int i = 0; i < VexNum; i++)
	    g.GetElem(i, kVex[i]);
	UFSets<ElemType> f(kVex,VexNum);// ���ݶ������鹹�첢�鼯 
	for (int v = 0; v < g.GetVexNum(); v++)
		for (int u = g.FirstAdjVex(v); u >= 0; u = g.NextAdjVex(v, u))
			if (v < u)			{	// ��v < u�ı߲��뵽��С�� 
                g.GetElem(v, v1); 
                g.GetElem(u, v2);
                KEdge.vertex1 = v1;
                KEdge.vertex2 = v2;
                KEdge.weight = g.GetWeight(v,u);
				ha.Insert(KEdge);
			}
	count = 0;					    // ��ʾ�Ѿ���ѡ�ı���

	while (count < VexNum - 1)	{	
        ha.DeleteTop(KEdge);        // �ӶѶ�ȡһ����
		v1 = KEdge.vertex1;
        v2 = KEdge.vertex2;
		if (f.Differ(v1, v2))	{	// ���������������㲻��ͬһ������
			cout << "��:( " << v1 << ", " << v2 << " ) Ȩ:" << KEdge.weight << endl ; // ����߼�Ȩֵ
			f.Union(v1, v2);		// �������������ڵ����ϲ���һ����
			count++;
		}
	}
}

#endif

