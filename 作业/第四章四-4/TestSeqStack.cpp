#include "SeqStack.h"	// ˳��ջ��
#define L 10
int main(void)
{
	char c = '1';
    SeqStack<int> sa(L);
    int x;
    char D;


    while (c != '0')
	{
        cout << endl << "1. ��ʾջ.";
        cout << endl << "2. ��ջ.";
        cout << endl << "3. ��ջ.";
        cout << endl << "4. �жϿ�ջ.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~5):";
		cin >> c;
		switch (c) 	{
	       case '1':
				cout << endl;
			    sa.Traverse(Write<int>);
				break;
		   case '2':
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> x;
			    cout << endl <<"������ջ����(L(l)/R(r)):";cin>>D;
			    if (sa.PushD(x,D) == SUCCESS)
			           cout << endl << "��ջ�ɹ�." << endl;
                else
                       cout << endl << "��ջʧ��." << endl;
			    break;
           case '3':
               cout << endl <<"�����ջ����(L(l)/R(r)):";cin>>D;
			    if (sa.PopD(x,D) == SUCCESS)
			           cout << endl << "ջ��Ԫ��ֵΪ��" << x << "." << endl;
                else
                       cout << endl << "ջΪ�ա� " << endl;
			    break;
           case '4':
               cout << endl <<"�����ջ����(L(l)/R(r)):";cin>>D;
			    if (sa.IsEmpty(D) == SUCCESS)
                       cout << endl << "ջΪ�ա� " << endl;
                else
                        cout << endl <<D<< "����ջ���ա� " << endl;
			    break;
		}
	}

	system("PAUSE");
	return 0;
}


