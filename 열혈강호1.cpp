#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>

#define unlimited 1234567890
using namespace std;
int V, E;
int adj[2222][2222];
int parent[2222],visited[2222],cap[2222];
int res;
int N, M;


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

		for (int i = 0;i <= N+M+1;i++) {
			if (visited[i] == 0 && adj[now][i]>0) {
				visited[i] = 1;
				cap[i] = min(cap[now], adj[now][i]);
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
		adj[j][i] -= cap[N+M+1];
		adj[i][j] += cap[N+M+1];
	}

	return cap[N+M+1];	
	
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1;i <= N;i++) {
		adj[0][i] = 1;
	}
	for (int j = N+1;j < N+M+1;j++) {
		adj[j][N + M + 1] = 1;
	}
	

	for (int i = 1;i <= N;i++) {
		int temp;
		scanf("%d", &temp);
		for (int j = 0;j < temp;j++) {
			int a;	scanf("%d", &a);
			adj[i][N+a] = 1;
		}
	}

	int flow;
	
	while (flow = bfs(), flow>0) {
		res += flow;
	}


	printf("%d\n", res);

	return 0;
	
}
