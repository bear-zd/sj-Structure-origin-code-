#include "CBLTree.h" // 孩子兄弟链表树
#include "Assistance.h"
//8 a a b a c a d c e c f e g e h f i
//5 a a b b c b d d e d f
int main()
{
	Tree<char> T;
	int n;
	char s,f;
	cout<<"请输入插入结点个数以及根节点"<<endl;
	cin>>n>>s;
	T.InsertFirst(s);
	for(int i = 0;i < n; i ++)
	{
		cout<<"请输入插入的第"<<i+1<<"个结点"<<endl;
		cin>>f>>s;
		T.Insert(f,s);
	}
	cout<<"先序遍历：";
	T.FirstRoot();
	cout<<endl;
	cout<<"高度："<<T.Height()<<endl;
	cout<<endl;
	cout<<"树的度："<<T.Degree()<<endl;
	return 0;
}

