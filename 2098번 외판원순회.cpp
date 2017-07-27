#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int W[20][20];
int dp[20][1000001];

// 방문한 노드를 제외하고 현재 node에서 나머지를 순회하는 비용
int tsp(int node, int visited) {
	if (visited == ((1 << N) - 1)) { // 전부 방문한 경우
		if (W[node][1] != 0)
			return W[node][1];
	}

	int ret = dp[node][visited];
	if (ret != 0) return ret;
	ret = 20000000;

	for (int i = 1;i <= N;i++) {
		if (!(visited & (1 << (i - 1))) && W[node][i] != 0) { // i 번 노드가 방문하지 않았다면
			ret = min(ret, W[node][i] + tsp(i, visited | (1 << (i - 1))));
			// i 번 노드 방문체크하고 i를 시작점으로 재귀
		}
	}
	

	return ret;
}

int main() {
	scanf("%d", &N);

	for (int i = 1;i <= N;i++)
		for (int j = 1;j <= N;j++)
			scanf("%d", &W[i][j]);

	printf("%d", tsp(1, 1));
	return 0;
}
