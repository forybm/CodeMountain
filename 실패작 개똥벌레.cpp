#include <stdio.h>
#include <algorithm>

using namespace std;

int H[500000]={0};

int main()
{
	int length,high;  //동굴의 길이, 동굴의 높이 
	int n[200000]; //종유석 갯 
	
	scanf("%d%d",&length,&high);
	
	for(int i=1;i<=length;i++)
	{
		scanf("%d",&n[i]);
	}

	for(int i=1;i<=length;i++)  
	{
		if(i%2==0)  //짝수번째 종유석은 위세어 아래로 
		{
			for(int j=high;j>=1;j--)
			{
				H[j]++;
				n[i]--;
				if(n[i]==0) break;
			}
		
		}
		else if(i%2==1) //홀수번째 종유석은 아래에서 위 
		{
			for(int j=1;j<=high;j++)
			{
				H[j]++;
				n[i]--;
				if(n[i]==0) break;
			}
		}
			
	}
	int count=0;
	sort(H+1,H+high+1);
	for(int i=1;i<=high;i++)
	{
		if(H[1]==H[i]) count++;
		else if(H[i]>H[1]) break;
	}
	printf("%d %d",H[1],count);
	
	
}
