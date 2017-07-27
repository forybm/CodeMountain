#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int dp[222][222];


void myf(int xxx) {
	vector <int> myV;

	for (int i = 0;i < xxx;i++) {
		int temp = 0;
		scanf("%d", &temp);
		myV.push_back(temp);
	}

	for (int i = 1;i < xxx - 1;i++) {
		dp[1][i] = myV[i - 1] + myV[i] + myV[i + 1];
	}


	for (int i = 2;i < xxx - 1;i++) {
		int max_ele = *max_element(dp[i-1], dp[i-1] + xxx);
		int max_index = max_element(dp[i-1], dp[i-1] + xxx) - dp[i-1];
		if(max_ele !=0) myV.erase(myV.begin() + max_index);
		for (int k = 0;k < myV.size();k++) {
			printf("\t%d", myV[k]);
		}
		printf("\n\t\t%d\n", max_ele);

		for (int j = 1;j < xxx - i;j++) {			
			dp[i][j] = max_ele + myV[j - 1] + myV[j] + myV[j + 1];
		}
	}

	for (int i = 0;i < xxx;i++) {
		for (int j = 0;j < xxx;j++) {
			printf("\t%d", dp[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", *max_element(dp[xxx - 2], dp[xxx - 2] + xxx));

	for (int i = 0;i < xxx;i++) {
		for (int j = 0;j < xxx;j++) {
			dp[i][j] = 0;
		}
	}

	

}

int main() {

	bool command = true;;
	while (command) {
		int temp=3;
		scanf("%d", &temp);
		if (temp == 0) break;
		else myf(temp);

	}



}
