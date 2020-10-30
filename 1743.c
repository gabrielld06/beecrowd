#include <stdio.h>
#include <string.h>

int main() {
	int resposta = 0, i, conect1[5], con[5];
	for(i=0;i<5;i++) {
		scanf("%d", &conect1[i]);
	}
	for(i=0;i<5;i++) {
		scanf("%d", &con[i]);
	}
	for(i=0;i<5;i++) {
		if(conect1[i] == con[i]) {
			resposta = 1;
			i = 5;
		}
	}
	if(resposta == 1) {
		printf("N\n");
	} else {
		printf("Y\n");
	}
}