//2013012085_À¯º´¹Î_A
//HeapSort


#include <stdio.h>
#include <stdlib.h>


int N, K;
int *arr;
int size;
int tmp;
void maxHeapify(int index);

#define swap(a,b) tmp=a; a=b; b=tmp;
#define max(a,b) a>b ? a:b

void buildHeap() {
	
	for (int i = size / 2;i > 0;i--) {
		maxHeapify(i);
	}
}

void maxHeapify(int index)
{
	int now_index = index;    // Initialize the now_index as root
	int left = index * 2;   // left = 2*index + 1
	int right = index * 2 + 1;    // right = 2*index + 2

									 // See if left child of root exists and is greater than root
	if (left < size && arr[left] > arr[now_index])
		now_index = left;

	// See if right child of root exists and is greater than the now_index so far
	if (right < size && arr[right] > arr[now_index])
		now_index = right;

	// Change root, if needed
	if (now_index != index)
	{
		swap(arr[now_index], arr[index]);
		maxHeapify(now_index);
	}
}


int main() {
	scanf("%d %d", &N, &K);
	arr = (int*)malloc(sizeof(int)*N);
	for (int i = 1;i <= N;i++) {
		scanf("%d", arr + i);
	}
	size = N;
	buildHeap();

	for (int i = 0;i < K;i++) {
		swap(arr[1], arr[size]);
		size--;
		buildHeap();
	}

	for (int i = 0;i < K;i++) printf("%d ", arr[N - i]);
	printf("\n");
	for (int i = 1;i <= size;i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}
