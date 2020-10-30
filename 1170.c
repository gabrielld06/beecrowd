#include <stdio.h>

int main() {
	int n, i, j;
	float x;
	scanf("%d", &n);
	for (j=0;j<n;j++){
		scanf("%f", &x);
		for (i=0;x>1;i++){
			x = x / 2;
		}
		printf("%d dias\n", i);
	}
	return 0;
}