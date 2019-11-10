#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SeqListDatatype;
typedef struct SeqList
{
	SeqListDatatype* _array;
	size_t _size;//有效个数据
	size_t _capacity;//容量
}SeqList;


void SeqListInit(SeqList* ps);//初始化
void SeqListDestory(SeqList* ps);
void SeqListPrintf(SeqList* ps);//打印

void SeqListCheckCapacity(SeqList* ps);//检查容量是否足够
void SeqListPushBack(SeqList* ps, SeqListDatatype x);//尾插
void SeqListPopBack(SeqList* ps);//尾删
void SeqListPushFront(SeqList* ps, SeqListDatatype x);//头插
void SeqListPopFront(SeqList* ps);//头删

int SeqListFind(SeqList* ps, SeqListDatatype x);//查找
void SeqListInsert(SeqList* ps, size_t pos, SeqListDatatype x);//任意位置插入
void SeqListErase(SeqList* ps, size_t pos);//任意位置删除
void SeqListRemove(SeqList* ps, SeqListDatatype x);//找到x并删除

void SeqListBubbleSort(SeqList* ps);//冒泡排序
int SeqListBinaryFind(SeqList* ps, SeqListDatatype x);//二分法查找
