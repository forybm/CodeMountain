#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int money, N;			//총 돈, 기업 수
int cc[22][333];		//cc[i][j] i번째 기업에 j원 투자할때 얻는 투자금.
int dp[22][333];

void myf()
{
	scanf("%d %d", &money, &N);
	for (int i = 1;i <= money;i++)
	{

			int a;
			scanf("%d", &a);

			for (int k = 1;k <= N;k++)
			{
				scanf("%d", &cc[k][a]);
			}

	}
	for (int i = 0;i <= money;i++)
	{
		dp[1][i] = cc[1][i];
	}
	int *temp;
	temp = (int*)malloc(sizeof(int)*(money+1));

	for (int i = 1;i <= N;i++)
	{
		for (int j = 0;j <= money;j++)
		{
			for (int k = 0;k <= j;k++)
			{
				temp[k] = dp[i - 1][k] + cc[i][j - k];
			}
			dp[i][j] = *max_element(temp, temp + money + 1);
		}	
	}
	printf("%d", dp[N][money]);
	
}

int main()
{
	myf();
}
