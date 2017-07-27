#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <vector>
#include <math.h>
#include <string.h>

char T[1111111],temp[1111111];
char P[1111111];
int f[1111111];
int ans[1111111];
int n, m;
void get_failure()
{
	int i = 0;
	for (int cur = 2; cur <= m; cur++) {
		while (i && P[cur] != P[i + 1]) i = f[i];
		if (P[cur] == P[i + 1]) i++;
		f[cur] = i;
	}
}

int main() {
	fgets(T + 1, sizeof(T) - 1, stdin);
	fgets(P + 1, sizeof(P) - 1, stdin);

	n = strlen(T + 1);
	m = strlen(P + 1);

	if (T[n] == '\n') n--;
	if (P[m] == '\n') m--;

		
	get_failure();
	
	int cnt = 0;
	int i = 0;
	for (int cur = 1;cur <= n;cur++) {
		while (i && T[cur] != P[i + 1]) i = f[i];
		if (T[cur] == P[i + 1]) i++;
		if (i == m) {
			ans[++cnt] = cur - m + 1;
			i = f[i];
		}
	}

	printf("%d\n", cnt);
	for (int j = 1;j <= cnt;j++) {
		printf("%d ", ans[j]);
	}



}
