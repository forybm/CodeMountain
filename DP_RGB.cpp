#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int N;
int cashe[1111][3];

int back(int k,int color)
{
	if(k==N+1) return 0;
	int ret=cashe[k][color];
	//if(ret!=-1) return ret;

	for(int i = 0; i<3;i++)
	{
		if(i==color) continue;
		ret=min(ret,cashe[k][i]+back(k+1,i));
	}
	return ret;
}

int main()
{	
	scanf("%d",&N);
	
	for(int i=0;i<N;i++)
	{
		int R,G,B;
		scanf("%d %d %d",&R,&G,&B);
		cashe[i][0]=R; cashe[i][1]=G; cashe[i][2]=B;
	}
	printf("%d\n",back(3,0));
}
