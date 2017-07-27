#include <stdio.h>
int arr[55][55];
bool check[55][55];

int M, N, K;

void dfs(int x, int y);
void myf()
{
	int count = 0;
	scanf("%d %d %d", &M, &N, &K);

	for (int i = 0;i < 55;i++)
	{
		for (int j = 0;j < 55;j++)
		{
			arr[i][j] = 0;
			check[i][j] = false;
		}
	}
	for (int i = 0;i < K;i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
	}

	for (int i = 0;i < M;i++)
	{
		for (int j = 0;j < N;j++)
			if (arr[i][j])
			{
				dfs(i, j);
				count++;
			}
	}
	printf("%d\n", count);

	
}

void dfs(int x, int y)
{
	
	if ( x >= 0 && x < M && y >= 0 && y < N &&!check[x][y] && arr[x][y])
	{
		check[x][y] = true;
		arr[x][y] = 0;

		dfs(x + 1, y);
		dfs(x - 1, y);
		dfs(x, y - 1);
		dfs(x, y + 1);
	}
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--) myf();
}

