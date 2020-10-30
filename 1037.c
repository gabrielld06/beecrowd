#include <stdio.h>

int main() {
	float numero;
	scanf("%f", &numero);
	if (numero <= 25 && numero >= 0) {
		printf("Intervalo [0,25]\n");
	} else if (numero <= 50 && numero > 25) {
		printf("Intervalo (25,50]\n");	
	} else if (numero <= 75 && numero > 50) {
		printf("Intervalo (50,75]\n");	
	} else if (numero <= 100 && numero > 75) {
		printf("Intervalo (75,100]\n");	
	} else {
		printf("Fora de intervalo\n");
	}
	return 0;
}