#include <stdio.h>

int main() {
	int n, i, maior=0, maiorI;
	scanf("%d", &n);
	int nota[n];
	for(i=0;i<n;i++) {
		scanf("%d", ¬a[i]);
		if(nota[i]>maior) {
			maior = nota[i];
			maiorI = i;
		}
	}
	if(maiorI == 0) {
		printf("S\n");
	} else {
		printf("N\n");
	}
}