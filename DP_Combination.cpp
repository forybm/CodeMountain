#include <stdio.h>

int dp[100][100];

int Combination(int n,int r)
{
	if(r==0||n==r) return 1;
	
	else{
		if(dp[n][r]>0) return dp[n][r];
		
		return dp[n][r] =Combination(n-1,r-1)+Combination(n-1,r);
	}
}

int main()
{
	int count;
	scanf("%d",&count);
	
	for(int i=0;i<count;i++)
	{
		int n,r;
		scanf("%d%d",&n,&r);
		
		printf("%d\n",Combination(n,r));
	}
}

