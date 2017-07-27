#include <stdio.h>
#include <stdlib.h> 

struct Node
{
	int data;
	struct Node* Next;
};

typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void Insert(int x,List l,Position p)
{
	Position tempcell;
	
	tempcell=(Position)malloc(sizeof(struct Node));
	if(tempcell == NULL) printf("Out of space !! \n");
	
	tempcell->data=x;
	tempcell->Next=NULL;
	
	tempcell->Next=p->Next;
	p->Next=tempcell;
}

int IsEmpty(List L)
{
	return L->Next == NULL;
}

int IsLast(Position P,List L)
{
	return P->Next == NULL;
}

Position Find(int x,List L)
{
	Position p;
	p=L->Next;
	while(p!=NULL && p->data!=x)
	{
		p=p->Next;
	}
	return p;
}

Position FindPrevious(int x,List L)
{
	Position p;
	p=L;
	while(p->Next !=NULL && p->Next ->data!=x)
	{
		p=p->Next;
	}
	return p;
}

void Delete(int x,List L)
{
	Position p, tempcell;
	p=FindPrevious(x,L);
	
	if(!IsLast(p,L))
	{
		tempcell=p->Next;
		p->Next=tempcell->Next;
		free(tempcell);
	}
}

void DataInsert(List L, int data, int target)
{
	Position P;
//	Position X;
	if(target!=-1){
	P=Find(target,L);
	Insert(data,L,P);
	}
	else{
		P=L;
		Insert(data,L,P);
	}
}

void PrintList(List L)
{
	Position P;
	P=L->Next;
	int t=0;
	while(P!=NULL)
	{
		printf("%d->",P->data);
		P=P->Next;
		
	}
	printf("NULL\n");
}

int main()
{
	List L;
	L = (List)malloc(sizeof(List));
	L->Next = NULL;
	Position a;
	char command;
	int x,target;
	
	while(1)
	{
		scanf("%c",&command);
		switch(command)
		{
			case 'i':
				scanf("%d%d",&x,&target);
				DataInsert(L,x,target);
				break;
			case 'p':
				PrintList(L);
				break;
			case 'd':
				scanf("%d",&x);
				Delete(x,L);
				break;
			case 'f':
				scanf("%d",&x);
				a=FindPrevious(x,L);
				printf("%d",a->data);
				break;
		}
	}
	
	return 0;
}

	
	







