#include <stdio.h>
#include <algorithm>

using namespace std;
int N, M;
long long p, q;
int arr[1000005];
long long tree1[1000005 * 4];
long long tree2[1000005 * 4];


long long maxx(int l,int r) {
	long long temp1,temp2,maax;
	temp1 = temp2 = maax = 0;
	while (l <= r &&l>=0 &&r>=0) {
		if (l % 2 == 1) {
			temp1 = tree1[l];
			l++;
		}
		if (r % 2 == 0) {
			temp2 = tree1[r];
			r--;
		}
		maax = max(maax,max(temp1, temp2));
		l /= 2;
		r /= 2;
	}
	return maax;
}

long long minn(int l, int r) {
	long long temp1, temp2, miin;
	temp1 = temp2 = miin= 9876543210;
	while (l <= r) {
		if (l % 2 == 1) {
			temp1 = tree2[l];
			l++;
		}
		if (r % 2 == 0) {
			temp2 = tree2[r];
			r--;
		}
		miin =min(miin, min(temp1, temp2));
		l /= 2;
		r /= 2;
	}
	return miin;
}


int main() {
	scanf("%d %d", &N, &M);
	
	p = 1; q = 1;
	while (p < N) {
		p *= 2;
		q += p;
	}

	for (int i = 1;i <= N;i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1;i <=N ;i++) {
		tree1[q - p + i] = arr[i];
		tree2[q - p + i] = arr[i];
	}
	for (int i = q - p + N + 1;i <= q;i++) {
		tree2[i] = 9876543210;
	}

	for (int i = q;i > 1;i = i - 2) {
		tree1[i / 2] = max(tree1[i], tree1[i - 1]);
		tree2[i / 2] = min(tree2[i], tree2[i - 1]);
	}
	
	for (int i = 0;i < M;i++) {
		int b, c;
		scanf("%d %d",&b,&c);
		printf("%lld %lld\n", minn(q - p + b, q - p + c), maxx(q - p + b, q - p + c));


	}


}
