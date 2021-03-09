#include "PostThreadBinaryTree.h"
int main()
{
    BinaryTree<char> bt;
    char e;
    PostThreadBinaryTreeNode<char> *p,*q;
	char pre[]={'A','B','D','E','G','C','F'};		// ��������
	char in[]={'D','B','G','E','A','C','F'};		// ��������
	int n = sizeof(pre)/sizeof(char);  // ������
    bt = CreateBinaryTree(pre, in, n);  // ���������
    	cout << "�������Ĺ���:" << endl;
    DisplayBTWithTreeShape(bt);
	PostThreadBinaryTree<char> PTBt(bt);//Ϊ�������������
    cout << "���������";
	bt.PostOrder(Write<char>);
	cout << endl;
	char c = 'x';
		system("PAUSE");

   	while (c != '0'){
        cout << endl << "1. ���Һ�����.";
        cout << endl << "0. �˳�."<<endl;
		cin >> c;
		switch (c) 	{
	         case '1':
                cout << "�����㣺";
                cin>> e;
                p=PTBt.Find(e);
                if (p == NULL)
                    cout << "�ý�㲻���ڣ�" << endl;
                else
                {
                    q=PTBt.Next(p);
                    if(q == NULL)
                        cout<< "�ý���޺�����";
                    else
                        cout<<q->data;
                }
		}
	}

	return 0;
}
