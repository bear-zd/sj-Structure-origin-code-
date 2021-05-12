#include "BinaryTree.h"		// 二叉链表类

int main(void)
{
	BinTreeNode<int> *p;
	/*char pre[]={'A','B','D','E','G','H','C','F','I'}; // 先序序列
	char in[]={'D','B','G','E','H','A','C','F','I'};  // 中序序列
	char pre[]={'a','b','d','h','i','e','j','k','c','f','l'};
	char in[]={'h','d','i','b','j','e','k','a','l','f','c'};*/
	int pre[] = {39,11,8,23,34,68,46,75,71,86};
	int in[] = {8,11,23,34,39,46,68,71,75,86};

	int n = 10;						                  // 结点个数
	BinaryTree<int> bt;
    char c = 'x';
    int  e;


	bt = CreateBinaryTree(pre, in, n);           // 构造二叉树

	cout << "由先序：A,B,D,E,G,H,C,F,I和中序：D,B,G,E,H,A,C,F,I构造的二叉树:" << endl;
	DisplayBTWithTreeShape<int>(bt);
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
        cout << endl << "a. 求最大宽度.";
        cout << endl << "b. 判断是否为二叉排序树.";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~b):";
		cin >> c;
		switch (c)
		{
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
				bt.LevelOrder(Write<int>);
				break;
	         case '4':
				cout << endl;
				bt.PreOrder(Write<int>);
				break;
	         case '5':
				cout << endl;
				bt.InOrder(Write<int>);
				break;
	         case '6':
				cout << endl;
				bt.PostOrder(Write<int>);
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
				{cout << endl;
				int *Barrel=new int [bt.Height()];
				cout<<bt.MaxWidth(bt.GetRoot(),0,Barrel)<<endl;
				break;}
             case 'b':
				cout << endl;
				LinkQueue<int> in;
                bt.IsSorted(bt.GetRoot() , in);
                int num;
                if(!in.IsEmpty())
                {
                  in.DelQueue(num);
                }
                while(!in.IsEmpty())
                {
                    int temp;
                    in.DelQueue(temp);
                    if(temp>=num)
                        num = temp;
                    else
                        break;
                }
                if (!in.IsEmpty())
                    cout << "不是二叉排序树!" << endl;
                else
                    cout << "是二叉排序树!" << endl;
                break;


		}
	}

	system("PAUSE");
	return 0;
}

