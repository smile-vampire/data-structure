#include"Slist.h"

void Test1()
{
	SlistNode* plist = NULL;
	SlistPushBack(&plist, 1);
	SlistPushBack(&plist, 2);
	SlistPushBack(&plist, 3);
	SlistPushBack(&plist, 4);
	SlistPrint(plist);
	SlistPopback(&plist);
	SlistPopback(&plist);
	SlistPopback(&plist);
	SlistPrint(plist);
}

void Test2()
{
	SlistNode* plist = NULL;
	SlistPushFrant(&plist, 1);
	SlistPushFrant(&plist, 2);
	SlistPushFrant(&plist, 3);
	SlistPushFrant(&plist, 4);
	SlistPrint(plist);
	SlistPopFrant(&plist);
	SlistPrint(plist);
}


int main()
{
	Test2();
	return 0;
}