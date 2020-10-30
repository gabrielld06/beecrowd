#include <stdio.h>
#include <math.h>

int main() {
	double r = 0, exp = 0;
	scanf("%lf", &r);
	exp = pow(r, 3);
	printf("VOLUME = %.3lf\n", (4.0/3)*3.14159*exp);
	return 0;
}