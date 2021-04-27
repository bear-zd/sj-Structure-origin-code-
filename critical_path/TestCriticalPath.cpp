#include "CriticalPath.h"				// �ؼ�·���㷨

int main(void)
{
    try									// ��try��װ���ܳ����쳣�Ĵ���
	{
		int infity = DEFAULT_INFINITY;
		char vexs[] = {'0', '1', '2', '3', '4', '5', '6'};
		int m[7][7] = {
			{infity,      8,  infity,       4,         5, infity, infity},
			{infity, infity,       3, infity, infity, infity, infity},
			{infity, infity, infity,infity, infity, infity,        6},
			{infity, infity, infity, infity,      1, infity, infity},
			{infity,        2,        7, infity, infity,      2, infity},
			{infity, infity,        3, infity, infity, infity,      9},
			{infity, infity, infity, infity, infity, infity, infity}
		};
		int n = 7;

		AdjListDirNetwork<char, int> net(vexs, n);

		for (int u = 0; u < n; u++)
			for (int v = n-1; v >= 0; v--)
				if (m[u][v] != infity) net.InsertArc(u, v, m[u][v]);

		cout << "ԭ��:" << endl;
		net.Display();					// ��ʾ��net
		cout << endl;
		system("PAUSE");				// ���ÿ⺯��system()

		if (CriticalPath(net) == SUCCESS)
			cout << endl << "���ڹؼ��" << endl;
		else
			cout << endl << "�����ڹؼ�� " << endl;
		cout << endl;
	}
	catch (Error err)					// ��׽�������쳣
	{
		err.Show();						// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵinfity, ���ز���ϵͳ
}

