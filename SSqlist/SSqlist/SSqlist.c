#include"SSqlist.h"


SSqlist* BuySlistNode(SSType x)
{
	SSqlist* node = (SSqlist*)malloc(sizeof(SSqlist));
	node->data = x;
	node->prev = NULL;
	node->next = NULL;

	return node;
}

SSqlist* InitSlist()
{
	SSqlist* pHead = BuySlistNode(0);
	pHead->prev = pHead;
	pHead->next = pHead;

	return pHead;
}

void SSqlistPrint(SSqlist* pHead)
{
	assert(pHead);
	SSqlist* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//后插记录头节点和最后一个结点
void SSqlistPushBack(SSqlist* pHead, SSType x)
{
	SSqlist* tail = pHead->prev;
	SSqlist* newnode = BuySlistNode(x);
	
	tail->next = newnode;
	newnode->prev = tail;
	pHead->prev = newnode;
	newnode->next = pHead;
}
//后删保存头节点和倒数第二个节点
void SSqlistPopback(SSqlist* pHead)
{
	assert(pHead);
	SSqlist* tail = pHead->prev;
	SSqlist* prev = tail->prev;

	pHead->prev = prev;
	prev->next = pHead;

	free(tail);
	tail = NULL;
}
//前插保存头结点和第一个结点
void SSqlistPushFrant(SSqlist* pHead, SSType x)
{
	SSqlist* first = pHead->next;

	SSqlist* newnode=BuySlistNode(x);

	pHead->next = newnode;
	newnode->prev = pHead;
	newnode->next = first;
	first->prev = newnode;
}
//前删头结点和第二个结点
void SSqlistPopFrant(SSqlist* pHead)
{
	assert(pHead && pHead->next);
	SSqlist* first = pHead->next;
	SSqlist* second = first->next;

	pHead->next = second;
	second->prev = pHead;
	free(first);
	first = NULL;
}
//任意位置后面添加  记录当前位置的后一个
void ListInsertafter(SSqlist* pos, SSType x)
{
	assert(pos);

	SSqlist* next = pos->next;
	SSqlist* newnode = BuySlistNode(x);

	pos->next = newnode;
	newnode->prev = pos;
	newnode->next = next;
	next->prev = newnode;
}
//任意位置后面删除  保存当前位置的后两个
void ListEraseafter(SSqlist* pos)
{
	assert(pos);

	SSqlist* next = pos->next;
	SSqlist* after = next->next;

	pos->next = after;
	after->prev = pos;
	free(next);
	next = NULL;
}

