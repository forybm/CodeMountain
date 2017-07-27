#include <stdio.h>
#include <stdlib.h>

#define Unlimit 9999999  //무한대를 표시하기 위한 정의

int N, M; //N : Node 의 개수 M : 길의 개수


int **adj;	//각 Vertex과 edge를 인접행렬로 나타내기 위한 이중포인터
int *node;	//출발점에서부터의 최소거리를 저장해주는 배열
bool *check; //다음 Vertex가 방문했던 곳인지 체크해주는 배열
int *back;	//각각의 최단경로를 나타내주기 위한 배열

//한 정점에서 최단경로를 뽑아주는 함수
int minPath() {
	int min = Unlimit;
	int arrayIndex;
	for (int i = 0;i < N;i++) {
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
void find(int start)
{

	for (int i = 0;i < N;i++) {
		node[i] = Unlimit;
	}
	node[start] = 0; //시작점까지의 거리는 0!!
	
	for (int i = 0;i < N;i++) {
		//천천히 길을 찾아 봅시다
		int now = minPath(); //처음 길이 있는 정점을 찾고
		check[now] = true; //그 정점을 방문!! 그리고 체크

		
		for (int i = 0;i < N;i++) {
		//방문하지 않았던 곳이면서 길이 있고 새로운 경로가 더 최단경로일 때
			if (!check[i] && adj[now][i] && node[now] != Unlimit
				&& node[i]> node[now] + adj[now][i]) {
				node[i] = node[now] + adj[now][i];
				back[i] = now; //최단거리를 추적하기 위해 현재값을 저장
			}
		}
	}
}


int main()
{
	//Vertex의 갯수와 Edge의 갯수를 입력받는다
	printf("Vertex의 갯수를 입력하세요 : ");
	scanf("%d", &N); 
	printf("Edge의 갯수를 입력하세요 :");
	scanf("%d", &M); 
	//입력받은 Vertex의 갯수만큼 동적할당!!
	node = (int*)malloc(sizeof(int)*N);		
	back = (int*)malloc(sizeof(int)*N);
	check = (bool*)malloc(sizeof(bool)*N);

	adj = (int**)malloc(sizeof(int*)*N);
	for (int i = 0;i < N;i++) {
		adj[i] = (int*)malloc(sizeof(int)*N);
	}
	//각 배열의 초기화
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			adj[i][j] = 0;
		}
		check[i] = false;
		node[i] = Unlimit;
		back[i] = 0;
	}

	for (int i = 0;i < M;i++) {
		int x, y, z;		//연결된 노드x,y와 그 가중치z

		scanf("%d %d %d", &x, &y, &z);
		if(x!=y) //자기 자신으로 가는 길은 없게 하기 위해 조건문 사용!
			adj[x][y] = z;
	}

	int start;
	//기준이 될 시작점을 선택!!
	printf("Start Node (0 ~ %d) ? : ", N-1);
	scanf("%d", &start);

	//각 Vertex의 인접행렬을 출력
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			printf("%d\t", adj[i][j]);
		}
		printf("\n");
	}

	//Dijkstra 알고리즘을 돌린다!!
	find(start);

	//최단경로와 최단시간을 출력!!
	for (int i = 0;i < N;i++) {
		if(node[i]!=Unlimit)	
			printf("%d >> %d 최단시간 %d\n",start, i, node[i]);
		else		//만약 경로가 없다면! 
			printf("%d >> %d 까지 가는 경로가 없음!!\n",start, i);
	}
	printf("\n\n");

	//최단경로를 역추적 하는 반복문!!
	for (int i = 0;i < N;i++) {
		//경로가 있다면 
		if (node[i] != Unlimit) {
			printf("%d >> %d 최단 경로 %d ",start,i, i);
			int now = i;
			//now 가 시작점이 될때까지 계속 back back 해준다
			while (now != start) {
				now = back[now]; 
				printf(" <- %d ", now);

			}
			printf("\n");
		}
		//경로가 없다면
		else
			printf("%d >> %d 까지 가는 경로가 없음!\n",start, i);
	}
	

	//
	char command1,command2;
	printf("\n\n종료를 하려면 아무 키나 입력!!\n");
	scanf("%c%c",&command1,&command2);

	return 0;
}

