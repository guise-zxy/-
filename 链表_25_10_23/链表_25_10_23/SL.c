#define _CRT_SECURE_NO_WARNINGS
#include"SL.h"


//1,�ֶ�����������ʵҲ�У��������Բ��ߣ����÷�װ��



//2.����������Ľڵ㺯����Ҫ�������ݡ���ȥ��ʼ��
SLNode* SLBuy(SLData x)
{
	SLNode* node = (SLNode*)malloc(sizeof(SLNode));
	node->next = NULL;
	node->data = x;
	return node;
}




//3. ��ӡ������
void SLPrint(SLNode * head)
{
	//�ж�һ��ʼ��������ָ���Ƿ�Ϊ�գ�������Ϊ��Ϊ�գ�
	assert(head);

	//��ʼ����Ҫ��ӡ����ָ��ǰ�����ָ��head���θ���nextָ�����ÿ��Ԫ�أ�����ӡ��
	SLNode* cur = head;
	do {
		printf("%d ", cur->data);
		
	
	} while (cur=cur->next);

}


//4.β�壺ע������Ϊ�յ����

void Pushback(SLNode** pphead, SLData x)
{
	assert(pphead);
	SLNode* newnode = SLBuy(x);
	SLNode* cur = *pphead;
	SLNode* dest = *pphead;
	if (cur == NULL)
	{
		newnode->data = x;
		newnode->next = NULL;
		*pphead = newnode;

	}
	else                           //��β��Ԫ��
	{
		while (cur)
		{
			dest = cur;
			assert(cur);
			cur = cur->next;
		}
		//����˵����ʱ��node�ڵ�Ϊ����β���ڵ�
		newnode->data = x;
		newnode->next = NULL;
		dest->next = newnode;
	}


}

