#include <stdio.h>

int main() {
	double x, y;
	scanf("%lf %lf", &x, &y);
	printf("Concluimos que, dado o limite da entrada, a resposta seria:  y = f(x) = %.5lf.\n", (x*y)/2.0);
	return 0;
}