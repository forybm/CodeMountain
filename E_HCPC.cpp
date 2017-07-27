#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;
int arr[1000000][10];
vector<char> v;

void myf() {
	int a, b;
	int testcase;
	int sw = 0;
	scanf("%d", &testcase);
	scanf("%d %d", &a, &b);
	if (a > b) {
		sw = a;
		a = b;
		b = sw;
	}
		
	for (int i = 0; i < testcase; i++) {
		int num;
		int temp;
		int result = 0;
		scanf("%d", &num);
		temp = num;
		v.clear();
		if ((num) % 2 == 1) {
			while (num > 0) {
				if (num%a == 3 || num%a == 6 || num%a == 9 || num%a == 10 || num%a == 12 || num%a == 21 || num%a == 25) {
					result++;
				}
				num = num / a;
			}
			
			if (result == 0) {
				while (temp > 0) {
					if (temp % a < 10) {
						v.push_back((char)(temp%a + '0'));
					}
					else {
						v.push_back((char)(temp%a - 10 + 'A'));
					}
					temp = temp / a;
				}
			}
			for (int j = 0; j < v.size(); j++)
				printf("%c", v[v.size() - 1 - j]);

			for (int j = 0; j < result; j++)
				printf("CLAP");
			printf("\n");
		}

		else {
			while (num > 0) {
				if (num%b == 3 || num%b == 6 || num%b == 9 || num%b == 10 || num%b == 12 || num%b == 21 || num%b == 25) {
					result++;
				}
				num = num / b;
			}
			if (result == 0) {
				while (temp > 0) {
					if (temp % b < 10) {
						v.push_back((char)(temp%b + '0'));
					}
					else {
						v.push_back((char)(temp%b - 10 + 'A'));
					}
					temp = temp / b;
				}
			}

			for (int j = 0; j < v.size(); j++)
				printf("%c", v[v.size() - 1 - j]);

			for (int j = 0; j < result; j++)
				printf("CLAP");
			printf("\n");
		}
		
	}
		
	}


int main() {
	myf();
	//while (testcase--) myf();
	return 0;
}

