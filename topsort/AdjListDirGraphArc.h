#ifndef __ADJ_LIST_NETWORK_ARC_H__
#define __ADJ_LIST_NETWORK_ARC_H__

// �ڽӱ�����������
struct AdjListGraphArc
{
// ���ݳ�Ա:
	int adjVex;								// ��ͷ�������
	AdjListGraphArc *nextArc; // ��һ���߽���ָ��
// ���캯��:
	AdjListGraphArc();					// �޲����Ĺ��캯��
	AdjListGraphArc(int v, AdjListGraphArc * next = NULL);
          // �����ڽӵ�Ϊv��ȨΪw���ڽӱ�
};

// �ڽӱ������������ʵ�ֲ���
AdjListGraphArc::AdjListGraphArc()
// �������������һ�����ڽӱ�߽��ߨD�D�޲ι��캯��
{
	adjVex = -1;
}

AdjListGraphArc::AdjListGraphArc(int v, AdjListGraphArc *next)
// ��������������ڽӵ����Ϊv���ߵ�ȨΪw����һ���߽���ָ��Ϊnext���ڽӱ�
{
	adjVex = v;
    nextArc = next;
}

#endif
