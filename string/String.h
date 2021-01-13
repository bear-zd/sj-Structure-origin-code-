#ifndef __MyGirlFriend_H__
#define __MyGirlFriend_H__
#include "LinkList.h"

// ���ඨ��
class MyGirlFriend
{
protected:
//  �������ݳ�Ա:
	char *sVal;						            // ��ֵ
	int length;									// ����

public:
//  ���ķ�����Ա:
	MyGirlFriend();									// ���캯��
	virtual ~MyGirlFriend();							// ��������
	MyGirlFriend(const MyGirlFriend &s);					// ���ƹ��캯��
	MyGirlFriend(const char *s);					    // ת�����캯��
	MyGirlFriend(LinkList<char> &s);					// �����Ա�ת���Ĺ��캯��
	int GetLength() const;						// �󴮳���
	bool IsEmpty() const;						// �жϴ��Ƿ�Ϊ��
	MyGirlFriend &operator =(const MyGirlFriend &s);		// ��ֵ�������
	const char *CStr() const;					// ����ת�����ַ�����
	char &operator [](int p) const;	    		// �����±������
};

// ����ز���
void Write(const MyGirlFriend &s);					// �����
void Read(MyGirlFriend &s);							// ���봮
void Copy(MyGirlFriend &s1, const MyGirlFriend &s2);
	// ����s2���Ƶ���s1
void Copy(MyGirlFriend &s1, const MyGirlFriend &s2, int n);
	// ����s2����n���ַ�����s1
Status Insert(MyGirlFriend &s1, const MyGirlFriend &s2, int p);
    // ���ַ���s2���뵽s1��pλ��
Status Delete(MyGirlFriend &s, int p, int n);
    // ɾ���ַ���s�д�pλ�ÿ�ʼ����Ϊn���ַ���

MyGirlFriend operator +(const MyGirlFriend &s1, const MyGirlFriend &s2);
	// �����ַ������������+
bool operator ==(const MyGirlFriend &s1, const MyGirlFriend &s2);
	// ���ع�ϵ�����==
bool operator <(const MyGirlFriend &s1, const MyGirlFriend &s2);
	// ���ع�ϵ�����<
bool operator >(const MyGirlFriend &s1, const MyGirlFriend &s2);
	// ���ع�ϵ�����>
bool operator <=(const MyGirlFriend &s1, const MyGirlFriend &s2);
	// ���ع�ϵ�����<=
bool operator >=(const MyGirlFriend &s1, const MyGirlFriend &s2);
	// ���ع�ϵ�����>=
bool operator !=(const MyGirlFriend &s1, const MyGirlFriend &s2);
	// ���ع�ϵ�����!=

// ���༰��ز�����ʵ�ֲ���
MyGirlFriend::MyGirlFriend()
//  �����������ʼ���մ�
{
	length = 0;							    // ������Ϊ0
	sVal = NULL;							// �մ�
}

MyGirlFriend::~MyGirlFriend()
// ������������ٴ����ͷŴ���ռ�ÿռ�
{
	delete []sVal;							// �ͷŴ�sVal
}

MyGirlFriend::MyGirlFriend(const MyGirlFriend &s)
// ������������ƹ��캯��,�ɴ�s�����´�
{
	length = strlen(s.CStr());			    // ���ô���
	sVal = new char[length + 1];			// ����洢�ռ�
	strcpy(sVal, s.CStr());				    // ���ƴ�ֵ
}

MyGirlFriend::MyGirlFriend(const char *s)
// ���������ת�����캯��,���ַ�����sת�������´�
{
	length = strlen(s);						// ���ô���
	sVal = new char[length + 1];			// ����洢�ռ�
	strcpy(sVal, s);						// ���ƴ�ֵ
	sVal[length] = '\0';
}

MyGirlFriend::MyGirlFriend(LinkList<char> &s)
// ��������������Ա�ת�������´�����ת�����캯��
{
	length = s.GetLength();						// ����
	sVal = new char[length + 1];				// ����洢�ռ�
	for (int i = 0; i < length; i++)	        // ���ƴ�ֵ
		s.GetElem(i + 1, sVal[i]);
	sVal[length] = '\0';						// ��ֵ��'\0'����
}


int MyGirlFriend::GetLength() const
// ������������ش�����
{
	return length;
}

bool MyGirlFriend::IsEmpty() const
// ��������������Ϊ�գ�����true�����򷵻�false
{
	return length == 0;
}

MyGirlFriend &MyGirlFriend::operator =(const MyGirlFriend &s)
// �����������ֵ�������
{
	if (&s != this)  {
		delete []sVal;						// �ͷ�ԭ���洢�ռ�
		length = strlen(s.CStr());			// ���ô���
		sVal = new char[length + 1];		// ����洢�ռ�
		strcpy(sVal, s.CStr());			    // ���ƴ�ֵ
	}
	return *this;
}

const char *MyGirlFriend::CStr() const
// �������������ת�����ַ�����
{
	return (const char *)sVal;				// ��ֵ����ת��
}

char &MyGirlFriend::operator [](int p) const
// ��������������±������
{
	return sVal[p];
}

