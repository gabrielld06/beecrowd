#include <stdio.h>
#include <string.h>

int main() {
	int i, n=1, k=0, x[32767], result;
	char entrada[32767], aux[32767], aux1[32767], *ler, op[32767];
	while(n != 0) {
		scanf("%d", &n);
		if(n == 0)
			break;
		scanf("%s", entrada);
		result = 0;
		i=0;
		op[0] = '+';
		strcpy(aux, entrada);
		ler = strtok(aux, "+-");
		while(ler != NULL) {
			sscanf(ler, "%d", &x[i]);
			i++;
			ler = strtok(NULL, "+-");
		}
		i=1;
		strcpy(aux1, entrada);
		ler = strtok(aux1, "0123456789");
		while(ler != NULL) {
			sscanf(ler, "%c", &op[i]);
			i++;
			ler = strtok(NULL, "0123456789");
		}
		for(i=0;i<n;i++) {
			if(op[i] == '+')
				result += x[i];
			else
				result -= x[i];
		}
		k++;
		printf("Teste %d\n%d\n\n", k, result);
	}
	return 0;
}