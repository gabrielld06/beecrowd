#include <stdio.h>

int main() {
	int i, t, n, x;
	scanf("%d", &n);
	for(i=0;i<n;i++) {
		scanf("%d", &t);
		x = t%4;
		if (x == 0)
			printf("1\n");
		else if (x == 1)
			printf("7\n");
		else if (x == 2)
			printf("9\n");
		else
			printf("3\n");
	}
	return 0;
}