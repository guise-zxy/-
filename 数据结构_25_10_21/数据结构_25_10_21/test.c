#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"


int main() {
	//1.测试初始化
	SL s1;
	SLInit(&s1);




	//2.测试 头插
	  Pushfront(&s1, 1);
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  Pushfront(&s1, 2);
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  Pushfront(&s1, 3);	
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  print(&s1);


	  //3.测试尾插
	  Pushback(&s1, 67);
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  print(&s1);

	  Pushback(&s1,4);
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  print(&s1);
	


	//4.测试头删
	  Popfront(&s1);
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  print(&s1);

	  Popfront(&s1);
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  print(&s1);


	  //5.测试指定位置插入  Insert
	  Insert(&s1,3,78);
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  print(&s1);

	  Insert(&s1, 3, 785);
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  print(&s1);


	  //6,指定位置删除
	 

	  Erase(&s1,0);
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  print(&s1);

	  Erase(&s1, 3);
	  printf("%d %d\n", (&s1)->capacity, (&s1)->size);
	  print(&s1);


	  //7.测试7.查找指定元素/修改
	  int ret = Find(&s1, 4);
		  printf("%d", ret);
	return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                            