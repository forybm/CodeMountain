#include <stdio.h>
#include <math.h>
#include <queue>
#include <algorithm>

using namespace std;

long long int dp[65];

void myf(int num) {
	int k;
	scanf("%d", &k);
	unsigned long long int ans2=0;
	ans2 = pow(2, k);


	printf("Case #%d\n", num + 1);
	printf("%lld %llu\n", dp[k], ans2);
}

int main() {
	setbuf(stdout, NULL);
	int T;
	scanf("%d", &T);
	dp[0] = 1; dp[1] = 2; dp[2] = 4; dp[3] = 8;

	queue <pair<long long int, int> > myQ;
	myQ.push(make_pair(16, 4));

	while (!myQ.empty()) {
		pair<long long int, int> now = myQ.front();
		if (now.second == 64) break;
		if (dp[now.second] == 0) dp[now.second] = now.first;
		else if (dp[now.second] > now.first) dp[now.second] = now.first;
		
		myQ.pop();

		if ((now.first-1)%3 == 0 && (now.first - 1) / 3 % 2 != 0) {
			
			if ((now.first - 1) / 3 % 2 != 0) {
				myQ.push(make_pair((now.first - 1) / 3, now.second + 1));
				if (((now.first - 1) / 3) % 3 == 0) myQ.push(make_pair(now.first * 2, now.second + 1));
			}
		}
		else myQ.push(make_pair(now.first * 2, now.second + 1));
		
	}

	
	for (int i = 0;i < T;i++) {
		myf(i);
	}
	return 0;

}
