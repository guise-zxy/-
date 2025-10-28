#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
typedef int SLData;

                                         //定义节点
typedef struct SLNode {
	SLData data;
	struct SLNode* next;
}SLNode;



//最基本的手动创建链表




//2.创建节点函数

SLNode* SLBuy(SLData x);


//3.  打印单链表函数
void SLPrint(SLNode* head);


//4.尾插：特别处理注意链表为空的情况

void Pushback(SLNode** pphead, SLData x);


//5.头插

void Pushfront(SLNode** pphead, SLData x);


//6.尾删:特别处理注意 链表 只有一个元素的情况，，，，但assert也要判断链表是否为空
void Popback(SLNode** pphead);



//7.头删
void Popfront(SLNode** pphead);


//8.查找
SLNode* SLFind(SLNode** pphead, SLData x);


//9.在指定位置pos之前插入元素，要考虑到存pos之前的元素pre
void SLInsertBefore(SLNode** pphead, SLNode* pos, SLData x);


//10.在指定位置pos之后插入元素；不用存pos之前的元素pre;
void SLInsertAfter( SLNode* pos, SLData x);

//11.在指定位置pos之前 删除 元素；
void EraseBefore(SLNode** pphead, SLNode* pos);


//12.在指定位置pos之后删除元素
void EraseAfter(SLNode* pos);



//13.测试销毁函数
void SLDestroy(SLNode** pphead);
