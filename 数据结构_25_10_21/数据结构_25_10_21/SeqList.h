#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
  /*       1.���ݽṹ��˳���
   ��ʼ��
   ����ͷ�壬β�壬��ָ��λ���ϲ��롣
   ɾ��ͷɾ��βɾ����ָ��λ��ɾ��
   ��/�ģ�����ĳ��Ԫ�أ������ض�ӦԪ�ص��±�ֵ��
   ����                                
   */
typedef int SLDateType;
typedef struct SeqList {                                        //��̬˳��������
	SLDateType * arr;
	int size;
	int capacity;
}SL;

void print(SL* p);
void SLInit(SL* p);                     //��ʼ��
void  Pushfront(SL* p, SLDateType x);  //ͷ��
void Pushback(SL*, SLDateType x);      //β��

void Popfront(SL* p);                  //ͷɾ
void Popback(SL* p);				   //βɾ

void Insert(SL* p, int pos, SLDateType x);   //ָ��λ�ò���
void Erase(SL* p, int pos);          //ָ��λ��ɾ��

int  Find(SL* p, SLDateType x);



