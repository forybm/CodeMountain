#include <stdio.h>
#include <stdlib.h>

typedef struct threadedTree *threadedPointer;
typedef threadedPointer TREE;
typedef struct threadedTree {
	bool leftThread;
	threadedPointer leftChild;
	char data;
	threadedPointer rightChild;
	bool rightThread;
};

threadedPointer insucc(threadedPointer tree) //왼쪽의 가장 오른쪽 찾기
{
	threadedPointer tmp;
	tmp = tree->leftChild;
	if (!tmp) {
		while (!tmp->rightThread)
			tmp = tmp->rightChild;
	}
	return tmp;
}

void insertLeft(threadedPointer s, threadedPointer r)
{
	threadedPointer tmp;
	r->leftChild = s->leftChild;
	r->leftThread = s->leftThread;
	r->rightChild = s;
	r->rightThread = true;
	s->leftChild = r;
	s->leftThread = false;
	if (!r->leftThread)
	{
		tmp = insucc(r);
		tmp->rightChild = r;
	}
}

 threadedPointer makeTree()
{
	threadedPointer tree;

	tree = (struct threadedTree*)malloc(sizeof(struct threadedTree));
	tree->leftThread = true;
	tree->rightThread = true;
	tree->leftChild = tree;
	tree->rightChild = tree;

	return tree;
}

void printer(threadedPointer tree)
{
	threadedPointer temp = tree;
	while (!temp->leftThread)
	{
		temp = temp->leftChild;
		printf("%3c",temp->data);
	}
}


int main()
{
	threadedPointer tree;
	threadedPointer temp;
	tree= makeTree();
	
	char command;

	while (1)
	{
		scanf("%c", &command);
		switch (command)
		{
		case 'i':
			char data;
			scanf("%c", &data);
			temp = makeTree();
			temp->data = data;
			insertLeft(tree, temp);
			break;

		case'p':
			printer(tree);
			break;
		case 'q':
			break;
		}
		if (command == 'q') break;
	}




}
