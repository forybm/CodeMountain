#include <stdio.h>

int testcase; 

int main()
{
	int a,b,last_number=1,j,k,answer;
	
	int arr[4]={0,};
	scanf("%d",&testcase);
	for(int ii=0;ii<testcase;ii++){
	scanf("%d %d",&a,&b);
	
	last_number=a;
	arr[0]=a;
	j=0;
	k=0;
	for(int i=0;i<b;i++)
	{
		j++;
		
		last_number=(last_number*a)%10;
		arr[j]=last_number;
		if(arr[j]==arr[0]) break;
	}
	
	answer=b%j;
	if (answer==0) {
		answer=j-1;
		printf("%d\n",arr[answer]);
	}
	else {
	printf("%d\n",arr[answer-1]);
}
}

	return 0;
	
}

	
	
