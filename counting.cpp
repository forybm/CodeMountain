//2013012085_À¯º´¹Î_A
//Counting.cpp

#include <stdio.h>
#include <stdlib.h>

int N, M, K;
int a[111111], b[111111], v[111111];
bool check[111111];
int main() {
	scanf("%d %d %d", &N, &M, &K);
	
	for (int i = 0;i < K;i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	for (int i = 0;i < N;i++) {
		int a; scanf("%d", &a);
		v[a]++; check[a] = true;
	}
	for (int i = 2;i <= M;i++) {
		v[i] = v[i] + v[i - 1];
	}

	for (int i = 0;i < K;i++) {
		int cnt = 0;
		if (check[a[i]]) cnt = v[b[i]] - v[a[i]-1];
		else cnt = v[b[i]] - v[a[i]];
		printf("%d\n", cnt);
	}
	
	return 0;
}
