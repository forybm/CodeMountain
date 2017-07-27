//2013012085_À¯º´¹Î_A
//connected_component.cpp 

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N, M;
int arr[1111][1111];
int check[1111];
int component[1111];
int cnt;

void bfs(int node) {
	queue <int> myQ;
	myQ.push(node);
	check[node] = 1;
	component[node] = cnt;
	while (!myQ.empty()) {
		int now = myQ.front(); myQ.pop();
		for (int i = 1;i <= N;i++) {
			if (arr[now][i] && !check[i]) {
				check[i] = 1;
				component[i] = cnt;
				myQ.push(i);
			}
		}
	}
}

void myf() {
	scanf("%d\n", &N);
	int a, b;
	while (scanf("%d %d",&a,&b)!= EOF) {
		arr[a][b] = arr[b][a] = 1;
	}
	for (int i = 1;i <= N;i++) {
		if (!check[i]) {
			cnt++;
			bfs(i);
		}
	}
	printf("%d\n", cnt);
	for (int i = 1;i <= N;i++) printf("%d\n", component[i]);
}
int main() {
	myf();
	return 0;
}

