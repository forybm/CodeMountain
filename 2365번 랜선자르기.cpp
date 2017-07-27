#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <vector>
#include <math.h>

using namespace std;
long long int K, N;
long long int arr[11111];

long long int result[3];
long long int temp;
void myf(long long int left, long long int right) {
	if (left == right) result[0] = left, result[1] = (left + right) / 2, result[2] = right;
	else if (abs(left - right) == 1) result[0] = left, result[1] = (left + right) / 2, result[2] = right;
	else {
		long long int res = 0;
		long long int middle = (left + right) / 2;
		for (long long int i = 0;i < K;i++) {
			res += arr[i] / middle;
		}
		temp = middle;

		if (res < N) myf(left, middle);
		else if (res >= N) myf(middle, right);
	}

}

int main() {
	scanf("%lld %lld", &K, &N);
	for (int i = 0;i < K;i++) {
		scanf("%lld", &arr[i]);
	}

	long long int right = *max_element(arr, arr + K);
	myf(0, right);
	int arr_index = 0;
	for (int j = 2;j >= 0;j--) {
		int ans = 0;
		for (int i = 0;i < K;i++) {
			ans += arr[i] / result[j];
		}
		if (ans == N) {
			arr_index = j;
			break;
		}
	}
	
	printf("%lld", result[arr_index]);

	return 0;

}
