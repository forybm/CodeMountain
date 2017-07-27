#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int testcase;
char str[222222];

int lps(int i, int j)
{
	if (i == j)
		return 1;

	if (str[i] == str[j] && i + 1 == j)
		return 2;

	if (str[i] == str[j]) {
		if (str[i + 1] == str[j - 1]) return lps(i + 1, j - 1) + 2;
		else return lps(i + 1, j - 1);
	}
	return max(lps(i, j - 1), lps(i + 1, j));
}

void myf() {
	scanf("%s", str);
	printf("%d\n", lps(0, strlen(str) - 1));
}
int main() {
	scanf("%d", &testcase);
	while (testcase--) myf();
}

