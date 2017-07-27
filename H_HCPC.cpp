#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int check[555];
int arr[555][555];
queue < pair<int, int> > gQ;
queue < pair<int, int> > sQ;
queue < pair<int, int> > bQ;

void myf() {
	int n;
	scanf("%d", &n);
	printf("%d %d", n + 1, n);
}
int main() {
	/*scanf("%d", &testcase);
	while (testcase--) myf();*/
	myf();
	return 0;
}

