#include "SqBinaryTree.h"				// ˳��洢��������

int main(void)
{
	int p;
	char c='a', e;

    char pre[]={'A','B','D','H','I','E','J','K','C','F','L','M','G','N','O'};		// ��������
	char in[]={'H','D','I','B','J','E','K','A','L','F','M','C','N','G','O'};		// ��������
	int n = 15, size=15;										// ������
	SqBinaryTree<char> bt;
	bt = CreateBinaryTree(pre, in, n, size);				// ���������

	cout << "������A,B,D,E,G,H,C,F,I������D,B,G,E,H,A,C,F,I����Ķ�����:" << endl;
	DisplayBTWithTreeShape<char>(bt);
	cout << endl;

	system("PAUSE");

    while (c != '0')	{
        cout << endl << "1. ��������.";
        cout << endl << "2. ɾ��������.";
        cout << endl << "3. ��α���";
        cout << endl << "4. �������.";
        cout << endl << "5. �������.";
        cout << endl << "6. �������.";
        cout << endl << "7. ��������Ľ����.";
        cout << endl << "8. ��������ĸ߶�.";
        cout << endl << "9. ��ʾ����������.";
        cout << endl << "a. �󹫹�����.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~7):";
		cin >> c;
		switch (c) 	{
		    case '1':
            	cout << endl << "���뱻����Ԫ�ص�ֵ:";
			    cin >> e;
			    p = bt.Find(e);
			    if (p == -1)
			    	cout << "�ý�㲻���ڣ�" << endl;
			    else {
            		cout << endl << "�������Ԫ�ص�ֵ:";
			    	cin >> e;
					bt.InsertLeftChild(p, e);	// ��������
			    }
			    break;
           	case '2':
            	cout << endl << "����ɾ������˫��Ԫ�ص�ֵ:";
			    cin >> e;
			    p = bt.Find(e);
			    if (p == -1)
			    	cout << "�ý�㲻���ڣ�" << endl;
			    else
					bt.DeleteRightChild(p);
			    break;
		    case '3':
				cout << endl;
				bt.LevelOrder(Write<char>);
				break;
	         case '4':
				cout << endl;
				bt.PreOrder(Write<char>);
				break;
	         case '5':
				cout << endl;
				bt.InOrder(Write<char>);
				break;
	         case '6':
				cout << endl;
				bt.PostOrder(Write<char>);
				break;
	         case '7':
				cout << endl;
				cout << "�������Ľ����Ϊ��" << bt.NodeCount() << endl;
				break;
	         case '8':
				cout << endl;
				cout << "�������ĸ߶�Ϊ��" << bt.Height() << endl;
				break;
	         case '9':
				cout << endl;
				DisplayBTWithTreeShape(bt);
				break;
            case 'a':
				cout << endl;
				int a,b,re;
				cout<<"�������һ��Ԫ�ص��±꣺";
				cin>>a;
				cout<<"������ڶ���Ԫ�ص��±꣺";
				cin>>b;
				re=bt.FindSameAncestor(a,b);
				bt.GetElem(re,e);
				cout<<e<<endl;
				break;
		}
	}

	system("PAUSE");
	return 0;
}

