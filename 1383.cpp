#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, in, f = 0;
	int linhas[9][10], colunas[9][10], quadrantes[3][3][10];
	
	cin >> n;
	
	for(int t = 0;t < n; ++t) {
		for(int i = 0;i < 9;i++) {
			for(int j = 0;j < 10;j++) {
				linhas[i][j] = 0;
				colunas[i][j] = 0;
			}
		}
		for(int i = 0;i < 3;i++) {
			for(int j = 0;j < 3;j++) {
				for(int k = 0;k < 10;k++) {
					quadrantes[i][j][k] = 0;
				}
			}
		}
		f = 0;
		for(int i = 0;i < 9;i++) {
			for(int j = 0;j < 9;j++) {
				cin >> in;
				if(not f) {
					if(!linhas[i][in]) {
						linhas[i][in] = 1;
					} else {
						f = 1;
					}
					if(!colunas[j][in]) {
						colunas[j][in] = 1;
					} else {
						f = 1;
					}
					if(!quadrantes[i/3][j/3][in]) {
						quadrantes[i/3][j/3][in] = 1;
					} else {
						f = 1;
					}
				}
			}
		}
		cout << "Instancia " << t+1 << endl;
		if(!f) {
			cout << "SIM" << endl;
		} else {
			cout << "NAO" << endl;
		}
		cout << endl;
	}
}