#include <cstring>					// ��׼������
#include <iostream>					// ��׼������
#include <cassert>					// ֧�ֶ���
using namespace std;				// ��׼������������ռ�std��


void reversename(char *name , char *newname)
{
    char *p;
    p = strchr(name , ' ');       //pָ�ڿո�' 'λ��
    *p = '\0';                    //�ѿո�Ϊ�������������name�ĳ���ֻ������
    strcpy(newname , p+1);        //p+1��name�գ����newname����name����
    strcat(newname , ",");        //newname�����ռӶ���
    strcat(newname , name);       //newname�����ռӶ��ż���
    *p = ' ';                     //�ָ�nameΪ��ʼʱ��״̬
    return;
}

int main()
{
    char name[30], newname[30];
    cout << "����һ��������������ǰ�����ں��м���һ���ո�ָ���" << endl; 
    cin.getline(name,30,'\n');    //���볤�Ȳ�����30���ַ���name
    reversename(name , newname);
    cout << "reversename:" << newname << endl;

	system("PAUSE");             
	return 0;               
}
