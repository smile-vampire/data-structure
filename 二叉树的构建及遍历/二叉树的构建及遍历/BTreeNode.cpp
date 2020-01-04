//题目描述
//编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。 例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。
//输入描述 :
//输入包括1行字符串，长度不超过100。
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