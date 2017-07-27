//2013012085_À¯º´¹Î_A
//Matrixchain.cpp

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int N;
int dp[111][111];
int back[111][111];
int p[111];
vector <int> v[111];
void split_array(int l, int r) {
	if (l >= r) return;
	v[l].push_back(-1);
	v[r].push_back(1);
	
	int k = back[l][r];
	split_array(l, k);
	split_array(k + 1, r);
}

int main() {
	scanf("%d", &N);
	for (int i = 0;i <= N;i++) scanf("%d", &p[i]);

	int pos = 0;
	for (pos = 1;pos <= N;pos++) {
		for (int i = 1;i <= N;i++) {
			if (i + pos <= N) {
				int minn = 987654321;
				for (int k = i;k < i + pos;k++) {
					int now = dp[i][k] + dp[k + 1][i + pos] + p[i - 1] * p[k] * p[i + pos];
					if (minn > now) {
						minn = now;
						back[i][i + pos] = k;
					}
				}
				dp[i][i + pos] = minn;
			}
			else break;
		}
	}
	for (int i = 1;i <= N;i++) back[i][i] = i;
	/*for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			printf("%d\t", dp[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			printf("%d\t", back[i][j]);
		}
		printf("\n");
	}*/

	printf("%d\n", dp[1][N]);
	split_array(1, N);

	for (int i = 1;i <= N;i++) {
		if (v[i].empty()) printf("%d ", i);
		else if (v[i][0] == 1) {
			printf("%d ", i);
			for (int check = 0;check < v[i].size();check++) {
				if (v[i][check] == 1)printf(") ");
			}
		}
		else if (v[i][0] == -1) {
			for (int check = 0;check < v[i].size();check++) {
				if (v[i][check] == -1) printf("( ");
			}
			printf("%d ", i);
		}
	}
	return 0;
}


