#include <stdio.h>

int dp[1111][1111];
int N,K;

int main()
{
	scanf("%d", &N);
	scanf("%d", &K);

	dp[1][0] = dp[1][1] = 1;
	for (int i = 1;i <= N;i++) {
		dp[i][1] = i; dp[i][0] = 1;
	}

	for (int i = 3;i <= N;i++) {
		for (int j = 2;j <= K;j++) {
			if (j * 2 > i) break;
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j])%1000000003;
		}
	}

	printf("%d", dp[N][K]);
}
