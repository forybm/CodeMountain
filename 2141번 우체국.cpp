#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

long long int X[111111], A[111111],dis[111111];
long long int dp[111111];
long long int Z[111111];
pair<long long int, long long int> ybm[111111];
long long int abst(long long int x)
{
	if (x < 0) return x*(-1);
	else return x;
}
int main()
{
	int N;
	
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%lld %lld", &X[i], &A[i]);
	}

	for (int i = 0;i < N;i++) {
		ybm[i] = make_pair(X[i], A[i]);
	}
	sort(ybm, ybm + N);

	Z[0] = ybm[0].second;
	for (int i = 1;i < N;i++) {
		Z[i] = Z[i - 1] + ybm[i].second;
	}


	for (int i = 1;i < N;i++) {
		dis[i] = abst(ybm[i].first - ybm[i - 1].first);
	}

	for (int i = 0;i < N;i++) {
		dp[0] += abst(ybm[i].first - ybm[0].first)*ybm[i].second;
	}
	
	for (int i = 1;i < N;i++) {
		dp[i] = dp[i - 1] + dis[i] * (Z[i - 1] - Z[N - 1] + Z[i - 1]);
	}
	
	for (int i = 0;i < N;i++)
	{
		printf("%lld %lld %lld %lld// dp: %lld\n", ybm[i].first, ybm[i].second, Z[i], dis[i],dp[i]);
	}

	long long int min = min_element(dp, dp + N) - dp;
	long long int answer = ybm[min].first;
	printf("%lld", answer);
	
}
