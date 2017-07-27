#include <stdio.h>
int a,b;

bool myf(){
	printf("asdasd\n");
		
	if(a>0){		
		a++;
		return true;
	}
	else {
		a=10;
		return false;
	}

}

int main(){
	
	a=-5;
	if(myf())printf("success");
	else printf("fail"); 
	printf("%d",a);
}
