#include <stdio.h>

void swap(int *a, int *b);

int main()
{
	int num1, num2;
	int *a, *b;

	puts("entered two integers : ");
	scanf("%d %d", &num1, &num2);
	a = &num1;
	b = &num2;
	printf("you entered %d %d\n", num1, num2);
	swap(&num1, &num2);
	printf("And Swaped two integer that : %d %d", num1, num2);

	return 0;
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
