#include <stdio.h>
#include <queue>
using namespace std;
 
int dis[101];
bool check[101];
int arr[101][101];
int main()
{
	int n,m,x,y;
	
	scanf("%d",&n);
	scanf("%d %d",&x,&y);
	scanf("%d",&m);
	
	for(int i = 1; i <= n; i++){
		dis[i]=-1;}
		
	for(int i = 0; i < m;i++)
	{
		int a , b;
		scanf("%d %d",&a,&b);
		arr[a][b]=arr[b][a]=1;
	}
	
	queue<int> myQ;
	myQ.push(x);
	check[x]=true;
	dis[x]=0;
	while(!myQ.empty())
	{
		int find = myQ.front();
		myQ.pop();
		
		for(int i=1; i<=n ;i++)
		{
			if(arr[find][i]!=0 && !check[i])
			{
				dis[i]=dis[find]+1;
				check[i]=true;
				myQ.push(i);
			}
		}
	}
	printf("%d\n",dis[y]);
}

		
	
	
