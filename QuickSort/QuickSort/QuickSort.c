#include<stdio.h>
//如果选第一个值做关键字，end先走
//如果选最后一个做关键字，begine先走
//时间复杂度有序最坏 N*N
//   最好在中间(N*logN)
//为了防止最坏情况  三数区中法优化
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
int GetMidIndex(int* a, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else//a[begin] > a[mid]
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
}
int PartSort(int* a, int begin, int end)
{
	//三数取中
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);
	int key = begin;
	while (begin < end)
	{
		
		while (begin < end && a[end] >= a[key])
		{
			--end;
		}
		
		while (begin < end && a[begin] <= a[key])
		{
			++begin;
		}

		Swap(&a[begin], &a[end]);
	}
	Swap(&a[key], &a[begin]);
	return begin;
}
//int PartSort(int* a, int begin, int end)
//{
//	int key = begin;//选最左key
//	while (begin < end)
//	{
//		//end 先走，找小
//		while (begin < end && a[end] >= a[key])
//		{
//			--end;
//		}
//		//begine 再走，找大
//		while (begin < end && a[begin] <= a[key])
//		{
//			++begin;
//		}
//
//		Swap(&a[begin], &a[end]);
//	}
//	Swap(&a[key], &a[begin]);
//	return begin;
//}
//int PartSort(int* a, int begin, int end)
//{
//	int key = end;选最右为key
//	while (begin < end)
//	{	
//		//begin先走，找大
//		while (begin < end && a[begin] <= a[key])
//		{
//			++begin;
//		}
//		//end 再走，找小
//		while (begin < end && a[end] >= a[key])
//		{
//			--end;
//		}
//		Swap(&a[begin], &a[end]);
//	}
//	Swap(&a[key], &a[begin]);
//	return begin;
//}


//挖坑法
int PartSort2(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);

	//begine是第一个坑位
	int key = a[begin];
	while (begin < end)
	{
		
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		
		a[begin] = a[end];

		while (begin < end && a[begin] <= key)
		{
			++begin;
		}

		a[end] = a[begin];
	}
	a[begin] = key;
	return begin;
}
//指针法
int PartSort3(int* a, int begin, int end)
{
	int prev = begin - 1;
	int cur = begin;
	int key = end;
	while (cur < end)
	{
		if (a[cur] < a[key])
		{
			++prev;
			Swap(&a[prev], &a[cur]);
			++cur;
		}
		else
		{
			++cur;
		}
	}
	Swap(&a[++prev], &a[key]);
	return prev;
}
void QuickSort(int* a, int left, int right)
{	//可能左边会大于右边
	if (left >= right)
		return;

	//小区间优化  快排+插入排序
	//if (right - left + 1 < 10)
	//{
		//InsertSort(a + left, right - left + 1);
	//}
	//else
	{
		int keyindex = PartSort(a, left, right);
		//[left,key-1]  key  [key+1,right]
		QuickSort(a, left, keyindex - 1);
		QuickSort(a, keyindex + 1, right);
	}
	
}
void PrintfArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main()
{
	int a[] = { 49, 38, 65, 97, 76, 13, 27, 49};
	QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	PrintfArray(a, sizeof(a) / sizeof(a[0]));
	return 0;
}
