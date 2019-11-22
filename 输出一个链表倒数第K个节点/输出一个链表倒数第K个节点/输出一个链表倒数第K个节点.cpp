//����˼·��
//����ָ��  ���� K ��  Ȼ��һ����
//�߽�����  �������ΪNULL������0��  ����NULL   ���K���������� ��ôҲ���ؿ�
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
	{//���Ϊ�ջ���k=0û����
		if (pListHead == NULL || k == 0)
		{
			return NULL;
		}
		ListNode* slow = pListHead;
		ListNode* fast = pListHead;

		for (unsigned i = 0; i<k - 1; ++i)
		{
			//unsigned������������������� �����޷�������ѭ��
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