#include <stdio.h>
#include <string.h>

int main() {
	char baguizinho[15], baguizinho1[15], baguizinho2[15]; //Top 10 variable names 2019
	scanf("%s", baguizinho);
	scanf("%s", baguizinho1);
	scanf("%s", baguizinho2);		
	if (strcmp(baguizinho, "vertebrado")==0) {
		if (strcmp(baguizinho1, "ave")==0) {
			if (strcmp(baguizinho2, "carnivoro")==0) {
				printf("aguia\n");
			} else if (strcmp(baguizinho2, "onivoro")==0) {
				printf("pomba\n");
			}
		} else if (strcmp(baguizinho1, "mamifero")==0) {
			if (strcmp(baguizinho2, "onivoro")==0) {
				printf("homem\n");
			} else if (strcmp(baguizinho2, "herbivoro")==0) {
				printf("vaca\n");
			}
		}
	} else if (strcmp(baguizinho, "invertebrado")==0) {
		if (strcmp(baguizinho1, "inseto")==0) {
			if (strcmp(baguizinho2, "hematofago")==0) {
				printf("pulga\n");
			} else if (strcmp(baguizinho2, "herbivoro")==0) {
				printf("lagarta\n");
			}
		} else if (strcmp(baguizinho1, "anelideo")==0) {
			if (strcmp(baguizinho2, "hematofago")==0) {
				printf("sanguessuga\n");
			} else if (strcmp(baguizinho2, "onivoro")==0) {
				printf("minhoca\n");
			}
		}
	}
	return 0;
}