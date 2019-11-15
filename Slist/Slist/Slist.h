#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;
typedef struct SlistNode
{
	SLTDataType data;
	struct SlistNode* next;
}SlistNode;

SlistNode* BuySlistNode(SLTDataType x);
void SlistPrint(SlistNode* plist);
void SlistPushBack(SlistNode** pplist, SLTDataType x);
void SlistPopback(SlistNode** pplist);
void SlistPushFrant(SlistNode** pplist,SLTDataType X);
void SlistPopFrant(SlistNode** pplist);
