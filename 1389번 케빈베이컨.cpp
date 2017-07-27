#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>

using namespace std;

int arr[101][101];

bool check[111][111];
int dis[111];

int main()
{
	int n ,M;
	
	scanf("%d %d",&n,&M);
	
	for(int i = 1 ; i <= M ; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		arr[a][b]=arr[b][a]=1;
	}
	queue <int > myQ;
	
	myQ.push(1);
	check[1][1] = true;
	
	while( !myQ.empty())
	{
		int now = myQ.front();
		myQ.pop();
		
		for(int i = 1 ; i <= n; i++)
		{
			if(arr[now][i] && !check[now][i])
			{
				dis[now] ++;
				check[i][now] = true;
			}
			myQ.push(i);
		}
	}
	
	//sort(arr+1,arr+n+1);
	
	printf("%d\n",arr[3]);
}

			
		
		
		 	
		
	
	
	
