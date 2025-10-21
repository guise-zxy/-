#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"
//为了方便测试而写的print函数
void print(SL* p)
{
	for (int i = 0; i < p->size; i++)
	{
		printf(" %d ", p->arr[i]);
	}
	printf("\n");
}






//1.初始化  和 CapacityCheck（）
void SLInit(SL* p)
{
	assert(p);
	p->arr = NULL;
	p->size = p->capacity = 0;
}

void CapacityCheck(SL* p)
{
	assert(p);
	if (p->capacity ==p->size)
	{	
		int newcapacity = p->capacity == 0 ? 4 : 2 * p->capacity;
		SL *temp = (SL *)realloc(p->arr,newcapacity* sizeof(SLDateType));
		if (temp != NULL)p->arr = temp;
		p->capacity = newcapacity;

	}
	
}


//2.头插
void  Pushfront(SL* p,SLDateType x)
{
	assert(p);

	//判断capacity大小即顺序表空间是否够插入元素 “CapacityCheck()函数“ ；检查“capacity”并且 不够“CapacityCheck()函数“增容””
	//!!!!!!!1！1调用CapacityCheck（）!1111!!!!!!!
	CapacityCheck(p);

	//  a.开始把下标为1及1后的所有元素往后移，流出头元素：下标0；
	for (int i = p->size; i >=1; i--)
	{
		p->arr[i] = p->arr[i-1];
	}

	
	//b.插入元素
	 p->arr[0] = x;

	//c.size+1；
	 p->size++;

}




//3.尾插

void  Pushback(SL* p, SLDateType x)
{
	assert(p);
	assert(p->size);
	//判断capacity大小即顺序表空间是否够插入元素 “CapacityCheck()函数“ ；检查“capacity”并且 不够“CapacityCheck()函数“增容””
	//!!!!!!!1！1调用CapacityCheck（）!1111!!!!!!!
	CapacityCheck(p);


	//b.插入元素
	p->arr[p->size] = x;

	//c.size+1；
	p->size++;

}


// 4.头删：一定要检查 size是否为 0个

void Popfront(SL* p)
{
	assert(p);
	assert(p->size);

	//a.向前挪动
	if (p->arr != NULL)
	{
		for (int i = 0; i <p->size-1 ; i++)
		{
			p->arr[i] = p->arr[i + 1];
		}
	}

	//b.size减1
	p->size--;
}


////5.尾删
void Popback(SL* p)
{
	assert(p);

	assert(p->size);
	

	//b.size减1
	p->size--;
}

// 6.在指定位置pos之前插入元素

void Insert(SL* p, int pos, SLDateType x)
{
	assert(p);

	assert(pos >= 0 && pos <=p->size);                           //注意：可以指定size位置上插入元素！1111111111111111111111
	CapacityCheck(p);


	//a.在pos下标及pos开始向后挪动,从后向前挪动
	for (int i = p->size; i >=pos+1; i--) 
	{
		p->arr[i] = p->arr[i - 1];
	}
	//b.插入元素
	p->arr[pos] = x;
	
	p->size++;

}

//7.在指定位置删除元素

void Erase(SL* p, int pos)
{
	assert(p);
	assert(p->size);
	assert(pos >= 0 && pos < p->size );
	//把下标pos元素及pos开始以后的元素向前移；
	for (int i = pos; i<p->size-1; i++)
	{
		p->arr[i] = p->arr[i + 1];
	}

	p->size--;

}


//8.查找元素/修改
int  Find(SL* p, SLDateType x)
{
	assert(p);
	assert(p->arr);

	for (int i = 0; i < p->size; i++)
	{
		if (p->arr[i] == x)
		{
			return  i;
		}
	}
	return -1;
}

//2.销毁
void  SLDestroy(SL* p)
{
	assert(p);
	if (p->arr != NULL)
	{
		free(p->arr);
		p->arr = NULL;

	}
	p->capacity = p->size = 0;
}




