#include "BinaryTree.h"		// ����������

int main(void)
{
	BinTreeNode<int> *p;
	/*char pre[]={'A','B','D','E','G','H','C','F','I'}; // ��������
	char in[]={'D','B','G','E','H','A','C','F','I'};  // ��������
	char pre[]={'a','b','d','h','i','e','j','k','c','f','l'};
	char in[]={'h','d','i','b','j','e','k','a','l','f','c'};*/
	int pre[] = {39,11,8,23,34,68,46,75,71,86};
	int in[] = {8,11,23,34,39,46,68,71,75,86};

	int n = 10;						                  // ������
	BinaryTree<int> bt;
    char c = 'x';
    int  e;


	bt = CreateBinaryTree(pre, in, n);           // ���������

	cout << "������A,B,D,E,G,H,C,F,I������D,B,G,E,H,A,C,F,I����Ķ�����:" << endl;
	DisplayBTWithTreeShape<int>(bt);
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
        cout << endl << "a. �������.";
        cout << endl << "b. �ж��Ƿ�Ϊ����������.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~b):";
		cin >> c;
		switch (c)
		{
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
                    cout << "���Ƕ���������!" << endl;
                else
                    cout << "�Ƕ���������!" << endl;
                break;


		}
	}

	system("PAUSE");
	return 0;
}

