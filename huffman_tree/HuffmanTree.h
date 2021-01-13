#ifndef __HUFFMAN_TREE_H__
#define __HUFFMAN_TREE_H__

#include "String.h"								// ����
#include "HuffmanTreeNode.h"					// �������������

// ����������
template <class CharType, class WeightType>
class HuffmanTree
{
protected:
//  �������������ݳ�Ա:
	HuffmanTreeNode<WeightType> *nodes;			// �洢�����Ϣ
	CharType *LeafChars;						// Ҷ����ַ���Ϣ
	String *LeafCharCodes;						// Ҷ����ַ�������Ϣ
	int num;									// Ҷ������

//	��������:
	void Select(int n, int &r1, int &r2);		// ��nodes[0 ~ n-1]��ѡ��˫��Ϊ0,Ȩֵ��С���������r1,r2
	void CreatHuffmanTree(CharType ch[], WeightType w[], int n);
		// ��n���ַ���Ȩֵ����һ�ù�������

public:
//  ���������������������ر���ϵͳĬ�Ϸ�������:
	HuffmanTree(CharType ch[], WeightType w[], int n);	// ��n���ַ���Ȩֵ�����������
	virtual ~HuffmanTree();						// ��������
	String Encode(CharType ch);					// ����
	LinkList<CharType> Decode(String strCode);	// ����
	HuffmanTree(const HuffmanTree<CharType, WeightType> &copy);	// ���ƹ��캯��
	HuffmanTree<CharType, WeightType> &operator=(const HuffmanTree<CharType, 
		WeightType>& copy);						// ��ֵ���������
};

// �����ֵܱ�ʾ�����������ʵ�ֲ���
template <class CharType, class WeightType>
void HuffmanTree<CharType, WeightType>::Select(int n, int &r1, int &r2)
// �����������nodes[0 ~ n-1]��ѡ��˫��Ϊ0,Ȩֵ��С���������r1,r2
{
	r1 = r2 = -1;
	for (int i = 0; i < n; i++)	    // ������ֵ��С���������
		if (nodes[i].parent == -1) 	// ֻ����˫�ײ�Ϊ-1�Ľ��
		   if (r1 == -1)	
			  r1 = i;
		   else if	(nodes[i].weight < nodes[r1].weight)	{
              r2 = r1;
              r1 = i;
           }
		   else if (r2 == -1 || nodes[i].weight < nodes[r2].weight)
	          r2 = i;
}

template <class CharType, class WeightType>
void HuffmanTree<CharType, WeightType>::CreatHuffmanTree(CharType ch[], WeightType w[], int n)
// �����������n���ַ���Ȩֵ����һ�ù�������
{
	num = n;					// Ҷ������
	int m = 2 * n - 1;			// ������

	nodes = new HuffmanTreeNode<WeightType>[m];
	LeafChars = new CharType[n];
	LeafCharCodes = new String[n];

	int i, p, q;					
	for (i = 0; i < n; i++)	{	// �洢Ҷ�����Ϣ
		nodes[i].weight = w[i];	
		nodes[i].leftChild = -1;
		nodes[i].rightChild = -1;
		nodes[i].parent = -1;
		LeafChars[i] = ch[i];	
	}

	for (i = n; i < m; i++){    // �����������
		int r1, r2;
		Select(i, r1, r2);
		// �ϲ���r1,r2Ϊ������
		nodes[r1].parent = nodes[r2].parent = i;// r1,r2��˫��Ϊi
		nodes[i].leftChild = r1;				// r1Ϊi������
		nodes[i].rightChild = r2;				// r2Ϊi���Һ���
		nodes[i].parent = -1;					// iΪ�µĸ���� 
		nodes[i].weight = nodes[r1].weight + nodes[r2].weight;//i��ȨΪr1,r2��Ȩֵ֮��
	}

	for (i = 0; i < n; i++)	{	    // ��n��Ҷ����ַ��ı���
		LinkList<char> charCode;	// �ݴ�Ҷ����ַ�������Ϣ
		q = i; 
        p = nodes[q].parent;
		while (p != -1)     {	    // ��Ҷ��㵽��������������
			if (nodes[p].leftChild == q)
                charCode.InsertElem(1, '0');// ���֧����Ϊ'0'
			else
                charCode.InsertElem(1, '1');// �ҷ�֧����Ϊ'1'
			q = p;
            p = nodes[q].parent;
		}
		LeafCharCodes[i] = charCode;		// �����ַ�����
	}
}


