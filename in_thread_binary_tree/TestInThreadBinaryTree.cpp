#include "InThreadBinaryTree.h"		  // ����������������

int main(void)
{
	char pre[]={'A','B','D','E','G','C','F'};		// ��������
	char in[]={'D','B','G','E','A','C','F'};		// ��������
	int n = 7;						  // ������
	BinaryTree<char> bt;
	char c = 'x', e;
	ThreadBinTreeNode<char> *p;


	bt = CreateBinaryTree(pre, in, n);// ���������
	cout << "������A,B,D,E,G,C,F������D,B,G,E,A,C,F����Ķ�����:" << endl;
	DisplayBTWithTreeShape<char>(bt);
	cout << endl;
	system("PAUSE");	

	cout << "���������������������:" << endl;
	InThreadBinTree<char> thrBt(bt);
	DisplayBTWithTreeShape<char>(thrBt);
	system("PAUSE");	
	
   	while (c != '0'){
        cout << endl << "1. �����Һ���.";
        cout << endl << "2. ɾ��������.";
        cout << endl << "3. �������.";
        cout << endl << "4. ��ʾ������.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~4):";
		cin >> c;
		switch (c) 	{
		    case '1':
            	cout << endl << "���뱻����Ԫ�ص�ֵ:";
			    cin >> e;
			    p = thrBt.Find(e);
			    if (p == NULL)
			    	cout << "�ý�㲻���ڣ�" << endl;
			    else {
            		cout << endl << "�������Ԫ�ص�ֵ:";
			    	cin >> e;
					thrBt.InsertRightChild(p, e);	// ��������
			    }
			    break;
           	case '2':
            	cout << endl << "����ɾ������˫��Ԫ�ص�ֵ:";
			    cin >> e;
			    p = thrBt.Find(e);
			    if (p == NULL)
			    	cout << "�ý�㲻���ڣ�" << endl;
			    else 
					thrBt.DeleteLeftChild(p);					
			    break;
	         case '3':
				cout << endl;
				thrBt.InOrder(Write<char>);
				break;
	         case '4':
				cout << endl;
				DisplayBTWithTreeShape(thrBt);
				break;
		}
	}
	
	system("PAUSE");	
	return 0;				
}

