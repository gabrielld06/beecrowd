#include <stdio.h>

int main() {
	int ano, mes, dia;
	scanf("%d", &dia);
	for (ano=0;dia>=365;ano++) {
		dia = dia-365;
	}
	for (mes=0;dia>=30;mes++) {
		dia = dia-30;
	}
	printf("%d ano(s)\n", ano);
	printf("%d mes(es)\n", mes);
	printf("%d dia(s)\n", dia);
	return 0;
}