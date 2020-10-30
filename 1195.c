#include <stdio.h>
#include <stdlib.h>

typedef struct sNo {
	int codigo;
	struct sNo*esquerda;
	struct sNo*direita;
}TNo;

typedef struct sNo* No;

No cria_arvore(){
	No raiz = (TNo *)malloc(sizeof(TNo));
	raiz = NULL;
	return raiz;
}

int eh_nulo(No raiz){
	if(raiz == NULL)
		return 1;
	return 0;
}

No insere(int cod, No no_atual) {
	if(eh_nulo(no_atual)){
		no_atual = (TNo *)malloc(sizeof(TNo));
		no_atual->codigo = cod;
		no_atual->esquerda = NULL;
		no_atual->direita = NULL;
	} else if(cod <no_atual->codigo){
		no_atual->esquerda = insere(cod, no_atual->esquerda);
	} else {
		no_atual->direita = insere(cod, no_atual->direita);
	}
	return no_atual;
}

void red(No no_atual) {
	if(no_atual != NULL) {
		printf(" %d",no_atual->codigo);
		red(no_atual->esquerda);
		red(no_atual->direita);
	}
}

void edr(No no_atual) {
	if(no_atual != NULL) {
		edr(no_atual->esquerda);
		edr(no_atual->direita);
		printf(" %d", no_atual->codigo);
	}
}

void erd(No no_atual) {
	if(no_atual != NULL) {
		erd(no_atual->esquerda);
		printf(" %d", no_atual->codigo);
		erd(no_atual->direita);
	}
}

int main() {
	int c, n, num, i=1;
	No raiz;
	scanf("%d", &c);
	while(c--) {
		raiz = cria_arvore();
		scanf("%d", &n);
		while(n--) {
			scanf("%d", &num);
			raiz = insere(num, raiz);
		}
		printf("Case %d:\nPre.:", i++);
		red(raiz);
		printf("\nIn..:");
		erd(raiz);
		printf("\nPost:");
		edr(raiz);
		printf("\n\n");
	}
	return 0;
}