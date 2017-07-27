#include <stdio.h>
#include <stdlib.h>

int main (){
	int num,i=0,j=0;
	char **student;
	
	
	scanf("%d",&num);
	printf("enter %d names : \n",num);
	
	student=(char**)malloc(sizeof(char*)*num);
	for(i=0;i<num;i++)
	{
		student[i]=(char*)malloc(sizeof(char)*20);
	}

	for(i=0;i<num;i++)
	{
		for(int j=0;j>20;j++)
			scanf("%s",student[i]);
		
	}
	printf("the names you entered : \n");
	
	for(i=0;i<num;i++)
	{
		printf("%s\n",student[i]);	
		
	}	
	return 0;
}
