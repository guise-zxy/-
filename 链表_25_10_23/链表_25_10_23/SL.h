#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
typedef int SLData;

                                         //定义节点
typedef struct SLNode {
	SLData data;
	struct SLNode * next;
}SLNode;



//最基本的手动创建链表




//2.创建节点函数

SLNode* SLBuy(SLData x);


//3.  打印单链表函数
void SLPrint(SLNode* head);


//4.尾插：需注意链表为空的情况

void Pushback(SLNode** pphead, SLData x);


//5.头插

void Pushfront(SLNode** pphead, SLData x)
{

}
