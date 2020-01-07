#include<stdio.h>
//预排序+插入排序
//（接近升序） （有序）
//时间复杂度 n^1.3--n^2
void ShellSort(int* a, int n)
{
	//单趟排序，间距为gap的插入排序
	//gap为1时插入排序
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (size_t i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
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
	int a[] = {9,12,5,7,4,8,6,3,1};
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	PrintfArray(a, sizeof(a) / sizeof(a[0]));
	return 0;
}
