#include <bits/stdc++.h>

using namespace std;

int main() {
	int px, py, ix, iy, n;
		
	 while(scanf("%d %d %d", &px, &py, &n)==3) {
		for(int i = 0;i < n;i++) {
			scanf("%d %d", &ix, &iy);
			cout << ((ix <= px and iy <= py or ix <= py and iy <= px) ? "Sim\n" : "Nao\n");
		}
	}
	
	return 0;
}