// 2013012085_À¯º´¹Î_A
// Selection Sort
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int *arr;
int N,M;


int main() {
	scanf("%d %d", &N, &M);
	arr = (int*)malloc(sizeof(int)*N);

	for (int i = 0;i < N;i++) {
		scanf("%d", &arr[i]);
		
	}
	
	int temp = 0;
	for (int i = 0;i < M;i++) {
		int minn = min_element(arr + i, arr + N) - arr;
		temp = arr[i];
		arr[i] = arr[minn];
		arr[minn] = temp;
	}
	
	for (int i = 0;i < N;i++) {
		printf("%d\n", arr[i]);
	}
	free(arr);
	return 0;

}
