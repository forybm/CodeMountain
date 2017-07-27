#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
int N[500000];
int M[500000];
 
int main() {
    int n, m;
     
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++) {
        scanf("%d", &N[i]);
    }
 
    sort(N, N + n);
 
    scanf("%d", &m);
 
    for (int i = 0; i < m; i++) {
        scanf("%d", &M[i]);
    }
 
    for (int i = 0; i < m; i++) {
        printf("%d ", upper_bound(N, N + n, M[i]) - lower_bound(N, N + n, M[i]));
    
	}
 	return 0;
}
 
