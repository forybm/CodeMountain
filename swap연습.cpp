#include <stdio.h>
#include <stdlib.h> 

void swap(int *a,int *b);

int main()
{
	int *arr;
	int *a,*b;
	
	arr=(int*)malloc(sizeof(int)*6);
	
	
	a=&arr[0];
	b=&arr[5];
	
	for(int i=0;i<6;i++)
	{
		scanf("%d",arr+i);
	}
	
	swap(a,b);
	for(int i=0;i<6;i++)
	{
		printf("%d ",arr[i]);
	}
	
	return 0;
}

void swap(int *a,int *b)
{
	int temp;
	
	temp=*a;
	*a=*b;
	*b=temp;
}
