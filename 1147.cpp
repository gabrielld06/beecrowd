#include <bits/stdc++.h>

using namespace std;

int main() {
	char in[2];
	int pos[8] = {8, 7, 6, 5, 4, 3, 2, 1};
	int n, t = 1, cv[2], p[2];
	cin >> in;
	while(strcmp(in, "0")) {
		cv[0] = pos[in[0] - '1'];
		cv[1] = in[1] - 96;
		
		int tab[9][9] = {0};
		n = 0;
		
		for(int i = 0;i < 8;i++) {
			cin >> in;
			p[0] = pos[in[0] - '1'];
			p[1] = in[1] - 96;
			
			if(p[0]+1 <= 8) {
				if(p[1]-1 >= 1) {
					tab[p[0]+1][p[1]-1] = 1;
				}
				if(p[1]+1 <= 8) {
					tab[p[0]+1][p[1]+1] = 1;
				}
			}
		}
		
		if(cv[0]+2 <= 8 and cv[1]+1 <= 8 and !tab[cv[0]+2][cv[1]+1]) {
			n++;
		}
		if(cv[0]+2 <= 8 and cv[1]-1 >= 1 and !tab[cv[0]+2][cv[1]-1]) {
			n++;
		}
		if(cv[0]-2 >= 1 and cv[1]+1 <= 8 and !tab[cv[0]-2][cv[1]+1]) {
			n++;
		}
		if(cv[0]-2 >= 1 and cv[1]-1 >= 1 and !tab[cv[0]-2][cv[1]-1]) {
			n++;
		}
		
		if(cv[0]+1 <= 8 and cv[1]+2 <= 8 and !tab[cv[0]+1][cv[1]+2]) {
			n++;
		}
		if(cv[0]+1 <= 8 and cv[1]-2 >= 1 and !tab[cv[0]+1][cv[1]-2]) {
			n++;
		}
		if(cv[0]-1 >= 1 and cv[1]+2 <= 8 and !tab[cv[0]-1][cv[1]+2]) {
			n++;
		}
		if(cv[0]-1 >= 1 and cv[1]-2 >= 1 and !tab[cv[0]-1][cv[1]-2]) {
			n++;
		}
		
		cout << "Caso de Teste #" << t++ << ": " << n << " movimento(s)." << endl;
		cin >> in;
	}
	
	
	return 0;
}