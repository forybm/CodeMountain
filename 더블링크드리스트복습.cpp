#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct node{
	int id;
	char stname[30];
	struct node *next;
	struct node *prev;
};

typedef struct node *PtrToNode;
typedef PtrToNode Position, List;

void Insert(int id,char *name,Position P,List L)
{
	Position tmp;
	tmp = (struct node*)malloc(sizeof(struct node));
	
	tmp->id=id;
	strcpy(tmp->stname,name);
	
	if(P->next == NULL)
	{
		P->next = tmp;
		tmp->next = NULL;
		tmp->prev = P;
	}
	else{
	tmp->next = P->next;
	P->next->prev = tmp;
	tmp->prev = P;
	P->next = tmp;
	}
}
Position FindSort(int id,List L)
{
	Position P = L;
	
	
	while( P->next != NULL && P->next->id < id)
	{
		P= P->next;
	}
	if(P->next!=NULL || P->id <id) return P;
	else return P->prev;
		

}

void DataInsert(int id,char *name,List L)
{
	Position P;
	P=FindSort(id,L);
	Insert(id,name,P,L);
}
	

Position Find(int id,List L)
{
	Position P;
	P=L->next;
	
	while(P->id != id && P->next != NULL)
	{
		P = P->next;
	}
	return P;
}

void Delete(int id,List L)
{
	Position P = Find(id,L);
	
	P->prev->next=P->next;
	P->next->prev=P->prev;
	free(P);
}

void PrintList(List L)
{
	Position P = L->next;
	while(P != NULL)
	{
		printf("ID : %d, Name : %s\n",P->id,P->stname);
		P=P->next;
	}
}
	
	

int main()
{
	List L;
	L=(struct node*)malloc(sizeof(struct node));
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
				DataInsert(ID,name,L);
				break;
			
			case 'p' :
				PrintList(L);
				break;
				
			case 'd':
				scanf("%d",&num);
				Delete(num,L);
				break;
		}
	}
}
	
	
	
	
	
