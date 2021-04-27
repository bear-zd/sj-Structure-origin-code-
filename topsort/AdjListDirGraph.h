#ifndef ADJLISTDIRGRAPH_H
#define ADJLISTDIRGRAPH_H
#include "Assistance.h"
#include "AdjListDirGraphArc.h"
#include "AdjListDirGraphVex.h"

template <class ElemType>
class AdjListDirGraph
{
protected:
    int vexNum,vexMaxNum,arcNum;
    AdjListGraphVex <ElemType> *vexTable ;
    mutable Status *tags ;
public:
    AdjListDirGraph (ElemType tb[],int vertexNum, int vertexMaxNum = DEFAULT_SIZE);
    ~AdjListDirGraph();
    AdjListDirGraph(const AdjListDirGraph<ElemType> &g);
    Status GetTag(int v) const;
	void SetTag(int v, Status tag) ;
    int GetVexNum() const ;
    int GetArcNum() const ;
    Status GetElem(int v, ElemType &e) const;
	Status SetElem(int v, const ElemType &e);
	int FirstAdjVex(int v) const;
	int NextAdjVex(int v1, int v2) const;
	void Display() const ;
	void Clear();
	void InsertArc(int v1, int v2);
};
template <class ElemType>
AdjListDirGraph<ElemType> :: AdjListDirGraph(ElemType tb[],int vertexNum, int vertexMaxNum) //构造函数
{
	if (vertexMaxNum < 0)
    	throw Error("允许的顶点最大数目不能为负!");        // 抛出异常

	if (vertexMaxNum < vertexNum)
    	throw Error("顶点数目不能大于允许的顶点最大数目!");// 抛出异常

	vexNum = vertexNum;
	vexMaxNum = vertexMaxNum;
	arcNum = 0;

	tags = new Status[vexMaxNum];
	vexTable = new AdjListGraphVex<ElemType>[vexMaxNum];

	for (int v = 0; v < vexNum; v++)  {
		tags[v] = UNVISITED;
		vexTable[v].data = tb[v];
		vexTable[v].firstarc = NULL;
	}
}

template <class ElemType>
AdjListDirGraph<ElemType> :: ~AdjListDirGraph() //析构函数
{
    Clear();
    delete []tags;
    delete []vexTable;
}
template <class ElemType>
void AdjListDirGraph<ElemType> :: Clear()
{
        	AdjListGraphArc *p;
	for (int v = 0; v < vexNum; v++)	{	// 释放边结点
	    p = vexTable[v].firstarc;
	    while (p != NULL) {
			vexTable[v].firstarc = p->nextArc;
			delete p;
			p = vexTable[v].firstarc;
        }
	}
    vexNum = 0;
	arcNum = 0;
}

template <class ElemType>
AdjListDirGraph<ElemType> :: AdjListDirGraph(const AdjListDirGraph<ElemType> &g) //拷贝构造函数
{
	AdjListGraphArc *p, *q;
	vexNum = g.vexNum;
	vexMaxNum = g.vexMaxNum;
	arcNum = g.arcNum;

	tags = new Status[vexMaxNum];
	vexTable = new AdjListGraphVex<ElemType>[vexMaxNum];
	for (int v = 0; v < vexNum; v++)	{
		tags[v] = g.tags[v];
		vexTable[v].data = g.vexTable[v].data;
		vexTable[v].firstarc = NULL;
		p = g.vexTable[v].firstarc;
		while (p != NULL)
           if (vexTable[v].firstarc == NULL) {
              vexTable[v].firstarc = new AdjListGraphArc(p->adjVex);
              q = vexTable[v].firstarc;
              p = p->nextArc;
           }
           else {
              q->nextArc = new AdjListGraphArc(p->adjVex);
              q = q->nextArc;
              p = p->nextArc;
           }
	}
}
template <class ElemType>
Status AdjListDirGraph<ElemType> :: GetTag(int v) const
{
    if (v < 0 || v > vexMaxNum)
        throw Error("错误的顶点数！");
    else
        return tags[v];
}
template <class ElemType>
void AdjListDirGraph<ElemType> :: SetTag(int v ,Status tag)
{
  if (v < 0 || v > vexMaxNum)
        throw Error("错误的顶点数！");
    else
        return tags[v]=tag;
}

