#include "Brute-Force.h"

int main(void)
{	// ��ʽ���ַ���ģʽƥ���㷨
	String ob("this is a string");
	String pat("is");
	cout << "����Ϊ��" ;
	Write(ob);
	cout << "�Ӵ�Ϊ��" ;
	Write(pat);
	
	cout << endl << "��������ʼλ�ã���0���ַ�������ģʽ����" ;
	cout << BF_find(ob, pat) << endl;

	cout << endl << "��������3���ַ���ʼ����ģʽ����" ;
	cout << BF_find(ob, pat, 3) << endl;

	pat="string";
	cout << endl << "��ģʽ��Ϊstring����������ʼλ�ò���ģʽ����" ;
	cout << BF_find(ob, pat) << endl;
	
	pat="this";
	cout << endl << "��ģʽ��Ϊthis����������ʼλ�ò���ģʽ����" ;
	cout << BF_find(ob, pat) << endl;

	cout << endl << "��ģʽ��Ϊthis����������3���ַ���ʼ����ģʽ����" ;
	cout << BF_find(ob, pat, 3) << endl;

	pat="that";
	cout << endl << "��ģʽ��Ϊthat����������ʼλ�ò���ģʽ����" ;
	cout << BF_find(ob, pat) << endl;

	pat="this is a string!";
	cout << endl << "��ģʽ��Ϊthis is a string!����������ʼλ�ò���ģʽ����" ;
	cout << BF_find(ob, pat) << endl;

	pat=ob;
	cout << endl << "��ģʽ��Ϊthis is a string����������ʼλ�ò���ģʽ����" ;
	cout << BF_find(ob, pat) << endl;

	system("PAUSE");        // ���ÿ⺯��system()
	return 0;               // ����ֵ0, ���ز���ϵͳ
}

