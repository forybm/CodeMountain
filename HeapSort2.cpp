//2013012085_유병민_A
//Priority Queue

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
int arr[111111];
int now = 1, start_index = 1;
int now_size, tmp;
void extract(int index);

//#define swap(a,b) tmp=a; a=b; b=tmp;
//#define max(a,b) a>b ? a:b

//추출
void extract(int index)
{
	int now_index = index;
	int left = index * 2;
	int right = index * 2 + 1;

	if (index > now_size / 2) return;
	//아래로 내리기
	if (right <= now_size) {
		if (arr[now_index] < max(arr[left], arr[right])) {
			if (arr[left] > arr[right]) {
				swap(arr[now_index], arr[left]);
				//printf("@@ %d \n", left);
				extract(left);
			}
			else {
				swap(arr[now_index], arr[right]);
				//printf("@@ %d \n", right);
				extract(right);
			}
		}
	}
	else {
		if (arr[now_index] < arr[left]) {
			swap(arr[now_index], arr[left]);
			//printf("@@ %d \n", left);
			extract(left);
		}
	}
}

void increaseKey(int index) {
	int now_index = index;

	//위로 올리기
	while (now_index > 1 && now_index <= now_size) {
		if (arr[now_index] > arr[now_index / 2]) {
			swap(arr[now_index], arr[now_index / 2]);
				now_index /= 2;
		}
		else break;
	}
	//아래로 내리기
	now_index = index;
	while (now_index <= now_size / 2) {
		int child = now_index * 2;
		if (child > now_size) break;
		if (child + 1 <= now_size) {
			if (arr[now_index] < max(arr[child], arr[child + 1])) {
				if (arr[child] > arr[child + 1]) {
					swap(arr[now_index], arr[child]);
					now_index = child;
				}
				else {
					swap(arr[now_index], arr[child + 1]);
					now_index = child + 1;

				}
			}
			else break;
		}
		else {
			if (arr[now_index] < arr[child]) {
				swap(arr[now_index], arr[child]);
				now_index = child;
			}
			else break;
		}
	}
}



int main() {
	int command; scanf("%d", &command);
	int cnt = 0;
	while (true) {
		switch (command) {
		case 1:
			int temp; scanf("%d", &temp);
			arr[now++] = temp;
			swap(arr[now - 1], arr[now_size + 1]);
			now_size++;
			increaseKey(now_size);
			
//			printf("case 1 : now_size = %d  now = %d increaseKey(%d)", now_size, now, now - 1);
			break;
		case 2:
			if (now_size > 0) {
				printf("%d ", arr[1]);
				swap(arr[1], arr[now_size]);
				//printf(" now_size = %d\n", now_size);
				now_size--; cnt++;
				extract(1);
			}
			break;
		case 3:
			int a, b; scanf("%d %d", &a, &b);
			arr[a] = b;
			increaseKey(a);
			break;
		case 0:		
			for (int i = 1;i <= now_size;i++) {
				printf("%d ", arr[i]);
			}
			break;
		}
		if (command == 0) break;
		scanf("%d", &command);
	}
	return 0;
}
