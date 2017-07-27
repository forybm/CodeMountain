#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <iostream>
#define Unlimit 9999999

using namespace std;
int N, M, T; 

int node[1111];
int back[1111];
int w[1111];

vector<vector<pair<int, int> > > G;
class Comparator
{
public:
	int operator() (const pair<int, int>& p1, const pair<int, int> &p2)
	{
		return p1.second>p2.second;
	}
};



void dijkstra(int source,int destination)
{
	for (int i = 1;i <= N; i++)
	{
		node[i] = Unlimit;
		
	}
	priority_queue<pair<int, int>, vector<pair<int, int> >, Comparator> Q;
	node[source] = 0;
	Q.push(make_pair(source, node[source]));
	while (!Q.empty())
	{
		int u = Q.top().first;
		if (u == destination) break;
		Q.pop();
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i].first;
			int w = G[u][i].second;
			if (node[v] > node[u] + w)
			{
				node[v] = node[u] + w;
				Q.push(make_pair(v, node[v]));
			}
		}
	}
}


int main()
{
	scanf("%d %d %d", &N, &M, &T);
	G.resize(N + 1);
	for (int i = 0;i < M;i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		G[x].push_back(make_pair(y, z));
	}

	
	
	for (int i = 1;i <= N;i++) {
		if (i != T) {
			dijkstra(T, i);
			w[i] = node[i];
		}
	}

	for (int i = 1;i <= N;i++) {
		if (i != T) {
			dijkstra(i, T);
			w[i] += node[T];
		}
	}
	int max = 0;
	int cnt = 0;
	for (int i = 1;i <= N;i++) {
		if (i != T) {
			if (max < w[i]) {
				max = w[i];
				cnt = 0;
			}
			else if (max == w[i]) {
				cnt++;
			}
		}
	}

	if (cnt > 0) printf("X\n%d", *max_element(w + 1, w + 1 + N));
	else printf("%d\n%d", max_element(w + 1, w + 1 + N) - w, *max_element(w + 1, w + 1 + N));


	return 0;
}

