#include "TriSparseMatrix.h"		// ϡ��������Ԫ��˳���

int main(void)
{

    try								// ��try��װ���ܳ����쳣�Ĵ���
	{
		const int rs = 7, cs = 6;
		TriSparseMatrix<int> a(rs, cs);	// ����һ��n��n��ϡ�����
		TriSparseMatrix<int> c(rs, cs);
		int m[rs][cs] = {
			15,	 0,	 0,	22,	 0, -5,
			 0,	11,	 3,	 0,	 0,  0,
			 0,	 0,	 0,	 6,	 0,  0,
			 0,	 0,	 0,	 0,	 0,  0,
		    91,	 0,	 0,	 0,	 0,  0,
             0,  7,  0,  0,  0,  0,
             0,  0, 28,  0,  0,  0
		};
		int n[rs][cs] = {
		3,0,1,4,6,0,
		0,3,5,0,4,0,
		1,0,0,0,2,4,
		2,6,1,3,6,0,
		1,4,7,0,0,0,
		1,3,5,7,6,6,
		1,5,8,6,5,0,
		};
		int i, j, v;					// ��ʱ����

		// ����ϡ�����a��Ԫ��ֵ
		for (i = 0; i < rs; i++)
			for (j = 0; j < cs; j++)
				a.SetElem(i, j, m[i][j]);	// ����Ԫ��ֵ
        for (i = 0; i < rs; i++)
			for (j = 0; j < cs; j++)
				c.SetElem(i, j, n[i][j]);	// ����Ԫ��ֵ

		// ��ʾϡ�����a
		cout << "����a:" << endl;
		for (i = 0; i < a.GetRows(); i++)	{
			for (j = 0; j < a.GetCols(); j++)	{
				a.GetElem(i, j, v);		// ȡԪ��ֵ
				cout << v << "\t";		// ��ʾԪ��ֵ
			}
			cout << endl;
		}
		cout << "����c:" << endl;
		for (i = 0; i < c.GetRows(); i++)	{
			for (j = 0; j < c.GetCols(); j++)	{
				c.GetElem(i, j, v);		// ȡԪ��ֵ
				cout << v << "\t";		// ��ʾԪ��ֵ
			}
			cout << endl;
		}
		TriSparseMatrix<int> b(7,6);
		TriSparseMatrix<int> d(7,6);
		TriSparseMatrix<int> e(5,5);

		cout << endl <<"a+a:"<<endl;
		b=a+a;
		for (i = 0; i < b.GetRows(); i++)	{
			for (j = 0; j < b.GetCols(); j++)	{
				b.GetElem(i, j, v);		// ��Ԫ��ֵ
				cout << v << "\t";		// ��ʾԪ��ֵ
			}
			cout << endl;
		}

        cout << endl <<"a+c:"<<endl;
		d=a+c;
		for (i = 0; i < d.GetRows(); i++)	{
			for (j = 0; j < d.GetCols(); j++)	{
				d.GetElem(i, j, v);		// ��Ԫ��ֵ
				cout << v << "\t";		// ��ʾԪ��ֵ
			}
			cout << endl;
		}

         cout << endl <<"a+e(��ͬ��ͬ��):"<<endl;
		a=a+e;
		for (i = 0; i < a.GetRows(); i++)	{
			for (j = 0; j < a.GetCols(); j++)	{
				a.GetElem(i, j, v);		// ��Ԫ��ֵ
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


