#include <stdio.h>
#include <math.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
#define Unlimit 1234567890
int node[111111];
int N, M, K;
int tmp[111111];
int back[111111];


vector<pair<int, int> > map[111111];
vector<int> dist;
void dijkstra()
{
	priority_queue<pair<int,int> > q;
	for (int i = 0;i < K;i++) {
		node[tmp[i]] = 0;
	}

	
	for (int i = 1;i <= N;i++)
		node[i] = Unlimit;
	for (int i = 0;i < K;i++) {
		node[tmp[i]] = 0;
		q.push(make_pair(tmp[i], node[tmp[i]]));
	}

	while (!q.empty())
	{
		int u = q.top().first;
		q.pop();
		int size = map[u].size();
		for (int i = 0;i<size;i++)
		{
			int v = map[u][i].first;
			int w = map[u][i].second;
			if (node[v]>node[u] + w)
			{
				node[v] = node[u] + w;
				q.push(make_pair(v, node[v]));
				back[v] = u;
			}
		}
	}
}

void myf(int num) {


	for (int i = 0;i <= N;i++) {
		node[i] = 0;
		tmp[i] = 0;
		back[i] = 0;
		map[i].clear();
	}
	
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0;i < M;i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b, c));
		map[b].push_back(make_pair(a, c));
	}
	for (int i = 0;i < K;i++) {
		int temp;
		scanf("%d", &temp);
		tmp[i] = temp;
	}
	dijkstra();

	long long int sum = 0;
	for (int i = 1;i <= N;i++) {
		sum += node[i];
	}
	long long int sum2 = 0;
	for (int i = 1;i <= N;i++) {
		//경로가 있다면 
			int now = i;
			//now 가 시작점이 될때까지 계속 back back 해준다
			while (node[now] != 0) {
				now = back[now];
			}
			sum2 += now;
		
	}
	//있다가 초기화 꼭해주기
	printf("Case #%d\n", num + 1);
	printf("%lld\n%lld\n", sum, sum2);
}

int main() {
	setbuf(stdout, NULL);
	int T;
	scanf("%d", &T);

	for (int i = 0;i < T;i++) {
		myf(i);
	}
	return 0;

}
