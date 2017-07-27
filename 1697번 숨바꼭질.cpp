#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;


bool check[100000];
int main()
{
	int start, end;
	
	scanf("%d %d",&start,&end);
	
	queue <pair<int,int> > myQ;
	
	pair<int, int> myP = make_pair(start,0);
	
	myQ.push(myP);
	
	check[start] = true;
	
	
	while(!myQ.empty())
	{
		pair <int, int> now ;
		now = myQ.front();
		myQ.pop();
		
		if(now.first == end){
			printf("%d\n",now.second);
			break;
		}
		
		if(now.first-1>=0 && !check[now.first-1]) 
		{
			myQ.push(make_pair(now.first-1,now.second+1));
			check[now.first-1] = true;
		}
		if(now.first+1<=100000 && !check[now.first+1])
		{
			myQ.push(make_pair(now.first+1,now.second+1));
			check[now.first+1] = true;
		}
		if(now.first*2<=100000 && !check[now.first*2])
		{
			myQ.push(make_pair(now.first*2,now.second+1));
			check[now.first*2] = true;
		}
	}
}

			
			
			
