#include <stdio.h>

int main() {
	int saida, viagem, fuso, hora;
	scanf("%d %d %d", &saida, &viagem, &fuso);
	hora = saida + viagem + fuso;
	if (hora>=24) {
		hora = hora - 24;
	}
	else if (hora<0) {
		hora = hora + 24;
	}
	printf("%d\n", hora);
}