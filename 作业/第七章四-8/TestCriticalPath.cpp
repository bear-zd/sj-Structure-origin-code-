#include "CriticalPath.h"				// 关键路径算法

int main(void)
{
    try									// 用try封装可能出现异常的代码
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

		cout << "原网:" << endl;
		net.Display();					// 显示网net
		cout << endl;
		system("PAUSE");				// 调用库函数system()

		if (CriticalPath(net) == SUCCESS)
			cout << endl << "存在关键活动" << endl;
		else
			cout << endl << "不存在关键活动 " << endl;
		cout << endl;
	}
	catch (Error err)					// 捕捉并处理异常
	{
		err.Show();						// 显示异常信息
	}

	system("PAUSE");					// 调用库函数system()
	return 0;							// 返回值infity, 返回操作系统
}

