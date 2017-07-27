#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>

using namespace std;

int N, M, K;
int arr[5001];
int pro[5001];

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1;i <= N;i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int j = 1;j <= K;j++)
	{
		scanf("%d", &pro[j]);
	}
	int day = 0;
	int check = 0, count = 0;
	for (day = 0;day < (N / M) + (N%M == 0 ? 0 : 1);day++)
	{

		for (int i = 1;i <= M;i++)
		{
			check = 0;
			if (day*M+i>N) break;
			for (int j = 1;j <= K;j++)
			{
				if (arr[day*M + i] == pro[j])
				{
					check++;
					break;
				}
				
			}
			if (check==0) count++;
			else break;
		}
	}
	printf("%d", count);

}


