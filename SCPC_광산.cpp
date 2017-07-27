#include <stdio.h>
#include <algorithm>

using namespace std;
int N;

pair<pair<int, int>,int> myp[111111];
int max_w[111111];
void myf(int x)
{
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		myp[i].first = make_pair(a, b);
		myp[i].second = c;
	}
	int maxe = 0;

	for (int j = 0;j < N;j++) {
		for (int k = 0;k < N;k++) {
			int temp = 0;
			for (int i = 0;i < N;i++) {
				
				//SW
				if (myp[i].first.first <= myp[j].first.first && myp[i].first.second <= myp[k].first.second && myp[i].second == 0) temp++;
				//NW
				else if (myp[i].first.first <= myp[j].first.first && myp[i].first.second >= myp[k].first.second && myp[i].second == 1) temp++;
				//SE
				else if (myp[i].first.first >= myp[j].first.first && myp[i].first.second <= myp[k].first.second && myp[i].second == 1) temp++;
				//NE
				else if (myp[i].first.first >= myp[j].first.first && myp[i].first.second >= myp[k].first.second && myp[i].second == 0) temp++;
			}
			if (maxe < temp) maxe = temp;
		}
			
	}

	int ans = maxe;
	printf("Case #%d\n%d\n",x,ans );

	/* ÃÊ±âÈ­ */
	for (int i = 0;i < N;i++) {
		myp[i].first = make_pair(0, 0);
		myp[i].second = 0;
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

