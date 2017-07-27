#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

char A[5555], B[5555];
int ha[5555][27], hb[5555][27], h[27];
int dp[5555][5555];
int la, lb;

void histo() {
	for (int i = 1;i < la ;i++) {
		for (int j = 0;j < 26;j++) {
			ha[i][j] = ha[i - 1][j];
		}
		ha[i][A[i] - 'A']++;
	}
	for (int i = 1;i < lb ;i++) {
		for (int j = 0;j < 26;j++) {
			hb[i][j] = hb[i - 1][j];
		}
		hb[i][B[i] - 'A']++;
	}
	for (int i = 1;i < la ;i++) {
		h[A[i] - 'A']++;
	}
	for (int i = 1;i < lb ;i++) {
		h[B[i] - 'A']++;
	}
}
//½ÃÀÛÁ¡ : histo=1 
int isBegin(char c, int x, int y) {
	if (ha[x][c - 'A'] + hb[y][c - 'A'] == 1) {
		return (x + y);
	}
	else return 0;
}

int isEnd(char c, int x, int y) {
	c = c - 'A';
	if (ha[x][c] + hb[y][c] == h[c]) {
		return (x + y);
	}
	else return 0;
}
void myf() {
	
	
	A[0] = ' ';
	B[0] = ' ';

	char temp[5555];
	scanf("%s", &temp);
	strcat(A, temp);
	scanf("%s", &temp);
	strcat(B, temp);
	la = strlen(A);
	lb = strlen(B);
	
	for (int i = 0;i <= la;i++) {
		for (int j = 0;j <= lb;j++) {
			dp[i][j] = 987654321;
		}
	}
	for (int i = 0;i <= la;i++) {
		for (int j = 0;j < 26;j++) {
			ha[i][j] = 0;
		}
	}
	for (int i = 0;i <= lb;i++) {
		for (int j = 0;j < 26;j++) {
			hb[i][j] = 0;
		}
	}
	for (int i = 0;i <= 26;i++) {
		h[i] = 0;
	}

	histo();



	dp[0][0] = 0;
	for (int i = 0;i < la;i++) {
		for (int j = 0;j < lb;j++) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] - isBegin(A[i + 1], i + 1, j) + isEnd(A[i + 1], i + 1, j));
		//	cout << -isBegin(A[i + 1], i + 1, j) + isEnd(A[i + 1], i + 1, j) << ' ';
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] - isBegin(B[j + 1], i, j + 1) + isEnd(B[j + 1], i, j + 1));
		//	cout << -isBegin(B[j + 1], i, j + 1) + isEnd(B[j + 1], i, j + 1) << endl;
		}
	}



	printf("%d\n", dp[la - 1][lb - 1]);

	for (int i = 0;i <= la;i++) {
		A[i] = NULL;
	}
	for (int i = 0;i <= lb;i++) {
		B[i] = NULL;
	}
	for (int i = 0;i <= la;i++) {
		for (int j = 0;j <= lb;j++) {
			dp[i][j] = 0;
		}
	}
}


int main() {
	int test;
	scanf("%d", &test);
	while(test--) myf();


}
