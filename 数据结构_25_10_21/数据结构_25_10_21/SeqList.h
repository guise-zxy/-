#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
  /*       1.数据结构：顺序表
   初始化
   增：头插，尾插，在指定位置上插入。
   删：头删，尾删，在指定位置删除
   查/改：查找某个元素，并返回对应元素的下标值，
   销毁                                
   */
typedef int SLDateType;
typedef struct SeqList {                                        //动态顺序表的声明
	SLDateType * arr;
	int size;
	int capacity;
}SL;

void print(SL* p);
void SLInit(SL* p);                     //初始化
void  Pushfront(SL* p, SLDateType x);  //头插
void Pushback(SL*, SLDateType x);      //尾插

void Popfront(SL* p);                  //头删
void Popback(SL* p);				   //尾删

void Insert(SL* p, int pos, SLDateType x);   //指定位置插入
void Erase(SL* p, int pos);          //指定位置删除

int  Find(SL* p, SLDateType x);



