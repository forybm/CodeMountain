#include <stdio.h>

int swap(int ptr1,int ptr2);

int main(){
	int a,b;
	printf("enter 2 integers\n");
	scanf("%d %d",&a,&b);
	
	//int ptr1=&a;
	//int ptr2=&b; 
	printf("you entered \n%d, %d\n",a,b);
	b=swap(a,b);
	printf("after swapping\n%d, %d\n",a,b);
	scanf("%d",&a);
	return 0;
}

int swap(int ptr1,int ptr2)
{
	int tmp;
	tmp=ptr1;
	ptr1=ptr2;
	ptr2=tmp;
	return ptr2;
}
