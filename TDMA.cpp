#include <stdio.h>
#include <math.h>

float T[6][6];
float abc[4][6];
float d[6];
float x[6];

float PP(int n)
{
	if(n==1) return (-1)*(abc[3][1]/abc[2][1]);
	else{
		return (-1)*abc[3][n]/(abc[1][n]*PP(n-1)+abc[2][n]);
	}
}

float QQ(int n)
{
	if(n==1) return d[1]/abc[2][1];
	else{
		return (d[n]- abc[1][n] * QQ(n-1)) / (abc[1][n]*PP(n-1) + abc[2][n]);
	}
}

int main()
{
	int n=0;
	
	
	printf("abc값 입력\n"); 
	for(int i=1;i<6;i++)
	{
		for(int j=1;j<4;j++)
		{
			scanf("%f",&abc[j][i]);
			
		}
	}
	printf("행렬값 입력\n"); 
	for(int i=1;i<6;i++)
	{
		for(int j=1;j<6;j++)
		{
			scanf("%f",&T[i][j]);
			
		}
	}
	printf("d 값 입력\n"); 
	for(int i=1;i<6;i++)
	{
		scanf("%f",&d[i]);
	}
	
	printf("\n_____________________________\n",QQ(5));
	
	
	x[5]=QQ(5);
	for(int i = 4; i>0;i--)
	{
		x[i]=PP(i+1)*x[i+1]+QQ(i);
	}
	
	for(int i=1;i<6;i++)
	{
		for(int j=1;j<6;j++)
		{
			printf("%f ",T[i][j]);
		}
		printf("\n");
	}
	
	printf("\n_____________________________\n");
	
	for(int i=1;i<6;i++)
	{
		printf("x%d = %f\n",i,x[i]);
	}
	
}
	
	
	
	
	
