#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *name;
	
	name = (char*)malloc(sizeof(char) * 30);
	
	printf("enter your name : "); 
	gets(name);
	printf("Your name is %s",name);
	
	
}
