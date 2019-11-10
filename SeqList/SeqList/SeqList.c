#include"SeqList.h"

void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->_size = 0;
	ps->_capacity = 0;
	ps->_array = NULL;
}

void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps->_array);
	ps->_array = NULL;
	ps->_capacity = ps->_size = 0;
}

void SeqListCheckCapacity(SeqList* ps)
{
	assert(ps);
	if (ps->_size == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity*2;
		ps->_array = realloc(ps->_array, sizeof(SeqListDatatype)*newcapacity);//重新接受地址
		ps->_capacity = newcapacity;//记录新容量8
	}
}

void SeqListPrintf(SeqList* ps)
{
	for (size_t i = 0; i < ps->_size; ++i)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}

void SeqListPushBack(SeqList* ps, SeqListDatatype x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	ps->_array[ps->_size] = x;
	ps->_size++;
}


void SeqListPopBack(SeqList* ps)
{
	assert(ps&&ps->_size > 0);
	//ps->_array[ps->_size - 1] = 0;
	ps->_size--;
}

void SeqListPushFront(SeqList* ps, SeqListDatatype x)
{
	assert(ps);

	SeqListCheckCapacity(ps);
	int end = ps->_size - 1;
	for (; end >= 0; --end)
	{
		ps->_array[end + 1] = ps->_array[end];
	}
	ps->_array[0] = x;
	ps->_size++;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps&&ps->_size>0);
	size_t start = 1;
	for (; start < ps->_size; ++start)
	{
		ps->_array[start - 1] = ps->_array[start];
	}
	ps->_size--;
}


int SeqListFind(SeqList* ps, SeqListDatatype x)
{
	for (size_t i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SeqList* ps, size_t pos, SeqListDatatype x)
{
	assert(ps&&pos<ps->_size);
	SeqListCheckCapacity(ps);

	size_t end = ps->_size;
	while (end > pos)
	{
		ps->_array[end] = ps->_array[end-1];
		--end;
	}
	ps->_array[pos] = x;
	ps->_size++;
}
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps&&pos<ps->_size);
	size_t i = pos + 1;
	while (i < ps->_size)
	{
		ps->_array[i - 1] = ps->_array[i];
		i++;
	}
	ps->_size--;
}

void SeqListRemove(SeqList* ps, SeqListDatatype x)
{
	int pos = SeqListFind(ps, x);
	if (pos >= 0)//找到了下标
	{
		SeqListErase(ps, pos);
	}
}

void SeqListBubbleSort(SeqList* ps)
{
	for (size_t end = ps->_size; end > 0; --end)
	{
		int exchange = 0;
		for (size_t i = 0; i < end-1; ++i)
		{
			if (ps->_array[i]>ps->_array[i + 1])
			{
				SeqListDatatype tmp = ps->_array[i];
				ps->_array[i] = ps->_array[i + 1];
				ps->_array[i + 1] = tmp;
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}
	
}

int SeqListBinaryFind(SeqList* ps, SeqListDatatype x)
{
	/*size_t begin = 0, end = ps->_size-1;
	while (begin <= end)
	{
		size_t mid = (begin + end) / 2;
		if (ps->_array[mid]==x)
		{
			return mid;
		}
		else if (ps->_array[mid] < x)
		{
			begin = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}*/
	size_t begin = 0, end = ps->_size;//如果用size 那么区间为左闭右开
	while (begin <end)//改变
	{
		size_t mid = (begin + end) / 2;
		if (ps->_array[mid] == x)
		{
			return mid;
		}
		else if (ps->_array[mid] < x)
		{
			begin = mid + 1;
		}
		else
		{
			end = mid;//改变
		}
	}
	return -1;
}