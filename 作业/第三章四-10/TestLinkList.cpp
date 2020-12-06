#include "LinkList.h"		// 单链表类

int main(void)
{
    int a[]={1,4,6,11,57,135,215,643};
    int b[]={3,6,13,62,67,125,465};
    LinkList <int >la(a,8);
    LinkList  <int >lb(b,7);
    la.Display();
    lb.Display();
    la.LinkCat(lb);
    la.Sort();
    la.Display();

	return 0;               // 返回值0, 返回操作系统
}
