#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <vector>
#include <math.h>

using namespace std;
long long int N, M;
long long int arr[111111];

int main() {
	scanf("%lld %lld", &N, &M);
	for (int i = 0;i < N;i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + N);
	long long int start = 0; long long int end = arr[0]*M;
	long long int res = 0;
	
	while (start<=end) {
		
		long long int middle = (start + end) / 2;
		long long int ans = 0;
		for (int i = 0;i < N;i++) {
			ans += middle/arr[i];
		}
		
		if (ans >= M) {
			res = middle;
			end = middle-1;
		}
		else start = middle+1;
	}

	printf("%lld", res);

	
}
