#include <stdio.h>
#include <stdlib.h>

#define Unlimit 9999999

int N, M; //N : Node 의 개수 M : 길의 개수

/*
int **adj; //인접행렬을 위한 이중포인터
int *node; //node마다 가중치
bool **check;
*/
int adj[111][111];
int node[111];
bool check[111][111];
int temp[111];
int count;

int minPath(int start, int finish) {
	
}


void find(int now)
{
	for (int i = 0;i < N;i++) {
		check[i][0] = true;
	}
	count = 0;
	
	for (int i = 0;i < N;i++) {
		if (adj[now][i] != 0 && !check[now][i]) {
			
			check[now][i] = true;
			if (node[i] == 0) node[i] = node[now] + adj[now][i]; //adj[now][i]가 최소거리가
			else if (node[i] != 0 && node[i]>node[now] + adj[now][i]) {
				node[i] = node[now] + adj[now][i];
			}
			
			printf("%d -> %d node[%d]\t%d\n",now,i,i,node[i]);
			temp[count] = i;
			count++;
		}
	}
	int k = count;
	for (int i = 0;i < k;i++) {
		find(temp[i]);
	}
}

int main()
{
	
	printf("Enter the number of Node, and road :");
	scanf("%d %d", &N, &M);
/*
	adj = (int**)malloc(sizeof(int*)*N);	//2차원배열 동적할당
	node = (int*)malloc(sizeof(int)*N);
	check = (bool**)malloc(sizeof(bool*)*N);

	for (int i = 0;i < N;i++) {
		adj[i] = (int*)malloc(sizeof(int)*N);
		check[i] = (bool*)malloc(sizeof(bool)*N);
	}

	for (int i = 0;i < N;i++) {
		node[i] = 0;
		for (int j = 0;j < N;j++) {
			adj[i][j] = 0;
		}
	} //adj배열 초기화
*/
	for (int i = 0;i < M;i++) {
		int x, y, z;		//연결된 노드x,y와 그 가중치z
		
		scanf("%d %d %d", &x, &y, &z);
		adj[x][y] = z;
	}
	int start,finish;
	printf("Start Node (0 ~ %d) ? : ",N);
	scanf("%d", &start);
	find(0);
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			printf("%d\t", adj[i][j]);
		}
		printf("\n");
	}

	for (int i = 0;i < N;i++) {
		printf("node[%d] : %d\n", i,node[i]);
	}
	
	
	
	
}




/*
예제
5 10
0 1 10
0 3 5
3 2 9
3 4 2
3 1 3
1 3 2
1 2 1
2 4 4
4 2 6
4 0 7
0

*/
