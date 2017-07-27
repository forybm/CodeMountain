#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
int odd[200001],even[200001];
int val[500001];
int val2[500001];
int main()
{
	int N,H,i;
	
	scanf("%d%d",&N,&H);
	
	for(i=1;i<=N;i++)
	{
		if(i%2==1) scanf("%d",&odd[(i+1)/2]);
		else scanf("%d",&even[i/2]);
	}
	
	sort(odd+1,odd+N/2+1);
	sort(even+1,even+N/2+1);
	
	for(i=1;i<=H;i++)
	{
		val[i]=N/2-(upper_bound(odd+1,odd+1+N/2,i-1)-lower_bound(odd+1,odd+1+N/2,0));
	}
	for(i=1;i<=H;i++)
	{
		val2[i]=N/2-(upper_bound(even+1,even+1+N/2,i-1)-lower_bound(even+1,even+1+N/2,0));
	}
	for(i=1;i<=H;i++)
	{
		val[i]=val[i]+val2[H-i+1];
	}
	
	int ans,count=0;
	sort(val+1,val+H+1);
	ans=*min_element(val+1,val+H+1);
	for(i=1;i<H+1;i++)
	{
		if(val[i]==ans) count++;
		else break;
	}
	
	printf("%d %d",ans,count);
	
}
	
	
