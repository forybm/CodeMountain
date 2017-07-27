#include <stdio.h>
#include <queue>

using namespace std;

int arr[1111][1111];
int arr2[1111][1111];
bool check[1111];
bool check2[1111];

int N, M, V;

void dfs(int n)
{
	printf("%d ", n);
	check2[n] = true;
	for (int i = 1;i <= N;i++)
	{
		if (arr2[n][i] && arr2[i][n] && !check2[i])
		{
			dfs(i);

		}
	}
}
int main()
{
	int i, j;
	scanf("%d %d %d", &N, &M, &V);
	for (i = 0;i < M;i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = arr[b][a] = 1;
		arr2[a][b] = arr2[b][a] = 1;
	}

	queue <int> myQ;
	myQ.push(V);
	check[V] = true;
	
	dfs(V);
	printf("\n");
	while (!myQ.empty())  //bfs
	{
		int now = myQ.front();
		myQ.pop();
		printf("%d ", now);
		for (i = 1;i <= N;i++)
		{
			if (arr[now][i] && arr[i][now] && !check[i])
			{
				myQ.push(i);
				check[i] = true;
			}
		}
		
	}
}
	
	



