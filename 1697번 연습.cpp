#include <stdio.h>
#include <algorithm>
#include <queue>


using namespace std;

bool check[100001];

int main()
{
	int N , K;
	
	scanf("%d %d",&N,&K);
	
	queue <pair<int,int> > myQ;
	
	pair<int, int> myP = make_pair(N,0);
	
	myQ.push(myP);
	
	check[N] = true;
	
		
	while(!myQ.empty())
	{
		pair <int, int> now = myQ.front();
		myQ.pop();
		
		if(now.first == K){
		printf("%d\n",now.second);
		break;
		}
		
		if(!check[now.first-1] && now.first-1>=0)
		{
			myQ.push(make_pair(now.first-1,now.second+1));
			check[now.first-1]= true;
			
		}
		if(!check[now.first+1] && now.first+1<=100000)
		{
			myQ.push(make_pair(now.first+1,now.second+1));
			check[now.first+1]= true;
			
		}
		if(!check[now.first*2] && now.first*2<=100000)
		{
			myQ.push(make_pair(now.first*2,now.second+1));
			check[now.first*2]= true;
			
		}
	
	}
	
	
}
