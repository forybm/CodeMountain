#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;
char str1[1111];
char str2[1111];
int dp[1111][1111];

void myf()
{
	scanf("%s", str1);
	scanf("%s", str2);

	for (int i = 1;i <= strlen(str1);i++)
	{
		for (int j = 1;j <= strlen(str2);j++)
		{
			if (str1[i-1] == str2[j-1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	printf("%d", dp[strlen(str1)][strlen(str2)]);

}

int main()
{
	myf();
	
}
