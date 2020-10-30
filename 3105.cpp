#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
	int x, y;
	double n, m, k, g_atual, g_menor = INFINITY;
	cin >> n >> m >> k;
	for(x=0;x<k;x++) {
		for(y=0;(x+1)*(y+1) <= k;y++) {
			if(n/(x+1) > m/(y+1)) {
				g_atual = n/(x+1);
			} else {
				g_atual = m/(y+1);
			}
			if (g_atual <g_menor) 
				g_menor = g_atual;
		}
	}
	cout << fixed;
	cout << setprecision(0) << g_menor << "\n";
	return 0;
}
