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

//����˼·��
//3��ָ��  ��Ϊcur ���������ͬ��Ҫ��¼�µ�ǰʱ��֮ǰ��ֵ  ��  ֮���ֵ
//ע��  val ���ܲ�ֹ����  �������Ҫ���������߾��ж��Ƿ�Ϊ�ظ���ֵ
//   �����ͷ���   һ��Ҫ�ı�ͷ�ڵ��λ��  ���Ҫ����ͷ���
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		ListNode* cur = pHead;//��¼��ǰֵ
		ListNode* prev = NULL;//��¼��ǰֵ��ǰһ��
		ListNode* next = NULL;//��¼��һ��ֵ

		while (cur)
		{
			if (cur->next != NULL&&cur->val == cur->next->val)
			{
				next = cur->next;
				//�����ͬ��Ҫɾ��
				while (next->val == next->next->val && next != NULL && next->next != NULL)
				{
					next = next->next;
				}
				if (cur == pHead)//�����ͷ���  ����Ҫ�ı�ͷ���   
				{
					pHead = next->next;
				}
				else
				{
					prev->next = next->next;
				}
				cur = next->next;//�ǵý�cur ָ��ı�  ����������
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