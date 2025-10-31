#define _CRT_SECURE_NO_WARNINGS

#include"List.h"


int main() {

	//测试初始化函数
	LTNode *plist=NULL;
	LTInit(&plist);
	
	//测试尾插并且测试打印函数；
	//LTPushback(plist, 5);
	//LTPushback(plist, 9);
	//LTPushback(plist, 10);
	//LTPushback(plist, 12);
	LTPrint(plist);
	return 0;
}