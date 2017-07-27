#include <stdio.h>
#include <algorithm>
using namespace std;

int h, m, s;
int x, y, z;

int main() {
	scanf("%d:%d:%d", &h, &m, &s);
	scanf("%d:%d:%d", &x, &y, &z);

	if(h>x) x = x + 24;
	else if (h == x&&m == y&&s == z) x = x + 24;
	int a, b, c;
	
	if (z - s >= 0) c = z - s;
	else {
		c = 60 + (z - s);
		y--;
	}
	if (y - m >= 0) b = y - m;
	else {
		b = 60 + (y - m);
		x--;
	}
	a = x - h;
	if (a < 0) a = 24 + a;
	if (a / 10 == 0) printf("0%d", a);
	else printf("%d",a);
	printf(":");
	
	if (b / 10 == 0) printf("0%d", b);
	else printf("%d",b);
	printf(":");
	
	if (c / 10 == 0) printf("0%d", c);
	else printf("%d",c);
	

}

