#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int testcase;
int arr[1111];

void myf() {
	memset(arr, 0, sizeof(arr));
	scanf("%d", &N);
	long long int sum = 1;
	for (int i = 0;i < N;i++) {
		int a; scanf("%d", &a);
		sum *= a*(a - 1);
	}
	printf("%lld\n", sum);

}
int main() {
	scanf("%d", &testcase);
	while (testcase--) myf();
}

