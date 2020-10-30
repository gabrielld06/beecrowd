#include <stdio.h>
#include <math.h>

int encontra_num(int a, int b, int c, int d) {
	int n = 1, i;
	for (i=1;i<sqrt(c);i++) {
		n = a*i;
		if (n%b != 0 && c%n == 0 && d%n != 0) {
			i = c-1;
			return n;
		}
	}
	if (c%a == 0 && c%b != 0 && d%c != 0 && i != c) {
		return c;
	}
	else if (i != c) {
		return -1;
	}
}

int main() {
	int a, b, c, d, i;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("%d\n", encontra_num(a, b, c, d));
	return 0;
}