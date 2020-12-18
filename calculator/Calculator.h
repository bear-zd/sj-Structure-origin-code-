#include "LinkStack.h"			// ��ʽջ��
int OperPrior(char op1, char op2)
// ������������ز�����op1��op2���ȼ��ȽϽ�� 
{
   int prior;								// ���ȼ��ȽϽ�� 
   switch (op1) {
      case '+' :
      case '-' : if (op2 == '+' || op2 == '-' || op2 == ')' || op2 == '#')
                    prior = 2;
                 else
                    prior = 1;
                 break;
      case '*' :
      case '/' :
      case '^' :  if (op2 == '^' || op2 == '(')
                     prior = 1;
	                else
                     prior = 2;
	                break;
      case '(' :  if (op2 == ')')
                     prior = 0;
                  else if (op2 == '#')
                     prior = -1;
	                else
                     prior = 1;
	                break;
      case ')' :  if (op2 == '(')
                     prior = -1;
	                else
                     prior = 2;
	                break;
      case '#' :  if (op2 == ')')
                     prior = -1;
	                else if (op2 == '#')
	                   prior = 3;
	                else   
                     prior = 1;
	                break;
  }                
	return prior;									// �������ȼ�
}

double Operate(double first, char op, double second)
// ���������ִ������first op second
{
   double result;
   switch (op) {
	    case '+' : result = first + second;			    // �ӷ�����
                 break;
	    case '-' : result = first - second;			    // ��������
                 break;
	    case '*' : result = first * second;			    // �˷�����
                 break;
	    case '/' : if (second == 0)                 // �������� 
                    throw Error("��������Ϊ��!");	// �׳��쳣
                 result = first / second;			  
                 break;
	    case '^' : result = pow(first, second);	    // ������
	               break;
   }             
	 return result;									                // ���������� 
}

bool IsOperator(char ch)
// ����������ж�ch�Ƿ�Ϊ������ 
{
   if (ch == '#' || ch == '(' || ch == '^' || ch == '*' ||
      ch == '/' || ch == '+' || ch== '-' || ch == ')')
      return true;
   else
      return false;
};

void PostfixExpressionCalculation ()
// �����������׺ʽ�ļ��� 
{
   LinkStack<double> opnd;						// ������ջ
   char ch;							            // ��ʱ�ַ�
   double operand, first, second;			    // ������

   cout << "�����׺���ʽ,��'#'�Ž���:";
   ch = GetChar();						        // ����һ���ַ�
   while (ch != '#') {	                        // ��ǰ���ʽ��δ�������, ��������
	  if (isdigit(ch) || ch == '.')		{	    // chΪһ���������ĵ�1���ַ�
         cin.putback(ch);			            // ���ַ�ch�Ż�������
         cin >> operand;				        // ���������
         opnd.Push(operand);			        // ��������ջ 
	  }
	  else if(!IsOperator(ch) || ch == '(' || ch ==')') {// ch�Ȳ��ǲ�����,Ҳ�����ڲ�����
           throw Error("���ʽ���зǷ�����!");  // �׳��쳣
	  }
	  else {	                                // chΪ������
         if (opnd.Pop(second) == UNDER_FLOW)    // ȡ�ڶ������� 
            throw Error("ȱ�ٲ�����!");	        // ȡ��ʧ�ܣ����׳��쳣
         if (opnd.Pop(first) == UNDER_FLOW)     // ȡ��һ������ 
            throw Error("ȱ�ٲ�����!");	        // ȡ��ʧ�ܣ��׳��쳣
		 opnd.Push(Operate(first, ch, second));	// ��������opndջ
	  }
	  ch = GetChar();			                // �������ַ�
   }
   if (opnd.Pop(operand) == UNDER_FLOW)
      throw Error("ȱ�ٲ�����!");	            // �׳��쳣
   if (!opnd.IsEmpty())
      throw Error("ȱ�ٲ�����!");	            // �׳��쳣
   cout << "���ʽ���Ϊ��" << operand << endl;	// ��ʾ���ʽ��ֵ
};

void InfixInToPostfix()
// �����������׺ʽת��Ϊ��׺ʽ 
{
   LinkStack<char>   optr;						// ������ջ
   char ch;							            // ��ʱ�ַ�
   char priorChar;						        // ��ǰ�����ǰһ���ַ�
   char op = '#';						        // ������ջ��ջ���ַ�
   double operand;							    // ������ 
   int operandCount = 0;                        // ������������ 
   optr.Push('#');						        // �ڲ�����ջ�м���һ��'#'
   priorChar = '#';					            // ǰһ�ַ�
   cout << "������׺���ʽ,��'#'�Ž���:";
   ch = GetChar();						        // ����һ���ַ�
   while (op != '#' || ch != '#') {	    // ��ǰ���ʽ��δ�������, ��������
      if (isdigit(ch) || ch == '.')		{	    // chΪһ���������ĵ�1���ַ�
	     if (priorChar == '0' || priorChar == ')')
            throw Error("����������֮��ȱ�������!");     // �׳��쳣
         cin.putback(ch);			            // ���ַ�ch�Ż�������
         cin >> operand;				        // ���������
         cout << operand << "  ";			    // ��������� 
         operandCount++;                        // ��������Ŀ��1 
         priorChar = '0';			            // ǰһ�ַ��ǲ�����
         ch = GetChar();				        // ������һ���ַ�
	  }
	  else if(!IsOperator(ch)) {	            // �Ȳ��ǲ�����,Ҳ���ǲ�����
         throw Error("���ʽ���зǷ�����!");    // �׳��쳣
	  }
	  else {	// chΪ������
         if (ch == '(' && (priorChar == '0' || priorChar == ')'))
            throw Error("'('ǰȱ�ٲ�����!");	// �׳��쳣
         while (OperPrior(op, ch) == 2) {
            if (operandCount < 2)
               throw Error("ȱ�ٲ�����!");
            operandCount--;
            optr.Pop(op);
            cout << op << "  ";
		    if (optr.Top(op) == UNDER_FLOW)
               throw Error("ȱ�ٲ�����!");	    // �׳��쳣
         }
		 switch (OperPrior(op, ch)) {
			case -1 : throw Error("���Ų�ƥ��!");	
			case 0  : optr.Pop(op);
                      if (optr.Top(op) == UNDER_FLOW) 
                         throw Error("ȱ�ٲ�����!");  // �׳��쳣
			          priorChar = ch;		    // �µ�ǰһ�ַ�Ϊ(
			          ch = GetChar();			// �������ַ�
                      break;
            case 1  : optr.Push(ch);
			          op = ch;
			          priorChar = ch;		    // �µ�ǰһ�ַ�Ϊ)
			          ch = GetChar();			// �������ַ�
                      break;
         }
	  }
   }
   if (operandCount != 1)
      throw Error("ȱ�ٲ�����!");	                        // �׳��쳣
   cout << endl;
};
