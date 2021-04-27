#include "ShortestPathDij.h"			// ���·���Ͻ�˹�����㷨

int main(void)
{
    try									// ��try��װ���ܳ����쳣�Ĵ���
	{
		int infity = DEFAULT_INFINITY;
		char vexs[] = {'A', 'B', 'C', 'D', 'E'};
		int m[5][5] = {
			{infity,     10, infity,     30,     100},
			{infity, infity,     50, infity,  infity},
			{infity, infity, infity, infity,      10},
			{infity, infity,     20, infity,      60},
			{infity, infity, infity, infity,  infity}
		};
		int n = 5;

		AdjListDirNetwork<char, int> net(vexs, n);

		for (int u = 0; u < n; u++)
		{	// �����ڽӾ������
			for (int v = n-1; v >=0; v--)
			{	// �����ڽӾ���Ԫ�ص�ֵ
				if (m[u][v] != infity) net.InsertArc(u, v, m[u][v]);
			}
		}

		cout << "ԭ��:" << endl;
		net.Display();					// ��ʾ��net
		cout << endl;
		system("PAUSE");				// ���ÿ⺯��system()

		int dist[n], path[n], v0 = 0;
		ShortestPathDij(net, v0, path, dist);		//��Dijskstra�㷨�����·��
		DisplayPathAndDist(net, v0, path, dist);	//��ʾ���·��
		cout << endl;
	}
	catch (Error err)					// ��׽�������쳣
	{
		err.Show();						// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}

