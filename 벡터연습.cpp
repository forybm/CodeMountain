#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main()
{	
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(6);	
	
	map<int,int> m;
	
	
	queue<int> qu;
	qu.push(3);
	qu.push(4);
	qu.push(5);
	
	for (int i=0;i<vec.size();i++)
	{
		printf("%d\n",vec[i]);
	}
	
	while(!qu.empty())
	{
		int now=qu.front();
		qu.pop();
		printf("%d\n",now);
	}
	
}

	
