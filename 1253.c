#include <stdio.h>
#include <string.h>

int main() {
	char codigo[51];
	char aux[51];
	int i, j, casos, cesar;
	scanf("%d", &casos);
	for (j=0;j<casos;j++) {
		getchar();
		scanf("%[^\n]s", codigo);
		scanf("%d", &cesar);
		for (i=0;i<strlen(codigo);i++) {
			codigo[i] = codigo[i] - cesar;	
			if (codigo[i] < 65) {
				codigo[i] = codigo[i] + 26;
			}
		}
		printf("%s\n", codigo);
	}
	return 0;
}