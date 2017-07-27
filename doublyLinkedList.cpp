#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
	int studentID;
	char studentName[30];
	
	struct Node* next;
	struct Node* prev;
};



typedef Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;


void Insert(List L,int ID,char *name,Position P)
{	
	Position tmpcell;
	tmpcell=(Position)malloc(sizeof(struct Node));
	
	tmpcell->studentID=ID;
	strcpy(tmpcell->studentName,name);
	
	tmpcell->prev = P;
	tmpcell->next = P->next;
	if(P->next!=NULL){P->next->prev = tmpcell;}
	P->next = tmpcell;
}

Position Find(List L,int ID)
{
	Position target;
	
	target = L;
	
	while(target->next != NULL && target->studentID < ID)
	{
		target = target->next;
	}
	if ( target->prev == NULL) return target;
	else return target->prev;
}

void dataInsert(List L,int ID,char *name)
{
	
	Position P;
	P=Find(L,ID);
	
	Insert(L,ID,name,P);
}

void Print(List L)
{
	Position P;
	P = L->next;
	
	while(P!=NULL)
	{
		printf("Student ID : %d , Name : %s\n",P->studentID,P->studentName);
			
		P=P->next;
		
	}
	
}

int main()
{
	char command;
	int ID;
	char name[30];

	List L;
	L=(List)malloc(sizeof(struct Node));
	
	L->next = NULL; L->prev = NULL;

	


	
	while(1)
	{
		scanf("%c",&command);
		
		switch(command)
		{
			case 'i' :
				scanf("%d %s",&ID,name);
				dataInsert(L,ID,name);
				break;
			case 'p' :
				Print(L);
				break;
			case 'q' :
				break;
		}
		if(command == 'q') break;
	}
}

			
	
