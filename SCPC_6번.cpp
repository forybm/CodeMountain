#include <stdio.h>
#include <math.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
pair<pair<int, int>, int > sh[211];
int arr[111][111];


void myf(int num) {
	int N, K;
	scanf("%d %d", &N, &K);

	//�ʱ�ȭ
	for (int i = 0;i < N;i++) {
		sh[i] = make_pair(make_pair(0, 0), 0);
	}
	for (int i = 0;i < K;i++) {
		for (int j = 0;j < 101;j++) {
			arr[i][j] = 0;
		}
	}
	//sh�Է�
	for (int i = 0;i < N;i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		sh[i] = make_pair(make_pair(a, b), c);
	}

	//arr�Է�
	for (int i = 0;i < K;i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		for (int k = x;k < y;k++) {
			arr[i][k] = 1;
		}
	}
	int check = 0;
	for (int i = 0;i < N;i++) {
		//��� ����ŭ
		for (int k = sh[i].first.first;k < sh[i].first.second;k++) {
			for (int j = 0;j < K;j++) {
				if (arr[j][k]) {
					arr[j][k] = 0; //j��° ����� �������
					sh[i].second--; //�ɸ��� �ð� 1����
					if (sh[i].second == 0)break;
				}
			}	
			if (sh[i].second == 0)break;

		}
		if (sh[i].second > 0) break;
		check++;
	}
	
	printf("Case #%d\n", num + 1);
	if (check == N) printf("1\n");
	else printf("0\n");
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
