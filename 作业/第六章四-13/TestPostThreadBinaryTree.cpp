#include "PostThreadBinaryTree.h"
int main()
{
    BinaryTree<char> bt;
    char e;
    PostThreadBinaryTreeNode<char> *p,*q;
	char pre[]={'A','B','D','E','G','C','F'};		// 先序序列
	char in[]={'D','B','G','E','A','C','F'};		// 中序序列
	int n = sizeof(pre)/sizeof(char);  // 结点个数
    bt = CreateBinaryTree(pre, in, n);  // 构造二叉树
    	cout << "二叉树的构造:" << endl;
    DisplayBTWithTreeShape(bt);
	PostThreadBinaryTree<char> PTBt(bt);//为二叉树添加线索
    cout << "后序遍历：";
	bt.PostOrder(Write<char>);
	cout << endl;
	char c = 'x';
		system("PAUSE");

   	while (c != '0'){
        cout << endl << "1. 查找后序结点.";
        cout << endl << "0. 退出."<<endl;
		cin >> c;
		switch (c) 	{
	         case '1':
                cout << "输入结点：";
                cin>> e;
                p=PTBt.Find(e);
                if (p == NULL)
                    cout << "该结点不存在！" << endl;
                else
                {
                    q=PTBt.Next(p);
                    if(q == NULL)
                        cout<< "该结点无后续！";
                    else
                        cout<<q->data;
                }
		}
	}

	return 0;
}
