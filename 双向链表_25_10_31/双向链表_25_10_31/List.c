#define _CRT_SECURE_NO_WARNINGS
#include"List.h"

//1.打印双向链表函数
void LTPrint(LTNode* phead)
{
	//判断phead是否为空，也是在判断当前链表是否为“双向链表”，若是双向链表，phead一定不为NULL；
	assert(phead);


	//开始从哨兵节点的下一个节点，即双向链表的 第一个 有效元素 开始遍历来打印；
	//pcur 用来存放当前遍历到的节点的指针；
	LTNode* pcur = phead->next;
	while (pcur!= phead)                       //注意：while 判断条件不能为 NULL，它与单链表不同，尾部元素的next的指针指向为phead;
	{
		printf(" %d", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}




//2.双向链表的初始化：即 哨兵位“头节点”的初始化；对双向链表进行操作，这个双向链表一定要有“哨兵位也就是“头节点”；
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



//3.创建节点函数;创建的每个节点的 pre和next 都指向自己；
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


//4.尾插函数

void LTPushback(LTNode* phead, LTDataType x)
{
	//因为一定会有哨兵位，即“头节点”，所以双向链表一定不为空；先判断
	assert(phead);
	//不为空，进行头插;
	//先创建数据为 x的节点->再尾插											
	LTNode* newnode = LTBuyNode(x);
	//a.先把newnode的指针处理完	   顺序必须为a->b->c,从后到前修改；原因为 如果你先修改了phead,那么之后你就通过不了head来去直接找到尾节点。 

	newnode->pre = phead->pre;
	newnode->next = phead;
	//b. 再把 双向链表 的尾部元素的指针修改；
	phead->pre->next = newnode;
	//c.再把  哨兵节点 的指针修改；
	phead->pre = newnode;

}
