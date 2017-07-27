#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
using namespace std;

int N;
int testcase;
int arr[1111];
int lis[1111];
int lds[1111];
int lids[1111];

int func_lis() {
	lis[0] = 1;
	for (int i = 1;i < N;i++) {
		int maax = 0;
		for (int j = 0;j < i;j++) {
			if ( arr[i] > arr[j]) {
				maax = max(lis[j] + 1,maax);
			}
		}
		if(maax >0) lis[i] = maax;
		else lis[i] = 1;
	}
	return 0;
}
int func_lds() {
	lds[N - 1] = 1;
	for (int i = N - 2;i >= 0;i--) {
		int maax = 0;
		for (int j = N - 1;j > i;j--) {
			if (arr[i] > arr[j]) {
				maax = max(lds[j] + 1, maax);
			}
		}
		if (maax >0) lds[i] = maax;
		else lds[i] = 1;
	}
	return 0;
}

int func_lids() {
	for (int i = 0;i <= N;i++) {
		lids[i] = lds[i] + lis[i];
	}
	return 0;
}
void myf() {
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", arr + i);
	}
	func_lis();
	//printf("lis : %d\n", *max_element(lis, lis + N));
	func_lds();
	//printf("lds : %d\n", *max_element(lds, lds + N));
	func_lids();
	//printf("lids : %d\n", *max_element(lids, lids + N) - 1);
	int ans[3];
	ans[0] = *max_element(lis, lis + N);
	ans[1] = *max_element(lds, lds + N);
	ans[2] = *max_element(lids, lids + N) - 1;

	printf("%d\n", *max_element(ans, ans + 3));
}
int main() {
	scanf("%d", &testcase);
	while (testcase--) myf();
}

