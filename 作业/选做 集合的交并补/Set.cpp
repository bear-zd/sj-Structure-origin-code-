#include "SeqList.h"	// ˳�����

int main(void)
{
	SeqList<int> la(50), lb(50),lc(50), ld(50),le(50);
	int e;
    cout << endl << "����la��Ԫ��e(e = 0ʱ�˳�):";
				cin >> e;
    while(e != 0) {la.InsertElem(e);cin>>e;}
    cout << endl << "����lb��Ԫ��e(e = 0ʱ�˳�):";
				cin >> e;
    while(e != 0) {lb.InsertElem(e);cin>>e;}

	cout << "����A:";
	la.Traverse(Write);		    // ��ʾ����A
	cout << endl;

	cout << "����B:";
	lb.Traverse(Write);		    // ��ʾ����B
	cout << endl;

    lc=la.Intersection(lb);
    cout<<"la��lb�Ľ�����";
    lc.Traverse(Write);
    cout<<endl;

    ld=la.Union(lb);
    cout<<"la��lb�Ĳ�����";
    ld.Traverse(Write);
     cout<<endl;

     le=la.Complement(lb);
    cout<<"lb����la�Ĳ�����";
    le.Traverse(Write);
     cout<<endl;
	system("PAUSE");            // ���ÿ⺯��system()��ͣϵͳ����
	return 0;                   // ���ز���ϵͳ
}
