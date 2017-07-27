#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;
int arr[111111];
void func() {
	memset(arr, 0, sizeof(arr));

	int n, k, m;
	int start;
	
	scanf("%d %d %d", &n, &k, &m);
	int a = 1, flag = 1;
	for (int i = 0;i < n*m;i++) {
		arr[i] = a;
		if (a + flag >= 16) {
			flag *= -1;
		}
		else if (a + flag <= 0) {
			flag *= -1;
		}
		a = a + flag;
	}
	
	int pos = k;
	start = arr[pos];

	for (int i = 0; i < m; i++) {
		if (start == 1)
			printf("mmmS\n");
		else if (start == 2)
			printf("mmSm\n");
		else if (start == 3)
			printf("mmSS\n");
		else if (start == 4)
			printf("mSmm\n");
		else if (start == 5)
			printf("mSmS\n");
		else if (start == 6)
			printf("mSSm\n");
		else if (start == 7)
			printf("mSSS\n");
		else if (start == 8)
			printf("Smmm\n");
		else if (start == 9)
			printf("SmmS\n");
		else if (start == 10)
			printf("SmSm\n");
		else if (start == 11)
			printf("SmSS\n");
		else if (start == 12)
			printf("SSmm\n");
		else if (start == 13)
			printf("SSmS\n");
		else if (start == 14)
			printf("SSSm\n");
		else if (start == 15)
			printf("SSSS\n");

		pos = pos + n;
		start = arr[pos];

	}

}

int main() {

	int ttt;

	scanf("%d", &ttt);

	for (int iii = 0; iii < ttt; iii++) {
		func();
	}

	return 0;

}
