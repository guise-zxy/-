#define _CRT_SECURE_NO_WARNINGS
#include"List.h"

//1.��ӡ˫��������
void LTPrint(LTNode* phead)
{
	//�ж�phead�Ƿ�Ϊ�գ�Ҳ�����жϵ�ǰ�����Ƿ�Ϊ��˫������������˫������pheadһ����ΪNULL��
	assert(phead);


	//��ʼ���ڱ��ڵ����һ���ڵ㣬��˫������� ��һ�� ��ЧԪ�� ��ʼ��������ӡ��
	//pcur ������ŵ�ǰ�������Ľڵ��ָ�룻
	LTNode* pcur = phead->next;
	while (pcur!= phead)                       //ע�⣺while �ж���������Ϊ NULL�����뵥����ͬ��β��Ԫ�ص�next��ָ��ָ��Ϊphead;
	{
		printf(" %d", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}




//2.˫������ĳ�ʼ������ �ڱ�λ��ͷ�ڵ㡱�ĳ�ʼ������˫��������в��������˫������һ��Ҫ�С��ڱ�λҲ���ǡ�ͷ�ڵ㡱��
void LTInit(LTNode ** pphead)
{
	*pphead = (LTNode*)malloc(sizeof(LTNode));
	if (*pphead == NULL)
	{
		perror("malloc failed!");
	}
	else
	{
		(*pphead)->next = (*pphead)->pre = *pphead;
		//return *pphead;
	}

}



//3.�����ڵ㺯��;������ÿ���ڵ�� pre��next ��ָ���Լ���
LTNode* LTBuyNode(LTDataType x) {
	LTNode* newnode = (LTNode *)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
	}
	else
	{
		newnode->data = x;
		newnode->next = newnode->pre = newnode;
		return newnode;
	}
}


//4.β�庯��

void LTPushback(LTNode* phead, LTDataType x)
{
	//��Ϊһ�������ڱ�λ������ͷ�ڵ㡱������˫������һ����Ϊ�գ����ж�
	assert(phead);
	//��Ϊ�գ�����ͷ��;
	//�ȴ�������Ϊ x�Ľڵ�->��β��											
	LTNode* newnode = LTBuyNode(x);
	//a.�Ȱ�newnode��ָ�봦����	   ˳�����Ϊa->b->c,�Ӻ�ǰ�޸ģ�ԭ��Ϊ ��������޸���phead,��ô֮�����ͨ������head��ȥֱ���ҵ�β�ڵ㡣 

	newnode->pre = phead->pre;
	newnode->next = phead;
	//b. �ٰ� ˫������ ��β��Ԫ�ص�ָ���޸ģ�
	phead->pre->next = newnode;
	//c.�ٰ�  �ڱ��ڵ� ��ָ���޸ģ�
	phead->pre = newnode;

}
