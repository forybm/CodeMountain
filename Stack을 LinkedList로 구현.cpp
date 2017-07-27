#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *Next;
};

typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

void pop(Stack S)
{
	Stack tmp;
	if(S->Next == NULL) printf("empty Stack!!\n");
	else{
		tmp=S->Next;
		S->Next=S->Next->Next;
		free(tmp);
	}
}

void push(int data,Stack S){
	Stack tmp;
	tmp=(struct Node*)malloc(sizeof(struct Node));
	if(tmp==NULL) printf("Out of Space!!\n");
	else{
		tmp->data = data;
		tmp->Next = S->Next;
		S->Next=tmp;
	}
}

bool IsEmpty(Stack S){
	return S->Next!=NULL;
}

void top(Stack S){
	if(S->Next== NULL) printf("Empty Stack!!\n");
	else{
	printf("Top data : %d\n",S->Next->data);
	}
}

void MakeEmpty(Stack S)
{
	free(S->Next);
}

Stack CreateStack(){
	Stack S;
	S = (struct Node*)malloc(sizeof(struct Node));
	if(S == NULL) printf("Out of space !!\n");
	else{
		S->Next = NULL;
	}
	return S;
}

void print(Stack S){
	Stack K = S->Next; 
	while(K != NULL){
		printf("%d ",K->data);
		K=K->Next;
	}
	printf("\n");
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
				push(data,S);
				break;
			
			case 't' : 
				top(S);
				break;
			
			case 'd' :
				pop(S);
				break;
			
			case 'q' : 
				MakeEmpty(S);
				break;
			
			case 'p' :
				print(S);
				break;
			
		}
		if(command == 'q') break;
	}
}
