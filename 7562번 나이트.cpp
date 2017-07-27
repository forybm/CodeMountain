#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

bool check[333][333];

int arr[333][333];

int dr[8] = {2,2,1,-1,-2,-2,-1,1};
int dc[8] = {-1,1,2,2,1,-1,-2,-2};
	
void func()
{
	int L;
	for(int i = 0 ; i<333;i++)
	{
		for(int j=0 ; j<333;j++)
		{
			arr[i][j] = 0;
			check[i][j] = false;
		}
	}
	
		scanf("%d",&L);
		int sa,sb,ea,eb;
		scanf("%d %d",&sa,&sb);
		scanf("%d %d",&ea,&eb);
		
		queue <pair<pair<int,int>, int> > myQ;
		int time=0;
		pair <pair<int,int>, int> myP;
		myP.first = make_pair(sa,sb);
		myP.second = time;
		
		myQ.push(myP);
		
		check[sa][sb] = true;
		
		
		while(!myQ.empty())
		{
			pair<pair<int , int>,int> now = myQ.front();
			pair<pair<int , int>,int> temp = make_pair(make_pair(0,0),0);
			
			myQ.pop();
			
			if((now.first).first == ea && (now.first).second == eb) 
			{
				printf("%d\n",now.second);
				break;
			}
			for(int k = 0 ; k < 8 ;k++)
			{
				int r = (now.first).first+dr[k];
				int c = (now.first).second+dc[k];
				if(r>=0 && r<L && c>=0 && c<L && !check[r][c]){
					check[r][c] = true;
					temp.first = make_pair(r,c);
					temp.second = now.second;
					now.first = make_pair(r,c);
					now.second++;
					myQ.push(now);
				}
			}
		}
}

int main()
{
	int testcase;
	scanf("%d",&testcase);
	
	while(testcase--) func();	
	
}
