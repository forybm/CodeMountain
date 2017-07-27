#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

typedef struct ListNode *position;
typedef position List;
typedef struct HashTbl *HashTable;

struct ListNode
{
	int Element;
	position Next;
};

struct HashTbl
{
	int TableSize;
	float A;
	List *TheLists;
};

HashTable createHash(int size, float A)
{
	HashTable H;
	H = (struct HashTbl*)malloc(sizeof(struct HashTbl));


	H->TableSize = size;
	H->A = A;

	H->TheLists = (position*)malloc(sizeof(position)*size);
	for (int i = 0;i < size;i++)
	{
		H->TheLists[i] = (struct ListNode*)malloc(sizeof(struct ListNode));
		H->TheLists[i]->Next = NULL;
	}
	return H;
}

int hx(int key, HashTable H)
{
	int k;
	k = (int)((H->TableSize)*(fmod((key *H->A),1)));
	return k;

}

position Find(int key, HashTable H)
{
	position P;
	List L;
	
	L = H->TheLists[hx(key, H)];
	P = L->Next;

	while (P != NULL && P->Element != key)
	{
		P = P->Next;
	}
	return P;
}
position FindPrevious(int key, HashTable H)
{
	position P;
	List L;

	L = H->TheLists[hx(key, H)];
	P = L;

	while (P != NULL && P->Next->Element != key)
	{
		P = P->Next;
	}
	return P;
}
void Insert(int key, HashTable H)
{
	position Pos, newCell;
	List L;

	Pos = Find(key, H);
	if (Pos == NULL)
	{
		newCell = (struct ListNode*)malloc(sizeof(struct ListNode));

		L = H->TheLists[hx(key, H)];
		newCell->Next = L->Next;
		newCell->Element = key;
		L->Next = newCell;
	}
	
}
void Delete(int key, HashTable H)
{
	position Pos,temp;
	List L;

	Pos = FindPrevious(key, H);
	if (!Pos) printf("There is no data !!\n");
	else {
		temp = Pos->Next;
		Pos->Next = Pos->Next->Next;
		free(temp);
	}

}

void FindPrint(int key, HashTable H)
{
	position P;
	List L;

	L = H->TheLists[hx(key, H)];
	P = L->Next;

	while (P != NULL && P->Element != key)
	{
		P = P->Next;
	}
	if (P == NULL) printf("Can't Find it in Hash Table !!\n");
	else printf("Find %d in Hash[%d]\n", key, hx(key, H));
}
void PrintAll(HashTable H)
{
	List L;
	for (int i = 0;i < H->TableSize;i++)
	{
		printf("Hash[%d] :", i);
		L = H->TheLists[i]->Next;
		while (L != NULL)
		{
			printf(" %d", L->Element);
			L = L->Next;
		}
		printf("\n");
	}
}

int main()
{
	char command;
	int table_size;
	float A;
	HashTable H;
	
	printf("Hash Table size : ");
	scanf("%d", &table_size);
	printf("A : ");
	scanf("%f", &A);

	H = createHash(table_size, A);

	while (1)
	{
		scanf("%c", &command);
		switch (command)
		{
			case 'i':
				int x;
				scanf("%d", &x);
				Insert(x, H);
				break;
			case'd':
				int y;
				scanf("%d", &y);
				Delete(y, H);
				break;
			case'f':
				int z;
				scanf("%d", &z);
				FindPrint(z, H);
				break;
			case'p':
				PrintAll(H);
				break;
			case'q':
				break;

		default:
			break;
		}
		if (command == 'q') break;
	}
}
