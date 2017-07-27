#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>

using namespace std;

int arr[55][55];
bool check[55][55];

int main()
{
	int N,M;
	scanf("%d %d", &N,&M);
	
	for(int i=0;i<M;i++){
		int a,b,c;
		scanf("%d %d",&a,&b);
		arr[b][a]=1;
	}
	int ybm = 0;

	for (int i = 1;i <= N;i++)
	{
		for (int j = 1;j <= N;j++)
		{
			if (arr[i][j]==1 &&arr[i][j] == arr[j][i])
			{
				ybm++;
				break;
			}
		}
	}
		if (ybm!=0) printf("NO");
		else printf("YES");
}


