#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 24
#define FALSE 0;
#define TRUE 1;

typedef struct node
{
	int data;
	struct node *link;
};

typedef struct node *nodePointer;

int main()
{
	short int out[MAX_SIZE];
	nodePointer seq[MAX_SIZE];
	nodePointer x,y,top;
	int i,j,n;
	
	printf("Enter the size ( <=%d) : ",MAX_SIZE);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		out[i] = TRUE;
		seq[i]= NULL;
	}
	
	printf("Enter a pair of numbers (-1 -1 to quit): ");
	scanf("%d%d",&i,&j);
	
	while(i>=0)
	{
		x = (struct node*)malloc(sizeof(struct node));
		x->data = j;
		x->link = seq[i];
		seq[i]=x;
		x=(struct node*)malloc(sizeof(struct node));
		x->data = i;
		x->link = seq[j];
		seq[j]=x;
		printf("Enter a pair of numbers (-1 -1 to quit): ");
		scanf("%d%d",&i,&j);
	}
	for(int i=0;i<n;i++){
		printf("seq[%d] data=%d \n",i,seq[i]->data);
		if(!seq[i]->link) printf("NULL\n");
	}
	for(int i=0;i<n;i++){
		x=seq[i];
		printf("seq[%d] : ",i);
		while(x){
			printf("\t%d",x->data);
			x=x->link;
		}
		printf("\n");
	}
		
	
	for(i=0;i<n;i++)
	{
		if(out[i]){
			printf("\nNew Class : %5d",i);
			out[i]= FALSE;
			x=seq[i]; top=NULL;
			for(;;)
			{
				
				while(x){
					j=x->data;
					if(out[j]){
						printf("%5d",j); out[j] = FALSE;
						y=x->link; x->link = top; top=x; x=y;
					}
					else x=x->link;
				}
				if(!top) break;
				x=seq[top->data]; top=top->link;
			}
		}
	}
}

					
					
					
					
					
		
		
		
		
		
