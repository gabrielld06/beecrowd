#include <iostream>
#define INF 2147483647
struct feitico {
	int dano;
	int mana;
};

int memo[1001][2001];

void resetar_memo() {
	for(int i=0;i<=1000;i++)
		for(int j=0;j<=2000;j++) memo[i][j] = -1;
}

int min(int x, int y) {
	return x < y ? x : y;
}

int demogorgon(int n, int p, feitico f[]) {
	int add, nadd, hp, ans;
	if(memo[n][p] == -1) {
		if(p <= 0)
			ans = 0;
		else if(n == 0)
			ans = INF;
		else {
			hp = p-f[n-1].dano;
			if(hp < 0) hp = 0;
			add = demogorgon(n-1, hp, f);
			nadd = demogorgon(n-1, p, f);
			if(add != INF) add += f[n-1].mana;
			ans = min(add, nadd);
		}
		memo[n][p] = ans;
	}
	return memo[n][p];
}

using namespace std;

int main() { 
	int n, p, resp;
	feitico f[10001];
	while(cin >> n) {
		cin >> p;
		for(int i=0;i<n;i++)
			cin >> f[i].dano >> f[i].mana;
		resetar_memo();
		resp = demogorgon(n, p, f);
		cout << (resp != INF ? resp : -1) << endl;
	}
	return 0;
}