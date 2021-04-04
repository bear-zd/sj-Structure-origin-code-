#include "UFSets.h"		            // 并查类

int main(void)
{
    try								// 用try封装可能出现异常的代码
	{
    const int n = 17;
    int c[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int a[] = {1, 3, 3, 1, 3, 8, 1, 3, 3, 3, 3, 14, 16, 14, 1, 1};
    int b[] = {2, 4, 5, 7, 6, 9, 8, 10, 11, 12, 13, 15, 0, 16, 3, 14};

		int i;
        for (i = 0; i < n; i++)
            cout<<setw(4)<<i;
        cout<<endl;

            UFSets<int> e1(c,n);

		for (i = 0; i < n-1; i++)
			{e1.Union1(a[i], b[i]);}	// 合并等价类
        cout<<"要求一：i为j的双亲"<<endl;
        for (i = 0; i < n; i++)
            cout<<setw(4)<<e1.GetElem(i);
            cout<<endl;
        for (i = 0; i < n; i++)
            cout<<setw(4)<<e1.GetParents(i);

        cout<<endl<<"________________________________"<<endl;

        cout<<"要求二：根据高度"<<endl;
        UFSets<int> e3(c,n);
        for (i = 0; i < n-1; i++)
			{e3.Union3(a[i], b[i]);}	// 合并等价类
        for (i = 0; i < n; i++)
            cout<<setw(4)<<e3.GetElem(i);
            cout<<endl;
        for (i = 0; i < n; i++)
        cout<<setw(4)<<e3.GetParents(i);

        cout<<endl<<"________________________________"<<endl;

        cout<<"要求三：根据结点数量"<<endl;
        UFSets<int> e2(c,n);
        for (i = 0; i < n-1; i++)
			{e2.Union2(a[i], b[i]);}	// 合并等价类
        for (i = 0; i < n; i++)
            cout<<setw(4)<<e2.GetElem(i);
            cout<<endl;
        for (i = 0; i < n; i++)
        cout<<setw(4)<<e2.GetParents(i);


        cout<<endl<<"________________________________"<<endl;







	}
	catch (Error err)		// 捕捉并处理异常
	{
		err.Show();			// 显示异常信息
	}

	system("PAUSE");        // 调用库函数system()
	return 0;               // 返回值0, 返回操作系统
}


