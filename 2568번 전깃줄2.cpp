#include <stdio.h>
#include <math.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define Max(a,b) a>b?a:b

int arr[500001]; int dp[500001];
int list[500001]; int back[500001];
int main() {
	int N;
	int count = 0;
	int max_index = 0;; int index;

	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a > max_index) max_index=a;
		arr[a] = b;
	}

	dp[1] = arr[1];
	for (int i = 1;i <= max_index;i++) {
		int max = 0; int arr_index = 0;
		for (int j = 1;j < i;j++) {
			if (arr[i] > arr[j] && max < dp[j]) {
				max = dp[j];
				arr_index = j;

			}
		}
		if (max == 0) dp[i] = 1;
		else dp[i] = dp[arr_index]+1;
	}

	int k = 1;
	
	int maxe = max_element(dp, dp + max_index+1)-dp;
	list[0] = maxe;
	int temp = *max_element(dp, dp + max_index + 1)-1;

	for (int i = maxe-1;i > 0;i--) {
		if (dp[i] == temp && arr[i] < arr[maxe] && arr[i]) {
			temp--;
			list[k++] = i;
		}
	}

	int next = 0;
	sort(list, list + k);
	for (int i = 1;i <= max_index;i++) {
		if (binary_search(list, list + k, i)==false && arr[i]!=0) {
			back[next++] = i;
		}
	}

	/**************************************/
	int answer = *max_element(dp, dp + max_index + 1);
	printf("%d\n", N-answer);
	for (int i = 0;i < next;i++) {
		printf("%d\n", back[i]);
	}
}
