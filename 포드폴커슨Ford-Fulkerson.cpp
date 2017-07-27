#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>

#define unlimited 1234567890
using namespace std;
int V, E;
int adj[111][111];
int parent[111],visited[111],cap[111];
int res;

int bfs() {
	memset(visited, 0, sizeof(visited));
	memset(cap, 0, sizeof(cap));
	visited[1] = 1;
	cap[1] = 123456789;
	
	queue <int> myQ;
	myQ.push(1);

	while (!myQ.empty()) {
		int now = myQ.front();
		myQ.pop();

		for (int i = 1;i <= V;i++) {
			if (visited[i] == 0 && adj[now][i]>0 && min(cap[now], adj[now][i]) > cap[i]) {
				visited[i] = 1;
				cap[i] = min(cap[now], adj[now][i]);
				parent[i] = now;
				myQ.push(i);
			}
		}
	}

	if (visited[V] == 0) {
		return 0;
	}

	for (int i = V;i > 1; i = parent[i]) {
		int j = parent[i];
		adj[j][i] -= cap[V];
		adj[i][j] += cap[V];
	}

	return cap[V];
	
}

int main() {
	scanf("%d %d", &V, &E);
	for (int i = 0;i < E;i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a][b] = c;
	}
	int flow;
	
	while (flow = bfs(), flow>0) {
		res += flow;
	}

	printf("%d\n", res);

	return 0;
	
	
}
