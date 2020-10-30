#include <stdio.h>
#include <string.h>
#include <math.h>

void troca(int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

int particiona(int v[], int a, int b) {
	int i, k = a;
	for (i=a+1;i<=b;i++) {
		if (v[i] < v[a]) {
			k++;
			troca(&v[i], &v[k]);
		}
	}
	troca(&v[a], &v[k]);
	return k;
}

void quick_sort(int v[], int a, int b) {
	if (a < b) {
		int p = particiona(v, a, b);
		quick_sort(v, a, p-1);
		quick_sort(v, p+1, b);
	}
}

int main() {
	int i = 0, j = 0, pacote, tcp[100000];
	char pack[7];
	while(scanf("%s", pack) != EOF) {
		i=0;
		while(strcmp(pack, "0")!=0) {
			scanf("%s", pack);
			if(strcmp(pack, "0") != 0)  {
				scanf("%d", &pacote);
				tcp[i] = pacote;
				i++;
			}
		}
		quick_sort(tcp, 0, i);
		if(i==0) {
			j++;
		} else {
			if (i > 0 && j == 1) {
				printf("Package 001\n");
			} else if (i > 0 && j > 1) {
				while(j>0) {
					printf("Package 000\n");
					j--;
				}
			}
			for(i=1;tcp[i]!=0;i++) {
				if(tcp[i] <= 9)
					printf("Package 00%d\n", tcp[i]);
				else if(tcp[i]<=99)
					printf("Package 0%d\n", tcp[i]);
				else
					printf("Package %d\n", tcp[i]);
			}
			printf("\n");
			j=0;
		}
	}
	return 0;
}