#include "LinkList.h"		// ��������

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

	return 0;               // ����ֵ0, ���ز���ϵͳ
}
