#ifndef __ADJ_LIST_NETWORK_VEX_H__
#define __ADJ_LIST_NETWORK_VEX_H__

// �ڽӱ�����������
template <class ElemType>
struct AdjListGraphVex
{
// ���ݳ�Ա:
	ElemType data;						// ����Ԫ��ֵ
	AdjListGraphArc *firstarc;
		// ָ���ڽ�����߽���ָ��

// ���캯��:
	AdjListGraphVex();				// �޲����Ĺ��캯��
	AdjListGraphVex(ElemType val,
		AdjListGraphArc *adj = NULL);
		// �в����Ĺ��캯��
};

// �ڽӱ������������ʵ�ֲ���
template <class ElemType>
AdjListGraphVex<ElemType>::AdjListGraphVex()
// �������������һ���ն�����D�D�޲ι��캯��
{
	firstarc = NULL;
}

template <class ElemType>
AdjListGraphVex<ElemType>::AdjListGraphVex(ElemType  val,
	AdjListGraphArc *adj)
// �����������������Ϊval,��Ϊeg�Ķ���
{
	data = val;
	firstarc = adj;
}

#endif
