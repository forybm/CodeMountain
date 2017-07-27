#include <stdio.h>
#include <queue>

using namespace std;

int check[101];
int dis[101];
int adj[101][101];

int main()
{
	int N , st , ed, M;
	scanf("%d",&N);
	scanf("%d %d",&st, &ed);
	scanf("%d",&M);
	
	for(int i = 1; i <= N; i++)
	{
		dis[i]=-1;
	}
	
	while(M--) {
		int a, b;
		scanf("%d %d",&a,&b);
		adj[a][b]=adj[b][a]=1;
	}
	
	queue <int> myQ;
	myQ.push(st);
	check[st]=1; dis[st]=0;
	
	while(!myQ.empty()){
		int now=myQ.front();
		myQ.pop();
		
		for(int i = 1; i<=N; i++)
		{
			if(adj[now][i] && !check[i])
			{
				check[i]=1;
				dis[i]=dis[now]+1;
				myQ.push(i);
			}
		}
	}
	
	printf("%d\n",dis[ed]);
}

