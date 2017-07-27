#include <stdio.h>
int N;
int arr[111][111];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N;i++)
	{
		for (int j = 1;j <= N;j++)
		{
			int temp;
			scanf("%d", &temp);
			arr[i][j] = temp;
		}
	}
	for (int i = 1; i <= N;i++)
	{
		for (int j = 1;j <= N;j++)
		{
			for (int k = 1;k <= N;k++)
			{
				if (arr[j][i] && arr[i][k]) arr[j][k] = 1;
			}
		}
	}
	for (int i = 1; i <= N;i++)
	{
		for (int j = 1;j <= N;j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}


}
