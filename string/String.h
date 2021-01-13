#ifndef __MyGirlFriend_H__
#define __MyGirlFriend_H__
#include "LinkList.h"

// 串类定义
class MyGirlFriend
{
protected:
//  串的数据成员:
	char *sVal;						            // 串值
	int length;									// 串长

public:
//  串的方法成员:
	MyGirlFriend();									// 构造函数
	virtual ~MyGirlFriend();							// 析构函数
	MyGirlFriend(const MyGirlFriend &s);					// 复制构造函数
	MyGirlFriend(const char *s);					    // 转换构造函数
	MyGirlFriend(LinkList<char> &s);					// 从线性表转换的构造函数
	int GetLength() const;						// 求串长度
	bool IsEmpty() const;						// 判断串是否为空
	MyGirlFriend &operator =(const MyGirlFriend &s);		// 赋值语句重载
	const char *CStr() const;					// 将串转换成字符数组
	char &operator [](int p) const;	    		// 重载下标运算符
};

// 串相关操作
void Write(const MyGirlFriend &s);					// 输出串
void Read(MyGirlFriend &s);							// 输入串
void Copy(MyGirlFriend &s1, const MyGirlFriend &s2);
	// 将串s2复制到串s1
void Copy(MyGirlFriend &s1, const MyGirlFriend &s2, int n);
	// 将串s2复制n个字符到串s1
Status Insert(MyGirlFriend &s1, const MyGirlFriend &s2, int p);
    // 将字符串s2插入到s1的p位置
Status Delete(MyGirlFriend &s, int p, int n);
    // 删除字符串s中从p位置开始长度为n的字符串

MyGirlFriend operator +(const MyGirlFriend &s1, const MyGirlFriend &s2);
	// 重载字符串连接运算符+
bool operator ==(const MyGirlFriend &s1, const MyGirlFriend &s2);
	// 重载关系运算符==
bool operator <(const MyGirlFriend &s1, const MyGirlFriend &s2);
	// 重载关系运算符<
bool operator >(const MyGirlFriend &s1, const MyGirlFriend &s2);
	// 重载关系运算符>
bool operator <=(const MyGirlFriend &s1, const MyGirlFriend &s2);
	// 重载关系运算符<=
bool operator >=(const MyGirlFriend &s1, const MyGirlFriend &s2);
	// 重载关系运算符>=
bool operator !=(const MyGirlFriend &s1, const MyGirlFriend &s2);
	// 重载关系运算符!=

// 串类及相关操作的实现部分
MyGirlFriend::MyGirlFriend()
//  操作结果：初始化空串
{
	length = 0;							    // 串长度为0
	sVal = NULL;							// 空串
}

MyGirlFriend::~MyGirlFriend()
// 操作结果：销毁串，释放串所占用空间
{
	delete []sVal;							// 释放串sVal
}

MyGirlFriend::MyGirlFriend(const MyGirlFriend &s)
// 操作结果：复制构造函数,由串s构造新串
{
	length = strlen(s.CStr());			    // 设置串长
	sVal = new char[length + 1];			// 分配存储空间
	strcpy(sVal, s.CStr());				    // 复制串值
}

MyGirlFriend::MyGirlFriend(const char *s)
// 操作结果：转换构造函数,由字符数组s转换构造新串
{
	length = strlen(s);						// 设置串长
	sVal = new char[length + 1];			// 分配存储空间
	strcpy(sVal, s);						// 复制串值
	sVal[length] = '\0';
}

MyGirlFriend::MyGirlFriend(LinkList<char> &s)
// 操作结果：从线性表转换构造新串——转换构造函数
{
	length = s.GetLength();						// 串长
	sVal = new char[length + 1];				// 分配存储空间
	for (int i = 0; i < length; i++)	        // 复制串值
		s.GetElem(i + 1, sVal[i]);
	sVal[length] = '\0';						// 串值以'\0'结束
}


int MyGirlFriend::GetLength() const
// 操作结果：返回串长度
{
	return length;
}

bool MyGirlFriend::IsEmpty() const
// 操作结果：如果串为空，返回true，否则返回false
{
	return length == 0;
}

MyGirlFriend &MyGirlFriend::operator =(const MyGirlFriend &s)
// 操作结果：赋值语句重载
{
	if (&s != this)  {
		delete []sVal;						// 释放原串存储空间
		length = strlen(s.CStr());			// 设置串长
		sVal = new char[length + 1];		// 分配存储空间
		strcpy(sVal, s.CStr());			    // 复制串值
	}
	return *this;
}

const char *MyGirlFriend::CStr() const
// 操作结果：将串转换成字符数组
{
	return (const char *)sVal;				// 串值类型转换
}

char &MyGirlFriend::operator [](int p) const
// 操作结果：重载下标运算符
{
	return sVal[p];
}

