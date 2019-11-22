//解题思路：
//快慢指针  先走 K 步  然后一起走
//边界条件  如果链表为NULL或者走0步  返回NULL   如果K大于链表长度 那么也返回空
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
	{//如果为空或者k=0没意义
		if (pListHead == NULL || k == 0)
		{
			return NULL;
		}
		ListNode* slow = pListHead;
		ListNode* fast = pListHead;

		for (unsigned i = 0; i<k - 1; ++i)
		{
			//unsigned如果倒数大于链表将崩溃 或者无符号无线循环
			if (fast->next != NULL)
			{
				fast = fast->next;
			}
			else
			{
				return NULL;
			}
		}
		while (fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};