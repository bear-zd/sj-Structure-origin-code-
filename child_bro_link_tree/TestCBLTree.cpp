#include "CBLTree.h" // �����ֵ�������
#include "Assistance.h"
//8 a a b a c a d c e c f e g e h f i
//5 a a b b c b d d e d f
int main()
{
	Tree<char> T;
	int n;
	char s,f;
	cout<<"���������������Լ����ڵ�"<<endl;
	cin>>n>>s;
	T.InsertFirst(s);
	for(int i = 0;i < n; i ++)
	{
		cout<<"���������ĵ�"<<i+1<<"�����"<<endl;
		cin>>f>>s;
		T.Insert(f,s);
	}
	cout<<"���������";
	T.FirstRoot();
	cout<<endl;
	cout<<"�߶ȣ�"<<T.Height()<<endl;
	cout<<endl;
	cout<<"���Ķȣ�"<<T.Degree()<<endl;
	return 0;
}

