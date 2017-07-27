#include <stdio.h>

int arr[111][111];
int d[111][111];
int main(){
	int N;
	scanf("%d",&N);
	
	for(int i =1 ;i<=N;i++)
	{
		for(int j = 1 ;j <=N;j++)
		{
			int a;
			scanf("%d",&a);
			arr[i][j] = a;
		}
	}
	
	for(int k = 1 ; k <= N ; k++)
	{
		for(int i = 1 ; i <= N ; i++)
		{
			for(int j = 1 ; j <= N ; j++)
			{
				if(arr[i][k] && arr[k][j]) arr[i][j] =1;
			}
		}
	}
	
	for(int i =1;i<=N;i++)
	{
		for(int j = 1 ;j <=N;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
	
		 
