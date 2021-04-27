#include "Kruskal.h"					// Kruskal�㷨

int main(void)
{
    try									// ��try��װ���ܳ����쳣�Ĵ���
	{
		int infity = DEFAULT_INFINITY;
		char vexs[] = {'0', '1', '2', '3', '4', '5'};
		int m[6][6] = {
			{infity,        5,        3,        5, infity, infity},
			{       5, infity, infity,        1,         5, infity},
			{       3, infity, infity,        6, infity,         6},
			{       5,        1,        6, infity,        5,         4},
			{infity,        5, infity,        5, infity,         2},
			{infity, infity,       6,         4,         2, infity}
		};
		int n = 6;

		AdjMatrixUndirNetwork<char, int> net(vexs, n);

		for (int u = 0; u < n; u++)	// �����ڽӾ������
			for (int v = u + 1; v < n; v++)	// �����ڽӾ���Ԫ�ص�ֵ
				if (m[u][v] != infity) net.InsertArc(u, v, m[u][v]);

		cout << "ԭ��:" << endl;
		net.Display();					// ��ʾ��net
		cout << endl;
		system("PAUSE");

		cout << "Kruskal�㷨������С�������ı�:" << endl;
		MiniSpanTreeKruskal(net);		// Kruskal�㷨
		cout << endl;
		//cout << "�ƴ�����������С��������"<<end;

	}
	catch (Error err)					// ��׽�������쳣
	{
		err.Show();						// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}

