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

	int len = strlen(str), len2 = strlen(str2);
	int pos = 0, pos2 = 0;
	while (pos < len && pos2 < len2) {
		if (str[pos] == str2[pos2]) {
			printf("%c", str[pos]);
			pos++; pos2++;
		}
		else pos++;
	}
	return 0;
}


