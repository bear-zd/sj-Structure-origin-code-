#ifndef __SHORTEST_PATH_FLOYD_H__
#define __SHORTEST_PATH_FLOYD_H__

#include "AdjListDirNetwork.h"			// �ڽӱ�������
#include "LinkStack.h"					// ջ

template <class ElemType , class WeightType>
void ShortestPathDij(const AdjListDirNetwork<ElemType,WeightType> &g,int v0,int *path , WeightType *dist)
{
    WeightType minVal, infinity = g.GetInfinity(); //��ʼ��ֵ
    int v,u;
    for ( v = 0 ; v < g.GetVexNum() ; v++)  //��һ�Σ���ʼ�����н����v0�ľ���
    {
        dist[v] = g.GetWeight(v0,v);
        if (dist[v] == infinity)
            path[v] = -1;
        else
            path[v] = v0;
        g.SetTag(v , UNVISITED);
    }
    g.SetTag(v0,VISITED);
    for (int i = 1 ; i < g.GetVexNum() ; i++ ) //Ѱ�����·��
    {
        minVal = infinity ;
        u = v0;
        for (v = 0 ; v<g.GetVexNum() ; v++)
            if (g.GetTag(v) == UNVISITED && dist[v] < minVal )
                {
                    u = v;
                    minVal = dist[v];
                }
        g.SetTag( u , VISITED );
        for (v = g.FirstAdjVex(u) ; v != -1; v = g.NextAdjVex(u ,v))
            if (g.GetTag(v) == UNVISITED && minVal + g.GetWeight(u,v)<dist[v])
                {
                    dist[v] = minVal + g.GetWeight(u,v);
                    path[v] = u;
                }
    }
}

template <class ElemType, class WeightType>
void DisplayPathAndDist(const AdjListDirNetwork<ElemType, WeightType> &g, int v0 , int *path, WeightType *dist)
{
    ElemType e1, e2;
	for (int v1 = 0; v1 < g.GetVexNum(); v1++)
            if (v1 != v0) {
			   cout << endl;
			   g.GetElem(v0, e1);
		       g.GetElem(v1, e2);
			   if (dist[v1] < g.GetInfinity() )	{	// ���ڴ�v1��v2���·��
				  cout << "�� " << e1 << " �� " << e2 << ":";
			      cout << " ·������ = " << dist[v1];
				  cout << " ·����";
				  LinkStack<int> s;	// �洢·�ϵĶ���
				  int v = v1;
				  while (v != v0)	{
					 s.Push(v);	// vΪ·���ϵĶ���
					 v = path[v];// ȡ��·���ϵ�ǰһ������
				  }
				  s.Push(v0);		// v��·������ʼ��
				  while (!s.IsEmpty())		{	// ���·�ϵĶ���
					 s.Pop(v);
			         g.GetElem(v, e1);
					 cout << e1 << " ";
				  }
			  }
			  else 	{	// ��v1��v2��·��
				 cout << "�� " << e1 << " �� " << e2 << ":";
				 cout << " ·������ = ��";
			  }
		  }
	cout << endl;
}

#endif

