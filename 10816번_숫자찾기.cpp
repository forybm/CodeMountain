#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
using namespace std;

int countNumber(long int arr[],int n,int value)
{
	int count=0;
	int check;
	check=*upper_bound(arr,arr+n,value);
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]<check)
		 
	}
	
	for(int i=check;i<n;i++)
	{
		
		if(arr[i]==value) count++;
		else if(arr[i]>value) break;
	}
	return count;
}

int main()
{
	int n1,n2;
	long int *arr;
	long int *value;
	int find;
	
	scanf("%d",&n1);
	arr=(long int*)malloc((sizeof (long int))*n1);
	for(int i=0;i<n1;i++)
	{
		scanf("%ld",&arr[i]);
	}
	sort(arr,arr+n1);
	scanf("%d",&n2);
	value=(long int*)malloc((sizeof (long int))*n2);
	for(int i=0;i<n2;i++)
	{
		scanf("%ld",&value[i]);
	}
	
	
	for(int i=0;i<n2;i++)
	{
		find=countNumber(arr,n1,value[i]);
		printf("%d ",find);
	}
	return 0;
}
}

