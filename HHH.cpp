#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int V[1111],L[1111];
int dp[1111];

void myf()
{
	scanf("%d", &N);
	for (int i = 1;i <= N;i++)
	{
		scanf("%d %d", &V[i],&L[i]);
		
	}
	dp[1] = 1;

	for (int i = 2;i <= N;i++)
	{
		int max = 0;
		int temp = 0;
		for (int j = 1;j<i;j++)
		{
			if (V[j] < V[i] && L[j]>L[i] && dp[j] > max)
			{
				max = dp[j];
				temp = j;
			}

		}
		if (max == 0) dp[i] = 1;
		else	dp[i] = dp[temp] + 1;
	}

	int max = *max_element(dp + 1, dp + N + 1);
	printf("%d", max);

}

int main()
{
	myf();

}
