#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int W[20][20];
int dp[20][1000001];

// �湮�� ��带 �����ϰ� ���� node���� �������� ��ȸ�ϴ� ���
int tsp(int node, int visited) {
	if (visited == ((1 << N) - 1)) { // ���� �湮�� ���
		if (W[node][1] != 0)
			return W[node][1];
	}

	int ret = dp[node][visited];
	if (ret != 0) return ret;
	ret = 20000000;

	for (int i = 1;i <= N;i++) {
		if (!(visited & (1 << (i - 1))) && W[node][i] != 0) { // i �� ��尡 �湮���� �ʾҴٸ�
			ret = min(ret, W[node][i] + tsp(i, visited | (1 << (i - 1))));
			// i �� ��� �湮üũ�ϰ� i�� ���������� ���
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
