#include <stdio.h>

int main() {
	int numero, hora;
	double salario;
	scanf("%d %d %lf", &numero, &hora, &salario);
	printf("NUMBER = %d\n", numero);
	printf("SALARY = U$ %.2lf\n", hora*salario);
	return 0;
}