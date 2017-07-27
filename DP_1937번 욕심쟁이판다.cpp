#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;
int arr[555][555];
int dp[555][555];
bool check[555][555];
int N;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };


void myf()
{
	int r, c;
	scanf("%d", &N);
	for (int i = 1;i <= N;i++)
	{
		for (int j = 1;j <= N;j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 1;i <= N;i++)
	{
		for (int j = 1;j <= N;j++)
		{
			for (int x = 1;x <= N;x++)
			{
				for (int y = 1;y <= N;y++)
				{
					check[x][y] = false;
				}
			}

			int time = 1;

			queue<pair<pair<int,int>,int> > myQ;
			pair<pair<int, int>, int> myP;
			myP.first = make_pair(i, j);
			myP.second = time;

			myQ.push(myP);
			check[i][j] = true;

			while (!myQ.empty())
			{
				pair<pair<int,int>,int> now = myQ.front();
				myQ.pop();
				
				dp[i][j] = now.second;
				
				for (int k = 0;k < 4;k++)
				{
					r = (now.first).first + dr[k];
					c = (now.first).second + dc[k];
					
					if (r > 0 && c > 0 && r <= N && c <= N && !check[r][c]
						&& arr[r][c] > arr[(now.first).first][(now.first).second])
					{
						check[r][c] = true;
						pair<pair<int, int>, int> temp;
						(temp.first).first = r;
						(temp.first).second = c;
						temp.second = now.second + 1;
						myQ.push(temp);

					}

					
				}
				

			}

		}
	}
	int max = 0;
	for (int i = 1;i <= N;i++)
	{
		for (int j = 1;j <= N;j++)
		{
			if (dp[i][j] >= max) max = dp[i][j];
		}
	}
	printf("%d", max);

}

int main()
{
	myf();
	return 0;
} 
/*
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;
int arr[555][555];
int dp[555][555];

int N;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int find(int x, int y)
{
	int temp = 0;
	for (int k = 0;k < 4;k++)
	{
		int r = x + dr[k];
		int c = y + dc[k];

		if (r > 0 && c > 0 && r <= N && c <= N)
		{
			if (arr[x][y] > arr[r][c])
			{
				if (dp[r][c]!=1) temp = max(temp, dp[r][c] + 1);
				else temp = max(temp, find(r, c) + 1);
			}
		}
	}
	if (temp == 0) temp = 1;
	return temp;
}

void myf()
{
	scanf("%d", &N);
	for (int i = 1;i <= N;i++)
	{
		for (int j = 1;j <= N;j++)
		{
			scanf("%d", &arr[i][j]);
			dp[i][j] = 1;
		}
	}
	for (int i = 1;i <= N;i++)
	{
		for (int j = 1;j <= N;j++)
		{
			dp[i][j]=find(i, j);
		}
	}
	
	int max = 0;
	for (int i = 1;i <= N;i++)
	{
		for (int j = 1;j <= N;j++)
		{
			if (dp[i][j] >= max) max = dp[i][j];
		}
	}
	printf("%d", max);


}

int main()
{
	myf();
	return 0;
} 
*/
