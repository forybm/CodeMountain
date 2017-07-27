#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

struct AvlNode
{
	int Element;
	AvlTree left;
	AvlTree right;
	int Height;
};

static int Height(Position P)
{
	if (P == NULL) return -1;
	else return P->Height;
}

static Position SingleLeftRotation(Position K2)
{
	Position K1;
	K1 = K2->left;
	K2->left = K1->right;
	K1->right = K2;

	K2->Height = max(Height(K2->left), Height(K2->right)) + 1;
	K1->Height = max(Height(K1->left), Height(K2)) + 1;

	return K1;
}

static Position SingleRightRotation(Position K1)
{
	Position K2;
	K2 = K1->right;
	K1->right = K2->left;
	K2->left = K1;

	K1->Height = max(Height(K1->left), Height(K1->right))+1;
	K2->Height = max(Height(K2->right), K1->Height) + 1;

	return K2;
}

static Position DoubleRotateWithLeft(Position K3)
{
	K3->left = SingleRightRotation(K3->left);

	return SingleLeftRotation(K3);
}

static Position DoubleRotateWithRight(Position K3)
{
	K3->right = SingleLeftRotation(K3->right);

	return SingleRightRotation(K3);
}

AvlTree Insert(int x, AvlTree T)
{
	if (T == NULL)
	{
		T = (AvlTree)malloc(sizeof(struct AvlNode));
		if (T == NULL) printf("Out of Spcae !! \n");
		else
		{
			T->Element = x;
			T->Height = 0;
			T->left = NULL;
			T->right = NULL;
		}
	}
	else if (x < T->Element)
	{
		T->left = Insert(x, T->left);
		if (Height(T->left) - Height(T->right) == 2)
		{
			if (x < T->left->Element)	T = SingleLeftRotation(T);
			else T = DoubleRotateWithRight(T);
		}
	}
	else
	{
		if (x > T->Element)
		{
			T->right = Insert(x, T->right);
			if (Height(T->right) - Height(T->left) == 2)
			{
				if (x > T->right->Element) T = SingleRightRotation(T);
				else T = DoubleRotateWithRight(T);
			}
		}
	}
	T->Height = max(Height(T->left), Height(T->right)) + 1;
	return T;
}

void Print(AvlTree T)
{
	if (T)
	{
		printf(" %d(%d) ", T->Element, T->Height);
		Print(T->left);
		Print(T->right);
	}
}

int main()
{
	char command;
	int temp;
	AvlTree T=NULL;
//	T = (AvlTree)malloc(sizeof(struct AvlNode));
//	T->Element = 0;	T->Height = 0;
//	T->left = NULL;	T->right = NULL;

	while (1)
	{
		scanf("%c", &command);
		switch (command)
		{
		case 'i':
			scanf("%d", &temp);
			T=Insert(temp, T);
			break;
		case'p':
			Print(T);
			break;
		case'q':
			break;

		default:
			break;
		}
		if (command == 'q') break;
	}
	return 0;

}
