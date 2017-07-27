#include <stdio.h>
#include <algorithm>
using namespace std;

long long int N, k,cnt;
long long int arr[10];

long long int pow(int a,long long int b) {
	int res = 1;
	for (int i = 0;i < b;i++) {
		res *= a;
	}
	return res;
}
int main() {
	scanf("%lld %lld", &N, &k);
	long long int temp = N;
	while (temp > 0) {
		temp = temp / 10;
		cnt++;
	}
	for (long long int i = 1;i <= cnt;i++) {
		arr[i] = 9 * pow(10, i-1)*i;
		//printf("%d\n", arr[i]);
	}
	long long int num = 0; int check = 0;
	for (int i = 1;i <= cnt;i++) {
		if (k - arr[i] > 0) k = k - arr[i], num++;
		else {
			check = 1;
			break;
		}
	}
	
	long long int start = pow(10, num); //printf("# %lld\n", start);
	long long int q, r, ans;
	q = k / (num + 1);
	r = k % (num + 1);
	//printf("k = %lld q=%lld r=%lld now = %lld num+1= %lld  N = %lld\n",k, q, r, start + q - 1, num + 1,N);
	
	if (r != 0) r = num + 1 - r;

	if (r == 0 &&start + q - 1 > N) {
		printf("-1");
		return 0;
	}
	else if (r > 0 && start + q - 1 +1> N ) {
		printf("-1");
		return 0;
	}
	if (r == 0) ans = (start + q - 1) % 10;
	else {
		ans = (start + q) % pow(10, r + 1);
		ans = ans / pow(10, r);
	}
	printf("%lld", ans);
}
