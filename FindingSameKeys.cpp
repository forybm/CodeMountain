//2013012085_À¯º´¹Î_A
//Finding Same Keys

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int N, M;
int *a, *b;

int apos, bpos,cnt;

int main() {
	scanf("%d %d", &N, &M);
	a = (int*)malloc(sizeof(int)*N);
	b = (int*)malloc(sizeof(int)*M);
	for (int i = 0;i < N;i++) scanf("%d", &a[i]);
	for (int i = 0;i < M;i++) scanf("%d", &b[i]);

	sort(a, a + N);
	sort(b, b + M);
	
	while (apos < N && bpos < M) {
		if (a[apos] > b[bpos]) bpos++;
		else if (a[apos] < b[bpos]) apos++;
		else {
			cnt++; apos++; bpos++;
		}
	}

	printf("%d", cnt);
	return 0;
}
