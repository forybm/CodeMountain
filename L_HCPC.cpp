#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

int dp[11111][11111];
char str[11111];
char str2[11111];
int back[11111][11111];
char bc[11111];

void myf() {
	scanf("%s", str);
	scanf("%s", str2);
	int len = strlen(str);
	int len2 = strlen(str2);
	int pos = 0;
	for (int i = 1;i <= len;i++) {
		for (int j = 1;j <= len2;j++) {
			if (str[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				back[i][j] = 3;
			}
			else {
				if (dp[i - 1][j] > dp[i][j - 1]) {
					back[i][j] = 1;
					dp[i][j] = dp[i - 1][j];
				}
				else {
					back[i][j] = 2;
					dp[i][j] = dp[i][j - 1];
				}
				//dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	int ans = dp[len][len2];
	if (ans == 0) {
		printf("Not Match\n");
		return;
	}
	int r = len;
	int c = len2;
	int cnt = 0;
	while (cnt != ans) {
		if (str[r-1] != str2[c-1]) {
			if (dp[r - 1][c]>dp[r][c - 1]) {
				r--;
			}
			else c--;
		}
		else {
			bc[pos++]=str[r-1]; cnt++;
			r--; c--;
		}
	}
	
	for (int i = pos-1;i >= 0;i--) {
		printf("%c",bc[i]);
	}
}

int main() {
	int testcase;
	//scanf("%d", &testcase);
	//while (testcase--) myf();
	myf();
	return 0;
}

