#include "String.h"			// ����

int main(void)
{
	String s1("It is a car.");
	String s2;
	char c = '1';
	int p,l;
	
	while (c != '0'){
        cout << endl << "1. ����Insert()";
        cout << endl << "2. ����Delete()";
        cout << endl << "3. ����Copy()";
        cout << endl << "4. ���Թ�ϵ�����==";
        cout << endl << "5. ����SubString()";
        cout << endl << "6. �����±������";
        cout << endl << "7. �������������+";
        cout << endl << "8. �����ַ���1";
        cout << endl << "9. �����ַ���2";        
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~9):";
		cin >> c;
		switch (c) 	{
			case '1':
				cout << "�ַ���s1Ϊ��";
				Write(s1);
				cout << "�ַ���s2Ϊ��";
				Write(s2);
				cout << endl << "�������λ�ã�";
				cin >> p;
				Insert(s1, s2, p);
				cout << endl << "������Ϊ��";
				Write(s1);
				cout << endl;
				break;
	       case '2':
				cout << "�ַ���s1Ϊ��";
				Write(s1);
				cout << endl << "����ɾ�������λ�úͳ��ȣ�";
				cin >> p >> l;
				Delete(s1, p, l);
				cout << endl << "ɾ�����Ϊ��";
				Write(s1);
				cout << endl;
				break;
		   case '3':
				cout << "�ַ���s1Ϊ��";
				Write(s1);
				cout << "�ַ���s2Ϊ��";
				Write(s2);
				Copy(s2 ,s1);
				cout << endl << "���ƽ��Ϊ��";
				Write(s2);
				cout << endl;
			    break;
           case '4':
				cout << "�ַ���s1Ϊ��";
				Write(s1);
				cout << "�ַ���s2Ϊ��";
				Write(s2);
				if (s1 == s2) 
       				cout << "s1��s2��ȡ�"<< endl;
    			else 
       				cout << "s1��s2����ȡ�"<< endl;
			    break;
           case '5':
				cout << "�ַ���s1Ϊ��";
				Write(s1);
				cout << endl << "�����Ӵ������λ�úͳ��ȣ�";
				cin >> p >> l;
				s2 = SubString(s1, p, l);
				cout << endl << "ȡ�Ӵ����Ϊ��";
				Write(s2);
				cout << endl;
			    break;
          case '6':
				cout << "�ַ���s1Ϊ��";
				Write(s1);
				cout << endl << "�����ַ��±꣺";
				cin >> p;
				cout << endl << "�����±���������Ϊ��" << endl;
				cout << s1[p] << endl;
			    break;
           case '7':
				cout << "�ַ���s1Ϊ��";
				Write(s1);
				cout << "�ַ���s2Ϊ��";
				Write(s2);
				s1 = s1 + s2;
				cout << endl << "�ַ������ӽ��Ϊ��";
				Write(s1);
				cout << endl;
				break;
          case '8':
				cout << endl << "�����ַ���1��";
				Read(s1);
			    break;
           case '9':
				cout << endl << "�����ַ���2��";
				Read(s2);
				break;
		}
	}
	system("PAUSE");        // ���ÿ⺯��system()
	return 0;               // ����ֵ0, ���ز���ϵͳ
}
