#include "BinaryTree.h"		// ����������

int main(void)
{
	BinTreeNode<string> *p;
	string pre[]={"-","/","*","+","6","3","2","3","*","8","5"}; // ��������
	string in[]={"6","+","3","*","2","/","3","-","8","*","5"};  // ��������
	int n = 11;						                  // ������
	BinaryTree<string> bt;
    char c = 'x';
    string e;


	bt = CreateBinaryTree(pre, in, n);           // ���������

	cout << "�ɱ��ʽ����Ķ�����:" << endl;
	DisplayBTWithTreeShape<string>(bt);
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
        cout << endl << "a. ����׺���ʽ";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~7):";
		cin >> c;
		switch (c) 	{
		    case '1':
            	cout << endl << "���뱻����Ԫ�ص�ֵ:";
			    cin >> e;
			    p = bt.Find(e);
			    if (p == NULL)
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
			    if (p == NULL)
			    	cout << "�ý�㲻���ڣ�" << endl;
			    else
					bt.DeleteRightChild(p);
			    break;
		    case '3':
				cout << endl;
				bt.LevelOrder(Write<string>);
				break;
	         case '4':
				cout << endl;
				bt.PreOrder(Write<string>);
				break;
	         case '5':
				cout << endl;
				bt.InOrder(Write<string>);
				break;
	         case '6':
				cout << endl;
				bt.PostOrder(Write<string>);
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
				cout<<"��׺���ʽΪ��"<<endl;
				bt.InExpression(*Write<string>);
				break;
		}
	}

	system("PAUSE");
	return 0;
}

