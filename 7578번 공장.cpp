#include <stdio.h>
#include <algorithm>

using namespace std;
int N, M;
long long p, q;

int arr[1000001];
int arr2[500005];
long long tree[500005 * 4];

long long calc(int l, int r) {
	if (l > r) return 0;
	long long sum = 0;
	while (l <= r) {
		if (l % 2 == 1) {
			sum += tree[l];
			l++;
		}
		if (r % 2 == 0) {
			sum += tree[r];
			r--;
		}
		l /= 2;
		r /= 2;
	}
	return sum;
}

void change(int index, int c) {

	tree[index] = c;
	while (index>1) {
		if (index % 2 == 0) {
			tree[index / 2] = tree[index + 1] + tree[index];
		}
		else if (index % 2 == 1) {
			tree[index / 2] = tree[index] + tree[index - 1];
		}
		index /= 2;
	}
}


int main() {
	scanf("%d", &N);
	for (int i = 1;i <= N;i++) {
		int temp;
		scanf("%d", &temp);
		arr[temp] = i;
	}
	for (int i = 1;i <= N;i++) {
		int temp; scanf("%d", &temp);
		arr2[i] = arr[temp];
	}
	p = 1;q = 1;
	while (p < N) {
		p *= 2;
		q += p;
	}
	long long cnt = 0;

	for (int i = 1;i <= N;i++) {
		cnt += calc(q - p + arr2[i] + 1, q);
		change(q - p + arr2[i], 1);
	}

	
	printf("%lld", cnt);

}
