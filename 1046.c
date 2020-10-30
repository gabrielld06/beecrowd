#include <stdio.h>

int main() {
	int hora, hora2, tempo;

	scanf("%d", &hora);
	scanf("%d", &hora2);

	tempo = hora2 - hora;

	if (hora2 <= hora) {
		tempo = tempo + 24;
	}
	printf("O JOGO DUROU %d HORA(S)\n", tempo);
	
	return 0;
}