#include<stdio.h>
//�Ӻ���ǰ����  
//ʱ�临�Ӷ�  n-n^2
void InsertSort(int* a, int n)
{
	for (size_t i = 0; i<n - 1; ++i)
	{
		//��������tmp��������
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;//a[end]<=tmp����end=-1
			}
		}
		a[end + 1] = tmp;
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
	int a[] = { 4, 2, 9, 5, 7, 6, 3, 1, 0, 8 };
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	PrintfArray(a, sizeof(a) / sizeof(a[0]));
	return 0;
}