template <class CharType, class WeightType>
HuffmanTree<CharType, WeightType>::HuffmanTree(CharType ch[], WeightType w[], int n)
// ������������ַ�,Ȩֵ���ַ����������������
{
	CreatHuffmanTree(ch, w, n);				// ���ַ�,Ȩֵ���ַ����������������
}

template <class CharType, class WeightType>
HuffmanTree<CharType, WeightType>::~HuffmanTree()
// ������������ٹ�������
{	
	if (nodes != NULL) delete []nodes;					// �ͷŽ����Ϣ
	if (LeafChars != NULL) delete []LeafChars;			// �ͷ�Ҷ����ַ���Ϣ
	if (LeafCharCodes != NULL) delete []LeafCharCodes;	// �ͷ�Ҷ����ַ�������Ϣ
}

template <class CharType, class WeightType>
String HuffmanTree<CharType, WeightType>::Encode(CharType ch)
// ��������������ַ�����
{
	for (int i = 0; i < num; i++)	    // �ҵ��ַ�,�õ�����
		if (LeafChars[i] == ch)
           return LeafCharCodes[i];
	throw Error("�Ƿ��ַ�,�޷�����!");	// �׳��쳣
}

template <class CharType, class WeightType>
LinkList<CharType> HuffmanTree<CharType, WeightType>::Decode(String strCode)
// ����������Ա��봮strCode��������,���ر���ǰ���ַ�����
{
	LinkList<CharType> charList;		// ����ǰ���ַ�����
	int p = 2 * num - 2;
	for (int i = 0; i < strCode.GetLength(); i++)	{	// ����ÿλ����
		if (strCode[i] == '0')
            p = nodes[p].leftChild;	    // '0'��ʾ���֧	
		else
            p = nodes[p].rightChild;	// '1'��ʾ���֧	

		if (nodes[p].leftChild == -1 && nodes[p].rightChild == -1)	{
            // ����ʱ�Ӹ���㿪ʼ������һ��Ҷ���
			charList.InsertElem(charList.GetLength() + 1, LeafChars[p]);
			p = 2 * num - 2;           // �Ӹ���ʼ�������� 
		}
	}
	
	if (p != 2 * num - 2)                   //���һ�δ���û�ж�Ӧ�ַ� 
	   throw Error("���벻��,�޷�����!");	// �׳��쳣

	return charList;					    // ���ر���ǰ���ַ�����
}

template <class CharType, class WeightType>
HuffmanTree<CharType, WeightType>::HuffmanTree(const HuffmanTree<CharType, WeightType> &copy)
// ����������ɹ�������copy�����¹��������������ƹ��캯��
{
	num = copy.num;								// Ҷ������
	int m = 2 * num - 1;						// ������� 
	nodes = new HuffmanTreeNode<WeightType>[m];
	LeafChars = new CharType[num];	
	LeafCharCodes = new String[num];

	int i;			
	for (i = 0; i < m; i++)	                    // ���ƽ����Ϣ
		nodes[i] = copy.nodes[i];		
	
	for (i = 0; i < num; i++)	{	
		LeafChars[i] = copy.LeafChars[i];		// ����Ҷ����ַ���Ϣ
		LeafCharCodes[i] = copy.LeafCharCodes[i];// ����Ҷ����ַ�������Ϣ
	}
}

template <class CharType, class WeightType>
HuffmanTree<CharType, WeightType> &HuffmanTree<CharType, WeightType>::operator=(const HuffmanTree<CharType, WeightType>& copy)	
// �������������������copy��ֵ����ǰ��������������ֵ���������
{
	if (&copy != this)	{
		if (nodes != NULL) delete []nodes;					// �ͷŽ����Ϣ
		if (LeafChars != NULL) delete []LeafChars;			// �ͷ�Ҷ����ַ���Ϣ
		if (LeafCharCodes != NULL) delete []LeafCharCodes;	// �ͷ�Ҷ����ַ�������Ϣ

		num = copy.num;						// Ҷ������
		int m = 2 * num - 1;				// ������� 
		nodes = new HuffmanTreeNode<WeightType>[m];
		LeafChars = new CharType[num];	
		LeafCharCodes = new String[num];

		int i;						
		for (i = 0; i < m; i++)	            // ���ƽ����Ϣ
			nodes[i] = copy.nodes[i];	
		
		for (i = 0; i < num; i++)	{	
            LeafChars[i] = copy.LeafChars[i];		// ����Ҷ����ַ���Ϣ
			LeafCharCodes[i] = copy.LeafCharCodes[i];// ����Ҷ����ַ�������Ϣ
		}	
	}
	return *this;
}

#endif
