#include <stdio.h>
#include <string.h>

int main() {
	char codigo[2000]={0};
	char aux[2000]={0};
	int i, j, k, l, m, c;
	scanf("%d", &c);
	for (i=0;i<c;i++) {
		getchar();
		scanf("%[^\n]s", codigo);
		for (j=0;j<strlen(codigo);j++) {
			if ((codigo[j]>=65 && codigo[j]<=90) || (codigo[j]>=97 && codigo[j]<=122)) {
				codigo[j] = codigo[j] + 3;	
			}
			aux[j] = codigo[j];
		}
		for (k=0;k<strlen(codigo);k++) {
			codigo[k] = aux[strlen(codigo)-1-k];
		}
		for (l=strlen(codigo)/2;l<strlen(codigo);l++) {
			codigo[l] = codigo[l]-1;
		}
		printf("%s\n", codigo);
	}
}