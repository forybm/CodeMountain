#include <stdio.h>
#include <algorithm>

using namespace std;
int dp[111111];
int check[11111];
int arr[111111][3];
int N;
int k;

void find(int n)
{
	dp[1] = arr[1][1];
	check[1] = 1;
	
	for (int i = 2;i < N;i++)
	{
		if (check[i - 1] == 0)
		{
			check[i] = min_element(arr[i], arr[i] + 2) - arr[i];
			if (arr[i][0] == arr[i][1]) check[i] = 1;
		}
		else if (check[i - 1] == 1)
		{
			check[i] = min_element(arr[i], arr[i] + 3) - arr[i];
			if (arr[i][0] == arr[i][1]) check[i] = 1;

		}
		else {
			check[i] = min_element(arr[i] + 1, arr[i] + 3) - arr[i];
			if (arr[i][1] == arr[i][2]) check[i] = 1;

		}
		dp[i] = dp[i - 1] + arr[i][check[i]];
	}
	dp[N] = dp[N - 1] + arr[N][1];



}

void myf()
{
	while (1) {
		scanf("%d", &N);
		if (N == 0)break;

		k++;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		
		find(N);

		printf("%d. %d\n", k, dp[N]);


		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				arr[i][j] = 0;
			}
			dp[i] = 0;
			check[i] = 0;
		}

	}
}
int main()
{
	myf();
}


