#include <bits/stdc++.h>
#define False 'N'
#define True 'S'

using namespace std;

char memo[100002][1002];

void resetar_memo(int n, int m) {
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=m;j++) {
			memo[i][j] = 'F';
		}
	}
}

char coins(int v, int m, vector<int> moedas) {
	int troco;
	char ans, add, nadd;
	if(memo[v][m] == 'F') {
		if(m == 0 and v != 0) {
			ans = False;
		} else if(v == 0) {
			ans = True;
		} else if(v < 0) {
			ans = False;
		} else {
			troco = v-moedas[m-1];
			if(troco == 0) {
				ans = True;
			} else {
				if(troco >= 0) {
					add = coins(troco, m-1, moedas);
				} else
					add = False;
				nadd = (add == True ? True : coins(v, m-1, moedas));
				ans = (add == True ? add : nadd);
			}
		}
		memo[v][m] = ans;
	}
	return memo[v][m];
}

int main() {
	int v, m, in;
	vector<int> moedas;
	cin >> v >> m;
	for(int i=0;i<m;i++) {
		scanf("%d", &in);
		moedas.push_back(in);
	}
	sort(moedas.begin(), moedas.begin()+m);
	vector<int>::iterator lb;
	lb = lower_bound(moedas.begin(), moedas.end(), v);
	if(moedas[lb - moedas.begin()] == v) {
		cout << True << "\n";
	} else {
		resetar_memo(v+1, m+1);
		cout << coins(v, lb-moedas.begin()+1, moedas) << "\n";
	}
	return 0;
}