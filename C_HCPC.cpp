#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;
int L, T, N;
int arr[33];
int dp[1111111][33];
void myf() {
	scanf("%d %d %d", &L, &T, &N);
	for (int i = 0;i < N;i++) {
		int temp;
		scanf("%d", &temp);
		arr[i] = temp*(-1);
	}
	for (int i = 1;i <= L;i++) {
		for (int j = 0;j < N;j++) {
			dp[i][j] = 987654321;
		}
	}
	sort(arr, arr + N);
	for (int i = 0;i < N;i++) {
		arr[i] *= (-1);
	}
	for (int i = 0;i < N;i++) {
		int temp = arr[i];int cnt = 1;
		while (temp <= L) {
			dp[temp][i] = cnt++;
			temp += arr[i];
		}
	}
	/*for (int i = 0;i <= L;i++) {
		for (int j = 0;j < N;j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}*/
	for (int j = 1;j < N;j++) {
		for (int i = 1;i <= L;i++) {
			if(i-arr[j] >= 0) dp[i][j] = min(dp[i][j - 1], dp[i - arr[j]][j] + 1);
		}
	}
	if (dp[L][N - 1] <= T) printf("%d\n", dp[L][N - 1]);

	else printf("I sincerely apologize for being late\n");
	/*for (int i = 0;i <= L;i++) {
		for (int j = 0;j < N;j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}*/
}


int main() {
	myf();
	//while (testcase--) myf();
	return 0;
}

