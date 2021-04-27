#include "ShortestPathDij.h"			// ���·���Ͻ�˹�����㷨

int main(void)
{
    try									// ��try��װ���ܳ����쳣�Ĵ���
	{
		int infity = DEFAULT_INFINITY;
		char vexs[] = {'0', '1', '2', '3', '4', '5'};
		int m[6][6] = {
			{infity,     45,      50,     15, infity, infity},
			{infity, infity,       5, infity,     20,      15},
			{infity, infity, infity, infity, infity, infity},
			{     10,     10,  infity, infity,      79, infity},
			{infity,     30, infity, infity,  infity, infity},
			{infity, infity, infity, infity,      20, infity}

		};
		int n = 6;

		AdjListDirNetwork<char, int> net(vexs, n);  //��

		for (int u = 0; u < n; u++)
		{	// �����ڽӾ������
			for (int v = n-1; v >=0; v--)
			{	// �����ڽӾ���Ԫ�ص�ֵ
				if (m[u][v] != infity)
                    net.InsertArc(u, v, m[u][v]);
			}
		}

		cout << "ԭ��:" << endl;
		net.Display();					// ��ʾ��net
		cout << endl;
		system("PAUSE");				// ���ÿ⺯��system()
        for (int v0 = 0 ; v0 < n ; v0++)
		{
		    int dist[n], path[n];
            ShortestPathDij(net, v0, path, dist);		//��Dijskstra�㷨�����·��
            DisplayPathAndDist(net, v0, path, dist);	//��ʾ���·��
            cout << endl;
		}
	}
	catch (Error err)					// ��׽�������쳣
	{
		err.Show();						// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}

