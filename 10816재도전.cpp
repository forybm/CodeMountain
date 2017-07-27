#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int binary_Search(long int arr[],int n,int value)
{
	int low,high,mid;
	int count=0;
	low=0; high=n-1;
	
	while(low<=high){
	
	mid=(low+high)/2;
	if(arr[mid]>value) high=mid-1;
	else if(arr[mid]<value) low=mid+1;
	else 
	{
		while(arr[mid]==value)
		{
			count++;
			mid++;
		}
	}
	return count;
}
}


int main()
{
	int n1,n2,high,low;
	long int *arr;
	long int *value;
	int find;
	
	scanf("%d",&n1);
	arr=(long int*)malloc((sizeof (long int))*n1);
	for(int i=0;i<n1;i++)
	{
		scanf("%ld",&arr[i]);
	}
	
	scanf("%d",&n2);
	value=(long int*)malloc((sizeof (long int))*n2);
	for(int i=0;i<n2;i++)
	{
		scanf("%ld",&value[i]);
	}
	
	sort(arr,arr+n1);
	high=arr[n1-1];
	low=arr[0];
	
	for(int i=0;i<n2;i++)
	{
		find=binary_Search(arr,n1,value[i]);
		printf("%d ",find);
	}
	return 0;
}
