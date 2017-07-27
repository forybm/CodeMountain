#include <stdio.h>
#include <stdlib.h>

int main()
{
	char **a;
	int n;
	puts("±ÛÀÚ¼ö");
	scanf("%d",&n);
	a=(char**)malloc(sizeof(char*)*n);
	for(int i=0;i<n;i++)
	{
		a[i]=(char*)malloc(sizeof(char)*30);
	}
	
	
	for(int i=0;i<n;i++){
	scanf("%s",a+i);
	}
	for(int i=0;i<n;i++){
		
	printf("%s\n",a+i); 
}
	return 0;
	
}

