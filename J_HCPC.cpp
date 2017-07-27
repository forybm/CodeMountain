#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;
int arr[64];
void myf() {
	arr[1] = 1;
	int temp = 2;
	int tmp = 2;
	for (int i = 2;i < 64;i++) {
		arr[i] = arr[i - 1] + temp;
		if (tmp == 2) {
			temp = temp + 2;
			tmp = 0;
		}
		tmp++;
	}
	int n;
	scanf("%d", &n);
	printf("%d", arr[n]);
}

int main() {
	int testcase;
	//scanf("%d", &testcase);
	//while (testcase--) myf();
	myf();
	return 0;
}

