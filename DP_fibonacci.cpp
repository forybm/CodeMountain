#include <stdio.h>

long long int dp[200];

long long int fibonacci(int n)
{
	if(n<=1){
		return n;
	}
	else{
		if(dp[n]>0) return dp[n];
		dp[n]=fibonacci(n-1)+fibonacci(n-2);
		return dp[n];
	}
}

int main()
{
	int n;
	
	scanf("%d",&n);
	
	printf("%ld\n",fibonacci(n));
	
}

