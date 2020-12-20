#ifndef __SQ_STACK_H__
#define __SQ_STACK_H__
#include "Assistance.h"	// 辅助软件包


// 顺序栈模板类
template<class ElemType>
class SeqStack
{
protected:
// 顺序栈的数据成员:
	int top;										// 栈顶指针
	int maxSize;									// 栈的最大容量
	ElemType *elems;								// 元素存储空间
	int top2;


public:
//  顺序栈的方法声明及重载编译系统默认方法声明:
	SeqStack(int size = DEFAULT_SIZE);				// 构造函数
	virtual ~SeqStack();							// 析构函数
	int GetLength() const;							// 求栈的长度
	bool IsEmpty(char D) const;							// 判断栈是否为空
	void Clear();									// 将栈清空
	void Traverse(void (*Visit)(const ElemType &)) const;	// 遍历栈
	Status Push(const ElemType e);				    // 入栈
	Status Top(ElemType &e,char D) const;				    // 取顶元素
	SeqStack(const SeqStack<ElemType> &s);		// 复制构造函数
	SeqStack<ElemType> &operator =(const SeqStack<ElemType> &s); // 赋值语句重载
	Status PushD(const ElemType e , char D='L');				    // 入栈
	Status PopD(ElemType &e ,char D='L');					    // 出栈
};



//第4题，双栈共享一个储存空间
template <class ElemType>
Status SeqStack<ElemType> :: PushD(const ElemType e , char D )
{
     if(top==top2-1)
        return OVER_FLOW;
    else
    {
        if(D=='L'||D=='l')
            {elems[++top]=e;return SUCCESS;}
        else if(D=='R'||D=='r')
            {elems[--top2]=e;return SUCCESS;}
        else
            return RANGE_ERROR;
    }
}

template <class ElemType>
Status SeqStack<ElemType> :: PopD(ElemType &e , char D )
{

    if(IsEmpty(D))return UNDER_FLOW;
    else
    {
        if(D=='L'||D=='l')
            {e=elems[top--];return SUCCESS;}
        else if(D=='R'||D=='r')
            {e=elems[top2++]=e;return SUCCESS;}
        else
            return RANGE_ERROR;
    }
}
// 顺序栈类的实现部分
template<class ElemType>
SeqStack<ElemType>::SeqStack(int size)
// 操作结果：构造一个最大容量为size的空栈
{
	maxSize = size;						// 栈的最大容量
	top2=size;
	if (elems != NULL) delete []elems;	// 释放已有存储空间
	elems = new ElemType[maxSize];		// 分配新的存储空间
	top = -1;
}

template<class ElemType>
SeqStack<ElemType>::~SeqStack()
// 操作结果：销毁栈
{
	delete []elems;					// 释放栈的存储空间
}

template <class ElemType>
int SeqStack<ElemType>::GetLength() const
// 操作结果：返回栈中元素个数
{
	return maxSize-(top2-top);
}

template<class ElemType>
bool SeqStack<ElemType>::IsEmpty(char D) const
// 操作结果：如栈为空，则返回true，否则返回false
{
    if (D=='L'||D=='l')
        return top == -1;
    if(D == 'R'||D=='r')
        return top2==maxSize;
    return false;
}

template<class ElemType>
void SeqStack<ElemType>::Clear()
// 操作结果：清空栈
{
	top = -1;
	top2 = maxSize-1;
}

template <class ElemType>
void SeqStack<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
    int i;
	for (i = 0; i <= top ; i++)
		(*Visit)(elems[i]);
    for(;i<top2;i++);
    for(;i<maxSize;i++)
        (*Visit)(elems[i]);
}

template<class ElemType>
Status SeqStack<ElemType>::Push(const ElemType e)
// 操作结果：将元素e追加到栈顶,如成功则返加SUCCESS,如栈已满将返回OVER_FLOW
{
	if (top == maxSize - 1) // 栈已满
		return OVER_FLOW;
	else  {	// 操作成功
		elems[++top] = e;	// 将元素e追加到栈顶
		return SUCCESS;
	}
}

template<class ElemType>
Status SeqStack<ElemType>::Top(ElemType &e,char D) const
// 操作结果：如栈非空,用e返回栈顶元素,函数返回SUCCESS,否则函数返回UNDER_FLOW
{
	if(IsEmpty(D))	 // 栈空
		return UNDER_FLOW;
	else	{ // 栈非空,操作成功
		e = elems[top];	// 用e返回栈顶元素
		return SUCCESS;
	}
}


template<class ElemType>
SeqStack<ElemType>::SeqStack(const SeqStack<ElemType> &s)
// 操作结果：由栈s构造新栈--复制构造函数
{
    maxSize = s.maxSize;			    // 栈的最大容量
    if (elems != NULL) delete []elems;	// 释放已有存储空间
    elems = new ElemType[maxSize];		// 分配存储空间
	top = s.top;					    // 复制栈顶指针
	for (int i = 0; i <= top; i++)      // 从栈底到栈顶对栈s的每个元素进行复制
		elems[i] = s.elems[i];
}

template<class ElemType>
SeqStack<ElemType> &SeqStack<ElemType>::operator = (const SeqStack<ElemType> &s)
// 操作结果：将栈s赋值给当前栈--赋值语句重载
{
	if (&s != this)	{
	    maxSize = s.maxSize;			    // 栈的最大容量
	    if (elems != NULL) delete []elems;	// 释放已有存储空间
	    elems = new ElemType[maxSize];		// 分配存储空间
		top = s.top;					    // 复制栈顶指针
		for (int i = 0; i <= top; i++)		// 从栈底到栈顶对栈s的每个元素进行复制
			elems[i] = s.elems[i];
	}
	return *this;
}

#endif
