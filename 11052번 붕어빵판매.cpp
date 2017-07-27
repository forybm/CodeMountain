#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int dp[1111];
int p[1111];
int temp[1111];
int main() {

	int N;
	scanf("%d", &N);
	
	for (int i = 1;i <= N;i++) {
		scanf("%d", &p[i]);
	}

	dp[1] = p[1];

	for (int i = 2;i <= N;i++) {
		for (int j = 1;j <= i;j++) {
			temp[j] = dp[i - j] + p[j];
		}
		dp[i] = *max_element(temp + 1, temp + N + 1);
	}
	
	printf("%d", dp[N]);



}
