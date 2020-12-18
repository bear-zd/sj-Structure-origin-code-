#include "LinkStack.h"	// ��ջ��

struct Datatypes
{
     short int retAddr;    //ģ�·��ص�ַ
     int nDisk;            //����n
     char SourcePeg;       //����A
     char AuxPeg;          //����B
     char DestPeg;         //����C
};

void SimuTowers(int n, char A, char B, char C)
{
     Datatypes  currArea;  //��ǰ������
     LinkStack<Datatypes> s;//ģ��ϵͳ����ʱ�Ķ�ջ
     char temp;
     short int i;

     //��ǰ��������ʼ��
     currArea.retAddr =1;
     currArea.nDisk =n;
     currArea.SourcePeg =A;
     currArea.AuxPeg =B;
     currArea.DestPeg =C;
     s.Push(currArea);      //��ǰ��������ջ
     //����Ϊģ�����
start:
     if (currArea.nDisk==1){
        cout << "Move Disk 1 from Peg " << currArea.SourcePeg
             << " to Peg " << currArea.DestPeg << endl;
        i=currArea.retAddr;
        s.Pop(currArea);                //��ջ�ָ���ǰ������
        switch(i)  {
           case 1: goto L1;
           case 2: goto L2;
           case 3: goto L3;
        }
     }

     //����ģ��ݹ��Ե��ù���
     s.Push(currArea);                  //��ǰ��������ջ
     currArea.nDisk--;
     temp = currArea.AuxPeg;
     currArea. AuxPeg =currArea.DestPeg;
     currArea.DestPeg =temp;
     currArea.retAddr =2;
     goto start;

     //����ģ�ⷵ�ص�һ�εݹ����
L2:
     cout << "Move Disk " << currArea.nDisk << " from Peg "
          << currArea.SourcePeg << " to Peg "
          << currArea.DestPeg << endl;
     s.Push(currArea);                            //��ǰ��������ջ
     currArea.nDisk--;
     temp = currArea.SourcePeg;
     currArea.SourcePeg = currArea.AuxPeg;
     currArea.AuxPeg=temp;
     currArea.retAddr=3;
     goto start;

     //����ģ�ⷵ�صڶ��εݹ����
L3:
     i = currArea.retAddr;
     s.Pop(currArea);         //��ջ�ָ���ǰ������
     switch(i){
        case 1: goto L1;
        case 2: goto L2;
        case 3: goto L3;
     }
     //����ģ�ⷵ��������
L1:
     return;
}

int main(void)
{
    int n;
    cout << "��������������";
    cin >> n; 
    SimuTowers(n,'A','B','C');
	system("PAUSE");  
	return 0;  
}


