#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct ListNode *position;
typedef position List;
typedef struct GraphTbl *GraphTable;

/*
struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	int *Array;
};

typedef struct QueueRecord *Queue;

void MakeEmpty(Queue Q) {
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}
int IsEmpty(Queue Q) {
	return Q->Size == 0;
}

static int Succ(int value, Queue Q)
{
	if (++value == Q->Capacity) value = 0;
	return value;
}

int IsFull(Queue Q)
{
	return Q->Size == Q->Capacity;
}


void Enqueue(int X, Queue Q)
{
	if (IsFull(Q)) printf("Full Queue !!\n");
	else {
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
	}
}

int Dequeue(Queue Q)
{
	int temp;
	if (IsEmpty(Q)) printf("Empty Queue !!\n");
	else {
		Q->Size--;
		temp = Q->Array[Q->Rear];
		Q->Array[Q->Rear] = NULL;
		if (Q->Rear == 0) Q->Rear = Q->Capacity;
		else Q->Rear--;
	}
	return temp;
}


Queue CreateQueue(int Capacity)
{
	Queue Q;

	Q = (Queue)malloc(sizeof(struct QueueRecord));
	Q->Array = (int*)malloc(sizeof(int)*Capacity);

	if (Q == NULL) printf("Out of Space !! \n");
	else {
		Q->Capacity = Capacity;
		Q->Size = 0;
		Q->Front = 1;
		Q->Rear = 0;
	}
	printf("\n %d 크기의 Queue가 생성되었습니다.\n", Capacity);
	return Q;
}

void PrintFront(Queue Q) {
	printf("Front Value : %d \n", Q->Array[Q->Front]);
}
void PrintRear(Queue Q) {
	printf("Rear Value : %d \n", Q->Array[Q->Rear]);
}
*/

struct ListNode
{
	int Element;
	position Next;
};
struct GraphTbl
{
	int TableSize;
	List *TheLists;
};
bool *check;

GraphTable createGraph(int size)
{
	GraphTable G;
	G = (struct GraphTbl*)malloc(sizeof(struct GraphTbl));
	G->TableSize = size;

	G->TheLists = (position*)malloc(sizeof(position)*size);
	for (int i = 0;i < size;i++) {
		G->TheLists[i] = (ListNode*)malloc(sizeof(ListNode));
		G->TheLists[i]->Next = NULL;
	}
	return G;
}
void InsertNode(GraphTable G,int x,int y)
{
	List temp1,temp2;
	temp1 = (ListNode*)malloc(sizeof(ListNode));
	temp2 = (ListNode*)malloc(sizeof(ListNode));

	temp1->Next = G->TheLists[x]->Next;
	G->TheLists[x]->Next = temp1;
	temp1->Element = y;

	temp2->Next = G->TheLists[y]->Next;
	G->TheLists[y]->Next = temp2;
	temp2->Element = x;

}

void print(GraphTable G, int num)
{
	position P;
	P = G->TheLists[num]->Next;
	while (P != NULL)
	{
		printf("\telement : %d", P->Element);
		P = P->Next;
	}

}
void PrintNode(GraphTable G)
{
	for (int i = 0;i < G->TableSize;i++) {
		printf("node[%d] -> ", i);
		print(G, i);
		printf("\n");
	}
}
bool visited(GraphTable G)
{
	bool* a;
	a = (bool*)malloc(sizeof(bool)*G->TableSize);
	for (int i = 0;i < G->TableSize;i++) a[i] = false;
	return a;
	
}

void dfs(GraphTable G,int v)
{
	List L;
	check[v] = true;
	printf("%d\t", v);
	for (L = G->TheLists[v]->Next;L != NULL;L = L->Next)
	{
		if (!check[L->Element])
			dfs(G,L->Element);
	}
	
}
/*
void bfs(int v,Queue Q,GraphTable G)
{
	List L;
	Q->Front = Q->Rear = NULL;
	printf("%d\t");
	check[v] = true;
	Enqueue(v, Q);
	while (!IsEmpty(Q)) {
		v = Dequeue(Q);
		for (L = G->TheLists[v]->Next;L != NULL;L = L->Next)
		{
			if (!check[L->Element]) {
				printf("%d\t", L->Element);
				Enqueue(L->Element, Q);
				check[L->Element] = true;
			}
		}
	}

}
*/
void bfs(int v, GraphTable G)
{
	List L;
	printf("%d\t", v);
	check[v] = true;
	queue<int> myQ;
	myQ.push(v);
	while (!myQ.empty()) {
		int now = myQ.front();
		myQ.pop();
		for (L = G->TheLists[now]->Next;L != NULL;L = L->Next) {
			if (!check[L->Element]) {
				printf("%d\t", L->Element);
				check[L->Element] = true;
				myQ.push(L->Element);
			}
		}
	}
}
int main()
{
	GraphTable G;
//	Queue Q = CreateQueue(G->TableSize);

	int size;
	printf("그래프의 사이즈 : ");
	scanf("%d", &size);
	G = createGraph(size);
	char command='a';
	while (command != 'q') {
		scanf("%c", &command);
		switch (command) {
			case'i':
				int v1,v2;
				scanf("%d %d", &v1,&v2);
				InsertNode(G,v1,v2);
				break;
			case'p':
				PrintNode(G);
				break;
			case'd':
				check = (bool*)malloc(sizeof(bool)*G->TableSize);
				for (int i = 0;i < G->TableSize;i++) {
					check[i] = false;
				}
				dfs(G, 0);
				printf("\n");
				break;
			case'b':
				check = (bool*)malloc(sizeof(bool)*G->TableSize);
				for (int i = 0;i < G->TableSize;i++) {
					check[i] = false;
				}
				bfs(0, G);
				printf("\n");
				break;
			case'q':
				break;
		}
	}

}


