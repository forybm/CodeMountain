#include <stdio.h>

bool finish(int arr[])
{
	if(arr[0] && arr[1] && arr[2] && arr[3] && arr[4] && arr[5] && arr[6] && arr[7] && 
	arr[8] && arr[9] ) return true;
	else return false;
}


void func(int a)
{
	
	
	int N,arr[10];
	int tmp,answer;
	scanf("%d",&N);
	
	for(int i = 0 ; i <10; i++) arr[i]=0;
	if(N==0) printf("Case #%d: INSOMNIA\n",a);
	else{
	while(!finish(arr))
	{
		
		for(int i = 1 ; ; i++)
		{
			tmp = N * i;
			answer=tmp;
			while(tmp){
				arr[tmp%10]=1;
				tmp=tmp/10;
			}
			if(finish(arr)) break;
		}
	}
	
	printf("Case #%d: %d\n",a,answer);}
	
}

int main()
{
	int testcase;
	int a;
	scanf("%d",&testcase);
	for(int i =1 ; i<=testcase;i++)
	{
		func(i);
	}

}
			
	
	
