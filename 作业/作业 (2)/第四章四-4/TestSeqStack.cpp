#include "SeqStack.h"	// 顺序栈类
#define L 10
int main(void)
{
	char c = '1';
    SeqStack<int> sa(L);
    int x;
    char D;


    while (c != '0')
	{
        cout << endl << "1. 显示栈.";
        cout << endl << "2. 入栈.";
        cout << endl << "3. 出栈.";
        cout << endl << "4. 判断空栈.";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~5):";
		cin >> c;
		switch (c) 	{
	       case '1':
				cout << endl;
			    sa.Traverse(Write<int>);
				break;
		   case '2':
			    cout << endl << "输入元素值:";
			    cin >> x;
			    cout << endl <<"输入入栈方向(L(l)/R(r)):";cin>>D;
			    if (sa.PushD(x,D) == SUCCESS)
			           cout << endl << "入栈成功." << endl;
                else
                       cout << endl << "入栈失败." << endl;
			    break;
           case '3':
               cout << endl <<"输入出栈方向(L(l)/R(r)):";cin>>D;
			    if (sa.PopD(x,D) == SUCCESS)
			           cout << endl << "栈顶元素值为：" << x << "." << endl;
                else
                       cout << endl << "栈为空。 " << endl;
			    break;
           case '4':
               cout << endl <<"输入出栈方向(L(l)/R(r)):";cin>>D;
			    if (sa.IsEmpty(D) == SUCCESS)
                       cout << endl << "栈为空。 " << endl;
                else
                        cout << endl <<D<< "方向栈不空。 " << endl;
			    break;
		}
	}

	system("PAUSE");
	return 0;
}


