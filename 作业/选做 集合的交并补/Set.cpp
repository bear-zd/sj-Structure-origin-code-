#include "SeqList.h"	// 顺序表类

int main(void)
{
	SeqList<int> la(50), lb(50),lc(50), ld(50),le(50);
	int e;
    cout << endl << "输入la的元素e(e = 0时退出):";
				cin >> e;
    while(e != 0) {la.InsertElem(e);cin>>e;}
    cout << endl << "输入lb的元素e(e = 0时退出):";
				cin >> e;
    while(e != 0) {lb.InsertElem(e);cin>>e;}

	cout << "集合A:";
	la.Traverse(Write);		    // 显示集合A
	cout << endl;

	cout << "集合B:";
	lb.Traverse(Write);		    // 显示集合B
	cout << endl;

    lc=la.Intersection(lb);
    cout<<"la与lb的交集：";
    lc.Traverse(Write);
    cout<<endl;

    ld=la.Union(lb);
    cout<<"la与lb的并集：";
    ld.Traverse(Write);
     cout<<endl;

     le=la.Complement(lb);
    cout<<"lb关于la的补集：";
    le.Traverse(Write);
     cout<<endl;
	system("PAUSE");            // 调用库函数system()暂停系统运行
	return 0;                   // 返回操作系统
}
