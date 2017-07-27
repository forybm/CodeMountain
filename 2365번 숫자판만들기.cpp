#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

#define lnf 987654321

vector<int> v[2555];
int N;
int col[55], row[55];
int g[111][111];
int check[2555], back[2555];
int cap[2555];
int flow, res;
int bfs() {
	memset(check, 0, sizeof(check));
	memset(cap, 0, sizeof(cap));

	queue <int> myQ;
	myQ.push(0);
	check[0] = 1;
	cap[0] = lnf;

	while (!myQ.empty()) {
		int now = myQ.front();
		myQ.pop();

		for (auto &i : v[now]) {
			if (!check[i] && g[now][i] > 0) {
				check[i] = 1;
				cap[i] = min(cap[now], g[now][i]);
				back[i] = now;
				myQ.push(i);
			}
		}
	}

	if (check[2 * N + 1] == 0) return 0;
	
	for (int i = 2 * N + 1;i > 0;i = back[i]) {
		int j = back[i];
		g[j][i] -= cap[2 * N + 1];
		g[i][j] += cap[2 * N + 1];
	}

	return cap[2 * N + 1];
}

int main() {
	scanf("%d", &N);
	for (int i = 1;i <= N;i++) {
		scanf("%d", &col[i]);
	}
	for (int i = 1;i <= N;i++) {
		scanf("%d", &row[i]);
	}


	for (int k = 1;k <= max(*max_element(col, col + N + 1), *max_element(row, row + N + 1));k++) {
		
		memset(g, 0, sizeof(g));
		memset(cap, 0, sizeof(cap));
		memset(check, 0, sizeof(check));
		memset(back, 0, sizeof(back));
		
		for (int i = 0;i <= 2 * N + 1;i++) v[i].clear();

		
		for (int i = 1;i <= N;i++) {
			v[0].push_back(i);
			v[i].push_back(i);
			g[0][i] = col[i];
		}

		for (int i = N + 1;i <= 2*N;i++) {
			v[i].push_back(2 * N + 1);
			v[2 * N + 1].push_back(i);
			g[i][2 * N + 1] = row[i - N];
		}

		for (int i = 1;i <= N;i++) {
			for (int j = N;j <= 2 * N;j++) {
				v[i].push_back(j); v[j].push_back(i);
			}
		}

		res = 0;
		for (int i = 1;i <= N;i++) {
			for (int j = N + 1;j <= 2 * N;j++) {
				g[i][j] = k;
			}
		}
		while (flow = bfs(), flow > 0) {
			res += flow;
		}
		
		int sum1 = 0;
		for (int i = 1;i <= N;i++) {
			sum1 += col[i];
		}
		if (res == sum1) {
			printf("%d\n", k);
			for (int i = 1;i <= N;i++) {
				for (int j = N+1;j <= 2*N;j++) {
					printf("%d ", g[j][i]);
				}
				printf("\n");
			}
			break;
		}
	}



}
