#ifndef __TOPSORT_H__
#define __TOPSORT_H__

#include "LinkQueue.h"						// ����
#include "LinkStack.h"						// ջ
#include "AdjListDirNetwork.h"			// �ڽӾ���������

template <class ElemType, class WeightType>
void StatIndegree(const AdjListDirNetwork<ElemType, WeightType> &g, int *indegree)
// ���������ͳ����g����������
{
	for (int v = 0; v < g.GetVexNum(); v++)
		indegree[v] = 0;	             // ��ʼ������������Ϊ0

	for (int v = 0; v < g.GetVexNum(); v++)
		for (int u = g.FirstAdjVex(v); u != -1; u = g.NextAdjVex(v, u))
			indegree[u]++;              // uΪ��<v,u>�Ļ�ͷ����
}

template <class ElemType, class WeightType>
Status CriticalPath(const AdjListDirNetwork<ElemType, WeightType> &g)
// ��ʼ����������������g
// �����������g�޻�·,�����g�Ĺؼ��,������SUCCESS,���򷵻�FAIL
{
	int *indegree = new int[g.GetVexNum()];	// �����������
	WeightType *ve = new int[g.GetVexNum()];	// �¼����緢��ʱ������
	WeightType *vl = new int[g.GetVexNum()];  // �¼���ٷ���ʱ������
	WeightType *ae = new int[g.GetArcNum()]; // ����緢��ʱ������
	WeightType *al = new int[g.GetArcNum()]; // ���ٷ���ʱ������
	LinkQueue<int> q;					// ���ڴ洢���Ϊ0�Ķ���
	LinkStack<int> s;					// ����ʵ�����������е�ջ
	int ee, el, u, v, count = 0;
	ElemType e1, e2;

	for (v = 0; v < g.GetVexNum(); v++) 	// ��ʼ���¼����緢��ʱ��
		ve[v] = 0;
	StatIndegree(g, indegree);				// ͳ�ƶ�������
	for (v = 0; v < g.GetVexNum(); v++)	// ��������
		if (indegree[v] == 0)	// �������Ϊ0�Ķ������
			q.EnQueue(v);

	while (!q.IsEmpty())	{	// ���зǿ�
		q.DelQueue(u);			// ȡ��һ�����Ϊ0�Ķ���
		s.Push(u);				// ����u��ջ,�Ա����������������
		count++;				// �Զ�����м���
		for (v = g.FirstAdjVex(u); v != -1; v = g.NextAdjVex(u, v))		{
            // vΪ��<u,v>�Ļ�ͷ����,��u��ÿ���ڽӵ���ȼ�1
			if (--indegree[v] == 0)	// v���Ϊ0,��v���
				q.EnQueue(v);
			if (ve[u] + g.GetWeight(u, v) > ve[v])	// �޸�ve[v]
				ve[v] = ve[u] + g.GetWeight(u, v);
		}
	}
	delete []indegree;			// �ͷ�indegree��ռ�õĴ洢�ռ�

	if (count < g.GetVexNum()) 	{
		delete []ve;			// �ͷ�ve��ռ�õĴ洢�ռ�
		return FAIL;			// ��g�л�·
	}

	s.Top(u);								// ȡ��ջ��,ջ��Ϊ���
	for (v = 0; v < g.GetVexNum(); v++) 	// ��ʼ���¼���ٷ���ʱ��
		vl[v] = ve[u];

	while (!s.IsEmpty())      {	// s�ǿ�
		s.Pop(u);
		for (v = g.FirstAdjVex(u); v != -1; v = g.NextAdjVex(u, v))	// vΪu��һ���ڽӵ�
			if (vl[v] - g.GetWeight(u, v) < vl[u])	// �޸�vl[u]
				vl[u] = vl[v] - g.GetWeight(u, v);
	}


	for (u = 0; u < g.GetVexNum(); u++)	{	// ��ee, el�͹ؼ�·��
		for (v = g.FirstAdjVex(u); v != -1; v = g.NextAdjVex(u, v))		{	// vΪu��һ���ڽӵ�
			ee = ve[u]; el = vl[v] - g.GetWeight(u, v);
			if (ee == el)	{	// <u, v>Ϊ�ؼ��
				g.GetElem(u, e1);
				g.GetElem(v, e2);
				cout << "<" << e1 << "," << e2 << "> ";
			}
		}
	}
	int i=0;
	for (u = 0; u < g.GetVexNum(); u++)	{	// ��ee, el�͹ؼ�·��
		for (v = g.FirstAdjVex(u); v != -1; v = g.NextAdjVex(u, v))
            {ae[i] = ve[u] ;i++;}}
    i=0 ;
    for (u = 0;u <g.GetVexNum(); u++)
    {
        for (v = g.FirstAdjVex(u); v != -1; v = g.NextAdjVex(u, v))
            {
                al[i] = vl[v] - g.GetWeight(u, v); i++;
            }
    }




	cout<<endl;
	cout << "Po :";
	for (int i=0 ; i < g.GetVexNum() ; i++)
        cout<<setw(4)<<i<<"  ";
    cout<<endl;
	cout << "ve :";
	for (int i=0 ; i < g.GetVexNum() ; i++)
        cout<<setw(4)<<ve[i]<<"  ";
    cout<<endl;
    cout << "vl :";
	for (int i=0 ; i < g.GetVexNum() ; i++)
        cout<<setw(4)<<vl[i]<<"  ";

    cout<<endl;
	cout << "ae :";
	for (int i=0 ; i < g.GetArcNum() ; i++)
        cout<<setw(4)<<ae[i]<<"  ";
    cout<<endl;
    cout << "al :";
	for (int i=0 ; i < g.GetArcNum() ; i++)
        cout<<setw(4)<<al[i]<<"  ";
	delete []ve;				// �ͷ�ve��ռ�õĴ洢�ռ�
	delete []vl;				// �ͷ�vl��ռ�õĴ洢�ռ�
	return SUCCESS;				// �����ɹ�
}

#endif

