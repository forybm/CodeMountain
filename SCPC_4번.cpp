#include <stdio.h>
#include <math.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
#define Unlimit 1234567890

int adj[10000][10000];
int node[111111];
int check[111111];
int N, M, K;
int tmp[111111];
int back[111111];

int minPath() {
	int min = Unlimit;
	int arrayIndex;
	for (int i = 1;i <= N;i++) {
		//경로중에 가장 최소경로를 찾고 그 주소를 저장
		if (!check[i] && node[i] <= min) {
			min = node[i];
			arrayIndex = i;
		}
	}
	//최단 경로가 있는 Vertex의 값을 리턴
	return arrayIndex;
}
//Dijkstra 알고리즘 구현
void find()
{

	for (int i = 1;i <= N;i++) {
		node[i] = Unlimit;
	}
	for (int i = 0;i < K;i++) {
		node[tmp[i]] = 0;
	}

	for (int i = 1;i <= N;i++) {
		//천천히 길을 찾아 봅시다
		int now = minPath(); //처음 길이 있는 정점을 찾고
		check[now] = true; //그 정점을 방문!! 그리고 체크

		for (int i = 1;i <= N;i++) {
			//방문하지 않았던 곳이면서 길이 있고 새로운 경로가 더 최단경로일 때
			if (!check[i] && adj[now][i] && node[now] != Unlimit
				&& node[i]> node[now] + adj[now][i]) {
				node[i] = node[now] + adj[now][i];
				back[i] = now; //최단거리를 추적하기 위해 현재값을 저장
			}
		}
	}
}


void myf(int num) {
	
	
	scanf("%d %d %d", &N, &M, &K);
	
	for (int i = 0;i <= N;i++) {
		check[i] = false;
		node[i] = 0;
		tmp[i] = 0;
		back[i] = 0;

		for (int j = 0;j <= N;j++) {
			adj[i][j] = 0;
		}
	}
	
	
	
	for (int i = 0;i < M;i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a][b] = adj[b][a] = c;
	}
	for (int i = 0;i < K;i++) {
		int temp;
		scanf("%d", &temp);
		tmp[i] = temp;
	}
	find();
	int sum = 0;
	for (int i = 1;i <= N;i++) {
		sum += node[i];
	}
	int sum2 = 0;
	for (int i = 1;i <= N;i++) {
		//경로가 있다면 
		if (node[i] != Unlimit) {
			int now = i;
			//now 가 시작점이 될때까지 계속 back back 해준다
			while (node[now] != 0) {
				now = back[now];
			}
			sum2 += now;
		}
	}
	//있다가 초기화 꼭해주기
	printf("Case #%d\n", num + 1);
	printf("%d\n%d\n", sum,sum2);
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
