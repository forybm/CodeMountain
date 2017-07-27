#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int testcase;

void myf() {
	scanf("%d", &N);
	if (N == 1) printf("0\n");
	else if (N % 2 == 0) printf("%d\n", N/2);
	else printf("%d\n", N);

}
int main() {
	scanf("%d", &testcase);
	while (testcase--) myf();
}

