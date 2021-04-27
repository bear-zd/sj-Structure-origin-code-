#include "ShortestPathFloyd.h"		// ���������㷨

int main(void)
{
    try									// ��try��װ���ܳ����쳣�Ĵ���
	{
		int infity = DEFAULT_INFINITY;
		char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F'};
		int m[6][6] = {
			{infity,	  12,		  3,      infity,	   9,		 10},
			{    12,  infity,	 infity,          2,       6,    infity},
			{     3,  infity,    infity,          2,  infity,         6},
			{infity,       2,         2,     infity,       4,         7},
			{     9,       6,	 infity,          4,  infity,         4},
			{    10,  infity,         6,          7,       4,    infity}
		};
		int n = 6;

		AdjListDirNetwork<char, int> net(vexs, n);

		for (int u = 0; u < n; u++)
			for (int v = n-1; v >=0; v--)
				if (m[u][v] != infity) net.InsertArc(u, v, m[u][v]);

		cout << "ԭ��:" << endl;
		net.Display();					// ��ʾ��net
		cout << endl;
		system("PAUSE");				// ���ÿ⺯��system()

		int **dist, **path;
		// ����洢�ռ�
		dist = new int *[net.GetVexNum()], path = new int *[net.GetVexNum()];
		for (int i = 0; i < net.GetVexNum(); i++)	{	
			dist[i] = new int[net.GetVexNum()]; 
            path[i] = new int[net.GetVexNum()]; 
		}

		ShortestPathFloyd(net, path, dist);	// ��Floyd�㷨�����·��
		DisplayPathAndDist(net, path, dist);// ��ʾ���·�� 
		cout << endl << endl;

		// �ͷŴ洢�ռ�
		for (int j = 0; j < net.GetVexNum(); j++)    {	
			delete []dist[j];
            delete []path[j]; 
		}
		delete []dist; delete []path;
	}
	catch (Error err)					// ��׽�������쳣
	{
		err.Show();						// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}

