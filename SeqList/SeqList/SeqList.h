#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SeqListDatatype;
typedef struct SeqList
{
	SeqListDatatype* _array;
	size_t _size;//��Ч������
	size_t _capacity;//����
}SeqList;


void SeqListInit(SeqList* ps);//��ʼ��
void SeqListDestory(SeqList* ps);
void SeqListPrintf(SeqList* ps);//��ӡ

void SeqListCheckCapacity(SeqList* ps);//��������Ƿ��㹻
void SeqListPushBack(SeqList* ps, SeqListDatatype x);//β��
void SeqListPopBack(SeqList* ps);//βɾ
void SeqListPushFront(SeqList* ps, SeqListDatatype x);//ͷ��
void SeqListPopFront(SeqList* ps);//ͷɾ

int SeqListFind(SeqList* ps, SeqListDatatype x);//����
void SeqListInsert(SeqList* ps, size_t pos, SeqListDatatype x);//����λ�ò���
void SeqListErase(SeqList* ps, size_t pos);//����λ��ɾ��
void SeqListRemove(SeqList* ps, SeqListDatatype x);//�ҵ�x��ɾ��

void SeqListBubbleSort(SeqList* ps);//ð������
int SeqListBinaryFind(SeqList* ps, SeqListDatatype x);//���ַ�����
