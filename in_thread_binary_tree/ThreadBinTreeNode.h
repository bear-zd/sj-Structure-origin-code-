#ifndef __IN_THREAD_BIN_TREE_NODE_H__
#define __IN_THREAD_BIN_TREE_NODE_H__

// ����������������
template <class ElemType>
struct ThreadBinTreeNode
{
// ���ݳ�Ա:
	ElemType data;							// ������
	ThreadBinTreeNode<ElemType> *leftChild;	// ����ָ����
	ThreadBinTreeNode<ElemType> *rightChild;// �Һ���ָ����
	int leftTag, rightTag;		            // ���ұ�־��

//	���캯��:
	ThreadBinTreeNode();					// �޲����Ĺ��캯�� 
	ThreadBinTreeNode(const ElemType &d,	// ������Ԫ��ֵ,ָ�뼰��־������
		ThreadBinTreeNode<ElemType> *lChild = NULL, 
		ThreadBinTreeNode<ElemType> *rChild = NULL,
		int leftTag = 0,
		int rightTag = 0);
};

// ����������������ʵ�ֲ���
template <class ElemType>
ThreadBinTreeNode<ElemType>::ThreadBinTreeNode()
// �������������һ��Ҷ���
{
	leftChild = rightChild = NULL;			// ����ָ����Ϊ��
	leftTag = rightTag = 0;			        // ���ñ�־��Ϊ0 
}

template <class ElemType>
ThreadBinTreeNode<ElemType>::ThreadBinTreeNode(const ElemType &d, 
		ThreadBinTreeNode<ElemType> *lChild, 
		ThreadBinTreeNode<ElemType> *rChild,
		int lTag,
		int rTag)
// �������������һ��������Ϊval,����ΪlChild,�Һ���ΪrChild�Ľ��,���
//	־ΪlTag,�ұ�־ΪrTag�Ľ��
{	
	data = d;								// ����Ԫ��ֵ
	leftChild = lChild;						// ����
	rightChild = rChild;					// �Һ���
	leftTag = lTag;							// ���־
	rightTag = rTag;						// �ұ�־
}

#endif

