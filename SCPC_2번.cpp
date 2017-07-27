#include <stdio.h>
#include <math.h>
#include <queue>
#include <algorithm>

using namespace std;

int arr[55555];

void myf(int num) {
	int N,K,L;
	long long int count = 0;
	scanf("%d %d %d", &N, &K, &L);
	if (L != 0) {
		for (int i = 0;i < L;i++) {
			int temp;
			scanf("%d", &temp);
			arr[temp] = 1;
		}
	}

	queue<pair<int, int> > myQ;
	myQ.push(make_pair(0, 0));

	while (!myQ.empty()) {
		pair<int, int> now = myQ.front();
		if (now.first == N) count++;
		myQ.pop();

		for (int i = 1;i <= K;i++) {
			if (now.first + i > N) break;
			if (now.second != i) {
				if (arr[now.first + i]==0 && now.first + i <= N) myQ.push(make_pair(now.first + i, i));
			}
		}

	}
	for (int i = 0;i <= N;i++) {
		arr[i] = 0;
	}

	count = count % 1000000009;

	printf("Case #%d\n", num + 1);
	printf("%lld\n", count);

}

int main() {
	setbuf(stdout, NULL);
	int T;
	scanf("%d", &T);
	
	for (int i = 0;i < T;i++) {
		myf(i);
	}
	return 0;

}
