#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
typedef int SLData;

                                         //����ڵ�
typedef struct SLNode {
	SLData data;
	struct SLNode* next;
}SLNode;



//��������ֶ���������




//2.�����ڵ㺯��

SLNode* SLBuy(SLData x);


//3.  ��ӡ��������
void SLPrint(SLNode* head);


//4.β�壺�ر���ע������Ϊ�յ����

void Pushback(SLNode** pphead, SLData x);


//5.ͷ��

void Pushfront(SLNode** pphead, SLData x);


//6.βɾ:�ر���ע�� ���� ֻ��һ��Ԫ�ص��������������assertҲҪ�ж������Ƿ�Ϊ��
void Popback(SLNode** pphead);



//7.ͷɾ
void Popfront(SLNode** pphead);


//8.����
SLNode* SLFind(SLNode** pphead, SLData x);


//9.��ָ��λ��pos֮ǰ����Ԫ�أ�Ҫ���ǵ���pos֮ǰ��Ԫ��pre
void SLInsertBefore(SLNode** pphead, SLNode* pos, SLData x);


//10.��ָ��λ��pos֮�����Ԫ�أ����ô�pos֮ǰ��Ԫ��pre;
void SLInsertAfter( SLNode* pos, SLData x);

//11.��ָ��λ��pos֮ǰ ɾ�� Ԫ�أ�
void EraseBefore(SLNode** pphead, SLNode* pos);


//12.��ָ��λ��pos֮��ɾ��Ԫ��
void EraseAfter(SLNode* pos);



//13.�������ٺ���
void SLDestroy(SLNode** pphead);
