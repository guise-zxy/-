#define _CRT_SECURE_NO_WARNINGS
#include"SL.h"


//1,手动创建链表其实也行，但复用性不高；不好封装；



//2.创建单链表的节点函数，要传“数据”进去初始化
SLNode* SLBuy(SLData x)
{
	SLNode* node = (SLNode*)malloc(sizeof(SLNode));
	node->next = NULL;
	node->data = x;
	return node;
}




//3. 打印链表函数
void SLPrint(SLNode * head)
{
	//判断一开始传进来的指针是否为空，即链表为不为空；
	assert(head);

	//开始根据要打印的所指向当前链表的指针head依次根据next指针遍历每个元素，并打印；
	SLNode* cur = head;
	do {
		printf("%d ", cur->data);
		
	
	} while (cur=cur->next);

}


//4.尾插：注意链表为空的情况

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
	else                           //找尾部元素
	{
		while (cur)
		{
			dest = cur;
			assert(cur);
			cur = cur->next;
		}
		//跳出说明此时的node节点为链表尾部节点
		newnode->data = x;
		newnode->next = NULL;
		dest->next = newnode;
	}


}

