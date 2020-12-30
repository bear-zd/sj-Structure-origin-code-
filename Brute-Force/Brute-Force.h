#ifndef __Brute_Force_H__
#define __Brute_Force_H__

#include "String.h"				// ����

int BF_find(const String &ob, const String &pat, const int p = 0)
// �������: ����ģʽ��pat��Ŀ�괮ob�д�λ��p��ʼ���Ӵ�������ҵ��򷵻ص�һ�γ��ֵ�λ�ã����򷵻�-1�� 
{
	int i = p, j = 0;
	while (i < ob.GetLength() && j < pat.GetLength()
        && pat.GetLength() - j <= ob.GetLength() - i)		
		if (ob[i] == pat[j])	{	// �����ȽϺ����ַ�
			i++; j++;
		}
		else	{	                // ָ�����,���¿�ʼ�µ�ƥ��
			i = i - j + 1; j = 0;
		}

	if (j >= pat.GetLength()) return i - j;// ƥ��ɹ�
	else return -1;						// ƥ��ʧ��
}

#endif

