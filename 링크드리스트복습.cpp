#include <stdio.h>
#include <stdlib.h>
 
typedef struct node{
	int data;
	struct node *next;
};

typedef struct node *PtrToNode;
typedef PtrToNode Position, List;

void Insert(int data,Position P,List L)
{
	Position tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	if(tmp == NULL) printf("Out of space!!\n");
	else{
		tmp->data = data;
		tmp->next = P->next;
		P->next = tmp;
	}
}

bool IsEmpty(List L)
{
	return L->next == NULL;
}

bool IsLast(Position P,List L)
{
	return P->next == NULL;
}

Position Find(int data,List L)
{
	Position P = L->next;
	while(P->next!=NULL)
	{
		if( P->data == data) return P;
		P = P->next;
	}
	return P;
}

Position FindPrevious(int data,List L)
{
	Position P = L->next;
	while(P->next!=NULL)
	{
		if( P->next->data == data) return P;
		P = P->next;
	}
	return L->next;
}

void Delete(int data,List L)
{
	Position P=FindPrevious(data,L);
	Position tmp;
	
	tmp = P->next;
	
	P->next = P->next->next;
	free(tmp);
}

void InsertData(int data,int target,List L)
{
	Position P;
	if(target!=-1){
		P=Find(target,L);
		if(P == NULL) printf("Can not find the target!!\n");
		else Insert(data,P,L);
	}
	else Insert(data,L,L);
}

void PrintList(List L)
{
	Position P = L->next;
	while(P != NULL)
	{
		printf("%d -> ",P->data);
		P = P->next;
	}
	printf("NULL\n");
}

	
int main()
{
	List L;
	L=(struct node*)malloc(sizeof(struct node));
	L->next = NULL; 
	char command;
	int n,target;
	
	while(1)
	{
		scanf("%c",&command);
	
		switch(command){
			case 'i' : 
				scanf("%d %d",&n,&target);
				InsertData(n,target,L);
				break;
			case 'p' :
				PrintList(L);
				break;
			case 'd' :
				scanf("%d",&n);
				Delete(n,L);
				break;
			case 'f':
				scanf("%d",&n);
				Position a = FindPrevious(n,L);
				printf("Find Previous value is %d \n",a->data);
				break;
			}
		}
	
}
	
	
	
	
