#include"SSqlist.h"

void Test()
{
	SSqlist* pHead = InitSlist();
	SSqlistPushBack(pHead, 1);
	SSqlistPushBack(pHead, 2);
	SSqlistPushBack(pHead, 3);
	SSqlistPushBack(pHead, 4);
	SSqlistPushBack(pHead, 5);
	SSqlistPrint(pHead);
	SSqlistPopback(pHead);
	SSqlistPrint(pHead);
	SSqlistPushFrant(pHead, 0);
	SSqlistPrint(pHead);
	SSqlistPopFrant(pHead);
	SSqlistPrint(pHead);
	ListInsertafter(pHead, 0);
	SSqlistPrint(pHead);
	ListInsertafter(pHead->prev, 5);
	SSqlistPrint(pHead);
	ListEraseafter(pHead);
	SSqlistPrint(pHead);
	ListEraseafter(pHead->prev->prev);
	SSqlistPrint(pHead);

}

int main()
{
	Test();
	return 0;
}