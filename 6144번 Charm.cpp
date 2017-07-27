#include <stdio.h>
#include <algorithm>

using namespace std;
int dp[2][12881];
int w[3403], d[3403];

int N,M;

void myf()
{
	scanf("%d %d", &N, &M);
	for (int i = 1;i <= N;i++)
	{
		scanf("%d %d", &w[i], &d[i]);
	}

	for (int i = 1;i <= N;i++)
	{
		for (int j = 0;j <= M;j++)
		{
			if ((j - w[i]) < 0) dp[i%2][j] = dp[(i - 1)%2][j];
			else dp[i%2][j] = max(dp[(i - 1)%2][j], dp[(i - 1)%2][j - w[i]] + d[i]);
		}
	}
	printf("%d", dp[N%2][M]);

}

int main()
{
	myf();
}


