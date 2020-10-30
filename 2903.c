#include <stdio.h>
#include <math.h>

int mdc(int a, int b) {
	int q, r;
	r = a%b;
	if(r!=0) {
		return mdc(b, r);
	} else {
		return b;
	}
}

int main() {
	int r, d;
	scanf("%d.%d", &r, &d);
	printf("%d\n", 36000/mdc(36000, 100*r + d));
	return 0;
}