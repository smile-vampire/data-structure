#include<stdio.h>
//���ѡ��һ��ֵ���ؼ��֣�end����
//���ѡ���һ�����ؼ��֣�begine����
//ʱ�临�Ӷ������ N*N
//   ������м�(N*logN)
//Ϊ�˷�ֹ����  �������з��Ż�
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
	//����ȡ��
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
//	int key = begin;//ѡ����key
//	while (begin < end)
//	{
//		//end ���ߣ���С
//		while (begin < end && a[end] >= a[key])
//		{
//			--end;
//		}
//		//begine ���ߣ��Ҵ�
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
//	int key = end;ѡ����Ϊkey
//	while (begin < end)
//	{	
//		//begin���ߣ��Ҵ�
//		while (begin < end && a[begin] <= a[key])
//		{
//			++begin;
//		}
//		//end ���ߣ���С
//		while (begin < end && a[end] >= a[key])
//		{
//			--end;
//		}
//		Swap(&a[begin], &a[end]);
//	}
//	Swap(&a[key], &a[begin]);
//	return begin;
//}


//�ڿӷ�
int PartSort2(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);

	//begine�ǵ�һ����λ
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
//ָ�뷨
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
{	//������߻�����ұ�
	if (left >= right)
		return;

	//С�����Ż�  ����+��������
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
