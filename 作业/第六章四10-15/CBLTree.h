#ifndef CBLTREE_H
#define CBLTREE_H
#include<iostream>
#include<queue>
using namespace std;
template <class T>
class Tree;//提前声明
template <class T>

class CBNode{

	public:
        CBNode<T> * firstchild;		//孩子结点
		T data;
		CBNode<T> * nextbrother;	//兄弟结点
		//构造函数
		CBNode(){   firstchild = nextbrother = NULL;    }
		CBNode(const T & d,CBNode<T> * f,CBNode<T> * n):data(d),firstchild(f),nextbrother(n){}
};

template <class T>
class Tree{
	friend CBNode<T>;
	private:
		CBNode<T> * root;							//根结点

		void FirstRoot(CBNode<T> * t);				//先根遍历
		void LastRoot(CBNode<T> * t);				//后根遍历
		void Release(CBNode<T> * t);				//释放结点及子节点
		CBNode<T> * search(T e,CBNode<T> * t);		//搜索结点t下的e并返回指针
		CBNode<T> * search(T e){    return search(e,root);    };	//搜索整个树中的e并返回指针
		int Height(CBNode<T> * t);					//返回树的高度
		int Degree(CBNode<T> * t);
	public:
		Tree(){    root = NULL;    }				//构造函数
		~Tree(){    Release(root);    }				//析构函数
		bool InsertFirst(T r);						//插入根结点
		bool Insert(T f,T s);						//插入结点
		void FirstRoot(){    FirstRoot(root);    };	//先根遍历
		void LastRoot(){    LastRoot(root);    };	//后根遍历
		int Height(){    return Height(root);    };	//返回树高度
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
		cout<<"该树已有首节点，请释放后插入"<<endl;
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
		cout<<"插入失败，找不到节点："<<s<<endl;
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
