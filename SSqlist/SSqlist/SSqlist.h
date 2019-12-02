#pragma once
//有头双向循环链表虽然结构复杂但是实现简单
//ListInsertafter、 ListEraseafter这两个接口就能实现上面的所有功能。
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SSType;
typedef struct SSqlist
{
	struct SSqlist* prev;
	struct SSqlist* next;
	SSType data;
}SSqlist;

SSqlist* BuySlistNode(SSType x);
SSqlist* InitSlist();
void SSqlistPrint(SSqlist* pHead);
void SSqlistPushBack(SSqlist* pHead, SSType x);
void SSqlistPopback(SSqlist* pHead);
void SSqlistPushFrant(SSqlist* pHead, SSType X);
void SSqlistPopFrant(SSqlist* pHead);
// 在pos的前面进行插入
void ListInsertafter(SSqlist* pos, SSType x);
// 删除pos位置的节点
void ListEraseafter(SSqlist* pos);