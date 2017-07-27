#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int arr[1111111];
int b[1111111],c[1111111];

int main()
{
	int count = 0,check=0;
	long long int num = 0;
	scanf("%d", &N);
	for (int i = 1;i <= N;i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 1;i <= N;i++)
	{
		if (arr[i] == i)
		{
			count++;
			break;
		}
	}
	if (count != 0) printf("-1");
	else
	{
		for (int i = 1;i <= N;i++) {
			b[i] = arr[i];
			c[i] = b[i];
		}
		num++;
		while (1)
		{
			for (int i = 1;i <= N;i++)
			{
				b[i] = arr[c[i]];
				c[i] = b[i];
			}

			for (int i = 1;i <= N;i++)
			{
				if (b[i] != i)
				{
					check++;
				}
				else break;
			}
			num++;
			if (num > 2 * 1000000000)
			{
				printf("-1");
				break;
			}
			else
			{
				if (check == N)
				{
					printf("%d", num);
					break;
				}
				else check = 0;
			}
		}


	}
	

}
