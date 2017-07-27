#include <stdio.h>
#include <stdlib.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

struct Node{
	int data;
	PtrToNode Next;
};

int IsEmpty(Stack S){
	if(S->Next == NULL) return 1;
	else return 0;
}

void Pop(Stack S){
	PtrToNode FirstCell;
	
	if(IsEmpty(S)) printf("Empty Stack!!\n");
	else{
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		free(FirstCell);
	}
}

void Push(int data,Stack S){
	PtrToNode TmpCell;
	
	TmpCell = (PtrToNode)malloc(sizeof(struct Node));
	
	if(TmpCell == NULL) printf ("Out of Space !!\n");
	else{
		TmpCell->data = data;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}

int Top(Stack S){
	if(!IsEmpty(S)) return S->Next->data;
	else{
	printf("Empty Stack! \n");
	return 0;
	}
}

void MakeEmpty(Stack S)
{
	free(S->Next);
}

Stack CreateStack(void)
{
	Stack S;
	
	S = (Stack)malloc(sizeof(struct Node));
	if(S == NULL) printf("Out of Space !!\n");
	else{
		S->Next = NULL;
	}
	
	return S;
}

int main()
{
	Stack S = CreateStack();
	
	int data;
	char command;
	while(1){
		scanf("%c",&command);
		switch(command)
		{
			case 'i' :
				scanf("%d",&data);
				Push(data,S);
				break;
			
			case 't' : 
			printf("Top : %d\n",Top(S));
			break;
			
			case 'd' :
				Pop(S);
				break;
			
			case 'q' : 
				MakeEmpty(S);
				break;
		}
		if(command == 'q') break;
	}
}

			

