#include <stdio.h>

int main()
{
	int j;
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	
	for(int i=0;i<10;i++)
	{
		j=a[i]++;
		printf("%d %d\n",j,a[i]);
	}
}
