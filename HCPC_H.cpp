#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int testcase;
int arr[111];
int res;

void myf() {
	memset(arr, 0, sizeof(arr));
	res = 0;
	scanf("%d %d", &N, &M);

	int st = 0, ed = N; int cnt = 0;
	
	for (int i = 0;i < N;i++) {
		scanf("%d", arr + i);
	}

	int start = 0, end = 0;
	for (int i = 1; i < N; i++) {
		if (arr[i-1] <= arr[i] &&arr[i] >= arr[i + 1]) {
			end = arr[i];
			if (start == end)
				continue;
			else {
				int hight = arr[end];
				if (arr[start] < arr[end])
					hight = arr[start];

				for (int j = start + 1; j < end; j++) {
					res += hight - arr[j];
				}
				start = end;
			}
		}
	}

	//printf("%d", res);
	
	//for (int i = 1;i < N;i++) {
	//	if (arr[i] >= arr[i-1]) st++;
	//	else break;
	//}
	//for (int j = N - 2;j >= 0;j--) {
	//	if (arr[j + 1] <= arr[j]) ed--;
	//	else break;
	//}

	//for (int i = st;i < ed;i++) {
	//	//int temp = 0;
	//	
	//	for (int j = i + 1;j < ed;j++) {
	//		if (arr[i] > arr[j]) {
	//			res += arr[i] - arr[j];
	//			if (j == ed - 1) res -= (j - i)*(arr[i] - arr[j]);
	//			//printf("arr[%d]=%d   arr[%d]=%d   sum = %d\n",i,arr[i],j,arr[j], arr[i] - arr[j]);
	//		}
	//		else {
	//			i = j-1;
	//			//res += temp;
	//			//printf("Jump to %d\n", j);
	//			//printf("%d ", arr[j]);
	//			break;
	//		}
	//	}
	//}
	//
	printf("res = %d start = %d & end = %d\n", res, st, ed);
	if (res == 0) printf("FAIL\n");
	else if (res <= M)printf("SWIM\n");
	else printf("DUMPED\n");
	
}
int main() {
	scanf("%d", &testcase);
	while (testcase--) myf();
}

