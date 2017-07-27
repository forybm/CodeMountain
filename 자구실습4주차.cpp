#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
	int studentID;
	char studentName[30];
	struct Node* next;
	struct Node* prev;
};

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void Insert(int ID,char *studentName,List L,Position P)
{
	
	Position tmpcell;
	
	
	tmpcell = (Position)malloc(sizeof(struct Node));
	
	if(tmpcell==NULL) printf("Out of Space!!\n");
	
	tmpcell->studentID = ID;
	strcpy(tmpcell->studentName,studentName);
	
	if(L->next == NULL)
	{
		L->next = tmpcell;
		tmpcell->prev = L;
		tmpcell->next = NULL;
	}
	else
	{
		P->next->prev = tmpcell;
		tmpcell->next = P->next;
		P->next = tmpcell;
		tmpcell->prev = P;
	}
	
}


Position NewFind(int ID,List L)
{
	Position P;
	P = L->next;
	while(P != NULL && P->studentID < ID)
	{
		P = P->next;
	}
	return P;
}

void dataInsert(int ID,char *studentName,List L)
{
	Position P;
	
	P=NewFind(ID,L);
	Insert(ID,studentName,L,P);
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
	
Position Find(int ID,List L)
{
	Position P;
	P = L;
	while(P->next != NULL && P->studentID != ID)
	{
		P = P->next;
	}
	return P;
}
	

void Delete(int ID,List L)
{
	Position P;
	P = Find(ID,L);
	P->prev->next = P->next;
	P->next->prev = P->prev;
	free(P);
}


int main()
{
	List L;
	L=(List)malloc(sizeof(struct Node));
	L->next = NULL;
	
	int ID;
	char name[30];
	char command;
	int num;
	while(1)
	{
		scanf("%c",&command);
		switch(command)
		{
			case 'i' :
				scanf("%d",&ID);
				scanf("%s",name);
				dataInsert(ID,name,L);
				break;
			
			case 'p' :
				Print(L);
				break;
				
			case 'd':
				scanf("%d",&num);
				Delete(num,L);
				break;
		}
	}
}
	
	
	
	
	
	
	
	
	
	




	
