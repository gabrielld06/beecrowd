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
	int i, j, pacote, tcp[100000];
	char string[15];
	while(scanf("%s", string) != EOF) {
		i=0;
		if(strcmp(string, "1")==0) {
			while(strcmp(string, "0")!=0) {
				scanf(" %[^\n^\r]s", string);
				if(strcmp(string, "0") == 0)
					break;
				sscanf(&string[8], "%d%*c", &pacote);
				tcp[i] = pacote;
				i++;
			}
			tcp[i] = 0;
			quick_sort(tcp, 0, i);
			for(j=1;j<=i;j++) {
				printf("Package %03d\n", tcp[j]);
			}
			printf("\n");
		}
	}
	return 0;
}