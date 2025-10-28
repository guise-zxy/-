#define _CRT_SECURE_NO_WARNINGS
#include"SL.h"


//1,�ֶ�����������ʵҲ�У��������Բ��ߣ����÷�װ��



//2.����������Ľڵ㺯����Ҫ�������ݡ���ȥ��ʼ��
SLNode* SLBuy(SLData x)
{
	SLNode* node = (SLNode*)malloc(sizeof(SLNode));
	// ֻ������һ��malloc����Ҫ��֮��ȥ�жϷ��صĵ�ַ�Ƿ�ΪNULL�����Ǻ�ϰ�ߡ�
	if (node == NULL)
	{
		assert(node);
		
	}
	
	node->data = x;
	node->next = NULL;
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

	printf("\n");

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

//5.ͷ��

void Pushfront(SLNode** pphead, SLData x)
{
	assert(pphead);
	SLNode* newnode = SLBuy(x);
	newnode->next = *pphead;
	*pphead = newnode;
}



//6��βɾ
void Popback(SLNode** pphead)
{
	assert(pphead && *pphead);
	if ((*pphead)->next == NULL)  //�ж������Ƿ�ֻ��һ��Ԫ�أ��ǵĻ���Ҫ�޸� *pphead
	{
		free(*pphead);
		*pphead = NULL;

	}
	else              //������2��Ԫ�����ϣ�ֱ�ӿ�ʼ��β��Ԫ��
	{

		//����Ԫ�أ��ҵ�Ҫɾ��β��Ԫ��  ���� ��¼ β��Ԫ�ص�ǰһ��Ԫ�� pre 
		SLNode* cur = *pphead;
		SLNode* pre = *pphead; 
		
		//ע���Ⱥ�˳���ܵ�����������һcur��NULL����ֱ�ӽ����õĻ��ǻᱨ��ġ�
		while (cur->next)
		{
			pre = cur;
			cur = cur->next;
		}

		//��ʱ����ѭ��֮�󣬵�ǰ��cur��ָ��ľ��� β��Ԫ��,pre����ָ��ǰһ��Ԫ�ء�
		free(cur);
		cur = NULL;
		pre->next = NULL;

	}

}

//7.ͷɾ
void Popfront(SLNode** pphead)
{
	assert(pphead && *pphead);
	   //��ų�ʼͷ�ڵ���¸�Ԫ�صĵ�ַ������������ͷ�ڵ㣻
	SLNode* temp = (*pphead)->next;
	//���ɵ�ͷ�ڵ��nextָ��ָ��Ϊ�գ���free��
	//(*pphead)->next = NULL;           ���в���Ҳ��
	free(*pphead);
	(*pphead) = temp;
}

//8.����Ԫ��
SLNode* SLFind(SLNode** pphead, SLData x)
{
	assert(pphead && *pphead);
	SLNode* cur=*pphead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}


//9.��ָ��λ��pos֮ǰ����Ԫ�أ��������ҵ�pre�����ǵ��������ǲ���ͨ��pos���ҵ�pre�ģ����Եô�ͷ�ڵ�ָ��������Ѱ��ɾ��ָ��posλ�õ�Ԫ�ء�

void SLInsertBefore(SLNode** pphead, SLNode* pos, SLData x)
{
	assert(pphead && pos&& *pphead);
	assert(*pphead); //Ҳ���Լ��� �ж� *pphead��������Ϊ ����ɵĹ��ܣ������û����߼��ϲ��ᴫ��������   ��ҲҪע�⣻
	SLNode* node = SLBuy(x);

	//���*pphead==pos(������ֻ��һ��Ԫ�ص����)��Ҫ�����ó���������Ϊ��û�� pre Ԫ�� ���� Ҫ�޸ĵ�ǰ�����ͷ�ڵ�*pphead��
	if (*pphead==pos)
	{
		node->next = pos;
		*pphead = node;
	}
	// ���Ԫ��ʱ
	else
	{

		//��posλ��Ԫ�أ�����Ҫ��¼ pos ��ǰ��һ��Ԫ�� pre;
		SLNode* pre = *pphead;
		SLNode* cur = *pphead;
		while ((cur != NULL) && (cur != pos))
		{
			pre = cur;
			cur = cur->next;
		}
		//������˵�����������˵��һ�����ҵ�posλ���ϵ�Ԫ�أ������Է���һ���Ǽ����жϵ�ǰcur�Ƿ�ΪNULL��
		//������ʱcurΪpos����ʼ���� ���� ������
		pre->next = node;
		node->next = pos;

	}



}

//10.��ָ��λ��pos ֮�����Ԫ��,,,,,,,����ʱ���Բ���ͷ�ڵ�ĵ�ַ������ֱ��ͨ��pos�� ɾ��;�ֻ��߿��Խ���Ϊ����ɾ��posԪ�أ����������ҵ�pre�����ǵ��������ǲ���ͨ��pos���ҵ�pre�ģ����Եô�ͷ�ڵ�ָ��������Ѱ��
void SLInsertAfter( SLNode* pos, SLData x)
{
	assert(pos);
	SLNode* node = SLBuy(x);

	////�ҵ�posλ��                                      //���Բ���pos���ģ�ֱ���õ�pos�޸ģ��˴�Ϊ������롣
	//SLNode* cur = *pphead;
	//while ((cur != NULL) && cur != pos)
	//{
	//	cur = cur->next;
	//}

	//����ѭ������ʱ��cur��Ϊ pos����ʼ���в��������
	node->next = pos->next;
	pos->next = node;


}


//11.ɾ����ָ��λ��pos֮ǰ��Ԫ�أ���Ӱ�쵽posԪ�ر���λ�ã�����ʱpos==*pphead����ɾ��pos�Լ������Ե��� Popfront()������		2������ҵ�pre�����ǵ��������ǲ���ͨ��pos���ҵ�pre�ģ����Եô�ͷ�ڵ�ָ��������Ѱ��
//ɾ��ָ��posλ��֮ǰ��һ��Ԫ��pre��							
void EraseBefore(SLNode** pphead, SLNode* pos)
{
	assert(pphead && pos&&*pphead);
	//�����ܴ���*pphead==pos�������Ҫ�ر���
	
	if (pos == *pphead)
	{
		//����ͷɾ������
		Popfront(pphead);
	}
	else         //��posԪ�أ�����¼pre
	{
		SLNode* pre = *pphead;
		//SLNode* cur = *pphead;    
		while (pre->next != pos)
		{
			pre = pre->next;
		}
		
		//�ҵ���pre,��ʼ����
		pre->next = pos->next;
		free(pos);
		pos = NULL;


	}

}



//10.��ָ��λ��pos ֮��ɾ��Ԫ��,,,,,,,����ʱ���Բ���ͷ�ڵ�ĵ�ַ������ֱ��ͨ��pos�� ɾ��;֮ǰҪ����������Ϊ����ɾ��posԪ�أ����������ҵ�pre�����ǵ��������ǲ���ͨ��pos���ҵ�pre�ģ����Եô�ͷ�ڵ�ָ��������Ѱ��
//12.ɾ��ָ��posλ��֮���Ԫ�ء�
void EraseAfter(SLNode* pos)
{
	assert(pos&&pos->next);
	SLNode* del = pos->next;
	pos->next = del->next;
	//ɾ��del��
	free(del);
	del = NULL;
}


//13.�����������
void SLDestroy(SLNode** pphead)
{

	assert(pphead && *pphead);
	SLNode* cur = *pphead;
	//��ʼ���������һ��free�����curָ����ΪNULL��
	while (cur)
	{
		SLNode* temp = cur;  
		cur= (cur->next);
		free(temp);

	//����cur
	   


	}
	//��ָ�������ͷ�ڵ� *pphead  ��ΪNULL,��ʱ��ǰ�����ѱ����٣�
	*pphead = NULL;

}
