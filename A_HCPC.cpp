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
	scanf("%d %d", &N, &M);
	for (int i = 0;i < M;i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		if (c == 0) {
			gQ.push(make_pair(a, b));
		}
		else if (c == 1) {
			sQ.push(make_pair(a, b));
		}
		else bQ.push(make_pair(a, b));
	}
	int cnt = 0;
	int gold = 0, silver = 0, bronze = 0;
	while (!gQ.empty() && cnt < N - 1) {
		pair<int, int> now = gQ.front(); gQ.pop();
		if ((!arr[now.first][now.second] && !arr[now.second][now.first]) && (!check[now.first] || !check[now.second])) {
			check[now.first] = check[now.second] = 1;
			arr[now.first][now.second] = arr[now.second][now.first] = 1;
			//printf("GOLD %d %d\n", now.first, now.second);
			gold++; cnt++;
		}
	}
	while (!sQ.empty() && cnt < N - 1) {
		pair<int, int> now = sQ.front(); sQ.pop();
		if ((!arr[now.first][now.second] && !arr[now.second][now.first]) && (!check[now.first] || !check[now.second])) {
			check[now.first] = check[now.second] = 1;
			arr[now.first][now.second] = arr[now.second][now.first] = 1;
			//printf("SILVER %d %d\n", now.first, now.second);
			silver++; cnt++;
		}
	}
	while (!bQ.empty() && cnt < N - 1) {
		pair<int, int> now = bQ.front(); bQ.pop();
		if ((!arr[now.first][now.second] && !arr[now.second][now.first]) && (!check[now.first] || !check[now.second])) {
			check[now.first] = check[now.second] = 1;
			arr[now.first][now.second] = arr[now.second][now.first] = 1;
			//printf("Bronze %d %d\n", now.first, now.second);
			bronze++; cnt++;
		}
	}
	printf("%d %d %d\n", gold, silver, bronze);

}
int main() {
	/*scanf("%d", &testcase);
	while (testcase--) myf();*/
	myf();
	return 0;
}

