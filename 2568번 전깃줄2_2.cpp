#include <stdio.h>
#include <math.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define Max(a,b) a>b?a:b

int myV[555555]; int myY[555555];
pair<int, int> myp[555555];
int arr[555555];
int dp[555555];
int main() {
	int N;

	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d %d", &myp[i].first, &myp[i].second);
	}
	
	sort(myp, myp + N);
	int last_index = 1; int count = 1;
	myV[0] = myp[0].first;
	myY[0] = myp[0].second;
	for (int i = 0;i < N;i++) {
		arr[i] = myp[i].first;
	}

	for (int i = 1;i < N;i++) {
		if (myp[i].second>myY[last_index-1]) {
			myV[last_index] = myp[i].first;
			myY[last_index] = myp[i].second;
			last_index++;
		}
		else {
			int temp_index = lower_bound(myY, myY + last_index, myp[i].second) - myY;
			myV[temp_index] = myp[i].first;
			myY[temp_index] = myp[i].second;
		}
	}
	for (int i = 0;i < last_index;i++) {
		printf("*%d\n", myV[i]);
	}
	printf("%d\n", N-last_index);
	int k = 0;
	
	
	for (int i = 0;i < N;i++) {
		printf("\t**%d\n", arr[i]);
	}

	for (int i = 0;i <N;i++) {
		if (!binary_search(myV, myV + N, myp[i].first)) {
			dp[k] = myp[i].first;
			k++;
		}

	}

	for (int i = 0;i < k;i++) {
		printf("%d\n", dp[i]);
	}

}
