#include <stdio.h>

int arr[1111][1111];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1;i <= N;i++)
	{
		int temp;
		scanf("%d", &temp);
		for (int j = 1;j <= temp;j++)
		{
			int a;
			scanf("%d", &a);
			arr[i][a] = 1;
		}
	}
	for (int i = 1;i <= N;i++)
	{
		for (int j = 1;j <= N;j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
