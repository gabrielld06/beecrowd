#include <bits/stdc++.h>

using namespace std;

void tower(int tab[10][10], char tabC[9][9], int x, int y) {
	for(int i = x+1;i < 9;i++) {
		tab[i][y] = 1;
		if(tabC[i][y] != '-') break;
	}
	for(int i = x-1;i > 0;i--) {
		tab[i][y] = 1;
		if(tabC[i][y] != '-') break;
	}
	for(int i = y+1;i < 9;i++) {
		tab[x][i] = 1;
		if(tabC[x][i] != '-') break;
	}
	for(int i = y-1;i > 0;i--) {
		tab[x][i] = 1;
		if(tabC[x][i] != '-') break;
	}
}

void bishop(int tab[10][10], char tabC[9][9], int x, int y) {
	for(int i = 1;x+i < 9 and y+i < 9;i++) {
		tab[x+i][y+i] = 1;
		if(tabC[x+i][y+i] != '-') break;
	}
	for(int i = 1;x+i < 9 and y-i > 0;i++) {
		tab[x+i][y-i] = 1;
		if(tabC[x+i][y-i] != '-') break;
	}
	for(int i = 1;x-i > 0 and y+i < 9;i++) {
		tab[x-i][y+i] = 1;
		if(tabC[x-i][y+i] != '-') break;
	}
	for(int i = 1;x-i > 0 and y-i > 0;i++) {
		tab[x-i][y-i] = 1;
		if(tabC[x-i][y-i] != '-') break;
	}
}

void pawn(int tab[10][10], int x, int y) {
	if(x+1 < 9) {
		if(y+1 < 9)
			tab[x+1][y+1] = 1;
		if(y+1 > 0)
			tab[x+1][y-1] = 1;
	}
}

void king(int tab[10][10], int x, int y) {
	if(x+1 < 9) {
		tab[x+1][y] = 1;
		if(y+1 < 9)
			tab[x+1][y+1] = 1;
		if(y+1 > 0)
			tab[x+1][y-1] = 1;
	}
	if(x-1 > 0) {
		tab[x-1][y] = 1;
		if(y+1 < 9)
			tab[x-1][y+1] = 1;
		if(y+1 > 0)
			tab[x-1][y-1] = 1;
	}
	if(y+1 < 9)
		tab[x][y+1] = 1;
	if(y+1 > 0)
		tab[x][y-1] = 1;
}

bool mate(int tab[10][10], int x, int y) {
	return tab[x+1][y-1] and tab[x+1][y] and tab[x+1][y+1] and
			tab[x][y-1] and tab[x][y] and tab[x][y+1] and
			tab[x-1][y-1] and tab[x-1][y] and tab[x-1][y+1];
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	string p;
	
	int pos[8] = {8, 7, 6, 5, 4, 3, 2, 1};
	int tab[10][10];
	char tabC[9][9];
	
	for(int i = 0;i < 10; i++) {
		tab[0][i] = 1;
		tab[i][9] = 1;
		tab[i][0] = 1;
		tab[9][i] = 1;
	}
	
	string pcs[10];
	
	while(cin >> n) {
		// Reset
		for(int i = 1;i < 9; i++) {
			for(int j = 1;j < 9; j++) {
				tab[i][j] = 0;
			}
		}
		memset(tabC, '-', sizeof(tabC));
		
		// read
		for(int i = 0;i < n;i++) {
			cin >> pcs[i];
			// put in table
			tabC[pos[pcs[i][2]-'1']][pcs[i][1]-96] = pcs[i][0];
		}
		// mark squares
		for(int i = 0;i < n;i++) {
			if(pcs[i][0] == 'T') {
				tower(tab, tabC, pos[pcs[i][2]-'1'], pcs[i][1]-96);
			} else if(pcs[i][0] == 'B') {
				bishop(tab, tabC, pos[pcs[i][2]-'1'], pcs[i][1]-96);				
			} else if(pcs[i][0] == 'R') {
				tower(tab, tabC, pos[pcs[i][2]-'1'], pcs[i][1]-96);
				bishop(tab, tabC, pos[pcs[i][2]-'1'], pcs[i][1]-96);
			} else if(pcs[i][0] == 'P') {
				pawn(tab, pos[pcs[i][2]-'1'], pcs[i][1]-96);	
			} else {
				king(tab, pos[pcs[i][2]-'1'], pcs[i][1]-96);
			}
		}
		cin >> p;
		cout << (mate(tab, pos[p[2]-'1'], p[1]-96) ? "SIM\n" : "NAO\n");
		//printTab(tab);
	}
	
	return 0;
}