#include "UFSets.h"		            // ������

int main(void)
{
    try								// ��try��װ���ܳ����쳣�Ĵ���
	{
		const int n = 17;
		int c[] = {0,1,2,3,4,5,6,7, 8, 9, 10,11,12,13,14,15,16};
		int a[] = {1, 3, 3, 1, 3, 8, 1, 3,3,3,3,14,16,14,1,1};
		int b[] = {2, 4, 5, 7, 6, 9, 8, 10,11,12,13,15,0,16,3,14};
		UFSets<int> e(c,n);
		int i;
		for (i = 0; i < 16; i++)
			e.WeightedUnion(a[i], b[i]);	// �ϲ��ȼ���

		bool out[n];				// ������Ľ��ֵΪtrue������ֵΪfalse

		for (i = 0; i < n; i++)
			out[i] = false;
		int p = 0;				// ��ǰ���
		while (p < n)		{	// ��û������ĵ�ǰ��㣬�����ȼ���
			cout << "{" << e.GetElem(p);
			out[p] = true;
			for (i = p + 1; i < n; i++)	{	// ����ȼ���
				if (!e.Differ(e.GetElem(p), e.GetElem(i)))	{	// p��i��ͬһ���ȼ�����
					cout << "," << e.GetElem(i);
					out[i] = true;
				}
			}
			cout << "}" << endl;
			while (p < n && out[p]) p++;
		}



	}
	catch (Error err)		// ��׽�������쳣
	{
		err.Show();			// ��ʾ�쳣��Ϣ
	}


	system("PAUSE");        // ���ÿ⺯��system()
	return 0;               // ����ֵ0, ���ز���ϵͳ
}


