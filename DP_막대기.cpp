#include <stdio.h>

long long int dp[22][22][22];

void myf()
{
	int n,l,r;
	for(int i=0;i<22;i++){
		for(int j=0;j<22;j++)
		{
			for(int k=0;k<22;k++)
			{
				dp[i][j][k]=0;
			}
		}
	}
	
	dp[1][1][1]=1;
	scanf("%d %d %d",&n,&l,&r);
	
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				dp[i][j][k]=dp[i-1][j-1][k]+dp[i-1][j][k-1]+dp[i-1][j][k]*(i-2);
			}
		}
	}
	
	printf("%llu\n",dp[n][l][r]);
}

int main()
{
	int testcase;
	scanf("%d",&testcase);
	while(testcase--) myf();
	
}

	
