#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"


int main() {
	//1.���Գ�ʼ��
	SL s1;
	SLInit(&s1);




	//2.���� ͷ��
	  Pushfront(&s1, 1);
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  Pushfront(&s1, 2);
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  Pushfront(&s1, 3);	
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  print(&s1);


	  //3.����β��
	  Pushback(&s1, 67);
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  print(&s1);

	  Pushback(&s1,4);
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  print(&s1);
	


	//4.����ͷɾ
	  Popfront(&s1);
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  print(&s1);

	  Popfront(&s1);
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  print(&s1);


	  //5.����ָ��λ�ò���  Insert
	  Insert(&s1,3,78);
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  print(&s1);

	  Insert(&s1, 3, 785);
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  print(&s1);


	  //6,ָ��λ��ɾ��
	 

	  Erase(&s1,0);
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  print(&s1);

	  Erase(&s1, 3);
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  print(&s1);


	  //7.����7.����ָ��Ԫ��/�޸�
	  int ret = Find(&s1, 4);
		  printf("%d", ret);
	return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                            