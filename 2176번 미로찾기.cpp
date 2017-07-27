#include <stdio.h>
#include <queue>

using namespace std;

int dr[4]={1,0,-1,0};
int dc[4]={0,1,0,-1};

int map[100][100];
int cnt[100][100];


int main()
{
	int row,col;
	
	scanf("%d %d",&row,&col);
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			scanf("%1d",&map[i][j]);
			cnt[i][j] = -1;
		}
	}
	
	
	queue<pair<int, int> > myQ;
	myQ.push(make_pair(0,0));
	
	cnt[0][0] = 1;
	while(!myQ.empty())
	{
		pair <int, int> now = myQ.front();
		myQ.pop();
		
		for(int k = 0 ; k < 4 ; k++)
		{
			int r = now.first + dr[k];
			int c = now.second + dc[k];
			
			if(r>=0 && r<row && c>=0 && c<col &&map[r][c]==1 && cnt[r][c]==-1)
			{
				cnt[r][c] = cnt[now.first][now.second] + 1;
				myQ.push(make_pair(r,c));
			}
		}
	}
	
	printf("%d\n",cnt[row-1][col-1]);
}
	

