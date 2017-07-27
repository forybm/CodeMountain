#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

char A[111111];
char temp[10000];
int tmp;
int max = 0;

void myf() {
	int n;
	scanf("%d", &n);
	scanf("%s", A);
	int arr[100];
	for (int i = 0; i < 100; i++)
		arr[i] = 0;
	for (int i = 0; i < n; i++) {
		if ((int)A[i] - (int)'a' >= 0) {
			arr[36 + ((int)A[i] - (int)'a')]++;
		}
		else if ((int)A[i] - (int)'A' >= 0) {
			arr[10 + (int)A[i] - (int)'A']++;
		}
		else {
			arr[(int)A[i] - (int)'0']++;
		}
	}

	for (int i = 0; i < 100; i++) {
		if (arr[i] != 0) {
			if (i < 10) {
				printf("%c %d\n", (int)'0' + i, arr[i]);
			}
			else if (i < 36) {
				printf("%c %d\n", (int)'A' + i-10, arr[i]);
			}
			else {
				printf("%c %d\n", (int)'a' + i - 36, arr[i]);
			}
		}

	}
}
int main() {
	int testcase;
	scanf("%d", &testcase);
	while (testcase--) myf();
	return 0;
}

