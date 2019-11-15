#include"Slist.h"

SlistNode* BuySlistNode(SLTDataType x)
{
	SlistNode* node = (SlistNode*)malloc(sizeof(SlistNode));
	node->data = x;
	node->next = NULL;

	return node;
}

void SlistPrint(SlistNode* plist)
{
	SlistNode* cur = plist;
	while (cur)
	{
		printf("%d->", cur->data);
		cur=cur->next;
	}
	printf("NULL\n");
}

void SlistPushBack(SlistNode** pplist, SLTDataType x)
{
	SlistNode* newnode = BuySlistNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SlistNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SlistPopback(SlistNode** pplist)
{
	//两种情况
	//1.空 或者只剩一个
	//2.非空
	SlistNode* prev = NULL;
	SlistNode* tail = *pplist;
	if (tail == NULL || tail->next == NULL)
	{
		free(tail);
		*pplist = NULL;
	}
	else
	{
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}

void SlistPushFrant(SlistNode** pplist, SLTDataType x)
{
	//空
	//非空
	assert(pplist);
	SlistNode* newnode = BuySlistNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		newnode->next = *pplist;
		*pplist = newnode;
	}
}

void SlistPopFrant(SlistNode** pplist)
{
	//空
	//一个
	//两个及以上
	SlistNode* first = *pplist;
	if (first == NULL)
	{
		return;
	}
	else if (first->next == NULL)
	{
		free(first);
		*pplist = NULL;
	}
	else
	{
		SlistNode* next = first->next;
		free(first);
		*pplist = next;
	}
}