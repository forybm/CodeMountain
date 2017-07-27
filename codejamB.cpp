#include <stdio.h>

void func(int a)
{
	char pancake[111];
	for(int i = 0 ; i < 111; i++) pancake[i]=0;
	
	
	int count =0;
	scanf("%s",pancake);
	
		for(int i=0;;i++)
		{
			if(pancake[i+1] == 0 ){
			if(pancake[i] == '-') count++;
			break;}
			if(pancake[i]!=pancake[i+1]) count++;
		}
		
	printf("Case #%d: %d\n",a,count);
}

int main()
{
	int testcase;
	scanf("%d",&testcase);
	for(int i = 1 ; i <= testcase ; i++)
	{
		func(i);
	}
}

		
	
