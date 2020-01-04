//��Ŀ����
//��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢���� �������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������������˶������Ժ��ٶԶ������������������������������
//�������� :
//�������1���ַ��������Ȳ�����100��
#include<stdio.h>
#include<malloc.h>
typedef struct BTreeNode
{
	struct BTreeNode* left;
	struct BTreeNode* right;
	int val;
}BTreeNode;

BTreeNode* CreateTree(char* a, int* index)
{
	if (a[*index] == '#')
		return NULL;
	BTreeNode* root = (BTreeNode*)malloc(sizeof(BTreeNode));
	root->val = a[*index];
	++(*index);
	root->left = CreateTree(a, index);
	++(*index);
	root->right = CreateTree(a, index);
	return root;
}


void InOrder(BTreeNode* root)
{
	if (root == NULL)
		return;
	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}
int main()
{
	char a[100] = { 0 };
	scanf("%s", a);
	int index = 0;
	BTreeNode* root = CreateTree(a, &index);
	InOrder(root);
	return 0;
}