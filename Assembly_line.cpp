//2013012085_À¯º´¹Î_A
//Assembly_line.cpp

#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int dp[2],dp2[2];
int e[2], x[2];
int a[111][2], t[111][2];
int back[111][3];
int l[111];
int main() {
	scanf("%d", &N);
	scanf("%d %d", &e[0], &e[1]);
	scanf("%d %d", &x[0], &x[1]);
	for (int i = 0;i < N;i++) scanf("%d", &a[i][0]);
	for (int i = 0;i < N;i++) scanf("%d", &a[i][1]);
	for (int i = 0;i < N - 1;i++) scanf("%d", &t[i][0]);
	for (int i = 0;i < N - 1;i++) scanf("%d", &t[i][1]);

	dp[0] = e[0] + a[0][0]; dp2[0] = e[1] + a[0][1];

	for (int i = 1;i < N;i++) {
		dp[i % 2] = min(dp[(i - 1) % 2] + a[i][0], dp2[(i - 1) % 2] + t[i - 1][1] + a[i][0]);
		back[i][1] = dp[(i - 1) % 2] + a[i][0] <= dp2[(i - 1) % 2] + t[i - 1][1] + a[i][0] ? 1 : 2;
		
		dp2[i % 2] = min(dp2[(i - 1) % 2] + a[i][1], dp[(i - 1) % 2] + t[i - 1][0] + a[i][1]);
		back[i][2] = dp2[(i - 1) % 2] + a[i][1] > dp[(i - 1) % 2] + t[i - 1][0] + a[i][1] ? 1 : 2;
	}
	
	l[N - 1] = dp[(N - 1) % 2] + x[0] <= dp2[(N - 1) % 2] + x[1] ? 1 : 2;

	
	for (int i = N - 1;i > 0;i--) {
		l[i - 1] = back[i][ l[i] ];
	}
	
	printf("%d\n", min(dp[(N - 1) % 2] + x[0], dp2[(N - 1) % 2] + x[1]));
	for (int i = 0;i < N;i++) {
		printf("%d %d\n", l[i], i + 1);
	}
	return 0;
}
