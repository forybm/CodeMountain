// 2013012085_À¯º´¹Î_A
// Insertion Sort
#include <stdio.h>
#include <stdlib.h>

int *arr;
int N;

void insertionSort() {
	int pos = 0;
	int temp = 0;
	for (int pos = 1;pos < N;pos++) {
		for (int i = pos;i > 0;i--) {
			if (arr[i] >= arr[i - 1]) {
				temp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp;
			}
			else break;
		}
	}
}

int main() {
	scanf("%d", &N);
	arr = (int*)malloc(sizeof(int)*N);

	for (int i = 0;i < N;i++) {
		int x;
		scanf("%d", &x);
		arr[i] = x;
	}
	insertionSort();
	for (int i = 0;i < N;i++) {
		printf("%d\n", arr[i]);
	}
	free(arr);
	return 0;

}
