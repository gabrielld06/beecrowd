#include <stdio.h>

int main() {
	int temp, km;
	float litro;
	scanf("%d %d", &temp, &km);
	litro = temp*km;
	printf("%.3f\n", litro/12);
	return 0;
}