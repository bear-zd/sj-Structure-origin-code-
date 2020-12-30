#include "TriSparseMatrix.h"		// ϡ��������Ԫ��˳���

int main(void)
{
	
    try								// ��try��װ���ܳ����쳣�Ĵ���
	{
		const int rs = 7, cs = 6;
		TriSparseMatrix<int> a(rs, cs);	// ����һ��n��n��ϡ�����
		int m[rs][cs] = {
			15,	 0,	 0,	22,	 0, -5, 
			 0,	11,	 3,	 0,	 0,  0, 
			 0,	 0,	 0,	 6,	 0,  0,
			 0,	 0,	 0,	 0,	 0,  0,
		    91,	 0,	 0,	 0,	 0,  0,
             0,  7,  0,  0,  0,  0,
             0,  0, 28,  0,  0,  0
		};
		int i, j, v;					// ��ʱ����	

		// ����ϡ�����a��Ԫ��ֵ
		for (i = 0; i < rs; i++) 
			for (j = 0; j < cs; j++)
				a.SetElem(i, j, m[i][j]);	// ����Ԫ��ֵ
		
		// ��ʾϡ�����a
		cout << "����a:" << endl;
		for (i = 0; i < a.GetRows(); i++)	{	
			for (j = 0; j < a.GetCols(); j++)	{	
				a.GetElem(i, j, v);		// ȡԪ��ֵ
				cout << v << "\t";		// ��ʾԪ��ֵ
			}
			cout << endl;
		}

		TriSparseMatrix<int> b;	
		
		cout << endl << "����a��ת�þ���:" << endl;
//		a.SimpleTranspose(b);
		a.FastTranspose(b); 
		for (i = 0; i < b.GetRows(); i++)	{
			for (j = 0; j < b.GetCols(); j++)	{	
				b.GetElem(i, j, v);		// ��Ԫ��ֵ
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


