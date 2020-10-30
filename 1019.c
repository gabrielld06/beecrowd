#include <stdio.h>

int main() {
	int n, i, j;
	scanf("%d", &n);
	for (i=0;n>=3600;i++) {
		n = n-3600;
	}
	for (j=0;n>=60;j++) {
		n = n-60;
	}
	printf("%d:%d:%d\n", i,j,n);
	return 0;
}