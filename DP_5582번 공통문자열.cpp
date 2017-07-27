#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
char str1[4444],str2[4444];
int dp[4444][4444];

void myf()
{	
	scanf("%d", &N);
	scanf("%s", str1);
	scanf("%s", str2);
	int check=0;
	
	if (str1[0] == str2[0]) dp[0][0] = 1;
	for (int i = 1;i < strlen(str1);i++)
	{
		for (int j = 1;j < strlen(str2);j++)
		{
			if (str2[j] == str1[i])
			{
				check++;
				dp[i][j] = dp[i-1][j-1]+1;
			}
			
		}
	}

	int max = 0;

	for (int i = 0;i < strlen(str1);i++)
	{
		for (int j = 0;j < strlen(str2);j++)
		{
			if (dp[i][j]>max) max = dp[i][j];
		}
	}

	if (check)printf("%d", max);
	else printf("0");
}

int main()
{
	myf();
}
