//2013012085_À¯º´¹Î_A
//Longest_common_sequence.cpp

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int dp[555][555];
char back[555];
char str[555], str2[555], temp[555];

int main() {
	scanf("%s", str);
	scanf("%s", str2);
	
	if (strcmp(str, str2) > 0) {
		swap(str, str2);
	}
	int cnt = 0;

	for (int i = 1;i <= strlen(str2);i++) {
		for (int j = 1;j <= strlen(str);j++) {
			if (str2[i - 1] == str[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	//printf("%d\n", dp[strlen(str2)][strlen(str)]);
	if (dp[strlen(str2)][strlen(str)] == 0) return 0;
	int c_index = strlen(str);
	int r_index = strlen(str2);
	
	/*while (cnt<dp[strlen(str2)][strlen(str)]) {
		if (str[c_index-1] == str2[r_index-1]) {
			back[cnt++] = str[c_index-1];
			r_index--; c_index--;
		}
		else {
			if (dp[r_index - 1][c_index] >= dp[r_index][c_index - 1]) {
				r_index--;
			}
			else c_index--;
		}
	}
	*/
	int c_pos = 0; int r_pos = 0;
	while (r_pos < r_index && c_pos < c_index) {
		if (str[c_pos] == str2[r_pos]) {
			back[cnt++] = str[c_pos];
	//		printf("# %d %d\n",cnt, dp[strlen(str2)][strlen(str)]);
			if (cnt == dp[strlen(str2)][strlen(str)]) {
	//			printf("@ %d\n", cnt);
				break;
			}
			r_pos++; c_pos++;
		}
		else {
			if (dp[r_pos + 1][c_pos] > dp[r_pos][c_pos + 1]) {
				r_pos++;
			}
			else c_pos++;
		}
	}
	
	//dp[strlen(str2)][strlen(str)]
	//for (int i = cnt - 1; i >= 0;i--) printf("%c", back[i]);
	printf("%s",back);
	return 0;
}


