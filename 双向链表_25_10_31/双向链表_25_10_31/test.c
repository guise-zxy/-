#define _CRT_SECURE_NO_WARNINGS

#include"List.h"


int main() {

	//���Գ�ʼ������
	LTNode *plist=NULL;
	LTInit(&plist);
	
	//����β�岢�Ҳ��Դ�ӡ������
	//LTPushback(plist, 5);
	//LTPushback(plist, 9);
	//LTPushback(plist, 10);
	//LTPushback(plist, 12);
	LTPrint(plist);
	return 0;
}