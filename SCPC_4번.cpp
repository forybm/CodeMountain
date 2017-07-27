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
		//����߿� ���� �ּҰ�θ� ã�� �� �ּҸ� ����
		if (!check[i] && node[i] <= min) {
			min = node[i];
			arrayIndex = i;
		}
	}
	//�ִ� ��ΰ� �ִ� Vertex�� ���� ����
	return arrayIndex;
}
//Dijkstra �˰��� ����
void find()
{

	for (int i = 1;i <= N;i++) {
		node[i] = Unlimit;
	}
	for (int i = 0;i < K;i++) {
		node[tmp[i]] = 0;
	}

	for (int i = 1;i <= N;i++) {
		//õõ�� ���� ã�� ���ô�
		int now = minPath(); //ó�� ���� �ִ� ������ ã��
		check[now] = true; //�� ������ �湮!! �׸��� üũ

		for (int i = 1;i <= N;i++) {
			//�湮���� �ʾҴ� ���̸鼭 ���� �ְ� ���ο� ��ΰ� �� �ִܰ���� ��
			if (!check[i] && adj[now][i] && node[now] != Unlimit
				&& node[i]> node[now] + adj[now][i]) {
				node[i] = node[now] + adj[now][i];
				back[i] = now; //�ִܰŸ��� �����ϱ� ���� ���簪�� ����
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
		//��ΰ� �ִٸ� 
		if (node[i] != Unlimit) {
			int now = i;
			//now �� �������� �ɶ����� ��� back back ���ش�
			while (node[now] != 0) {
				now = back[now];
			}
			sum2 += now;
		}
	}
	//�ִٰ� �ʱ�ȭ �����ֱ�
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
