#include <stdio.h>
#include <stdlib.h>

int add(int x,int y);
int sub(int x,int y);
int mul(int x,int y);
int div1(int x,int y);
int(*pf[4])(int x,int y)={add,sub,mul,div1};
int main(){
	int n=0;
	int a,b;
	while(1){
	printf("==================\n");
	printf("0. add\n");
	printf("1. sub\n");
	printf("2. mul\n");
	printf("3. div\n");
	printf("4. exit\n");
	printf("==================\n");
	printf("Select Operation : ");
	scanf("%d",&n);
	if(n==4) break;
	printf("Input %d operand : ",n);
	scanf("%d %d",&a,&b);
	printf("Result = %d\n",pf[n](a,b));
}

}

int add(int x,int y){
	return x+y;
}
int sub(int x,int y){
	return x-y;
}
int mul(int x,int y){
	return x*y;
}
int div1(int x,int y){
	return x/y;
}
	
	
