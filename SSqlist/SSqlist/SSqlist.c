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

//����¼ͷ�ڵ�����һ�����
void SSqlistPushBack(SSqlist* pHead, SSType x)
{
	SSqlist* tail = pHead->prev;
	SSqlist* newnode = BuySlistNode(x);
	
	tail->next = newnode;
	newnode->prev = tail;
	pHead->prev = newnode;
	newnode->next = pHead;
}
//��ɾ����ͷ�ڵ�͵����ڶ����ڵ�
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
//ǰ�屣��ͷ���͵�һ�����
void SSqlistPushFrant(SSqlist* pHead, SSType x)
{
	SSqlist* first = pHead->next;

	SSqlist* newnode=BuySlistNode(x);

	pHead->next = newnode;
	newnode->prev = pHead;
	newnode->next = first;
	first->prev = newnode;
}
//ǰɾͷ���͵ڶ������
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
//����λ�ú������  ��¼��ǰλ�õĺ�һ��
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
//����λ�ú���ɾ��  ���浱ǰλ�õĺ�����
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

