#define _CRT_SECURE_NO_WARNINGS
#include"SL.h"


//1,手动创建链表其实也行，但复用性不高；不好封装；



//2.创建单链表的节点函数，要传“数据”进去初始化
SLNode* SLBuy(SLData x)
{
	SLNode* node = (SLNode*)malloc(sizeof(SLNode));
	// 只用用了一次malloc，都要在之后去判断返回的地址是否为NULL，这是好习惯。
	if (node == NULL)
	{
		assert(node);
		
	}
	
	node->data = x;
	node->next = NULL;
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

	printf("\n");

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

//5.头插

void Pushfront(SLNode** pphead, SLData x)
{
	assert(pphead);
	SLNode* newnode = SLBuy(x);
	newnode->next = *pphead;
	*pphead = newnode;
}



//6。尾删
void Popback(SLNode** pphead)
{
	assert(pphead && *pphead);
	if ((*pphead)->next == NULL)  //判断链表是否只有一个元素？是的话就要修改 *pphead
	{
		free(*pphead);
		*pphead = NULL;

	}
	else              //链表有2个元素以上，直接开始找尾部元素
	{

		//遍历元素，找到要删的尾部元素  并且 记录 尾部元素的前一个元素 pre 
		SLNode* cur = *pphead;
		SLNode* pre = *pphead; 
		
		//注意先后顺序不能调换，否则万一cur是NULL，那直接解引用的话是会报错的。
		while (cur->next)
		{
			pre = cur;
			cur = cur->next;
		}

		//此时跳出循环之后，当前的cur所指向的就是 尾部元素,pre就是指向前一个元素。
		free(cur);
		cur = NULL;
		pre->next = NULL;

	}

}

//7.头删
void Popfront(SLNode** pphead)
{
	assert(pphead && *pphead);
	   //存放初始头节点的下个元素的地址，方便最后更新头节点；
	SLNode* temp = (*pphead)->next;
	//将旧的头节点的next指针指向为空，再free；
	//(*pphead)->next = NULL;           这行不加也行
	free(*pphead);
	(*pphead) = temp;
}

//8.查找元素
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


//9.在指定位置pos之前插入元素；你必须得找到pre，但是单向链表是不能通过pos来找到pre的；所以得传头节点指针来遍历寻找删除指定pos位置的元素。

void SLInsertBefore(SLNode** pphead, SLNode* pos, SLData x)
{
	assert(pphead && pos&& *pphead);
	assert(*pphead); //也可以加上 判断 *pphead，但是因为 所完成的功能，所以用户在逻辑上不会传个空链表；   但也要注意；
	SLNode* node = SLBuy(x);

	//如果*pphead==pos(包含了只有一个元素的情况)，要单独拿出来处理，因为它没有 pre 元素 并且 要修改当前链表的头节点*pphead。
	if (*pphead==pos)
	{
		node->next = pos;
		*pphead = node;
	}
	// 多个元素时
	else
	{

		//找pos位置元素，并且要记录 pos 的前面一个元素 pre;
		SLNode* pre = *pphead;
		SLNode* cur = *pphead;
		while ((cur != NULL) && (cur != pos))
		{
			pre = cur;
			cur = cur->next;
		}
		//按理来说调用这个函数说明一定能找到pos位置上的元素，但是以防万一还是加上判断当前cur是否为NULL；
		//正常此时cur为pos，开始进行 插入 操作；
		pre->next = node;
		node->next = pos;

	}



}

//10.在指定位置pos 之后插入元素,,,,,,,，此时可以不传头节点的地址，，，直接通过pos来 删除;又或者可以解释为你想删除pos元素，那你必须得找到pre，但是单向链表是不能通过pos来找到pre的；所以得传头节点指针来遍历寻找
void SLInsertAfter( SLNode* pos, SLData x)
{
	assert(pos);
	SLNode* node = SLBuy(x);

	////找到pos位置                                      //可以不找pos在哪，直接拿到pos修改，此处为冗余代码。
	//SLNode* cur = *pphead;
	//while ((cur != NULL) && cur != pos)
	//{
	//	cur = cur->next;
	//}

	//出了循环，此时的cur即为 pos，开始进行插入操作；
	node->next = pos->next;
	pos->next = node;


}


//11.删除在指定位置pos之前的元素，会影响到pos元素本身位置；若此时pos==*pphead，则删除pos自己，可以调用 Popfront()函数；		2必须得找到pre，但是单向链表是不能通过pos来找到pre的；所以得传头节点指针来遍历寻找
//删除指定pos位置之前的一个元素pre。							
void EraseBefore(SLNode** pphead, SLNode* pos)
{
	assert(pphead && pos&&*pphead);
	//不可能存在*pphead==pos的情况，要特别处理；
	
	if (pos == *pphead)
	{
		//调用头删函数；
		Popfront(pphead);
	}
	else         //找pos元素，并记录pre
	{
		SLNode* pre = *pphead;
		//SLNode* cur = *pphead;    
		while (pre->next != pos)
		{
			pre = pre->next;
		}
		
		//找到了pre,开始操作
		pre->next = pos->next;
		free(pos);
		pos = NULL;


	}

}



//10.在指定位置pos 之后删除元素,,,,,,,，此时可以不传头节点的地址，，，直接通过pos来 删除;之前要传，那是因为你想删除pos元素，那你必须得找到pre，但是单向链表是不能通过pos来找到pre的；所以得传头节点指针来遍历寻找
//12.删除指定pos位置之后的元素。
void EraseAfter(SLNode* pos)
{
	assert(pos&&pos->next);
	SLNode* del = pos->next;
	pos->next = del->next;
	//删除del；
	free(del);
	del = NULL;
}


//13.单链表的销毁
void SLDestroy(SLNode** pphead)
{

	assert(pphead && *pphead);
	SLNode* cur = *pphead;
	//开始遍历，逐个一次free，最后将cur指针置为NULL；
	while (cur)
	{
		SLNode* temp = cur;  
		cur= (cur->next);
		free(temp);

	//更新cur
	   


	}
	//将指向链表的头节点 *pphead  置为NULL,此时当前链表已被销毁；
	*pphead = NULL;

}
