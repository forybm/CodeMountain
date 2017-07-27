#include <stdio.h>

void myf()
{
	int N;
	scanf("%d",&N);
	printf("%d : ",N); 
	for (int i = 0;i < N;i++)
	{
		int temp;
		scanf("%d", &temp);
		printf("%d ",temp);
	}
	
	printf("\n");
}

int main()
{
	int testcase;
	scanf("%d", &testcase);
	printf("%d\n",testcase);

	for (int i = 1; i <= testcase;i++)
	{
		myf();
	}
}
