#include <stdio.h>
#include <string.h>

int main() {
	char nome[100], ultimo[100], ultimot[100], temp[100];
	int i;
	strcpy(ultimo, " ");
	strcpy(ultimot, " ");
	strcpy(temp, " ");
	while(fgets(nome, sizeof(nome), stdin) != NULL) {
		for(i=0;i<strlen(nome);i++) {
			if (nome[i]>=65 && nome[i]<=90) {
				temp[i] = nome[i] +32;
			}else{
				temp[i] = nome[i];
			}
		}
		if(strcmp(temp, ultimot) > 0) {
			strcpy(ultimot, temp);
			strcpy(ultimo, nome);
		}
	}
	printf("%s", ultimo);
}
