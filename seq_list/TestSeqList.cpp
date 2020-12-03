#include "SeqList.h"	// ˳�����

int main(void)
{
	char c = '*';
    SeqList<int> la(6);
    int e, i;
    Status sta;
    
	while (c != '0')
	{
        cout << endl << "1. �������Ա�.";
        cout << endl << "2. ��ʾ���Ա�.";
        cout << endl << "3. ȡָ��Ԫ��.";
        cout << endl << "4. ����Ԫ��ֵ.";
        cout << endl << "5. ɾ��Ԫ��.";
        cout << endl << "6. ����Ԫ��.";
        cout << endl << "7. Ԫ�ض�λ.";
        cout << endl << "8. �����Ա���.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~8):";
		cin >> c;
		switch (c) 	{
			case '1':
			    la.Clear();
			    sta = SUCCESS;
				cout << endl << "����e(e = 0ʱ�˳�):";
				cin >> e;
				while (e != 0 && sta != OVER_FLOW)	{
					sta = la.InsertElem(e);
					if (sta == OVER_FLOW) 
						cout << "���Ա�����." << endl;
					else
						cin >> e;
				}
				break;
			case '2':
			    la.Traverse(Write<int>);
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
			    sta = la.InsertElem(i, e);
			    
			    if (sta == RANGE_ERROR) 
					cout << "λ�÷�Χ��." << endl;
				else if (sta == OVER_FLOW) 
					cout << "���Ա�����." << endl;
				else
					cout << "����ɹ�." << endl;	
			    break;
			case '7':
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> e;
			    i = la.LocateElem(e); 
			    if (i != 0) 
					cout << "Ԫ��" << e << "�����Ϊ��" << i << endl;
				else
					cout << "Ԫ��" << e << "�����ڡ�"  << endl;
			    break;
			case '8':
			    cout << endl << "���Ա�ĳ���Ϊ:" << la.GetLength() << endl; 
			    break;
       	}
	}

   	system("PAUSE");        		// ���ÿ⺯��system()����ͣ�������� 
   	return 0;               		// ���ز���ϵͳ
}


