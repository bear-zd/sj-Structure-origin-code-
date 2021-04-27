#ifndef __SHORTEST_PATH_FLOYD_H__
#define __SHORTEST_PATH_FLOYD_H__

#include "AdjListDirNetwork.h"			// 邻接表有向网
#include "LinkStack.h"					// 栈

template <class ElemType , class WeightType>
void ShortestPathDij(const AdjListDirNetwork<ElemType,WeightType> &g,int v0,int *path , WeightType *dist)
{
    WeightType minVal, infinity = g.GetInfinity(); //初始化值
    int v,u;
    for ( v = 0 ; v < g.GetVexNum() ; v++)  //第一次，初始化所有结点与v0的距离
    {
        dist[v] = g.GetWeight(v0,v);
        if (dist[v] == infinity)
            path[v] = -1;
        else
            path[v] = v0;
        g.SetTag(v , UNVISITED);
    }
    g.SetTag(v0,VISITED);
    for (int i = 1 ; i < g.GetVexNum() ; i++ ) //寻找最短路径
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
			   if (dist[v1] < g.GetInfinity() )	{	// 存在从v1到v2最短路径
				  cout << "从 " << e1 << " 到 " << e2 << ":";
			      cout << " 路径长度 = " << dist[v1];
				  cout << " 路径：";
				  LinkStack<int> s;	// 存储路上的顶点
				  int v = v1;
				  while (v != v0)	{
					 s.Push(v);	// v为路径上的顶点
					 v = path[v];// 取上路径上的前一个顶点
				  }
				  s.Push(v0);		// v是路径上起始点
				  while (!s.IsEmpty())		{	// 输出路上的顶点
					 s.Pop(v);
			         g.GetElem(v, e1);
					 cout << e1 << " ";
				  }
			  }
			  else 	{	// 从v1到v2无路径
				 cout << "从 " << e1 << " 到 " << e2 << ":";
				 cout << " 路径长度 = ∞";
			  }
		  }
	cout << endl;
}

#endif

