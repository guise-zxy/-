#define _CRT_SECURE_NO_WARNINGS

#include"SL.h"

int main()
{
	//3.���Դ����ڵ㺯��   ��   ��ӡ����
	
	SLNode* node1 = SLBuy(1);
	SLNode* node2 = SLBuy(2);
	SLNode* node3 = SLBuy(3);
	
	//4.����β��
	Pushback(&node1, 67);
	Pushback(&node1, 68);
	SLPrint(node1);
	//5.����ͷ��
	Pushfront(&node1, 456);
	Pushfront(&node1, 897);
		SLPrint(node1);

	//6.����βɾ
	Popback(&node1);
	SLPrint(node1);
	

	//7.����ͷɾ
	Popfront(&node1);
	SLPrint(node1);

	/*Popfront(&node1);
	SLPrint(node1);*/


	//8.���� ����
	SLNode* p = SLFind(&node1, 1);
	//if (p != NULL)
	//{
	//	printf("%d\n", p->data);
	//}
	//else
	//{
	//	printf("û�ҵ�");
	//}

	//9.���� ��ָ��λ��pos֮ǰ����Ԫ��x;
	SLInsertBefore(&node1,p, 57);
	SLPrint(node1);
	SLInsertBefore(&node1,p, 547);
	SLPrint(node1);

	SLNode* node5 = SLBuy(90);
	    //pos֮ǰ����Ҫ�ر��ǵ������*pphead==pos
	SLInsertBefore(&node5, node5, 57);
	SLPrint(node5);



	//10.���� ��ָ��λ��pos֮�����Ԫ��x;
	SLInsertAfter( p, 8866);
	SLPrint(node1);

	SLInsertAfter(node5, 7789);
	SLPrint(node5);

//11.���� ɾ��pos֮ǰ��Ԫ�أ���pos����
EraseBefore(&node5,node5);
SLPrint(node5);


//12.���� ɾ��pos֮���Ԫ�أ�

Pushback(&node5,4);
Pushback(&node5,5);
SLPrint(node5);
EraseAfter(node5);
EraseAfter(node5);
SLPrint(node5);


//13.�������ٺ�����
SLDestroy(&node5);

//����һ��ֱ�Ӵ�ӡ��SLPrint�����ᱨ����ʱ����ΪNULL��
//SLPrint(node5);
//�����������Թ۲죻


	return 0;

}


