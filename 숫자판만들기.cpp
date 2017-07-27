#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <vector>


#define unlimited 1234567890
using namespace std;
int V, E;
int g[2222][2222];
int parent[2222], visited[2222], cap[2222];
int res;
int N, M, K;
vector<int> v[2222];

int bfs() {
	memset(visited, 0, sizeof(visited));
	memset(cap, 0, sizeof(cap));
	visited[0] = 1;
	cap[0] = 123456789;

	queue <int> myQ;
	myQ.push(0);

	while (!myQ.empty()) {
		int now = myQ.front();
		myQ.pop();

		for (auto &i : v[now]) {
			if (visited[i] == 0 && g[now][i]>0) {
				visited[i] = 1;
				cap[i] = min(cap[now], g[now][i]);
				parent[i] = now;
				myQ.push(i);
			}
		}
	}

	if (visited[2*N + 1] == 0) {
		return 0;
	}

	for (int i = 2*N + 1;i > 0; i = parent[i]) {
		int j = parent[i];
		g[j][i] -= cap[2*N + 1];
		g[i][j] += cap[2*N + 1];
	}

	return cap[2*N + 1];

}

int main() {
	scanf("%d", &N);

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			v[i].push_back(j);
		}
	}

	for (int i = 1; i <= N; i++) {
		int a; scanf("%d", &a);
		g[0][i] = a;
	}

	for (int i = N + 1;i <= 2 * N;i++) {
		int a; scanf("%d", &a);
		g[i][2 * N + 1] = a;
	}

	for (int k = 0;;k++) {
		for (int i = N + 1; i <= 2 * N; i++) g[i][2 * N + 1] = 1, v[i].push_back(2 * N + 1), v[2 * N + 1].push_back(i);
		for (int i = 1;i <= N;i++) {
			for (int j = N + 1;j <= 2 * N;j++) {
				g[i][j] = k; v[i].push_back(j); v[j].push_back(i); g[j][i] = k;
			}
		}
		int flow;

		while (flow = bfs(), flow > 0) {
			res += flow;
		}

	}
	printf("%d\n", res);

	return 0;

}
