#include <stdio.h>

int main() {
	int produto, unidade, i;
	double preco, total = 0;
	for (i=0;i<2;i++){
		scanf("%d %d %lf", &produto, &unidade, &preco);
		total = total + preco * unidade;
	}
	printf("VALOR A PAGAR: R$ %.2lf\n", total);
	return 0;
}