#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
typedef int SLData;

                                         //����ڵ�
typedef struct SLNode {
	SLData data;
	struct SLNode * next;
}SLNode;



//��������ֶ���������




//2.�����ڵ㺯��

SLNode* SLBuy(SLData x);


//3.  ��ӡ��������
void SLPrint(SLNode* head);


//4.β�壺��ע������Ϊ�յ����

void Pushback(SLNode** pphead, SLData x);


//5.ͷ��

void Pushfront(SLNode** pphead, SLData x)
{

}
