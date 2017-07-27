#include <stdio.h>
#include <algorithm>

using namespace std;
int N, M, K;
long long p, q;
int arr[10000005];
long long tree[1000005 * 4];

long long calc(int l,int r) {
	long long sum = 0;
	while (l <= r &&l>=0 &&r>=0) {
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

void change(int b, int c) {
	
	int index = q - p + b;
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
	scanf("%d %d %d", &N, &M, &K);
	
	p = 1; q = 1;
	while (p < N) {
		p *= 2;
		q += p;
	}

	for (int i = 1;i <= N;i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1;i <=N ;i++) {
		tree[q - p + i] = arr[i];
	}

	for (int i = q;i > 3;i = i - 2) {
		tree[i / 2] = tree[i] + tree[i - 1];
	}

	int command = 3;
	int cnt1 = 0;
	int cnt2 = 0;
	int b, c;

	while (cnt1 != M || cnt2 != K) {
		scanf("%d", &command);
		switch (command) {
		case 1:
			scanf("%d %d", &b, &c);
			change(b, c);
			
			cnt1++;
			break;
		case 2:

			scanf("%d %d", &b, &c);
			printf("%lld\n", calc(q-p+b, q-p+c));
			cnt2++;
			break;

		}
	}


}
