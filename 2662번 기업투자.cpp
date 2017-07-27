#include <stdio.h>
#include <algorithm>

using namespace std;

int W[21][333];
int dp[22][333];
int back[22][333];
int loc[22];
int N,K;

int main()
{
	scanf("%d %d", &K, &N); //K 돈, N 기업수
	for (int i = 1;i <= K;i++) {
		int temp;
		scanf("%d", &temp);
		for (int j = 1;j <= N;j++) {
			scanf("%d", &W[j][temp]); //W[기업][금액]
		}
	}
	/* 
	for (int i = 1;i <= K;i++) {
		dp[1][i] = W[1][i];
	}*/

	for (int i = 1;i <= N;i++) {
		for (int j = 0;j <= K;j++) {
			for (int k = 0;k <= j;k++) {
				if (dp[i][j] < (dp[i - 1][j - k] + W[i][k])) {
					dp[i][j] = (dp[i - 1][j - k] + W[i][k]);
					back[i][j] = k;
				}
			}
		}
	}
	printf("%d\n", dp[N][K]);

	for (int i = N;i > 0;i--) {
		loc[i] = back[i][K];
		K -= back[i][K];
	}

	
	for (int i = 1;i <= N;i++)
	{
		printf("%d ", loc[i]);
	}
}
	