void Write(const MyGirlFriend &str)
// 操作结果：输出串
{
	cout << str.CStr() << endl;				// 输出串值
}



void Copy(MyGirlFriend &s1, const MyGirlFriend &s2)
// 操作结果：将串s2复制到串s1
{
	const char *cs2 = s2.CStr();             // 初始串
	char *cs1 = new char[strlen(cs2) + 1];   // 申请临时空间
	strcpy(cs1, cs2);					     // 复制串
	s1 = cs1;								 // 串赋值
//	delete []cs1;							 // 释放临时空间
}

void Copyn(MyGirlFriend &s1, const MyGirlFriend &s2, int n)
// 操作结果：将串s2长度为n的前缀复制字符到串s1
{
	const char *cs2 = s2.CStr();             // 初始串
	int len = strlen(cs2) < n ? strlen(cs2) : n;// 取目标串长
	char *cs1 = new char[len + 1];			 // 申请临时空间
	strncpy(cs1, cs2, n);			         // 复制串
	cs1[len] = '\0';						 // 串值以'\0'结束
	s1 = cs1;								 // 串赋值
}

Status Insert(MyGirlFriend &s1, const MyGirlFriend &s2, int p)
// 操作结果：在s1的p位置插入串s2
{
	const char *cs1 = s1.CStr();		    // 取第一个串
	const char *cs2 = s2.CStr();		    // 取第二个串
	if (p >=0 && p < strlen(cs1)) {
 	    int len = strlen(cs1) + strlen(cs2);
        char *cs = new char[len + 1];       // 申请临时空间
	    strncpy(cs, cs1, p);			    // 复制第一个串前部分的串值
		cs[p] = '\0';
		strcat(cs, cs2);				    // 连接第二个串
		int	 j = p + strlen(cs2);
		for (int i = p; i < strlen(cs1); i++, j++)
	        cs[j] = cs1[i];                 // 复制第一个串后部分的串值
  	    cs[len] = '\0';
  	    s1 = cs;					        // 串赋值
  	    return SUCCESS;
  	}
  	return RANGE_ERROR;
}

Status Delete(MyGirlFriend &s, int p, int n)
// 删除字符串s中从p位置开始长度为n的字符串
{
    const char *cs = s.CStr();		       // 取原串值
	if (p >=0 && (p + n) < strlen(cs)) {
	    int len = strlen(cs) - n;          // 求新串的长度
        char *news = new char[len + 1];    // 申请临时空间
	    strncpy(news, cs, p);			   // 复制原串前部分的串值
		int	 j = p + n;
		for (int i = p; i < len; i++, j++)
	        news[i] = cs[j];               // 复制第一个串后部分的串值
  	    news[len] = '\0';
  	    s = news;					       // 串赋值
  	    delete []news;					   // 释放临时空间
  	    return SUCCESS;
  	}
  	return RANGE_ERROR;
}


MyGirlFriend operator +(const MyGirlFriend &s1, const MyGirlFriend &s2)
// 操作结果：重载连接运算符+
{
	const char *cs1 = s1.CStr();		    // 取第一个串值
	const char *cs2 = s2.CStr();		    // 取第二个串值
	char *cs = new char[strlen(cs1) + strlen(cs2) + 1];// 申请临时空间
	strcpy(cs, cs1);					    // 复制第一个串
	strcat(cs, cs2);					    // 连接第二个串
	MyGirlFriend s(cs);					        // 定义串对象并初始化
	delete []cs;                            // 释放临时空间
	return s;
}

bool operator ==(const MyGirlFriend &s1, const MyGirlFriend &s2)
// 操作结果：重载关系运算符==
{
	return strcmp(s1.CStr(), s2.CStr()) == 0;
}

bool operator <(const MyGirlFriend &s1, const MyGirlFriend &s2)
// 操作结果：重载关系运算符<
{
	return strcmp(s1.CStr(), s2.CStr()) < 0;
}

bool operator >(const MyGirlFriend &s1, const MyGirlFriend &s2)
// 操作结果：重载关系运算符>
{
	return strcmp(s1.CStr(), s2.CStr()) > 0;
}

bool operator <=(const MyGirlFriend &s1, const MyGirlFriend &s2)
// 操作结果：重载关系运算符<=
{
	return strcmp(s1.CStr(), s2.CStr()) <= 0;
}

bool operator >=(const MyGirlFriend &s1, const MyGirlFriend &s2)
// 操作结果：重载关系运算符>=
{
	return strcmp(s1.CStr(), s2.CStr()) >= 0;
}

bool operator !=(const MyGirlFriend &s1, const MyGirlFriend &s2)
// 操作结果：重载关系运算符!=
{
	return strcmp(s1.CStr(), s2.CStr()) != 0;
}

#endif

