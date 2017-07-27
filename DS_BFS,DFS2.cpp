#include <stdio.h>
#include <stdlib.h>
#include <queue>

/*
test case
8 10
0 1
0 2
1 3
1 4
2 5
2 6
3 7
4 7
5 7
6 7

*/

using namespace std;

int vertex,edge;
bool *visited;

typedef struct node *np;
typedef struct headNode *HN;
typedef struct headNode {
	int size;
	np* theLists;
};
typedef struct node {
	int V;
	np next;
};
HN adj;

void input(int a, int b) {
	np temp1,temp2;
	temp1 = (struct node*)malloc(sizeof(struct node));
	temp2 = (struct node*)malloc(sizeof(struct node));
	
	temp1->V = b;
	temp1->next = adj->theLists[a]->next;
	adj->theLists[a]->next = temp1;

	temp2->V = a;
	temp2->next = adj->theLists[b]->next;
	adj->theLists[b]->next = temp2;


}
void print(HN head) {
	np temp;
	temp = (struct node*)malloc(sizeof(struct node));
	for (int i = 0;i < vertex;i++) {
		printf("node[%d] : ", i);
		temp = head->theLists[i]->next;
		while (temp) {
			printf("%5d", temp->V);
			temp = temp->next;
		}
		printf("\n");
	}
}

void bfs(int v) {
	queue <int> myQ;
	np temp = (struct node*)malloc(sizeof(node));

	myQ.push(v);
	visited[v] = true;

	while (!myQ.empty()) {
		int now = myQ.front();
		printf("%5d", now);
		myQ.pop();

		for (temp = adj->theLists[now]->next;temp;temp = temp->next) {
			if (!visited[temp->V]) {
				visited[temp->V] = true;
				myQ.push(temp->V);
			}
		}

	}
}

void dfs(int v) {
	np temp = (struct node*)malloc(sizeof(node));
	visited[v] = true;
	printf("%5d", v);
	for (temp = adj->theLists[v]->next;temp;temp = temp->next) {
		if (!visited[temp->V]) {
			visited[temp->V] = true;
			dfs(temp->V);
		}
	}

}
int main()
{
	scanf("%d %d", &vertex, &edge);

	adj = (struct headNode*)malloc(sizeof(struct headNode));
	visited = (bool*)malloc(sizeof(bool)*vertex);
	adj->size = vertex;
	adj->theLists = (np*)malloc(sizeof(np)*vertex);
	for (int i = 0;i < vertex;i++) {
		visited[i] = false;
		adj->theLists[i] = (struct node*)malloc(sizeof(struct node));
		adj->theLists[i]->next = NULL;
	}


	
	
	for (int i = 0;i < edge;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		input(a, b);
	}
	//print(adj);

	dfs(0);
	for (int i = 0;i < vertex;i++) {
		visited[i] = false;
	}
	printf("\n bfs :");
	bfs(0);



}
