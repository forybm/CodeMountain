#include <stdio.h>
#include <algorithm>

using namespace std;
int N, M, K;
long long arr[1000001];

struct Tree {
	long long val;
	long long lazy;
};

struct Tree tree[1000001 * 4];

long long init(int node, int start, int end) {
	if (start == end) {
		return tree[node].val = arr[start];
	}
	else {
		return tree[node].val = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

void update(int now, int left, int right, int start, int end, long long val) {
	if (tree[now].lazy != 0) {
		tree[now].val += tree[now].val*(right - left + 1);
		if (left != right) {
			tree[now * 2].lazy += tree[now].lazy;
			tree[now * 2 + 1].lazy += tree[now].lazy;
		}
		tree[now].lazy = 0;
	}
	if (start > right || end < left) return;
	if (start <= left && right <= end) {
		tree[now].val += (right - left + 1)*val;
		if (left != right) {
			tree[now * 2].lazy += val;
			tree[now * 2 + 1].lazy += val;
		}
		return;
	}
	else {
		int mid = (left + right) / 2;
		update(now * 2, left, mid, start, end, val);
		update(now * 2 + 1, mid + 1, right, start, end, val);
	}
	if (left != right) {
		tree[now].val = tree[now * 2].val + tree[now * 2 + 1].val;
	}
}

long long sum(int now, int left, int right, int start, int end) {

	if (tree[now].lazy != 0) {
		tree[now].val += tree[now].lazy*(right - left + 1);
		if (left != right) {
			tree[now * 2].lazy += tree[now].lazy;
			tree[now * 2 + 1].lazy += tree[now].lazy;
		}
		tree[now].lazy = 0;
	}

	if (end<left || start>right) return 0;
	if (start <= left && right <= end) return tree[now].val;
	else {
		int mid = (right + left) / 2;
		return sum(now * 2, left, mid, start, end) + sum(now * 2 + 1, mid + 1, right, start, end);
	}
}


int main() {
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1;i <= N;i++) {
		scanf("%lld", &arr[i]);
	}

	init(1, 1, N);
	
	int command = 3;
	int cnt1 = 0;
	int cnt2 = 0;
	int b, c, d;

	for (int i = 0;i < M + K;i++) {
		scanf("%d", &command);
		switch (command) {
		case 1:
			scanf("%d %d %d", &b, &c, &d);
			update(1, 1, N, b, c, d);
			break;
		case 2:
			scanf("%d %d", &b, &c);
			printf("%lld\n", sum(1, 1, N, b, c));
			break;
		}
	}


}
