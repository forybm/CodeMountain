#include <stdio.h>
#include <queue>

using namespace std;

bool check[111];
int arr[111][111];
int main()
{
	int n,m;
	
	scanf("%d",&n);
	scanf("%d",&m);
	
	for(int i = 0 ; i < m ; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		arr[a][b]=arr[b][a]=1;
	}
	
	queue <int> myQ;
	myQ.push(1);
	check[1]= true;
	
	int count = 0;
	
	while(!myQ.empty())
	{
		int now = myQ.front();
		myQ.pop();
		
		for(int i = 1 ; i <= n ; i++){
		if(!check[i] && arr[now][i])
		{
			count++;
			check[i] = true;
			myQ.push(i);
			
		}
		}
		
	}
	
	printf("%d\n",count);
	
}

