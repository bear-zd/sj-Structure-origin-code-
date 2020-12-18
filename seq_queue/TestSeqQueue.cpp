#include "SeqQueue.h"	// ѭ��������

int  main(void)
{
	char c = '1';
    SeqQueue<int> qa(10);
    int x;
    while (c != '0')
	{
        cout << endl << "1. ���ɶ���.";
        cout << endl << "2. ��ʾ����.";
        cout << endl << "3. �����.";
        cout << endl << "4. ������.";
        cout << endl << "5. ȡ����ͷ.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~5):";
		cin >> c;
		switch (c) 
		{
			case '1':
                qa.Clear();
				cout << endl << "����e(e = 0ʱ�˳�)";
				cin >> x;
				while (x != 0)	{
					qa.EnQueue(x);
					cin >> x;
				}
				break;
	       case '2':
				cout << endl;
			    qa.Traverse(Write<int>);
				break;
		   case '3':
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> x;
			    if (qa.EnQueue(x) == OVER_FLOW)
                   cout << endl << "��������!";
			    else
                   cout << endl << "��ӳɹ�.";
			    break;
           case '4':
			    qa.DelQueue(x);
			    cout << endl << "��ͷԪ��ֵΪ " << x << " ." << endl;
			    break;
           case '5':
			    qa.GetHead(x);
			    cout << endl << "��ͷԪ��ֵΪ " << x << " ." << endl;
			    break;
		}
	}

	system("PAUSE"); 
	return 0;    

}


