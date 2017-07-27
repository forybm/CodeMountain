#include <stdio.h>
#include <map>

using namespace std;
struct myclass{
	char name[20];
	int math;
};
int main()
{
	map <char,int> m;
	map <myclass,int> m2;	
	m['a']=10;
	m['b']=20;
	m['c']=30;
	m['d']=70;
}
