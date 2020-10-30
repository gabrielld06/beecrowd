#include <stdio.h>
#include <math.h>

int main() {
	int x, y, n, m, k, g_atual, g_menor = 2147483647;
	scanf("%d %d %d", &n, &m, &k);
	for(x=0.0;x<k;x+=1) {
		for(y=0.0;(x+1)*(y+1) <= k;y+=1) {
			if(n/(x+1) > m/(y+1)) {
				g_atual = n/(x+1);
			} else {
				g_atual = m/(y+1);
			}
			if (g_atual <g_menor) 
				g_menor = g_atual;
		}
	}
	printf("%d\n", g_menor);
	return 0;
}
