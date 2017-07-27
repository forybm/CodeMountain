#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>

using namespace std;

int arr[100001];

int main()
{
	int N;
	int min;
	scanf("%d", &N);
	for (int i = 0;i < N;i++)
	{
		scanf("%d ", &arr[i]);
	}
	int M;
	scanf("%d", &M);
	for (int i = 0;i < M;i++)
	{
		int temp;
		scanf("%d", &temp);
		min = *lower_bound(arr,arr+N,temp);
		printf("%d\n", min);
	}
	

}


