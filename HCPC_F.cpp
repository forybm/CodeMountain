#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
using namespace std;

int N;
int testcase;
char arr[11];
void myf() {
	scanf("%s", arr);
	if (atoi(arr) == 22) {
		printf("2\n");
		return;
	}
	int maax = 0; int max_char = 0;
	
	for (int i = 0;i < strlen(arr);i++) {
		int cnt = 0; int temp_char = (int)arr[i] - 48;
		for (int j = i;j < strlen(arr);j++) {
			if (arr[i] == arr[j]) cnt++;
			else {
				break;
			}
		}
		if (cnt > 9) {
			i = i + cnt;
			cnt = 1;
		}
		maax = max(maax, cnt);
		max_char = max(max_char, temp_char);
	}

	int ans = max(maax, max_char);
	if (ans < 3) ans = 3;
	printf("%d\n", ans);
}
int main() {
	scanf("%d", &testcase);
	while (testcase--) myf();
}

