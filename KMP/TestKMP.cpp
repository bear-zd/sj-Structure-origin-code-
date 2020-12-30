#include "KMP.h"		      // KMP�㷨

int main(void)
{	// ��ʽKMP�ַ���ģʽƥ���㷨
	String ob("this is a string");
	String pat("is");
	
	cout << "����Ϊ��" ;
	Write(ob);
	cout << "ģʽ��Ϊ��" ;
	Write(pat);
	
	cout << endl << "��������ʼλ�ã���0���ַ�������ģʽ����" ;
	cout << KMP_find(ob, pat) << endl;

	cout << endl << "��������3���ַ���ʼ����ģʽ����" ;
	cout << KMP_find(ob, pat, 3) << endl;

	pat="string";
	cout << endl << "��ģʽ��Ϊstring����������ʼλ�ò���ģʽ����" ;
	cout << KMP_find(ob, pat) << endl;
	
	pat="this";
	cout << endl << "��ģʽ��Ϊthis����������ʼλ�ò���ģʽ����" ;
	cout << KMP_find(ob, pat) << endl;

	cout << endl << "��ģʽ��Ϊthis����������1���ַ���ʼ����ģʽ����" ;
	cout << KMP_find(ob, pat, 1) << endl;

	pat="that";
	cout << endl << "��ģʽ��Ϊthat����������ʼλ�ò���ģʽ����" ;
	cout << KMP_find(ob, pat) << endl;

	pat="this is a string!";
	cout << endl << "��ģʽ��Ϊthis is a string!����������ʼλ�ò���ģʽ����" ;
	cout << KMP_find(ob, pat) << endl;

	pat=ob;
	cout << endl << "��ģʽ��Ϊthis is a string����������ʼλ�ò���ģʽ����" ;
	cout << KMP_find(ob, pat) << endl;

	system("PAUSE");        // ���ÿ⺯��system()
	return 0;               // ����ֵ0, ���ز���ϵͳ
}
