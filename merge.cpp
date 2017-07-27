// 2013012085_À¯º´¹Î_A
// Merge Sort
#include <stdio.h>
#include <stdlib.h>

int *a;
int *temp;
int N;

void Merge(int Lpos, int Rpos, int RightEnd);

void Msort(int left, int right) {
	int center;
	if (left < right) {
		center = (left + right) / 2;
		Msort(left, center);
		Msort(center + 1, right);
		Merge(left, center + 1, right);
	}
}

void Merge(int Lpos, int Rpos, int RightEnd) {
	int LeftEnd, tmpPos;
	tmpPos = Lpos;
	LeftEnd = Rpos - 1;

	int numElements = RightEnd - Lpos + 1;

	while (Lpos <= LeftEnd && Rpos <= RightEnd) {
		if (a[Lpos] >= a[Rpos]) {
			temp[tmpPos++] = a[Lpos++];
		}
		else {
			temp[tmpPos++] = a[Rpos++];
		}
	}
	while (Lpos <= LeftEnd) {
		temp[tmpPos++] = a[Lpos++];
	}
	while (Rpos <= RightEnd) {
		temp[tmpPos++] = a[Rpos++];
	}
	for (int i = 0;i <numElements;i++, RightEnd--) {
		a[RightEnd] = temp[RightEnd];
	}

}


int main() {
	scanf("%d", &N);
	a = (int*)malloc(sizeof(int)*N);
	temp = (int*)malloc(sizeof(int)*N);

	for (int i = 0;i < N;i++) {
		int x;
		scanf("%d", &x);
		a[i] = x;
	}

	Msort(0, N - 1);

	for (int i = 0;i < N;i++) {
		printf("%d\n", a[i]);
	}

	return 0;

}
