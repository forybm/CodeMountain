#include <stdio.h>
#include <math.h>
int main(){
	double x1,x2,y1,y2,r1,r2;
	double d;
	int i,test_case;
	scanf("%d",&test_case);
	for(i=0;i<test_case;i++)
	{
				scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2);
				
				d=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
				if(x1==x2&&y1==y2&&r1==r2) printf("-1\n");
				else if(x1==x2&&y1==y2&&r1!=r2) printf("0\n");
				
				if(x1!=x2||y1!=y2)
				{
					if(r1>d&&r2>d){
					if(r1+r2>d) printf("2\n");
					else if (r1+r2==d) printf("1\n");
					else if (r1+r2<d) printf("0\n");
				}
					else if(r1<d||r2<d)
					{
						if(r1+d==r2) printf("1\n");
						else if (r2+d==r1) printf("1\n");
						else printf("0\n");
				}
			}
				
	}
}
