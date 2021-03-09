#include "BinaryTree.h"		// 二叉链表类

int main(void)
{
	BinTreeNode<string> *p;
	string pre[]={"-","/","*","+","6","3","2","3","*","8","5"}; // 先序序列
	string in[]={"6","+","3","*","2","/","3","-","8","*","5"};  // 中序序列
	int n = 11;						                  // 结点个数
	BinaryTree<string> bt;
    char c = 'x';
    string e;


	bt = CreateBinaryTree(pre, in, n);           // 构造二叉树

	cout << "由表达式构造的二叉树:" << endl;
	DisplayBTWithTreeShape<string>(bt);
	cout << endl;

	system("PAUSE");

    while (c != '0')	{
        cout << endl << "1. 插入左孩子.";
        cout << endl << "2. 删除右子树.";
        cout << endl << "3. 层次遍历";
        cout << endl << "4. 先序遍历.";
        cout << endl << "5. 中序遍历.";
        cout << endl << "6. 后序遍历.";
        cout << endl << "7. 求二叉树的结点数.";
        cout << endl << "8. 求二叉树的高度.";
        cout << endl << "9. 显示二叉排序树.";
        cout << endl << "a. 求中缀表达式";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~7):";
		cin >> c;
		switch (c) 	{
		    case '1':
            	cout << endl << "输入被插入元素的值:";
			    cin >> e;
			    p = bt.Find(e);
			    if (p == NULL)
			    	cout << "该结点不存在！" << endl;
			    else {
            		cout << endl << "输入插入元素的值:";
			    	cin >> e;
					bt.InsertLeftChild(p, e);	// 插入左孩子
			    }
			    break;
           	case '2':
            	cout << endl << "输入删除子树双亲元素的值:";
			    cin >> e;
			    p = bt.Find(e);
			    if (p == NULL)
			    	cout << "该结点不存在！" << endl;
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
				cout << "二叉树的结点数为：" << bt.NodeCount() << endl;
				break;
	         case '8':
				cout << endl;
				cout << "二叉树的高度为：" << bt.Height() << endl;
				break;
	         case '9':
				cout << endl;
				DisplayBTWithTreeShape(bt);
				break;
            case 'a':
				cout << endl;
				cout<<"中缀表达式为："<<endl;
				bt.InExpression(*Write<string>);
				break;
		}
	}

	system("PAUSE");
	return 0;
}

