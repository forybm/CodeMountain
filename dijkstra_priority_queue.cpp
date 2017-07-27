#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>

#define inf 98765432100

using namespace std;
int N, M, start, desti;
long long node[1111];

vector <pair <int, long long> > G[1111];

struct largerthan {
	bool operator()(pair<int, long long> a, pair<int, long long> b) {
		return a.second > b.second;
	}
};
bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}
void dijkstra(int st, int fi) {
	memset(node, inf, sizeof(node));
	node[st] = 0;


	priority_queue<pair<int, long long>,vector<pair<int,long long> >,largerthan>q;

	q.push(make_pair(st, node[st]));
	
	while (!q.empty()) {
		int now = q.top().first;
		if (now == fi) break;
		q.pop();
		for (auto &i : G[now]) {
			int v = i.first;
			long long w = i.second;
			if (node[v]>node[now] + w) {
				node[v] = node[now] + w;
				q.push(make_pair(v, node[v]));
			}

		}
	}	

}

void myf() {
	scanf("%d %d %d %d", &N, &M, &start, &desti);
	for (int i = 1;i <= M;i++) {
		int a, b;
		long long c;
		scanf("%d %d %lld", &a, &b, &c);
		G[a].push_back(make_pair(b, c));
		G[b].push_back(make_pair(a, c));
	}

	dijkstra(start, desti);
	for (int i = 1;i <= N;i++) {
		printf("\t%lld\n", node[i]);
	}

}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) myf();

}
