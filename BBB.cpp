#include <stdio.h>
#include <algorithm>

using namespace std;
int dp[2][13000];
int p[3500], b[3500];

int N, M;

void myf()
{
	scanf("%d %d", &N, &M);
	for (int i = 1;i <= N;i++)
	{
		scanf("%d %d", &p[i], &b[i]);
	}

	for (int i = 1;i <= N;i++)
	{
		for (int j = 0;j <= M;j++)
		{
			if ((j - p[i]) < 0) dp[i % 2][j] = dp[(i - 1) % 2][j];
			else dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[(i - 1) % 2][j - p[i]] + b[i]);
		}
	}
	printf("%d", dp[N % 2][M]);

}

int main()
{
	myf();
}

