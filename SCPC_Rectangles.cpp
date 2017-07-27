#include <stdio.h>
#include <algorithm>

using namespace std;

pair<pair<int, int>, pair<int, int> > rect[5555];

int plane(pair<pair<int, int>, pair<int, int> >a) {
	return (a.second.first - a.first.first)*(a.second.second - a.first.second);
}
bool comp(pair<pair<int, int>, pair<int, int> >a, pair<pair<int, int>, pair<int, int> > b) {
	return plane(a) < plane(b);
}
int K;
int dp[5555];
void myf(int x)
{
	
	int xx, yy;
	scanf("%d %d %d",&xx,&yy, &K);
	
	for (int i = 0;i < K;i++) {
		scanf("%d %d %d %d", &rect[i].first.first, &rect[i].first.second, &rect[i].second.first, &rect[i].second.second);
	}

	sort(rect, rect + K,comp);
	for (int i = 0;i < K;i++) {
		printf("%d >> (%d,%d) (%d,%d)\n", i, rect[i].first.first, rect[i].first.second, rect[i].second.first, rect[i].second.second);
	}
	dp[0] = 1;

	for (int i = 1;i < K;i++) {
		int maxe = 0;
		int temp = 0;
		for (int j = 0;j < i;j++) {
			if (plane(rect[j]) <= plane(rect[i]) && rect[j].first.first>=rect[i].first.first && rect[j].first.second>=rect[i].first.second &&
				rect[j].second.first<=rect[i].second.first && rect[j].second.second<=rect[i].second.second && dp[j] > maxe) {
				maxe = dp[j];
				temp = j;
			}

			if (maxe == 0) dp[i] = 1;
			else dp[i] = dp[temp] + 1;
		}
	
	}
	for (int i = 0;i < K;i++) {
		printf("\t dp[%d]=%d\n", i, dp[i]);
	}
	int ans = *max_element(dp, dp + K);
	printf("#%d Case\n%d\n",x, ans);


	/* ÃÊ±âÈ­ */
	for (int i = 0;i < K;i++) {
		dp[i] = 0;
		rect[i].first.first = 0; rect[i].first.second = 0;
		rect[i].second.first = 0;rect[i].second.second = 0;

	}
}

int main()
{
	int test;
	setbuf(stdout, NULL);
	scanf("%d", &test);
	
	for (int i = 1;i <= test;i++)myf(i);
	return 0;
}

