#include"SeqList.h"

void SeqList1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrintf(&s);
	SeqListPopBack(&s);
	SeqListPrintf(&s);
	SeqListPushFront(&s, 0);
	SeqListPrintf(&s);
	SeqListPopFront(&s);
	SeqListPrintf(&s);
}
void SeqList2()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 0);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrintf(&s);
	SeqListInsert(&s, 3, 30);
	SeqListPrintf(&s);
	SeqListErase(&s, 0);
	SeqListErase(&s, 2);
	SeqListPrintf(&s);
	SeqListRemove(&s, 5);
	SeqListPrintf(&s);

}
void SeqList3()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 5);
	SeqListPrintf(&s);
	SeqListBubbleSort(&s);
	SeqListPrintf(&s);
	printf("%d\n", SeqListBinaryFind(&s, 3));
	printf("%d\n", SeqListBinaryFind(&s, 4));
}
int main()
{
	SeqList3();
	return 0;
}