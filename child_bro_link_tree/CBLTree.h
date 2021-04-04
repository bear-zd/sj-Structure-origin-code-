#ifndef CBLTREE_H
#define CBLTREE_H
#include<iostream>
#include<queue>
using namespace std;
template <class T>
class Tree;//��ǰ����
template <class T>

class CBNode{

	public:
        CBNode<T> * firstchild;		//���ӽ��
		T data;
		CBNode<T> * nextbrother;	//�ֵܽ��
		//���캯��
		CBNode(){   firstchild = nextbrother = NULL;    }
		CBNode(const T & d,CBNode<T> * f,CBNode<T> * n):data(d),firstchild(f),nextbrother(n){}
};

template <class T>
class Tree{
	friend CBNode<T>;
	private:
		CBNode<T> * root;							//�����

		void FirstRoot(CBNode<T> * t);				//�ȸ�����
		void LastRoot(CBNode<T> * t);				//�������
		void Release(CBNode<T> * t);				//�ͷŽ�㼰�ӽڵ�
		CBNode<T> * search(T e,CBNode<T> * t);		//�������t�µ�e������ָ��
		CBNode<T> * search(T e){    return search(e,root);    };	//�����������е�e������ָ��
		int Height(CBNode<T> * t);					//�������ĸ߶�
		int Degree(CBNode<T> * t);
	public:
		Tree(){    root = NULL;    }				//���캯��
		~Tree(){    Release(root);    }				//��������
		bool InsertFirst(T r);						//��������
		bool Insert(T f,T s);						//������
		void FirstRoot(){    FirstRoot(root);    };	//�ȸ�����
		void LastRoot(){    LastRoot(root);    };	//�������
		int Height(){    return Height(root);    };	//�������߶�
		int Degree(){return Degree(root);};
};
template <class T>
int Tree<T>::Degree(CBNode<T> * t)
{
    int i=1,n=0;
    if(!t)
        return i;
    if(t->nextbrother!=NULL)
    {
        while(t->nextbrother!=NULL)
        {
            if(t->firstchild!=NULL)
                n=Degree(t->firstchild);
            t=t->nextbrother;
            i++;
        }
    return i>n?i:n;
    }
    else
        return Degree(t->firstchild);

}
//_______________________________________________________________________
template <class T>
int Tree<T>::Height(CBNode<T> * t)
{
	CBNode<T> * p;
	int h = 0;
	int h1 = 0;
	if(!t) return 0;
	p = t->firstchild;
	while(p)
	{
		h1 = Height(p);
		if(h1>h)
			h = h1;
		p = p->nextbrother;
	}
	return h+1;
}
//_______________________________________________________________________
template <class T>
bool Tree<T>::InsertFirst(T r)
{
	if(root)
	{
		cout<<"���������׽ڵ㣬���ͷź����"<<endl;
		return false;
	}
	CBNode<T> * p = new CBNode<T>(r,NULL,NULL);
	root = p;
	return true;
}
//_______________________________________________________________________
template <class T>
bool Tree<T>::Insert(T f,T s)
{
	CBNode<T> * q = search(f);
	if(!q)
	{
		cout<<"����ʧ�ܣ��Ҳ����ڵ㣺"<<s<<endl;
		return false;
	}
	CBNode<T> * p = new CBNode<T>(s,NULL,NULL);
	CBNode<T> * r = NULL;
	if(!(q->firstchild))
	{
		q->firstchild = p;
		return true;
	}
	else
	{
		r = q->firstchild;
		while(r->nextbrother)
		{
			r = r->nextbrother;
		}
		r->nextbrother = p;
		return true;
	}
	return false;
}
//_______________________________________________________________________
template <class T>
void Tree<T>::FirstRoot(CBNode<T> * t)
{
	if(t)
	{
		cout<<t->data<<" ";
		FirstRoot(t->firstchild);
		FirstRoot(t->nextbrother);
	}
}
//_______________________________________________________________________
template <class T>
void Tree<T>::LastRoot(CBNode<T> * t)
{
	if(t)
	{
		LastRoot(t->firstchild);
		cout<<t->data<<" ";
		LastRoot(t->nextbrother);
	}
}
//_______________________________________________________________________
template <class T>
void Tree<T>::Release(CBNode<T> * node)
{
	if(node != NULL)
	{
		Release(node->firstchild);
		Release(node->nextbrother);
		delete node;
	}
}
//_______________________________________________________________________
template <class T>
CBNode<T> * Tree<T>::search(T e,CBNode<T> * t)
{
	if(!t)
		return NULL;
	if(t->data == e)
		return t;
	CBNode<T> * p;
	p = search(e,t->firstchild);
	if(p)
		return p;
	return search(e,t->nextbrother);
}

#endif // CBLTREE_H
