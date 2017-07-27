#include <stdio.h>
#include <math.h>
int arr[22];
int n;
int p;

void nq(int x)
{
	if (x == n) { p++; return; }

	for (int i = 0; i < n; i++)
	{
		int j;
		for (j = 0; j < x; j++)
			if (x - j == i - arr[j] || x - j == (i - arr[j])*(-1) || i == arr[j])
				break;

		if (j != x)continue;
		arr[x] = i;
		nq(x + 1);
	}
}

int main()
{
	scanf("%d", &n);

	nq(0);

	printf("%d", p);
	
}
