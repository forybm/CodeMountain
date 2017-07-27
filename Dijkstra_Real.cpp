#include <stdio.h>
#include <stdlib.h>

#define Unlimit 9999999  //���Ѵ븦 ǥ���ϱ� ���� ����

int N, M; //N : Node �� ���� M : ���� ����


int **adj;	//�� Vertex�� edge�� ������ķ� ��Ÿ���� ���� ����������
int *node;	//��������������� �ּҰŸ��� �������ִ� �迭
bool *check; //���� Vertex�� �湮�ߴ� ������ üũ���ִ� �迭
int *back;	//������ �ִܰ�θ� ��Ÿ���ֱ� ���� �迭

//�� �������� �ִܰ�θ� �̾��ִ� �Լ�
int minPath() {
	int min = Unlimit;
	int arrayIndex;
	for (int i = 0;i < N;i++) {
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
void find(int start)
{

	for (int i = 0;i < N;i++) {
		node[i] = Unlimit;
	}
	node[start] = 0; //������������ �Ÿ��� 0!!
	
	for (int i = 0;i < N;i++) {
		//õõ�� ���� ã�� ���ô�
		int now = minPath(); //ó�� ���� �ִ� ������ ã��
		check[now] = true; //�� ������ �湮!! �׸��� üũ

		
		for (int i = 0;i < N;i++) {
		//�湮���� �ʾҴ� ���̸鼭 ���� �ְ� ���ο� ��ΰ� �� �ִܰ���� ��
			if (!check[i] && adj[now][i] && node[now] != Unlimit
				&& node[i]> node[now] + adj[now][i]) {
				node[i] = node[now] + adj[now][i];
				back[i] = now; //�ִܰŸ��� �����ϱ� ���� ���簪�� ����
			}
		}
	}
}


int main()
{
	//Vertex�� ������ Edge�� ������ �Է¹޴´�
	printf("Vertex�� ������ �Է��ϼ��� : ");
	scanf("%d", &N); 
	printf("Edge�� ������ �Է��ϼ��� :");
	scanf("%d", &M); 
	//�Է¹��� Vertex�� ������ŭ �����Ҵ�!!
	node = (int*)malloc(sizeof(int)*N);		
	back = (int*)malloc(sizeof(int)*N);
	check = (bool*)malloc(sizeof(bool)*N);

	adj = (int**)malloc(sizeof(int*)*N);
	for (int i = 0;i < N;i++) {
		adj[i] = (int*)malloc(sizeof(int)*N);
	}
	//�� �迭�� �ʱ�ȭ
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			adj[i][j] = 0;
		}
		check[i] = false;
		node[i] = Unlimit;
		back[i] = 0;
	}

	for (int i = 0;i < M;i++) {
		int x, y, z;		//����� ���x,y�� �� ����ġz

		scanf("%d %d %d", &x, &y, &z);
		if(x!=y) //�ڱ� �ڽ����� ���� ���� ���� �ϱ� ���� ���ǹ� ���!
			adj[x][y] = z;
	}

	int start;
	//������ �� �������� ����!!
	printf("Start Node (0 ~ %d) ? : ", N-1);
	scanf("%d", &start);

	//�� Vertex�� ��������� ���
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			printf("%d\t", adj[i][j]);
		}
		printf("\n");
	}

	//Dijkstra �˰����� ������!!
	find(start);

	//�ִܰ�ο� �ִܽð��� ���!!
	for (int i = 0;i < N;i++) {
		if(node[i]!=Unlimit)	
			printf("%d >> %d �ִܽð� %d\n",start, i, node[i]);
		else		//���� ��ΰ� ���ٸ�! 
			printf("%d >> %d ���� ���� ��ΰ� ����!!\n",start, i);
	}
	printf("\n\n");

	//�ִܰ�θ� ������ �ϴ� �ݺ���!!
	for (int i = 0;i < N;i++) {
		//��ΰ� �ִٸ� 
		if (node[i] != Unlimit) {
			printf("%d >> %d �ִ� ��� %d ",start,i, i);
			int now = i;
			//now �� �������� �ɶ����� ��� back back ���ش�
			while (now != start) {
				now = back[now]; 
				printf(" <- %d ", now);

			}
			printf("\n");
		}
		//��ΰ� ���ٸ�
		else
			printf("%d >> %d ���� ���� ��ΰ� ����!\n",start, i);
	}
	

	//
	char command1,command2;
	printf("\n\n���Ḧ �Ϸ��� �ƹ� Ű�� �Է�!!\n");
	scanf("%c%c",&command1,&command2);

	return 0;
}

