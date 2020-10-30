#include <stdio.h>

int main() {
	int valida = 0;
	float nota, notav = 0;
	while(valida != 2) {
		scanf("%f", ¬a);
		if (nota > 10 || nota < 0) {
			printf("nota invalida\n");
		} else {
			notav = notav + nota;
			valida += 1;
		}
	}
	printf("media = %.2f\n", notav / 2);
}