#include <stdio.h>

int main() {
	int codigo, n;
	float total;
	scanf("%d %d", &codigo, &n);
	switch(codigo) {
		case 1:
			total = 4.0 * n; 
		break;
		case 2:
			total = 4.5 * n; 
		break;
		case 3:
			total = 5.0 * n; 
		break;
		case 4:
			total = 2.0 * n; 
		break;
		case 5:
			total = 1.5 * n; 
		break;
	}
	printf("Total: R$ %.2f\n", total);
}