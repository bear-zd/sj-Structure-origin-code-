#include "DblLinkList.h"		// ˫��ѭ��������
 
int main(void)
{
	char c = '1';
    DblLinkList<double> la,lb;
    double e;
	int i;

    while (c != '0')	{
        cout << endl << "1. �������Ա�.";
        cout << endl << "2. ��ʾ���Ա�.";
        cout << endl << "3. ȡָ��Ԫ��ֵ.";
        cout << endl << "4. ����Ԫ��ֵ.";
        cout << endl << "5. ɾ��Ԫ��.";
        cout << endl << "6. ����Ԫ��.";
        cout << endl << "7. Ԫ�ض�λ.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~7):";
		cin >> c;
		switch (c) 		{
			case '1':
                la.Clear();
				cout << endl << "����e(e = 0ʱ�˳�):";
				cin >> e;
				while (e != 0)				{
					la.InsertElem(la.GetLength() + 1, e);
					cin >> e;
				}
				break;
			case '2':
			    lb = la;
			    lb.Traverse(Write<double>);
				break;
			case '3':
			    cout << endl << "����Ԫ��λ��:";
			    cin >> i;
			    if (la.GetElem(i, e) == NOT_PRESENT) 
					cout << "Ԫ�ز��洢." << endl;
				else
					cout << "Ԫ��:" << e << endl;
			    break;
			case '4':
			    cout << endl << "����λ��:";
			    cin >> i;
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> e;
				if (la.SetElem(i, e) == RANGE_ERROR)
					cout << "λ�÷�Χ��." << endl;
				else
					cout << "���óɹ�." << endl;
			    break;
			case '5':
			    cout << endl << "����λ��:";
			    cin >> i;
			    if (la.DeleteElem(i, e) == RANGE_ERROR) 
					cout << "λ�÷�Χ��." << endl;
				else
					cout << "��ɾ��Ԫ��ֵ:" << e << endl;
			    break;
			case '6':
			    cout << endl << "����λ��:";
			    cin >> i;
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> e;
			    if (la.InsertElem(i, e) == RANGE_ERROR) 
					cout << "λ�÷�Χ��." << endl;
				else
					cout << "�ɹ�:" << e << endl;
			    break;
			case '7':
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> e;
			    i = la.LocateElem(e);
			    if (i == 0) 
					cout << "ָ��Ԫ�ز�����." << endl;
				else
					cout << "ָ��Ԫ�ص����Ϊ��" << i << endl;
			    break;		
          }
	}

	system("PAUSE");			
	return 0;		
}
