#ifndef __PRIM_H__
#define __PRIM_H__
#include "AdjMatrixUndirNetwork.h"	// �ڽӾ���������

template <class ElemType, class WeightType>
struct CloseArcType {
   WeightType lowweight;
   int nearvertex;
};

template <class ElemType, class WeightType>
void MiniSpanTreePrim(const AdjMatrixUndirNetwork<ElemType, WeightType> &g, int u0)
// ��ʼ������������g,u0Ϊg��һ������
// �����������Prim�㷨��u0����������g����С������
{
   WeightType min;
   ElemType v1, v2;
   int vexnum = g.GetVexNum();
   CloseArcType<ElemType, WeightType> * closearc;

   if (u0 < 0 || u0 >= vexnum)
      throw Error("����u0������!"); // �׳��쳣

	int u, v, k;						// ��ʾ�������ʱ���� 
	closearc = new CloseArcType<ElemType, WeightType>[vexnum];	// ����洢�ռ�
	for (v = 0; v < vexnum; v++)	{	// ��ʼ����������adjVex�����Զ�������־����ʱU = {v0}
		closearc[v].nearvertex = u0;
		closearc[v].lowweight = g.GetWeight(u0, v);
	}
	closearc[u0].nearvertex = -1;
	closearc[u0].lowweight = 0;
	
	for (k = 1; k < vexnum; k++) {	// ѡ��������������g.GetVexNum() - 1������
		min = g.GetInfinity();
        v = u0;// ѡ��ʹ�ñ�<w, adjVex[w]>Ϊ����V-U��U�ľ�����СȨֵ�ı�
		for (u = 0; u < vexnum; u++)
           if (closearc[u].lowweight != 0 && closearc[u].lowweight < min) {
			  v = u;
              min = closearc[u].lowweight;
	       }
 	    if (v != u0) {
           g.GetElem(closearc[v].nearvertex, v1);
           g.GetElem(v, v2);     
		   cout << "��:( " << v1 << ", " <<  v2 << " ) Ȩ:" << min << endl ; // ����߼�Ȩֵ
		   closearc[v].lowweight = 0;		// ��w����U
		   for (u = g.FirstAdjVex(v); u != -1 ; u = g.NextAdjVex(v, u)) 	// �¶��㲢��U������ѡ����С��
			  if (closearc[u].lowweight != 0 && (g.GetWeight(v, u) < closearc[u].lowweight))	{	// <v, w>Ϊ�µ���С��
				closearc[u].lowweight = g.GetWeight(v, u);
				closearc[u].nearvertex = v;
			  }
		}
		
	}
	delete []closearc;			// �ͷŴ洢�ռ�  
}

#endif

