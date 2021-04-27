#include "Kruskal.h"					// Kruskal算法

int main(void)
{
    try									// 用try封装可能出现异常的代码
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

		for (int u = 0; u < n; u++)	// 生成邻接矩阵的行
			for (int v = u + 1; v < n; v++)	// 生成邻接矩阵元素的值
				if (m[u][v] != infity) net.InsertArc(u, v, m[u][v]);

		cout << "原网:" << endl;
		net.Display();					// 显示网net
		cout << endl;
		system("PAUSE");

		cout << "Kruskal算法产生最小生成树的边:" << endl;
		MiniSpanTreeKruskal(net);		// Kruskal算法
		cout << endl;
		//cout << "破窗法产生的最小生成树："<<end;

	}
	catch (Error err)					// 捕捉并处理异常
	{
		err.Show();						// 显示异常信息
	}

	system("PAUSE");					// 调用库函数system()
	return 0;							// 返回值0, 返回操作系统
}