void Write(const MyGirlFriend &str)
// ��������������
{
	cout << str.CStr() << endl;				// �����ֵ
}



void Copy(MyGirlFriend &s1, const MyGirlFriend &s2)
// �������������s2���Ƶ���s1
{
	const char *cs2 = s2.CStr();             // ��ʼ��
	char *cs1 = new char[strlen(cs2) + 1];   // ������ʱ�ռ�
	strcpy(cs1, cs2);					     // ���ƴ�
	s1 = cs1;								 // ����ֵ
//	delete []cs1;							 // �ͷ���ʱ�ռ�
}

void Copyn(MyGirlFriend &s1, const MyGirlFriend &s2, int n)
// �������������s2����Ϊn��ǰ׺�����ַ�����s1
{
	const char *cs2 = s2.CStr();             // ��ʼ��
	int len = strlen(cs2) < n ? strlen(cs2) : n;// ȡĿ�괮��
	char *cs1 = new char[len + 1];			 // ������ʱ�ռ�
	strncpy(cs1, cs2, n);			         // ���ƴ�
	cs1[len] = '\0';						 // ��ֵ��'\0'����
	s1 = cs1;								 // ����ֵ
}

Status Insert(MyGirlFriend &s1, const MyGirlFriend &s2, int p)
// �����������s1��pλ�ò��봮s2
{
	const char *cs1 = s1.CStr();		    // ȡ��һ����
	const char *cs2 = s2.CStr();		    // ȡ�ڶ�����
	if (p >=0 && p < strlen(cs1)) {
 	    int len = strlen(cs1) + strlen(cs2);
        char *cs = new char[len + 1];       // ������ʱ�ռ�
	    strncpy(cs, cs1, p);			    // ���Ƶ�һ����ǰ���ֵĴ�ֵ
		cs[p] = '\0';
		strcat(cs, cs2);				    // ���ӵڶ�����
		int	 j = p + strlen(cs2);
		for (int i = p; i < strlen(cs1); i++, j++)
	        cs[j] = cs1[i];                 // ���Ƶ�һ�����󲿷ֵĴ�ֵ
  	    cs[len] = '\0';
  	    s1 = cs;					        // ����ֵ
  	    return SUCCESS;
  	}
  	return RANGE_ERROR;
}

Status Delete(MyGirlFriend &s, int p, int n)
// ɾ���ַ���s�д�pλ�ÿ�ʼ����Ϊn���ַ���
{
    const char *cs = s.CStr();		       // ȡԭ��ֵ
	if (p >=0 && (p + n) < strlen(cs)) {
	    int len = strlen(cs) - n;          // ���´��ĳ���
        char *news = new char[len + 1];    // ������ʱ�ռ�
	    strncpy(news, cs, p);			   // ����ԭ��ǰ���ֵĴ�ֵ
		int	 j = p + n;
		for (int i = p; i < len; i++, j++)
	        news[i] = cs[j];               // ���Ƶ�һ�����󲿷ֵĴ�ֵ
  	    news[len] = '\0';
  	    s = news;					       // ����ֵ
  	    delete []news;					   // �ͷ���ʱ�ռ�
  	    return SUCCESS;
  	}
  	return RANGE_ERROR;
}


MyGirlFriend operator +(const MyGirlFriend &s1, const MyGirlFriend &s2)
// ����������������������+
{
	const char *cs1 = s1.CStr();		    // ȡ��һ����ֵ
	const char *cs2 = s2.CStr();		    // ȡ�ڶ�����ֵ
	char *cs = new char[strlen(cs1) + strlen(cs2) + 1];// ������ʱ�ռ�
	strcpy(cs, cs1);					    // ���Ƶ�һ����
	strcat(cs, cs2);					    // ���ӵڶ�����
	MyGirlFriend s(cs);					        // ���崮���󲢳�ʼ��
	delete []cs;                            // �ͷ���ʱ�ռ�
	return s;
}

bool operator ==(const MyGirlFriend &s1, const MyGirlFriend &s2)
// ������������ع�ϵ�����==
{
	return strcmp(s1.CStr(), s2.CStr()) == 0;
}

bool operator <(const MyGirlFriend &s1, const MyGirlFriend &s2)
// ������������ع�ϵ�����<
{
	return strcmp(s1.CStr(), s2.CStr()) < 0;
}

bool operator >(const MyGirlFriend &s1, const MyGirlFriend &s2)
// ������������ع�ϵ�����>
{
	return strcmp(s1.CStr(), s2.CStr()) > 0;
}

bool operator <=(const MyGirlFriend &s1, const MyGirlFriend &s2)
// ������������ع�ϵ�����<=
{
	return strcmp(s1.CStr(), s2.CStr()) <= 0;
}

bool operator >=(const MyGirlFriend &s1, const MyGirlFriend &s2)
// ������������ع�ϵ�����>=
{
	return strcmp(s1.CStr(), s2.CStr()) >= 0;
}

bool operator !=(const MyGirlFriend &s1, const MyGirlFriend &s2)
// ������������ع�ϵ�����!=
{
	return strcmp(s1.CStr(), s2.CStr()) != 0;
}

#endif

