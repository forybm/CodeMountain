#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void myf(int test)
{
	int N;
	int *people;
	int large;
	char c;
	scanf("%d", &N);

	people = (int*)malloc(sizeof(int)*N);

	for (int i = 0;i < N;i++)
	{
		int temp;
		scanf("%d", &temp);
		people[i] = temp;
	}

	printf("Case #%d:", test);
	while (*max_element(people, people + N)!=0) {
		large = max_element(people, people + N) - people;
		people[large]--;
		c = large + 65;
		printf(" %c", c);
		if (*max_element(people, people + N) == 0) break;

		large = max_element(people, people + N) - people;
		people[large]--;
		c = large + 65;
		printf("%c", c);
	}
	
	printf("\n");

	free(people);
	



}

int main()
{
	int testcase;
	scanf("%d", &testcase);

	for (int i = 1; i <= testcase;i++)
	{
		myf(i);
	}
}
