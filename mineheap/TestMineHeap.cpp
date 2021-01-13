#include "MineHeap.h"

int main()
{
	int a[12]={80,57,99,35,23,11,74,29,62,16};
	MinHeap<int> ha(a,20,10);
	int e;
	char c = 'x'; 
	cout<<endl;
	
	cout << "��С������Ϊ��" << endl;
	ha.Traverse(Write<int>);
	cout << endl << endl;	

    while (c != '0')	{
        cout << endl << "1. ����Ԫ��.";
        cout << endl << "2. ɾ���Ѷ�Ԫ��.";
        cout << endl << "3. ��ʾ��.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~3):";
		cin >> c;
		switch (c) 	{
		    case '1':
            	cout << endl << "�������Ԫ�ص�ֵ:";
			    cin >> e;
				ha.Insert(e);
			    break;
           	case '2':
				ha.DeleteTop(e);
				cout<<"ɾ���ĶѶ�Ԫ��Ϊ:"<<e<<endl;
			    break;
		    case '3':
				cout << endl;
				ha.Traverse(Write<int>);
				break;
		}
	}

	
	system("pause");
	return 0;
}
