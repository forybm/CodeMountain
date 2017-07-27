#include <stdio.h>
float flag;
void interrupt(){
	flag = 1/flag;
}
int main(){
	int n = 0x01;
	flag = 2;
	int x = 20;
	while(x--){
		n=n*flag;
		if(n==0x80 || n==0x01) flag=1/flag;
		if(x==10) interrupt();
		printf("%d\n",n);
	}
}
