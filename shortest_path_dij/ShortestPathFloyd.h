#ifndef __SHORTEST_PATH_FLOYD_H__
#define __SHORTEST_PATH_FLOYD_H__

#include "AdjListDirNetwork.h"			// �ڽӱ�������
#include "LinkStack.h"					// ջ

template <class ElemType, class WeightType>
void ShortestPathFloyd(const AdjListDirNetwork<ElemType, WeightType> &g, int **path, 
	WeightType **dist)
// �������: ��Floyd�㷨��������g�и��Զ���u��v֮������·��path[u][v]��·������
//	dist[u][v],path[u][v]�洢��u��v�����·�������˶����ǰһ����Ķ����,dist[u][v]
//	�洢��u��v�����·���ĳ���
{
	for (int u = 0; u < g.GetVexNum(); u++)
		for (int v = 0; v < g.GetVexNum(); v++)
		{	// ��ʼ��path��dist
			dist[u][v] = (u != v) ? g.GetWeight(u, v) : 0;
			if (u != v && dist[u][v] < g.GetInfinity())
               path[u][v] = u;	// ���ڱ�<u,v>
			else
               path[u][v] = -1;											// �����ڱ�<u,v>
		}

	for (int k = 0; k < g.GetVexNum(); k++)
		for (int i = 0; i < g.GetVexNum(); i++)
			for (int j = 0; j < g.GetVexNum(); j++)
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					// ��i��k�ٵ�j��·�����ȸ���
					dist[i][j] = dist[i][k] + dist[k][j]; 
					path[i][j] = path[k][j];
				}
}

template <class ElemType, class WeightType>
void DisplayPathAndDist(const AdjListDirNetwork<ElemType, WeightType> &g, int **path, WeightType **dist)
{
    ElemType e1, e2;
	for (int v1 = 0; v1 < g.GetVexNum(); v1++)
		for (int v2 = 0; v2 < g.GetVexNum(); v2++)   
            if (v1 != v2) {
			   cout << endl;
			   g.GetElem(v1, e1);
		       g.GetElem(v2, e2);
			   if (dist[v1][v2] < g.GetInfinity() )	{	// ���ڴ�v1��v2���·��
				  cout << "�� " << e1 << " �� " << e2 << ":";
			      cout << " ·������ = " << dist[v1][v2];
				  cout << " ·����";
				  LinkStack<int> s;	// �洢·�ϵĶ���
				  int v = v2;
				  while (v != v1)	{
					 s.Push(v);	// vΪ·���ϵĶ���
					 v = path[v1][v];// ȡ��·���ϵ�ǰһ������
				  }
				  s.Push(v1);		// v��·������ʼ��
				  while (!s.IsEmpty())		{	// ���·�ϵĶ���
					 s.Pop(v);
			         g.GetElem(v, e1);	
					 cout << e1 << " ";
				  }
			  }
			  else 	{	// ��v1��v2��·��
				 cout << "from " << e1 << " to " << e2 << ":";
				 cout << " dist = ��";	 
			  }
		  }
	cout << endl;
}

#endif

