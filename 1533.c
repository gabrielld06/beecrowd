#include <stdio.h>

int main() {
	int i, n, maior=0, maiori=0, assasin=0, assasini, sus[1001];
	do{
		maior=0;
		scanf("%d", &n);
		if(n!=0) {
			for(i=0;i<n;i++) {
				scanf("%d", &sus[i]);
				if(sus[i]>maior) {
					assasini = maiori;
					assasin = maior;
					maior = sus[i];
					maiori = i;
				} else if(sus[i]>assasin) {
					assasin = sus[i];
					assasini = i;
				}
			}
			printf("%d\n", assasini+1);
		}
	}while(n!=0);
}