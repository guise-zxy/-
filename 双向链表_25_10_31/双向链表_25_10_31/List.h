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

//1.��ӡ����
void LTPrint(LTNode* phead);



//2.���� ��ʼ�� �����������ڱ�λ����ͷ�ڵ㡱��
void LTInit(LTNode** pphead);


//3.�����ڵ㺯����������Ҫ�и��ܴ�����˫�������ڵ� �ĺ���LTBuyNode(),

LTNode* LTBuyNode(LTDataType x);



//���� �����ڵ㺯��֮�󣬾Ϳ���дβ�庯���ˣ�
void LTPushback(LTNode* phead, LTDataType x);

//ͷ�庯��
void LTPushfront()
{


}
