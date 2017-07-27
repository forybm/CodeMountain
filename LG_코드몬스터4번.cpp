#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

FILE* in = fopen("input.txt", "r");
FILE* out = fopen("output.txt", "w");
int x[1000001];
int yy1[1000001], yy2[1000001];
void myf() {
	memset(x, 0, sizeof(x));
	memset(yy1, 0, sizeof(yy1));
	memset(yy2, 0, sizeof(yy2));

	int N;
	double L = 0;
	fscanf(in,"%d", &N);
	for (int i = 1;i <= N;i++) {
		fscanf(in,"%d %d %d",&x[i],&yy1[i],&yy2[i]);
	}
	for (int i = 2;i <= N;i++) {
		double h = x[i] - x[i - 1];
		double w;

		if ((yy1[i] <= yy2[i - 1] && yy1[i] >= yy1[i - 1]) || (yy2[i] <= yy2[i - 1] && yy2[i] >= yy1[i - 1])
			|| (yy2[i - 1] <= yy1[i] && yy2[i - 1] >= yy2[i]) || (yy1[i - 1] <= yy2[i] && yy1[i - 1] >= yy1[i])) {
			w = 0;
		}
		else {
			int arr[4];
			arr[0] = abs(yy1[i] - yy1[i - 1]);
			arr[1] = abs(yy1[i] - yy2[i - 1]);
			arr[2] = abs(yy2[i] - yy1[i - 1]);
			arr[3] = abs(yy2[i] - yy2[i - 1]);
			w = *min_element(arr, arr + 4);
		}
		L += sqrt(w*w+h*h);
	}
	fprintf(out,"%.2lf\n", L);

	//fprintf(out,"%lld\n", cnt);
}

int main() {
	
	int tt;
	fscanf(in,"%d", &tt);
	while (tt--)myf();
	return 0;
}
