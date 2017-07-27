#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef pair <char*, char*> mypair;
mypair mp[100000];

int B_search(char arr[],int size,char find[])
{
	int low=0,high=size-1;
	int mid;
	mid=(low+high)/2;
}
	
int main()
{

	int n, m;
	int temp = 0;
	char **answer;

	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;i++)
	{
		mp[i].first = (char*)malloc(sizeof(char) * 20);
		mp[i].second = (char*)malloc(sizeof(char) * 10);

	}
	answer = (char**)malloc(sizeof(char*)*m);
	for (int i = 0;i<m;i++)
	{
		answer[i] = (char*)malloc(sizeof(char) * 5);
	}

	for (int i = 0;i < n;i++)
	{
		scanf("%s", mp[i].first);
		sprintf(mp[i].second, "%d", i + 1);
	}

	for (int i = 0;i < m;i++)
	{
		scanf("%s", answer[i]);
	}
	
	//////////////////////////////
	
	
	
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j<n;j++)
		{
			if (strcmp(answer[i], mp[j].first) == 0)
			{
				printf("%s\n", mp[j].second);
				break;
			}
			else if (strcmp(answer[i], mp[j].second) == 0)
			{
				printf("%s\n", mp[j].first);
				break;
			}
		}
	}
	

}
