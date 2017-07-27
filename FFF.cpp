#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>

using namespace std;

bool check[22][22];
int arr[22][22];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int main()
{
	int N, M;

	scanf("%d %d", &N, &M);
	int sa, sb, fa, fb;
	scanf("%d %d %d %d", &sa, &sb, &fa, &fb);
	for (int i = 1;i <= N;i++)
	{
		for (int j = 1;j <= M;j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}


	
	queue<pair<pair<int, int>, int> > myQ;
	pair<pair<int, int>, int> myP;
	myP.first= make_pair(sa, sb);
	myP.second = 1;
	
	myQ.push(myP);

	while (!myQ.empty())
	{
		pair<pair<int, int>, int> now=myQ.front();
		pair<pair<int, int>, int> tempP;

		myQ.pop();


		if (now.first.first == fa && now.first.second == fb)
		{
			printf("%d", now.second*100 + 3000);
			break;
		}
		for (int k = 0;k < 4;k++)
		{
			int r = now.first.first + dr[k];
			int c = now.first.second + dc[k];
			if (r > 0 && c>0 && r <= N && c <= M && !check[r][c] && arr[r][c])
			{
				check[r][c] = true;
				tempP.first = make_pair(r, c);
				int temp = now.second + 1;
				tempP.second = temp;
				myQ.push(tempP);
			}
		}
	}




}


