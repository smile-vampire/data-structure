//https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
//解题思路：
  //定义两个链表  按题目要求分开 再合并到一起
//注意  循环结束要保证greathead->next  为NULL
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		ListNode* lessHead = (ListNode*)malloc(sizeof(ListNode));
		lessHead->next = NULL;
		ListNode* lessTail = lessHead;

		ListNode* greatHead = (ListNode*)malloc(sizeof(ListNode));
		greatHead->next = NULL;
		ListNode* greatTail = greatHead;

		ListNode* cur = pHead;

		while (cur)
		{
			if (cur->val<x)
			{
				lessTail->next = cur;
				lessTail = cur;
			}
			else
			{
				greatTail->next = cur;
				greatTail = cur;
			}
			cur = cur->next;
		}
		greatTail->next = NULL;
		lessTail->next = greatHead->next;

		ListNode* list = lessHead->next;
		free(lessHead);
		free(greatHead);
		return list;
	}
};