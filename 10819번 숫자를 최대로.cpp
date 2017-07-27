#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N, M;
int arr[55];
int maax[55];
int miin[55];

void myf() {
	scanf("%d", &N);
	for (int i = 0;i < N;i++) scanf("%d", &arr[i]);
	sort(arr, arr + N);
	int xpos = 0;
	int npos = 0;
	for (int i = 0;i < N / 2;i++) {
		maax[i] = arr[i];
	}
	for (int i = N / 2;i < N;i++) {
		miin[i - N / 2] = arr[i];
	}
	for (int i = 0;i < N;i++) {
		if (i % 2 == 0) {
			arr[i] = miin[npos++];
		}
		else arr[i] = maax[xpos++];
	}
	int sum = 0;
	for (int i = 0;i < N - 1;i++) {
		int temp = arr[i] - arr[i + 1];
		if (temp < 0) temp *= -1;
		sum += temp;
	}
	for (int i = 0;i < N;i++) printf("%d\n", arr[i]);
	printf("%d", sum);
}

int main() {
	myf();
	return 0;
}

