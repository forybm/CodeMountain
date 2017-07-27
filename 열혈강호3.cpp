#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <vector>


#define unlimited 1234567890
using namespace std;
int V, E;
int g[2222][2222];
int parent[2222],visited[2222],cap[2222];
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

	if (visited[N+M+1] == 0) {
		return 0;
	}

	for (int i = N+M+1;i > 0; i = parent[i]) {
		int j = parent[i];
		g[j][i] -= cap[N+M+1];
		g[i][j] += cap[N+M+1];
	}

	return cap[N+M+1];
	
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		int Z; scanf("%d", &Z);
		for (int k = 0; k < Z; k++) {
			int j; scanf("%d", &j);
			v[i].push_back(N + j);
			v[N + j].push_back(i);
			g[i][N + j] = 1;		
		}
	}
	g[0][N + M + 2] = K;
	v[0].push_back(N + M + 2);
	for (int i = 1; i <= N; i++) g[0][i] = 1, v[0].push_back(i), v[i].push_back(0) ,g[N+M+2][i]=1, v[N+M+2].push_back(i);
	for (int i = 1; i <= M; i++) g[N + i][N + M + 1] = 1, v[N + i].push_back(N + M + 1), v[N + M + 1].push_back(N + i);
	int flow;
	
	while (flow = bfs(), flow>0) {
		res += flow;
	}


	printf("%d\n", res);

	return 0;
	
}
