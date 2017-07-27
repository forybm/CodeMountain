//2013012085_À¯º´¹Î_A
//topologic_sort.cpp

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int N;
vector <int> arr[1111];
vector <int> ans;
int check[1111];
int color[1111]; //0 : white / 1 : gray / 2 : black
int isCycle;
void dfs(int now) {

	if (color[now] == BLACK) return;
	color[now] = GRAY;
	for (int i = 0;i < arr[now].size();i++) {
		if (color[arr[now][i]] == GRAY) {
			isCycle = 1;
			return;
		}
		if (color[arr[now][i]] != BLACK) {
			color[arr[now][i]] = GRAY;
			dfs(arr[now][i]);
		}
	}
	ans.push_back(now);
	color[now] = BLACK;
}

void myf() {
	//input
	scanf("%d\n", &N);
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF) {
		arr[a].push_back(b);
	}
	memset(color, WHITE, sizeof(color));
	for (int i = 1;i <= N;i++) sort(arr[i].begin(), arr[i].end());
	for (int i = 1;i <= N;i++) dfs(i);
	if (isCycle == 1) {
		printf("0");
		return;
	}
	else printf("1\n");
	for (int i = ans.size() - 1;i >= 0;i--) printf("%d ", ans[i]);
}

int main() {
	myf();
	return 0;
}

