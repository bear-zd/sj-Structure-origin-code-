#include "HuffmanTree.h"	// ����������

int main(void)
{
    try	{					// ��try��װ���ܳ����쳣�Ĵ���
		char ch[] = {'A', 'B', 'C', 'D'}; 
		int w[] = {12, 3, 5, 9};
		int n = 4, i;

		HuffmanTree<char, int> hmTree1(ch, w, n);
		HuffmanTree<char, int> hmTree(hmTree1);
		hmTree = hmTree1;			
		String strText = "ABCDADCBD";	// �ı���
		String strCode = "100111010011";		// ���봮

		cout << "���ַ��ı���Ϊ:" << endl;
		for (i = 0; i < n; i++)  {
			String strTmp = hmTree.Encode(ch[i]);
			cout << ch[i] << " : " << strTmp.CStr() << endl;
		}
		
		cout << "�ı���" << strText.CStr() << "����Ϊ:";
		for (i = 0; i < strText.GetLength(); i++)		{
			String strTmp = hmTree.Encode(strText[i]);
			cout << strTmp.CStr();
		}
		cout << endl;
		system("PAUSE");	
		cout << "���봮" << strCode.CStr() << "����Ϊ:";
		LinkList<char> lkText = hmTree.Decode(strCode);
		strText = lkText;
		cout << strText.CStr() << endl;
	}
	catch (Error err)	{	// ��׽�������쳣
		err.Show();			// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");  
	return 0;        
}
