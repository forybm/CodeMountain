#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int arr[111111];
int dp[111111];


void myf()
{
	scanf("%d", &N);
	for (int i = 1;i <= N;i++)
	{
		scanf("%d", &arr[i]);
	}
	dp[1] = arr[1];

	for (int i = 1;i <= N;i++)
	{
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}

	int max = *max_element(dp + 1, dp + N+1);
	printf("%d", max);
}

int main()
{
	myf();
	return 0;
}



	

