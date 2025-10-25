#define _CRT_SECURE_NO_WARNINGS

#include"SL.h"

int main()
{
	SLNode* node1 = SLBuy(1);
	SLNode* node2 = SLBuy(2);
	SLNode* node3 = SLBuy(3);
	Pushback(&node1, 67);
	Pushback(&node1, 68);
	SLPrint(NULL);


	
	//SLPrint(node1);
	return 0;
}