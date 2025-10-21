#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"
//Ϊ�˷�����Զ�д��print����
void print(SL* p)
{
	for (int i = 0; i < p->size; i++)
	{
		printf(" %d ", p->arr[i]);
	}
	printf("\n");
}






//1.��ʼ��  �� CapacityCheck����
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


//2.ͷ��
void  Pushfront(SL* p,SLDateType x)
{
	assert(p);

	//�ж�capacity��С��˳���ռ��Ƿ񹻲���Ԫ�� ��CapacityCheck()������ ����顰capacity������ ������CapacityCheck()���������ݡ���
	//!!!!!!!1��1����CapacityCheck����!1111!!!!!!!
	CapacityCheck(p);

	//  a.��ʼ���±�Ϊ1��1�������Ԫ�������ƣ�����ͷԪ�أ��±�0��
	for (int i = p->size; i >=1; i--)
	{
		p->arr[i] = p->arr[i-1];
	}

	
	//b.����Ԫ��
	 p->arr[0] = x;

	//c.size+1��
	 p->size++;

}




//3.β��

void  Pushback(SL* p, SLDateType x)
{
	assert(p);
	assert(p->size);
	//�ж�capacity��С��˳���ռ��Ƿ񹻲���Ԫ�� ��CapacityCheck()������ ����顰capacity������ ������CapacityCheck()���������ݡ���
	//!!!!!!!1��1����CapacityCheck����!1111!!!!!!!
	CapacityCheck(p);


	//b.����Ԫ��
	p->arr[p->size] = x;

	//c.size+1��
	p->size++;

}


// 4.ͷɾ��һ��Ҫ��� size�Ƿ�Ϊ 0��

void Popfront(SL* p)
{
	assert(p);
	assert(p->size);

	//a.��ǰŲ��
	if (p->arr != NULL)
	{
		for (int i = 0; i <p->size-1 ; i++)
		{
			p->arr[i] = p->arr[i + 1];
		}
	}

	//b.size��1
	p->size--;
}


////5.βɾ
void Popback(SL* p)
{
	assert(p);

	assert(p->size);
	

	//b.size��1
	p->size--;
}

// 6.��ָ��λ��pos֮ǰ����Ԫ��

void Insert(SL* p, int pos, SLDateType x)
{
	assert(p);

	assert(pos >= 0 && pos <=p->size);                           //ע�⣺����ָ��sizeλ���ϲ���Ԫ�أ�1111111111111111111111
	CapacityCheck(p);


	//a.��pos�±꼰pos��ʼ���Ų��,�Ӻ���ǰŲ��
	for (int i = p->size; i >=pos+1; i--) 
	{
		p->arr[i] = p->arr[i - 1];
	}
	//b.����Ԫ��
	p->arr[pos] = x;
	
	p->size++;

}

//7.��ָ��λ��ɾ��Ԫ��

void Erase(SL* p, int pos)
{
	assert(p);
	assert(p->size);
	assert(pos >= 0 && pos < p->size );
	//���±�posԪ�ؼ�pos��ʼ�Ժ��Ԫ����ǰ�ƣ�
	for (int i = pos; i<p->size-1; i++)
	{
		p->arr[i] = p->arr[i + 1];
	}

	p->size--;

}


//8.����Ԫ��/�޸�
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

//2.����
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




