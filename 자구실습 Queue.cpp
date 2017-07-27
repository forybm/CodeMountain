#include <stdio.h>
#include <stdlib.h>

struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	int *Array;
};

typedef struct QueueRecord *Queue;

void MakeEmpty(Queue Q){
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}
int IsEmpty(Queue Q){
	return Q->Size == 0;
}

static int Succ(int value, Queue Q)
{
	if(++value == Q->Capacity) value = 0 ;
	return value;
}

int IsFull(Queue Q)
{
	return Q->Size == Q->Capacity;
}

	
void Enqueue(int X, Queue Q)
{
	if(IsFull(Q)) printf("Full Queue !!\n");
	else{
		Q->Size ++;
		Q->Rear = Succ(Q->Rear,Q);
		Q->Array[Q->Rear] = X;
	}
}

void Dequeue(Queue Q)
{
	if(IsEmpty(Q)) printf("Empty Queue !!\n");
	else{
		Q->Size--;
		Q->Array[Q->Rear] == NULL;
		if(Q->Rear == 0) Q->Rear = Q->Capacity;
		else Q->Rear--;
	}
}

		
Queue CreateQueue(int Capacity)
{
	Queue Q;
	
	Q = (Queue)malloc(sizeof(struct QueueRecord));
	Q->Array = (int*)malloc(sizeof(int)*Capacity);
	
	if( Q == NULL ) printf("Out of Space !! \n");
	else{
		Q->Capacity = Capacity;
		Q->Size = 0;
		Q->Front = 1;
		Q->Rear = 0;
	}
	printf("\n %d 크기의 Queue가 생성되었습니다.\n",Capacity); 
	return Q;
}

void PrintFront(Queue Q){
	printf("Front Value : %d \n", Q->Array[Q->Front]);
}
void PrintRear(Queue Q){
	printf("Rear Value : %d \n", Q->Array[Q->Rear]);
}

int main()
{
	int number,data;
	printf("큐의 사이즈를 입력하세요 :  "); 
	scanf("%d",&number);
	
	Queue Q = CreateQueue(number);
	
	char command;
	
	while(1)
	{
		scanf("%c",&command);
		switch(command)
		{
			case 'e' :
				scanf("%d",&data);
				Enqueue(data,Q);
				break;
			case 'd' :
				Dequeue(Q);
				break;
			case 'f' :
				PrintFront(Q);
				break;
			case 'r' :
				PrintRear(Q);
				break;
			case 'q' : 
				break;
			}
		if (command == 'q') break;
	}
}

	



