#ifndef __STRING_H__
#define __STRING_H__
#include "LinkList.h"
// ���ඨ�� 
class String 
{
protected:
//  �������ݳ�Ա:
	char *sVal;						            // ��ֵ
	int length;									// ����	

public:                           
//  ���ķ�����Ա:
	String();									// ���캯�� 
	virtual ~String();							// ��������
	String(const String &s);					// ���ƹ��캯��
	String(const char *s);					    // ת�����캯��
	String(LinkList<char> &s);					// �����Ա�ת���Ĺ��캯��
	int GetLength() const;						// �󴮳���			 
	bool IsEmpty() const;						// �жϴ��Ƿ�Ϊ��
	String &operator =(const String &s);		// ��ֵ�������
	const char *CStr() const;					// ����ת�����ַ�����
	char &operator [](int p) const;	    		// �����±������
};

// ����ز���
void Write(const String &s);					// �����
void Copy(String &s1, const String &s2);
	// ����s2���Ƶ���s1
void Copy(String &s1, const String &s2, int n);
	// ����s2����n���ַ�����s1 
Status Insert(String &s1, const String &s2, int p);
    // ���ַ���s2���뵽s1��pλ�� 
Status Delete(String &s, int p, int n);
    // ɾ���ַ���s�д�pλ�ÿ�ʼ����Ϊn���ַ��� 
String SubString(const String &s, int p, int n);	
	// ��s�ĵ�p���ַ���ʼ�ĳ���Ϊn���Ӵ�
String operator +(const String &s1, const String &s2);
	// ���ع�ϵ�����+
bool operator ==(const String &s1, const String &s2);
	// ���ع�ϵ�����==
bool operator <(const String &s1, const String &s2);
	// ���ع�ϵ�����<
bool operator >(const String &s1, const String &s2);
	// ���ع�ϵ�����>
bool operator <=(const String &s1, const String &s2);
	// ���ع�ϵ�����<=
bool operator >=(const String &s1, const String &s2);
	// ���ع�ϵ�����>=
bool operator !=(const String &s1, const String &s2);
	// ���ع�ϵ�����!=

// ���༰��ز�����ʵ�ֲ���
String::String()
//  �����������ʼ���մ� 
{
	length = 0;							    // ������Ϊ0
	sVal = NULL;							// �մ�
}

String::~String()
// ������������ٴ����ͷŴ���ռ�ÿռ�
{
	delete []sVal;							// �ͷŴ�sVal
}

String::String(const String &s)
// ������������ƹ��캯��,�ɴ�s�����´�
{
	length = strlen(s.CStr());			    // ���ô���
	sVal = new char[length + 1];			// ����洢�ռ�
	strcpy(sVal, s.CStr());				    // ���ƴ�ֵ
}

String::String(const char *s)
// ���������ת�����캯��,���ַ�����sת�������´�
{
	length = strlen(s);						// ���ô���
	sVal = new char[length + 1];			// ����洢�ռ� 
	strcpy(sVal, s);						// ���ƴ�ֵ
	sVal[length] = '\0';
}

String::String(LinkList<char> &s)
// ��������������Ա�ת�������´�����ת�����캯��
{
	length = s.GetLength();						// ����
	sVal = new char[length + 1];				// ����洢�ռ� 
	for (int i = 0; i < length; i++)	        // ���ƴ�ֵ
		s.GetElem(i + 1, sVal[i]);
	sVal[length] = '\0';						// ��ֵ��'\0'����	
}


int String::GetLength() const
// ������������ش�����			 
{
	return length;
}

bool String::IsEmpty() const
// ��������������Ϊ�գ�����true�����򷵻�false
{
	return length == 0;
}

String &String::operator =(const String &s)
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

const char *String::CStr() const
// �������������ת�����ַ����� 
{
	return (const char *)sVal;				// ��ֵ����ת��
}

char &String::operator [](int p) const
// ��������������±������
{
	return sVal[p];
}

void Write(const String &str)
// ��������������
{
	cout << str.CStr() << endl;				// �����ֵ
}

void Copy(String &s1, const String &s2)
// �������������s2���Ƶ���s1
{
	const char *cs2 = s2.CStr();             // ��ʼ��
	char *cs1 = new char[strlen(cs2) + 1];   // ������ʱ�ռ�
	strcpy(cs1, cs2);					     // ���ƴ�
	s1 = cs1;								 // ����ֵ
//	delete []cs1;							 // �ͷ���ʱ�ռ�
}

void Copyn(String &s1, const String &s2, int n)
// �������������s2����Ϊn��ǰ׺�����ַ�����s1 
{
	const char *cs2 = s2.CStr();             // ��ʼ��
	int len = strlen(cs2) < n ? strlen(cs2) : n;// ȡĿ�괮��
	char *cs1 = new char[len + 1];			 // ������ʱ�ռ�
	strncpy(cs1, cs2, n);			         // ���ƴ�
	cs1[len] = '\0';						 // ��ֵ��'\0'����
	s1 = cs1;								 // ����ֵ
}

Status Insert(String &s1, const String &s2, int p)
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

Status Delete(String &s, int p, int n)
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

String SubString(const String &s, int p, int n)
// ��ʼ��������s���ڣ�0 <= p < s.GetLength()��0 <= n <= s.GetLength() - p
// ������������ش�s�ĵ�p���ַ���ʼ�ĳ���Ϊn���Ӵ�
{
	if  (0 <= p && p + n < s.GetLength() && 0 <= n)	{
		char *sub = new char[n + 1];		// ������ʱ�ռ�
		const char *strp = s.CStr();		// �����ַ�����
		strncpy(sub, strp + p, n);		    // ���ƴ�
		sub[n] = '\0';						// ��ֵ��'\0'����
		String cs(sub);					    // ���ɴ�����
		delete []sub;                       // �ͷ���ʱ�ռ�
		return cs;
	}
	else	{	// ���ؿմ�
		String cs("");						// ���ɿմ�����
		return cs;
	}
}

String operator +(const String &s1, const String &s2)
// ����������������������+ 
{
	const char *cs1 = s1.CStr();		    // ȡ��һ����ֵ 
	const char *cs2 = s2.CStr();		    // ȡ�ڶ�����ֵ 
	char *cs = new char[strlen(cs1) + strlen(cs2) + 1];// ������ʱ�ռ�
	strcpy(cs, cs1);					    // ���Ƶ�һ����
	strcat(cs, cs2);					    // ���ӵڶ�����
	String s(cs);					        // ���崮���󲢳�ʼ�� 
	delete []cs;                            // �ͷ���ʱ�ռ�
	return s;
}

bool operator ==(const String &s1, const String &s2)
// ������������ع�ϵ�����==
{
	return strcmp(s1.CStr(), s2.CStr()) == 0;
}

bool operator <(const String &s1, const String &s2)
// ������������ع�ϵ�����<
{
	return strcmp(s1.CStr(), s2.CStr()) < 0;
}

bool operator >(const String &s1, const String &s2)
// ������������ع�ϵ�����>
{
	return strcmp(s1.CStr(), s2.CStr()) > 0;
}

bool operator <=(const String &s1, const String &s2)
// ������������ع�ϵ�����<=
{
	return strcmp(s1.CStr(), s2.CStr()) <= 0;
}

bool operator >=(const String &s1, const String &s2)
// ������������ع�ϵ�����>=
{
	return strcmp(s1.CStr(), s2.CStr()) >= 0;
}

bool operator !=(const String &s1, const String &s2)
// ������������ع�ϵ�����!=
{
	return strcmp(s1.CStr(), s2.CStr()) != 0;
}

#endif

