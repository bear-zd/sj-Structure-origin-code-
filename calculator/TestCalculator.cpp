#include "Calculator.h"

int main(void)
{
	char c = '1';

    while (c != '0')
	{
        cout << endl << "1. ��׺ʽ�ļ���.";
        cout << endl << "2. ��׺ʽת��Ϊ��׺ʽ.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~2):";
		cin >> c;
		switch (c) 	{
			case '1':
      			GetChar();              // ��ȡ�س��� 
      			try { 
		     		PostfixExpressionCalculation();
      			}
	    		catch (Error err)	{	// ��׽�������쳣
	         		cout << endl;
		     		err.Show();			// ��ʾ�쳣��Ϣ
	    		}
				break;
	       case '2':
      			GetChar();              // ��ȡ�س��� 
      			try { 
		     		InfixInToPostfix();
      			}
	    		catch (Error err)	{	// ��׽�������쳣
	         		cout << endl;
		     		err.Show();			// ��ʾ�쳣��Ϣ
	    		}
				break;
		}
	}

	system("PAUSE"); 
	return 0;   
}
