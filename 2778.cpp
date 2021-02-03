#include <iostream>
#define INF 2147483647
using namespace std;

int memo[101][101][21][21][3];
int m_max; // Borda direita da matriz

// Espaços do memo
// Memo[Para N][Para M][Para X][Para Y][Para Direção]
// Direção:
// Estando em (i, j) ele pode ter vindo de i+1, j-1 ou j+1, defini que para:
// Direção == 1: veio de (i, j-1) então podemos ir para (i-1, j) ou (i, j+1)
// Direção == 2: veio de (i, j+1) então podemos ir para (i-1, j) ou (i, j-1)
// Direção == 0: veio de (i+1, j) então podemos ir para (i-1, j) ou (i, j-1) ou (i, j+1)
// Este ultimo sendo atribuido na primeira chamada no main

// Função para definir -1 em todas as posições do memo
void resetar_memo(int n, int m, int x, int y) {
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=m;j++) {
			for(int k=0;k<=x;k++) {
				for(int l=0;l<=y;l++) {
					for(int z=0;z<=3;z++) {
						memo[i][j][k][l][z] = -1;
					}
				}
			}
		}
	}
}

// Calculo de minimo
int min(int x, int y) {
	return x < y ? x : y;
}

// Primeira cadeia de if's para direção == 1, direção == 2 e direção == 0;
// Segunda cadeia de if's para a posição na matriz conforme o seguinte exemplo:
// C = Cima, E = Esquerda, D = Direita, X = Nenhuma (0,0)
// |X | E | E |E |
// |CD|CDE|CDE|CE|
// |CD|CDE|CDE|CE|
// |C |CDE|CDE|CE|
// De acordo com as possibilidades de caminho determinada pelos dois if's e realizada uma
// ultima checagem x e y, isto é, se mat[n][m] é negativo ou nulo e se é possivel adiciona-lo
// a solução, condição determinada por x > 0 para mat[n][m] == 0 e y > 0 para mat[n][m] < 0,
// caso as condições sejam válidas é realizada a proxima chamada, caso contrario ans recebe INF;
// ao final se ans != INF, isto é, foi possivel fazer as operações ans += mat[n][m], e memo = ans,
// caso contrario, memo = ans, que é INF;
// Dentro do main se a resposta for INF então é impossivel, e é printado "Impossivel", caso contrario
// é printado o resultado
int opt(int mat[101][101], int n, int m, int x, int y, int dir) {
	int ans = 0;
	if(memo[n][m][x][y][dir] == -1) {
		if(dir == 1) {
			if(n == 0 and m == 0) {
				if((mat[n][m] == 0 and x == 0) or (mat[n][m] < 0 and y == 0)) {
					ans = INF;
				}
			} else if(n != 0 and m == 0) {
				if((mat[n][m] == 0 and x == 0) or (mat[n][m] < 0 and y == 0)) {
					ans = INF;
				} else {
					if(mat[n][m] == 0)
						ans = min(opt(mat, n-1, m, x-1, y, 0), opt(mat, n, m+1, x-1, y, 1));
					else if(mat[n][m] < 0)
						ans = min(opt(mat, n-1, m, x, y-1, 0), opt(mat, n, m+1, x, y-1, 1));
					else
						ans = min(opt(mat, n-1, m, x, y, 0), opt(mat, n, m+1, x, y, 1));
				}
			} else if(n != 0 and m == m_max) {
				if((mat[n][m] == 0 and x == 0) or (mat[n][m] < 0 and y == 0)) {
					ans = INF;
				} else {
					if(mat[n][m] == 0)
						ans = opt(mat, n-1, m, x-1, y, 0);
					else if(mat[n][m] < 0)
						ans = opt(mat, n-1, m, x, y-1, 0);
					else
						ans = opt(mat, n-1, m, x, y, 0);
				}
			} else {
				if((mat[n][m] == 0 and x == 0) or (mat[n][m] < 0 and y == 0)) {
					ans = INF;
				} else {
					if(mat[n][m] == 0)
						ans = min(opt(mat, n-1, m, x-1, y, 0), opt(mat, n, m+1, x-1, y, 1));
					else if(mat[n][m] < 0)
						ans = min(opt(mat, n-1, m, x, y-1, 0), opt(mat, n, m+1, x, y-1, 1));
					else
						ans = min(opt(mat, n-1, m, x, y, 0), opt(mat, n, m+1, x, y, 1));
				}
			}
		} else if(dir == 2) {
			if(n == 0 and m == 0) {
				if((mat[n][m] == 0 and x == 0) or (mat[n][m] < 0 and y == 0)) {
					ans = INF;
				}
			} else if(n != 0 and m == 0) {
				if((mat[n][m] == 0 and x == 0) or (mat[n][m] < 0 and y == 0)) {
					ans = INF;
				} else {
					if(mat[n][m] == 0)
						ans = opt(mat, n-1, m, x-1, y, 0);
					else if(mat[n][m] < 0)
						ans = opt(mat, n-1, m, x, y-1, 0);
					else
						ans = opt(mat, n-1, m, x, y, 0);
				}
			} else if(n != 0 and m == m_max) {
				if((mat[n][m] == 0 and x == 0) or (mat[n][m] < 0 and y == 0)) {
					ans = INF;
				} else {
					if(mat[n][m] == 0)
						ans = min(opt(mat, n-1, m, x-1, y, 0), opt(mat, n, m-1, x-1, y, 2));
					else if(mat[n][m] < 0)
						ans = min(opt(mat, n-1, m, x, y-1, 0), opt(mat, n, m-1, x, y-1, 2));
					else
						ans = min(opt(mat, n-1, m, x, y, 0), opt(mat, n, m-1, x, y, 2));
				}
			} else if(n == 0 and m != 0) {
				if((mat[n][m] == 0 and x == 0) or (mat[n][m] < 0 and y == 0)) {
					ans = INF;
				} else {
					if(mat[n][m] == 0)
						ans = opt(mat, n, m-1, x-1, y, 2);
					else if(mat[n][m] < 0)
						ans = opt(mat, n, m-1, x, y-1, 2);
					else
						ans = opt(mat, n, m-1, x, y, 2);
				}
			} else {
				if((mat[n][m] == 0 and x == 0) or (mat[n][m] < 0 and y == 0)) {
					ans = INF;
				} else {
					if(mat[n][m] == 0)
						ans = min(opt(mat, n-1, m, x-1, y, 0), opt(mat, n, m-1, x-1, y, 2));
					else if(mat[n][m] < 0)
						ans = min(opt(mat, n-1, m, x, y-1, 0), opt(mat, n, m-1, x, y-1, 2));
					else
						ans = min(opt(mat, n-1, m, x, y, 0), opt(mat, n, m-1, x, y, 2));
				}
			}
		} else {
			if(n == 0 and m == 0) {
				if((mat[n][m] == 0 and x == 0) or (mat[n][m] < 0 and y == 0)) {
					ans = INF;
				}
			} else if(n != 0 and m == 0) {
				if((mat[n][m] == 0 and x == 0) or (mat[n][m] < 0 and y == 0)) {
					ans = INF;
				} else {
					if(mat[n][m] == 0)
						ans = min(opt(mat, n-1, m, x-1, y, 0), opt(mat, n, m+1, x-1, y, 1));
					else if(mat[n][m] < 0)
						ans = min(opt(mat, n-1, m, x, y-1, 0), opt(mat, n, m+1, x, y-1, 1));
					else
						ans = min(opt(mat, n-1, m, x, y, 0), opt(mat, n, m+1, x, y, 1));
				}
			} else if(n != 0 and m == m_max) {
				if((mat[n][m] == 0 and x == 0) or (mat[n][m] < 0 and y == 0)) {
					ans = INF;
				} else {
					if(mat[n][m] == 0)
						ans = min(opt(mat, n-1, m, x-1, y, 0), opt(mat, n, m-1, x-1, y, 2));
					else if(mat[n][m] < 0)
						ans = min(opt(mat, n-1, m, x, y-1, 0), opt(mat, n, m-1, x, y-1, 2));
					else
						ans = min(opt(mat, n-1, m, x, y, 0), opt(mat, n, m-1, x, y, 2));
				}
			} else if(n == 0 and m != 0) {
				if((mat[n][m] == 0 and x == 0) or (mat[n][m] < 0 and y == 0)) {
					ans = INF;
				} else {
					if(mat[n][m] == 0)
						ans = opt(mat, n, m-1, x-1, y, 2);
					else if(mat[n][m] < 0)
						ans = opt(mat, n, m-1, x, y-1, 2);
					else
						ans = opt(mat, n, m-1, x, y, 2);
				}
			} else {
				if((mat[n][m] == 0 and x == 0) or (mat[n][m] < 0 and y == 0)) {
					ans = INF;
				} else {
					if(mat[n][m] == 0) {
						ans = min(opt(mat, n-1, m, x-1, y, 0), min(opt(mat, n, m-1, x-1, y, 2), opt(mat, n, m+1, x-1, y, 1)));
					} else if(mat[n][m] < 0) {
						ans = min(opt(mat, n-1, m, x, y-1, 0), min(opt(mat, n, m-1, x, y-1, 2), opt(mat, n, m+1, x, y-1, 1)));
					} else {
						ans = min(opt(mat, n-1, m, x, y, 0), min(opt(mat, n, m-1, x, y, 2), opt(mat, n, m+1, x, y, 1)));
					}
				}
			}
		}
		if(ans != INF) ans += mat[n][m];
		memo[n][m][x][y][dir] = ans;
	}
	return memo[n][m][x][y][dir];
}

int main() {
	int n, m, x, y, mat[101][101], resp;
	while(cin >> n) {
		cin >> m >> x >> y;
		m_max = m-1;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++)
				cin >> mat[i][j];
		}
		resetar_memo(n, m, x, y);
		resp = opt(mat, n-1, m-1, x, y, 0);
		if(resp == INF)
			cout << "Impossivel" << endl;
		else
			cout << resp << endl;
	}
	return 0;
}