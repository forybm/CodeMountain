#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
	int n1,n2;
	int arr[100000];
	int value[100000];
	int answer;
	scanf("%d",&n1);
	for(int i=0;i<n1;i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n1);
	
	scanf("%d",&n2);
	for(int i=0;i<n2;i++)
	{
		scanf("%d",&value[i]);
	}
	
	for(int i=0;i<n2;i++)
	{
		if(binary_search(arr,arr+n1,value[i])) printf("1\n");
		else printf("0\n");
	}
}
	
