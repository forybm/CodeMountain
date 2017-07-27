//lower_Bound,uppper_bound test


#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	
	int a[10];
	int value;
	int restore;
	//vector<int>::iterator low;	
	
	for(int i=0;i<10;i++)
	{
		a[i]=i+1;
	}
//	vector<int>::iterator low,up;
//	low=lower_bound (a,a+10,5); //          ^
  
	puts("what is number we find ?");
	
	scanf("%d",&value);
//	restore=lower_bound(a,a+10,5,greater <int>());
	printf("%d",lower_bound(a,a+10,value));
}
/*
	// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector
using namespace std;
int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  vector<int>::iterator low,up;
  low=lower_bound (v.begin(), v.end(), 20); //          ^
  up= upper_bound (v.begin(), v.end(), 20); //                   ^

  cout << "lower_bound at position " << (low- v.begin()) << '\n';
  printf("upper_bound at position %d\n",*up);

  return 0;
}


*/	
