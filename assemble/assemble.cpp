#include "SeqList.h"	// ˳�����

int main(void)
{
	char a[] = {'A','C','E','G','I'}, b[] = {'A','B','C','D','H','I','J'},e; 
	SeqList<char> la(a,5,50), lb(b,7,50), lc(50);
	
	for (int i = 1; i <= la.GetLength(); i++)	{
		la.GetElem(i, e);		// ȡ��la�е�i��Ԫ��e
		if (lb.LocateElem(e))   // ���e��lb�д洢,������뵽lc��
			lc.InsertElem(e); 
	}
	
	cout << "����A:";
	la.Traverse(Write);		    // ��ʾ����A
	cout << endl;

	cout << "����B:";
	lb.Traverse(Write);		    // ��ʾ����B
	cout << endl;

	cout << "����C:";
	lc.Traverse(Write);		    // ��ʾ����C
	cout << endl;

	system("PAUSE");            // ���ÿ⺯��system()��ͣϵͳ���� 
	return 0;                   // ���ز���ϵͳ
}
