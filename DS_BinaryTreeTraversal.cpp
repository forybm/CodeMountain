#include <stdio.h>
#include <stdlib.h>

typedef struct _TreeNode TreeNode;

struct _TreeNode
{
	int data;
	TreeNode* leftChild;
	TreeNode* rightChild;
};
TreeNode* createTreeNode(int data)
{
	TreeNode *p;
	p = (TreeNode*)malloc(sizeof(TreeNode));
	p->leftChild = NULL;
	p->rightChild = NULL;

	p->data = data;

	return p;
}
void preorder(TreeNode* p)
{
	if (p)
	{
		printf("%d ", p->data);
		preorder(p->leftChild);
		preorder(p->rightChild);
	}
}
void postorder(TreeNode* p)
{
	if (p)
	{
		postorder(p->leftChild);
		postorder(p->rightChild);
		printf("%d ", p->data);

	}
}
void inorder(TreeNode* p)
{
	if (p)
	{
		inorder(p->leftChild);
		printf("%d ", p->data);
		inorder(p->rightChild);
	}
}
void InsertTreeNode(TreeNode** p, int value)
{
	if ((*p) == NULL) (*p) = createTreeNode(value);
	else if ((*p)->data > value) InsertTreeNode(&((*p)->leftChild), value);
	else InsertTreeNode(&((*p)->rightChild), value);

}

int main()
{
	char command;
	TreeNode**p;
	p = (TreeNode**)malloc(sizeof(TreeNode*));
	*p = NULL;

	while (1)
	{
		scanf("%c", &command);
		switch (command)
		{
		case 'i':
			int value;
			scanf("%d", &value);
			InsertTreeNode(p, value);
			break;
		case'a':
			printf("Preorder : ");
			preorder(*p);
			printf("\n");
			break;
		case's':
			printf("Inorder : ");
			inorder(*p);
			printf("\n");
			break;
		case'd':
			printf("Postorder : ");
			postorder(*p);
			printf("\n");
			break;

		case'q':
			break;

		}
		if (command == 'q') break;

		
	}
}
