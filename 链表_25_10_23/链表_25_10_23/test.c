#define _CRT_SECURE_NO_WARNINGS

#include"SL.h"

int main()
{
	//3.测试创建节点函数   和   打印函数
	
	SLNode* node1 = SLBuy(1);
	SLNode* node2 = SLBuy(2);
	SLNode* node3 = SLBuy(3);
	
	//4.测试尾插
	Pushback(&node1, 67);
	Pushback(&node1, 68);
	SLPrint(node1);
	//5.测试头插
	Pushfront(&node1, 456);
	Pushfront(&node1, 897);
		SLPrint(node1);

	//6.测试尾删
	Popback(&node1);
	SLPrint(node1);
	

	//7.测试头删
	Popfront(&node1);
	SLPrint(node1);

	/*Popfront(&node1);
	SLPrint(node1);*/


	//8.测试 查找
	SLNode* p = SLFind(&node1, 1);
	//if (p != NULL)
	//{
	//	printf("%d\n", p->data);
	//}
	//else
	//{
	//	printf("没找到");
	//}

	//9.测试 在指定位置pos之前插入元素x;
	SLInsertBefore(&node1,p, 57);
	SLPrint(node1);
	SLInsertBefore(&node1,p, 547);
	SLPrint(node1);

	SLNode* node5 = SLBuy(90);
	    //pos之前插入要特别考虑的情况：*pphead==pos
	SLInsertBefore(&node5, node5, 57);
	SLPrint(node5);



	//10.测试 在指定位置pos之后插入元素x;
	SLInsertAfter( p, 8866);
	SLPrint(node1);

	SLInsertAfter(node5, 7789);
	SLPrint(node5);

//11.测试 删除pos之前的元素（即pos本身）
EraseBefore(&node5,node5);
SLPrint(node5);


//12.测试 删除pos之后的元素；

Pushback(&node5,4);
Pushback(&node5,5);
SLPrint(node5);
EraseAfter(node5);
EraseAfter(node5);
SLPrint(node5);


//13.测试销毁函数；
SLDestroy(&node5);

//方法一：直接打印，SLPrint函数会报错，此时链表为NULL；
//SLPrint(node5);
//方法二：调试观察；


	return 0;

}


