#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;
int N;
vector <int> v[11111];
vector <int> reverse_v[11111];
int p_time[11111];
int t_time[11111];
int main() {
	scanf("%d", &N);
	for (int i = 1;i < N;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		reverse_v[b].push_back(a);
	}
	int police, thief;
	scanf("%d %d", &police, &thief);

	queue <pair<int,int> > q;
	q.push(make_pair(police,0));
	int cnt = 1;
	while (!q.empty()) {
		pair<int,int> now = q.front();
		q.pop();
		for (auto &i : v[now.first]) {
			p_time[i] = now.second + 1;
			q.push(make_pair(i,p_time[i]));
		}
	}
	q.push(make_pair(thief, 0));
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		for (auto &i : reverse_v[now.first]) {
			t_time[i] = now.second + 1;
			q.push(make_pair(i, t_time[i]));
		}
	}
	for (int i = 1;i <= N;i++) {
		printf("%d : %d   %d\n", i, p_time[i], t_time[i]);
	}
	int maxx = 0;
	for (int i = 1;i <= N;i++) {
		if (p_time[i] > t_time[i] && maxx < p_time[i]) maxx = p_time[i];
	}
	if(police!=thief)printf("%d\n", maxx);
	else printf("0");
	return 0;
}