template <class ElemType>
int AdjListDirGraph<ElemType> :: GetArcNum() const
{
    return arcNum ;
}

template <class ElemType>
int AdjListDirGraph<ElemType> :: GetVexNum() const
{
    return vexNum ;
}

template <class ElemType>
Status AdjListDirGraph<ElemType> :: GetElem(int v, ElemType &e) const
{
    if (v < 0 || v >= vexNum )
        return NOT_PRESENT;
    else
    {
        e = vexTable[v].data;
        return SUCCESS;
    }
}

template <class ElemType>
Status AdjListDirGraph<ElemType> :: SetElem(int v,const ElemType &e)
{
    if (v < 0 || v >= vexNum)
        return NOT_PRESENT;
    else
    {
        vexTable = e;
        return SUCCESS;
    }
 }

template <class ElemType>
int AdjListDirGraph<ElemType>::FirstAdjVex(int v) const
// 操作结果：返回顶点v的第一个邻接点
{
	if (v < 0 || v >= vexNum)
       throw Error("v不合法!");// 抛出异常

	if (vexTable[v].firstarc == NULL)
	   return -1;              // 不存在邻接点
	else
	   return vexTable[v].firstarc->adjVex;
}

template <class ElemType>
int AdjListDirGraph<ElemType>::NextAdjVex(int v1, int v2) const
// 操作结果：返回顶点v1的相对于v2的下一个邻接点
{
	AdjListGraphArc *p;
	if (v1 < 0 || v1 >= vexNum)
       throw Error("v1不合法!");	// 抛出异常
	if (v2 < 0 || v2 >= vexNum)
       throw Error("v2不合法!");	// 抛出异常
	if (v1 == v2)
       throw Error("v1不能等于v2!");// 抛出异常

	p = vexTable[v1].firstarc;
	while (p != NULL && p->adjVex != v2)
	    p = p->nextArc;

	if (p == NULL || p->nextArc == NULL)
		return -1;                   // 不存在下一个邻接点
	else
		return p->nextArc->adjVex;
}

template <class ElemType>
void AdjListDirGraph<ElemType>::Display() const
// 操作结果: 显示邻接矩阵有向图
{
	AdjListGraphArc *p;
    cout << "有向图共有" << vexNum << "个顶点，" << arcNum << "条边。" << endl;
	for (int v = 0; v < vexNum; v++)	{	// 显示第v个邻接链表
		cout << v << ":\t" << vexTable[v].data;				// 显示顶点号
	    p = vexTable[v].firstarc;
	    while (p != NULL) {
        	cout << "-->(" << p->adjVex << ")";
            p = p->nextArc;
		}
		cout << endl;
	}
}
template <class ElemType>
void AdjListDirGraph<ElemType>::InsertArc(int v1, int v2)
// 操作结果：插入顶点为v1和v2,权为w的边
{
	if (v1 < 0 || v1 >= vexNum)
       throw Error("v1不合法!");	// 抛出异常
	if (v2 < 0 || v2 >= vexNum)
       throw Error("v2不合法!");	// 抛出异常
	if (v1 == v2)
       throw Error("v1不能等于v2!");// 抛出异常

	AdjListGraphArc *p, *q;
	p = vexTable[v1].firstarc;
	while (p != NULL && p->adjVex != v2) {
		q = p;
		p = p->nextArc;
	}
	if (p == NULL) {
		if (vexTable[v1].firstarc == NULL)
    		vexTable[v1].firstarc = new AdjListGraphArc(v2);
    	else
    		q->nextArc = new AdjListGraphArc(v2);
    			arcNum++;
	}
    else
       throw Error("这条边已经存在!");// 抛出异常
}



#endif // ADJLISTDIRGRAPH_H
