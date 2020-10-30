#include <stdio.h>

int main() {
	int t, v, d;
	while(scanf("%d %d", &v, &t)!=EOF) {
		printf("%d\n", v*(t*2));
	}
	return 0;
}
