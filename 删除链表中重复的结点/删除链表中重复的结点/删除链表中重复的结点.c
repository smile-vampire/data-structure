https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&&tqId=11209&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/

//解题思路：
//3个指针  因为cur 如果遇到相同的要记录下当前时刻之前的值  和  之后的值
//注意  val 可能不止两个  如果碰到要继续给下走就判断是否还为重复的值
//   如果是头结点   一定要改变头节点的位置  最后要返回头结点
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		ListNode* cur = pHead;//记录当前值
		ListNode* prev = NULL;//记录当前值得前一个
		ListNode* next = NULL;//记录下一个值

		while (cur)
		{
			if (cur->next != NULL&&cur->val == cur->next->val)
			{
				next = cur->next;
				//如果相同都要删除
				while (next->val == next->next->val && next != NULL && next->next != NULL)
				{
					next = next->next;
				}
				if (cur == pHead)//如果是头结点  则需要改变头结点   
				{
					pHead = next->next;
				}
				else
				{
					prev->next = next->next;
				}
				cur = next->next;//记得将cur 指向改变  继续向下走
			}

			else
			{
				prev = cur;
				cur = cur->next;
			}
		}
		return pHead;
	}
};