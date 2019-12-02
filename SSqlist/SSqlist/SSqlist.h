#pragma once
//��ͷ˫��ѭ��������Ȼ�ṹ���ӵ���ʵ�ּ�
//ListInsertafter�� ListEraseafter�������ӿھ���ʵ����������й��ܡ�
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
// ��pos��ǰ����в���
void ListInsertafter(SSqlist* pos, SSType x);
// ɾ��posλ�õĽڵ�
void ListEraseafter(SSqlist* pos);