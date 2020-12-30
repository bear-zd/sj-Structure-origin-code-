#include "CrossList.h"		// ϡ��������Ԫ��˳���

int main(void)
{
    try								// ��try��װ���ܳ����쳣�Ĵ���
	{
		const int rs = 6, cs=7;
		CrossList<int> a(rs, cs),d(rs,cs);	// ����һ��rs��cs��ϡ�����
		int m[rs][cs] = {
			 0,	 0,	11,	 0,	 0, 13,  0, 
			12,	 0,	 0,	 0,	 0,  0, 14, 
			 0,	-4,	 0,	 0,	 0, -8,  0, 
			 0,	 0,	 0,	 0,	 0,  0,  0,
			 0,	 0,	 0,	 0,	 0,  0,  0,
			 0, -8,  0,  0,  0,  0,  0
		};
		int i, j, v;

		// ����ϡ�����a��Ԫ��ֵ
		for (i = 0; i < rs; i++)
			for (j = 0; j < cs; j++)
				a.SetElem(i, j, m[i][j]);	// ����Ԫ��ֵ

		// ��ʾϡ�����a
		cout << "��ʾ����a:" << endl; 
		for (i = 0; i < a.GetRows(); i++)  { 
			for (j = 0; j < a.GetCols(); j++)	{	// ��
				a.GetElem(i, j, v);		// ȡԪ��ֵ
				cout << v << "\t";		// ��ʾԪ��ֵ
			}
			cout << endl;
		}
		cout << endl;

		cout << "��ʾ����a+a:" << endl; 
		CrossList<int> c(a);	
		c = a + c;
		for (i = 0; i < c.GetRows(); i++)  { 
		  for (j = 0; j < c.GetCols(); j++)	{	// ��
			c.GetElem(i, j, v);		// ȡԪ��ֵ
			cout << v << "\t";		// ��ʾԪ��ֵ
		  }
	      cout << endl;
		}
	}
	catch (Error err)		// ��׽�������쳣
	{
		err.Show();			// ��ʾ�쳣��Ϣ
	}

  	system("PAUSE");        // ���ÿ⺯��system()
	return 0;               // ����ֵ0, ���ز���ϵͳ
}

