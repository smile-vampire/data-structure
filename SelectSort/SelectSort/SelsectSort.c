#include<stdio.h>
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	* p1 = *p2;
	*p2 = tmp;
}
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin<end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin; i <= end; ++i)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
			maxi = mini;
		Swap(&a[end], &a[maxi]);

		++begin;
		--end;
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
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	PrintfArray(a, sizeof(a) / sizeof(a[0]));
	return 0;
}