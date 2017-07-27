#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
int arr[111111];
long long int w[111111];

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 1;i <= N;i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1;i <= N;i++) {
		w[i] = 9876543210;
	}
	w[1] = min(arr[1],K);
	
	for (int i = 2;i <= N;i++) {
			int temp = 0;
			temp = min(min(w[i - 1] + K, w[i - 2] + 2 * K), min(w[i - 2] + arr[i], w[i - 1] + arr[i]));
			if (temp < w[i]) w[i] = temp;
	}
	printf("%lld", min(w[N - 1], w[N]));
	return 0;
}
