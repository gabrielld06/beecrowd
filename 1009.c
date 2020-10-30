#include <stdio.h>

int main() {
	char vetor[100];
	scanf("%s", vetor);
	double salario, venda;
	scanf("%lf %lf", &salario, &venda);
	printf("TOTAL = R$ %.2lf\n", venda*0.15+salario);
	return 0;
}