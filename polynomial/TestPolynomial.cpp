#include "Polynomial.h"	// ����ʽ��
int main(void)
{
	char c = '1';
    Polynomial fa, fb, fc;
    PolyItem it;

    while (c != '0'){
        cout << endl << "1. ���ɶ���ʽ.";
        cout << endl << "2. ��ʾ����ʽ.";
        cout << endl << "3. ����ʽ�ӷ�.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~3):";
		cin >> c;
		switch (c) 	{
			case '1':
				cout << endl << "����(coef, expn)(expn = -1ʱ�˳�):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1)	{
					fa.InsItem(it);
					cin >> it.coef >> it.expn;
				}
				break;
			case '2':
				cout << endl;
			    fa.Display();
			    cout << endl;
				break;
			case '3':
				// ����fa
				fa.SetZero();		// ��fa����Ϊ0
				cout << endl << "�����һ������ʽÿ���ϵ����ָ��(coef, expn)(e = -1ʱ�˳�):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1)	{
					fa.InsItem(it);
					cin >> it.coef >> it.expn;
				}
			    
				// ����fb
				fb.SetZero();		// ��fb����Ϊ0
				cout << endl << "����ڶ�������ʽÿ���ϵ����ָ��(coef, expn)(e = -1ʱ�˳�):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1)	{
					fb.InsItem(it);
					cin >> it.coef >> it.expn;
				}
			    
				fc = fa + fb;
			    cout << "fa:" << endl;			// ��ʾfa
				fa.Display();
			    cout << endl;			

			    cout << "fb:" << endl;			// ��ʾfa
				fb.Display();
			    cout << endl;			

			    cout << "fa + fb:" << endl;		// ��ʾfc = fa + fb
				fc.Display();
			    cout << endl;			
				break;
		}
	}
	system("PAUSE");				// ���ÿ⺯��system()
	return 0;						// ����ֵ0, ���ز���ϵͳ
}
