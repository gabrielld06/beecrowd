#include <stdio.h>

int main () {
	long long int fatm = 1, fatn = 1;
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF) {
    	while (m>1){
    		fatm = fatm * m;
    		m = m - 1;
		}
		while (n>1){
			fatn = fatn * n;
    		n = n - 1;
		}
        printf ("%lli\n", fatm + fatn);
        fatm = 1;
        fatn = 1;
	}
    return 0;
}