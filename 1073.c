#include <stdio.h>
#include <math.h>

int main() {
	int n = 0, i;
	double exp = 0;
	scanf("%d", &n);
	for (i=2;i<=n;i=i+2){
		exp = pow(i, 2);
		printf("%d^%d = %.0lf\n", i, 2, exp);
	}
}