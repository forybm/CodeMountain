#include <stdio.h>
#include <math.h>
#include <queue>
#include <algorithm>

using namespace std;

int arr[55555];
int dp[55555][101];
void myf(int num) {
	int N, K, L;
	long long int count = 0;
	scanf("%d %d %d", &N, &K, &L);
	if (L != 0) {
		for (int i = 0;i < L;i++) {
			int temp;
			scanf("%d", &temp);
			arr[temp] = 1;
		}
	}

	for (int i = 1;i <= K;i++) {
		if (!arr[i]) dp[i][i] = 1;
	}
	for (int i = 2;i <= N;i++) {
		if (!arr[i]) {
			for (int j = 1;j <= K;j++) {
				for (int k = 1;k <= K;k++) {
					if (k != j &&i - j>0&&!arr[i-j]) {
						dp[i][j] += dp[i - j][k];
						dp[i][j] = dp[i][j] % 1000000009;
					}
				}
			}
		}
	}

	for (int i = 0;i <= K;i++) {
		count += dp[N][i];
	}

	for (int i = 0;i <= N;i++) {
		arr[i] = 0;
		for (int j = 0;j <= K;j++) {
			dp[i][j] = 0;
		}
	}

	count = count % 1000000009;

	printf("Case #%d\n", num + 1);
	printf("%lld\n", count);

}

int main() {
	setbuf(stdout, NULL);
	int T;
	scanf("%d", &T);

	for (int i = 0;i < T;i++) {
		myf(i);
	}
	return 0;

}
