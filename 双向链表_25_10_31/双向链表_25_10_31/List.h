#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
typedef int LTDataType;

typedef struct  LTNode {
	LTDataType data;
	struct LTNode* next;
	struct LTNode* pre;
}LTNode;

//1.打印函数
void LTPrint(LTNode* phead);



//2.声明 初始化 函数，创建哨兵位即“头节点”；
void LTInit(LTNode** pphead);


//3.创建节点函数；那首先要有个能创建“双向链表”节点 的函数LTBuyNode(),

LTNode* LTBuyNode(LTDataType x);



//有了 创建节点函数之后，就可以写尾插函数了；
void LTPushback(LTNode* phead, LTDataType x);

//头插函数
void LTPushfront()
{


}
