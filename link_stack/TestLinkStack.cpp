#include "LinkStack.h"	// ��ջ��ģ�� 

int main(void)
{
	char c = '1';
    LinkStack<int> sa;
    int x;
    while (c != '0')	{
        cout << endl << "1. ����ջ.";
        cout << endl << "2. ��ʾջ.";
        cout << endl << "3. ��ջ.";
        cout << endl << "4. ��ջ.";
        cout << endl << "5. ȡջ��.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~5):";
		cin >> c;
		switch (c) 		{
			case '1':
			    sa.Clear();
				cout << "����e(e = 0ʱ�˳�)" << endl;
    		    cin >> x;
  				while (x != 0){
					sa.Push(x);
					cin >> x;
                }
				break;
	       case '2':
				cout << endl;
			    sa.Traverse(Write<int>);
				break;
		   case '3':
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> x;
			    sa.Push(x);
			    break;
           case '4':
			    if (sa.Pop(x) == SUCCESS)
			           cout << endl << "ջ��Ԫ��ֵΪ��" << x << "." << endl;
                else
			           cout << endl << "ջΪ��." << endl;
                break;
           case '5':
			    if (sa.Top(x) == SUCCESS)
			           cout << endl << "ջ��Ԫ��ֵΪ��" << x << "." << endl;
                else
			           cout << endl << "ջΪ��." << endl;
			    break;
		}
	}

	system("PAUSE");  
	return 0;  
}


