#include <stdio.h>
typedef long long int lld;
FILE* in = fopen("input.txt", "r");
FILE* out = fopen("output.txt", "w");
void myf() {
	lld x, y;
	lld cnt = 0;
	fscanf(in,"%lld %lld", &x, &y);
	
	lld i = 1;
	while (i <= y) {
		cnt += (y - x - 1) / i;
		if (x%i - y%i >= 0)cnt++;
		i *= 2;
	}
	fprintf(out,"%lld\n", cnt);
}

int main() {
	
	int tt;
	fscanf(in,"%d", &tt);
	while (tt--)myf();
	return 0;
}
