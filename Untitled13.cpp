#include <stdio.h>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

int arr[1111][1111];
bool check[1111][1111];
int main()
{
	int N,M,V;
	
	scanf("%d %d %d",&N,&M,&V);
	
	for(int i = 0 ; i < M ; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		arr[a][b] = arr[b][a] = 1;
	}
	
	queue<pair<int,int>> myQ;
	pair<int,int> temp = make_pair(V,0);
	
	myQ.push(temp);
	
	check[V] = true;
	printf("%d ",V);
	while(!myQ.empty())
	{
		pair<int,int> now = myQ.front();
		myQ.pop();
		
		if(	!check[now-1] && now-1>=0){
			printf("%d ",now-1);
			myQ.push(now-1);
		}
		
		if(	!check[now+1] && now+1<N){
			printf("%d ",now+1);
			myQ.push(now+1);
		}
	
	
	
