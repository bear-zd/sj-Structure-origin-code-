#include "UFSets.h"		            // 并查类

int main(void)
{
    try								// 用try封装可能出现异常的代码
	{
		const int n = 17;
		int c[] = {0,1,2,3,4,5,6,7, 8, 9, 10,11,12,13,14,15,16};
		int a[] = {1, 3, 3, 1, 3, 8, 1, 3,3,3,3,14,16,14,1,1};
		int b[] = {2, 4, 5, 7, 6, 9, 8, 10,11,12,13,15,0,16,3,14};
		UFSets<int> e(c,n);
		int i;
		for (i = 0; i < 16; i++)
			e.WeightedUnion(a[i], b[i]);	// 合并等价类

		bool out[n];				// 已输出的结点值为true，否则值为false

		for (i = 0; i < n; i++)
			out[i] = false;
		int p = 0;				// 当前结点
		while (p < n)		{	// 对没有输出的当前结点，输出其等价类
			cout << "{" << e.GetElem(p);
			out[p] = true;
			for (i = p + 1; i < n; i++)	{	// 输出等价类
				if (!e.Differ(e.GetElem(p), e.GetElem(i)))	{	// p与i在同一个等价类中
					cout << "," << e.GetElem(i);
					out[i] = true;
				}
			}
			cout << "}" << endl;
			while (p < n && out[p]) p++;
		}



	}
	catch (Error err)		// 捕捉并处理异常
	{
		err.Show();			// 显示异常信息
	}


	system("PAUSE");        // 调用库函数system()
	return 0;               // 返回值0, 返回操作系统
}


