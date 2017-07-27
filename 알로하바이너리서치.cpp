#include <stdio.h>
#include <algorithm>

using namespace std;

int BinarySearch(int arr[100000],int value,int n)
{
	int high=n-1,low=0,mid;
	
	while(low<=high)
	{
		mid=(low+high)/2;
		
		if(arr[mid]>value) high=mid-1;
		else if(arr[mid]<value) low=mid+1;
		else return 1;	 
	}
	return 0;
	
}



int main()
{
	int n1,n2,low,high;
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
	for(int i=0;i<n2;i++){
	answer=BinarySearch(arr,value[i],n1);
	printf("%d\n",answer);
	}
		
	return 0;
	
}

